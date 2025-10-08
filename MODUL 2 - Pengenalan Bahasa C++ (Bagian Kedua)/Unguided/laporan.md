# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Tadzkiroh Aziziyah Haqia</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

## Guided 

### 1. [Array]
#include <iostream>
using namespace std;

int main() {
    // Array 1 Dimensi
    int arr1D[5] = {10, 20, 30, 40, 50};
    cout << "Array 1 Dimensi:" << endl;
    for (int i = 0; i < 5; i++) { //
        cout << "arr1D[" << i << "] = " << arr1D[i] << endl;
    }
    cout << endl;

    // Array 2 Dimensi (baris x kolom)
    int arr2D[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    cout << "Array 2 Dimensi:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "arr2D[" << i << "][" << j << "] = " << arr2D[i][j]
            << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Array Multi Dimensi (3D)
    int arr3D[2][2][3] = {
        { {1, 2, 3}, {4, 5, 6} },
        { {7, 8, 9}, {10, 11, 12} }
    };
    cout << "Array 3 Dimensi:" << endl;
    for (int i = 0; i < 2; i++) { 
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                cout << "arr3D[" << i << "][" << j << "]["
                << k << "] = "<< arr3D[i][j][k] << endl;
            }
        }
    }

    return 0;
}

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 2. [functionProcedure]
#include <iostream>
using namespace std;

void tulis (int x) {
    for (int i = 0; i < x; i++) {
        cout << "Baris ke -: " << i+1 << endl;
    }
}

int main() {
    int jum;
    cout << "Jumlah baris kata: ";
    cin >> jum;
    tulis(jum);
    return 0;
}

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 3. [Pointer]
#include <iostream>
using namespace std;

void tukar (int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in ptr (address of a): " << ptr << endl; 
    cout << "Value pointed to by ptr: " << *ptr << endl; //ditunjuk pointer yg isinya 20

    tukar(&a, &b); //&a->*
    cout << "After swapping, value of a=" << a << " and b=" << b << endl; //berhasil ditukar

    return 0;
}

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 4. [Reference]
#include <iostream>
using namespace std;

void tukar (int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 20, b = 30;
    int& ref = a;

    cout << "Nilai a: " << a << endl;
    cout << "Alamat a (&a): " << &a << endl;
    cout << "Nilai ref (alias a): " << ref << endl; 
    cout << "Alamat ref (&ref): " << &ref << endl; 

    //Mengubah nilai a lewat reference
    ref = 50;
    cout << "\nSetelah ref = 50;" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai ref: " << ref << endl;

    tukar(a, b);
    cout << "After swapping, value of a=" << a << " and b=" << b << endl; 

    return 0;
}

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Unguided 

### 1. [Soal]

#include <iostream>
using namespace std;

int main() {
    int arrA[3][3];
    int arrB[3][3];
    int hasil[3][3];

    //elemen A
    cout << "matriks A:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arrA[i][j];
        }
    }

    //elemen B
    cout << "matriks B:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arrB[i][j];
        }
    }

    //Penjumlahan
    cout << "Hasil A+B:" << endl ;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = arrA[i][j] + arrB[i][j];
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }

    //Pengurangan 
    cout << "Hasil A-B:" << endl ;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = arrA[i][j] - arrB[i][j];
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }

    //Perkalian
    cout << "Hasil A*B:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = 0;
            for (int x = 0; x < 3; x++) {
                hasil[i][j] += arrA[i][x] * arrB[x][j];
            }
            cout << hasil[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

#### Output:
<img width="811" height="451" alt="Screenshot 2025-10-08 205322" src="https://github.com/user-attachments/assets/940a9e77-78ed-4d88-979b-50b61cea4496" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 2. [Soal]
#include <iostream>
using namespace std;

void tukar_pointer (int *x, int *y, int *z) {
    int temp;
    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

void tukar_reference (int &x, int &y, int &z) {
    int temp;
    temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a = 12, b = 18, c = 26;
    cout << "Nilai sebelum di tukar: "<< a <<", "<< b <<", "<< c << endl;
    tukar_pointer(&a, &b, &c); //&a->*
    cout << "After swapping pointer, value of a=" << a << " b=" << b << " and c=" << c << endl; //berhasil ditukar
    tukar_reference(a, b, c);
    cout << "After swapping reference, value of a=" << a << " b=" << b << " and c=" << c << endl;

    return 0;
}

#### Output:
<img width="616" height="88" alt="Screenshot 2025-10-08 210815" src="https://github.com/user-attachments/assets/2ef38b1a-5b81-405f-b29f-70b75379cf5f" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 3. [Soal]
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

#### Output:
<img width="844" height="645" alt="Screenshot 2025-10-08 215511" src="https://github.com/user-attachments/assets/197de574-7f20-46b8-851d-e02e09aa75b3" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
https://www.programiz.com/cpp-programming/examples/add-matrix
https://www.programiz.com/cpp-programming/arrays
Modul 1 & 2 Pengenalan Bahasa C++
