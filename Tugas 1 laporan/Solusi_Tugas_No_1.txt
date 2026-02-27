#include <iostream>
using namespace std;

int matrix[2][3] = {
        {6, 7, 8},
        {1, 5, 3}
};

const int rows = 2;
const int cols = 3;

int min_value = matrix[0][0];
int max_value = matrix[0][0];
int total = 0;

int main() {    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < min_value) {
                min_value = matrix[i][j];
            }
            if (matrix[i][j] > max_value) {
                max_value = matrix[i][j];
            }
            total += matrix[i][j];
        }
    }
    
    float average = static_cast<float>(total) / (rows * cols);
    
    cout << "Matriks:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << "\nNilai minimum  : " << min_value << endl;
    cout << "Nilai maksimum : " << max_value << endl;
    cout << "Rata-rata      : " << average << endl;
    
    return 0;
}