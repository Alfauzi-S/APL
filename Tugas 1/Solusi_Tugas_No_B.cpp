#include <iostream>
using namespace std;

bool cekTripelPythagoras(int a, int b, int c) {
    int max_val, sisi1, sisi2;

    if (a >= b && a >= c) {
        max_val = a; sisi1 = b; sisi2 = c;
    } else if (b >= a && b >= c) {
        max_val = b; sisi1 = a; sisi2 = c;
    } else {
        max_val = c; sisi1 = a; sisi2 = b;
    }

    int kuadratHipotenusa = sisi1 * sisi1 + sisi2 * sisi2;

    cout << "Nilai kuadrat dari sisi miring (hipotenusa) = " << kuadratHipotenusa << endl;

    return kuadratHipotenusa == (max_val * max_val);
}

int main() {
    int a, b, c;

    cout << "Masukkan bilangan a: ";
    cin >> a;
    cout << "Masukkan bilangan b: ";
    cin >> b;
    cout << "Masukkan bilangan c: ";
    cin >> c;

    if (cekTripelPythagoras(a, b, c)) {
        cout << "Tripel Pythagoras." << endl;
    } else {
        cout << "Bukan Tripel Pythagoras." << endl;
    }

    return 0;
}