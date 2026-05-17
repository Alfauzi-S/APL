#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <climits>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;

// Daftar node sesuai urutan kolom
const vector<string> nodeNames = {
    "FT", "FPIK", "FHUKUM", "FK", "FKIP", "Farmasi", "FKM",
    "FEB", "Rektorat", "FAHUTAN", "FISIPOL", "FAPERTA"
};

map<string, int> nameToIdx;

int getIdx(const string& name) {
    return nameToIdx[name];
}

struct Edge {
    int to;
    int weight;
};

int main() {
    // Inisialisasi mapping
    for (size_t i = 0; i < nodeNames.size(); i++) {
        nameToIdx[nodeNames[i]] = i;
    }

    int n = nodeNames.size();
    vector<vector<Edge>> graph(n);

    auto addEdge = [&](const string& u, const string& v, int w) {
        int iu = getIdx(u);
        int iv = getIdx(v);
        graph[iu].push_back({iv, w});
        graph[iv].push_back({iu, w});
    };

    // Data edge (hanya yang melibatkan node dalam tabel)
    addEdge("FT", "FPIK", 280);
    addEdge("FT", "FHUKUM", 350);
    addEdge("FT", "FK", 450);
    addEdge("FT", "FKIP", 550);
    addEdge("FT", "Farmasi", 600);
    addEdge("FPIK", "FEB", 350);
    addEdge("FPIK", "FKIP", 290);
    addEdge("FHUKUM", "FKM", 270);
    addEdge("FK", "FEB", 350);
    addEdge("FKIP", "Rektorat", 300);
    addEdge("FKIP", "FAHUTAN", 290);
    addEdge("FKIP", "FISIPOL", 408);
    addEdge("Farmasi", "FKM", 55);
    addEdge("FEB", "Rektorat", 120);
    addEdge("FEB", "FAPERTA", 450);
    addEdge("Rektorat", "FAPERTA", 230);

    int start = getIdx("FT");
    int target = getIdx("FAPERTA");

    // Dijkstra dengan pencatatan history
    vector<int> dist(n, INT_MAX);
    vector<bool> settled(n, false);
    vector<int> prev(n, -1);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    struct Update {
        int node;
        int oldDist;
        int newDist;
    };
    vector<pair<int, vector<Update>>> history;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (settled[u]) continue;
        settled[u] = true;

        vector<Update> updates;
        for (const Edge& e : graph[u]) {
            int v = e.to;
            int w = e.weight;
            if (!settled[v] && dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                int old = dist[v];
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push({dist[v], v});
                updates.push_back({v, old, dist[v]});
            }
        }
        history.push_back({u, updates});
        if (u == target) break;
    }

    // Cetak header dengan setw (lebar kolom disesuaikan)
    const int colWidth = 24;
    cout << left;
    cout << setw(colWidth) << "Iterasi";
    for (const string& name : nodeNames) {
        cout << setw(colWidth) << name;
    }
    cout << endl;

    // Simulasi state
    vector<int> currentDist(n, INT_MAX);
    vector<bool> currentSettled(n, false);
    currentDist[start] = 0;

    // Baris 0 (inisial)
    cout << setw(colWidth) << "0 (inisial)";
    for (int i = 0; i < n; i++) {
        if (i == start) cout << setw(colWidth) << "0*";
        else cout << setw(colWidth) << "∞";
    }
    cout << endl;

    // Proses setiap iterasi
    for (size_t iter = 0; iter < history.size(); iter++) {
        int u = history[iter].first;
        vector<Update> updates = history[iter].second;
        currentSettled[u] = true;
        for (const Update& upd : updates) {
            currentDist[upd.node] = upd.newDist;
        }

        string iterLabel = to_string(iter+1) + " (pilih " + nodeNames[u] + ")";
        cout << setw(colWidth) << iterLabel;
        for (int i = 0; i < n; i++) {
            if (i == u) {
                cout << setw(colWidth) << (to_string(currentDist[i]) + "*");
            } else {
                bool updated = false;
                int oldVal = -1;
                for (const Update& upd : updates) {
                    if (upd.node == i) {
                        updated = true;
                        oldVal = upd.oldDist;
                        break;
                    }
                }
                if (updated) {
                    int weight = -1;
                    for (const Edge& e : graph[u]) {
                        if (e.to == i) {
                            weight = e.weight;
                            break;
                        }
                    }
                    string expr;
                    if (oldVal == INT_MAX) {
                        expr = "MIN[∞, " + to_string(currentDist[u]) + "+" + to_string(weight) + "] = " + to_string(currentDist[i]);
                    } else {
                        expr = "MIN[" + to_string(oldVal) + ", " + to_string(currentDist[u]) + "+" + to_string(weight) + "] = " + to_string(currentDist[i]);
                    }
                    cout << setw(colWidth) << expr;
                } else {
                    if (currentDist[i] == INT_MAX) cout << setw(colWidth) << "∞";
                    else {
                        string val = to_string(currentDist[i]);
                        if (currentSettled[i]) val += "*";
                        cout << setw(colWidth) << val;
                    }
                }
            }
        }
        cout << endl;
    }

    // Tampilkan rute terpendek
    cout << "\n=== Rute Terpendek ===\n";
    if (dist[target] == INT_MAX) {
        cout << "Tidak ada jalur dari FT ke FAPERTA" << endl;
    } else {
        vector<int> path;
        for (int v = target; v != -1; v = prev[v]) path.push_back(v);
        reverse(path.begin(), path.end());
        cout << "Rute: ";
        for (size_t i = 0; i < path.size(); i++) {
            cout << nodeNames[path[i]];
            if (i != path.size()-1) cout << " → ";
        }
        cout << "\nPanjang Lintasan = " << dist[target] << " meter" << endl;
    }

    return 0;
}