#include <iostream>
using namespace std;

int cariMaksimum(int arr[], int n) {
    int maks = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maks)
        maks = arr[i];
    }
    return maks;
}

int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
        min  = arr[i];
    }
    return min;
}

void hitungRataRata(int arr[], int n)  {
        float total = 0;
        for (int i = 0; i < n; i++) {
            total += arr[i];
        }
        float rata = total / n;
        cout << "Nilai rata-rata: " << rata << endl;
}

void tampilkanArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Array 1 Dimensi
    int arrA[10] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}, n=10, pilihan;

    do {
        cout << "=== MENU ARRAY ====" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Nilai Maksimum" << endl;
        cout << "3. Nilai Minimum" << endl;
        cout << "4. Nilai Rata-rata" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                tampilkanArray(arrA, n);
                break;
            case 2:
                cout << "Nilai maksimum: " << cariMaksimum(arrA, n) << endl;
                break;
            case 3:
                cout << "Nilai minimum: " << cariMinimum(arrA, n) << endl;
                break;
            case 4:
                hitungRataRata(arrA, n);
                break;
            default:
                return 0;
    }
} while (pilihan == 1 || pilihan == 2 || pilihan == 3 || pilihan == 4);

}