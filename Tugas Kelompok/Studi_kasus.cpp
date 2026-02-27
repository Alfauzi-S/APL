#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
using namespace std;

struct Produk {
    int id;
    string nama;
    string lokasi;
};

void exchangeSort(Produk arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].id > arr[j].id) {
                Produk temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int fibonacciSearch(Produk arr[], int n, int x) {
    int fibM2 = 0, fibM1 = 1, fibM = fibM2 + fibM1;

    while (fibM < n) {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM = fibM2 + fibM1;
    }

    int offset = -1;
    while (fibM > 1) {
        int i = min(offset + fibM2, n - 1);

        if (arr[i].id < x) {
            fibM = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM - fibM1;
            offset = i;
        } else if (arr[i].id > x) {
            fibM = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fibM - fibM1;
        } else {
            return i;
        }
    }

    if (fibM1 && offset + 1 < n && arr[offset + 1].id == x) 
        return offset + 1;
    return -1;
}

int main() {
    Produk data[15] = {
        {105, "Speaker Aktif", "G-12"}, {23, "Mouse Wireless", "B-04"},
        {89, "Webcam HD", "F-09"}, {12, "Keyboard Gaming", "A-02"},
        {45, "HDMI Cable 2m", "C-05"}, {67, "Headset Bluetooth", "D-07"},
        {90, "Power Bank 20000mAh", "F-10"}, {34, "USB Hub 4 Port", "B-05"},
        {56, "Flashdisk 64GB", "D-06"}, {78, "Mousepad Gaming", "E-08"},
        {11, "Kabel Data Type-C", "A-01"}, {29, "Earphone In-Ear", "B-03"},
        {88, "Adapter Laptop Universal", "F-08"}, {50, "Webcam Cover", "C-06"},
        {100, "Stand Laptop", "G-11"}
    };
    
    int n = 15;

    exchangeSort(data, n);

    cout << "=== DATA INVENTARIS TERURUT (ID TERKECIL - TERBESAR) ===" << endl;
    cout << setw(10) << "ID Produk" << " | " << setw(25) << "Nama Barang" << " | " << "Lokasi" << endl;
    cout << "--------------------------------------------------------" << endl;
    
    for (int i = 0; i < n; i++) {
        cout << setw(10) << data[i].id << " | " 
            << setw(25) << data[i].nama << " | " 
            << data[i].lokasi << endl;
    }

    int target = 90;
    int index = fibonacciSearch(data, n, target);

    cout << "\n=== HASIL PENCARIAN ID " << target << " ===" << endl;
    if (index != -1) {
        cout << "Barang Ditemukan!" << endl;
        cout << "Nama Barang : " << data[index].nama << endl;
        cout << "Lokasi Rak  : " << data[index].lokasi << endl;
    } else {
        cout << "Barang dengan ID " << target << " tidak ditemukan." << endl;
    }

    return 0;
}