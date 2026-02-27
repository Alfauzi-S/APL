#include <iostream>
using namespace std;

double pangkat(int a, int b) {
    if (b == 0) {
        return 1;
    } else if (b > 0) {
        return a * pangkat(a, b - 1);
    } else {  // b < 0
        return 1.0 / pangkat(a, -b);
    }
}

int main() {
    int a, b;

    cout << "Masukkan bilangan (a): ";
    cin >> a;
    cout << "Masukkan pangkat (b): ";
    cin >> b;

    cout << "Hasil dari " << a << "^" << b << " adalah: " << pangkat(a, b) << endl;

    return 0;
}