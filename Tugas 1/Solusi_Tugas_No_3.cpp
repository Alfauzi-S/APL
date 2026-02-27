#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Masukkan jumlah baris: ";
    cin >> rows;
    cout << "Masukkan jumlah kolom: ";
    cin >> cols;
    
    if (rows <= 0 || cols <= 0) {
        cerr << "\nError: Dimensi array harus bernilai positif!" << endl;
        return 1;
    }
    
    double matrix[rows][cols];
    double total = 0.0;
    
    cout << "\nMasukkan elemen matriks:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Elemen [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
            total += matrix[i][j];
        }
    }
    
    cout << "\nMatriks:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    double average = total / (rows * cols);
    
    cout << "\nTotal elemen   : " << rows * cols << endl;
    cout << "Jumlah nilai   : " << total << endl;
    cout << "Rata-rata      : " << average << endl;
    
    return 0;
}