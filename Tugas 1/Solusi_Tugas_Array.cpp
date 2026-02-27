#include <iostream>
using namespace std;

int angka[101] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
    31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
    51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
    61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
    71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
    81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
    91, 92, 93, 94, 95, 96, 97, 98, 99, 100
};

int main() {
    cout << "Bilangan Prima :" << endl;
    int prima[25];
    int k = 0;

    for (int i = 0; i < 101; i++) {
        int pembagi = 0;
        for (int j = 1; j <= angka[i]; j++) {
            if (angka[i] % j == 0) 
                pembagi++;
        }

        if (pembagi == 2) {
            prima[k] = angka[i];
            cout << angka[i] << " ";
            k++;
        }
    }

    cout << "\n\nBilangan Fibonacci :" << endl;
    int fib[15];
    fib[0] = 0;
    fib[1] = 1;
    cout << fib[0] << " " << fib[1] << " ";
    
    int n = 2;
    while (true) {
        int next = fib[n - 1] + fib[n - 2];
        if (next > 100) break;
        
        fib[n] = next;
        cout << fib[n] << " ";
        n++;
    }

    cout << "\n\nBilangan Fibonacci prima :" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (fib[i] == prima[j]) {
                cout << fib[i] << " ";
                break;
            }
        }
    }
    
    cout << endl;
    return 0;
}