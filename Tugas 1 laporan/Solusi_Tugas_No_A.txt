#include <iostream>
using namespace std;

void tentukanJenisSegitiga(double sisi1, double sisi2, double sisi3) {
    double a, b, c;

    if (sisi1 >= sisi2 && sisi1 >= sisi3) {
        a = sisi2; b = sisi3; c = sisi1;
    } else if (sisi2 >= sisi1 && sisi2 >= sisi3) {
        a = sisi1; b = sisi3; c = sisi2;
    } else {
        a = sisi1; b = sisi2; c = sisi3;
    }

    if (a + b <= c) {
        cout << "Tidak bisa membentuk segitiga." << endl;
    } else {
        double c_kuadrat = c * c;
        double ab_kuadrat = a * a + b * b;

        if (c_kuadrat == ab_kuadrat) {
            cout << "Segitiga siku-siku." << endl;
        } else if (a == b || b == c || a == c) {
            cout << "Segitiga sama kaki." << endl;
        } else {
            cout << "Segitiga sembarang." << endl;
        }
    }
}

int main() {
    double sisi1, sisi2, sisi3;

    cout << "Masukkan sisi 1: ";
    cin >> sisi1;
    cout << "Masukkan sisi 2: ";
    cin >> sisi2;
    cout << "Masukkan sisi 3: ";
    cin >> sisi3;

    tentukanJenisSegitiga(sisi1, sisi2, sisi3);

    return 0;
}