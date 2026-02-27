#include <iostream>
using namespace std;

int main() {
    double matrix[2][2];
    double det;

    cout << "Masukkan elemen matriks 2x2:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "Elemen [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    
    cout << "\nMatriks:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    if (det == 0) {
        cout << "\nMatriks tidak memiliki invers (determinan = 0).\n";
    } else {
        double invers[2][2];

        invers[0][0] = matrix[1][1] / det;
        invers[0][1] = -matrix[0][1] / det;
        invers[1][0] = -matrix[1][0] / det;
        invers[1][1] = matrix[0][0] / det;

        cout << "\nMatriks invers:\n";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout << invers[i][j] << "\t";
            }
            cout << endl;
        }
    }

    return 0;
}