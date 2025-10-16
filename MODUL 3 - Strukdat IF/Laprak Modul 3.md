# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Tadzkiroh Aziziyah Haqia</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

## Guided 

### 1. [mahasiswa.cpp]
#include <iostream>
using namespace std;
#include "mahasiswa.h"

void inputMhs(mahasiswa &m){
    cout << "input nama = ";
    cin >> (m).nim;
    cout << "input nilai = ";
    cin >> (m).nilai1;
    cout << "input nilai2 = ";
    cin >> (m).nilai2;
}

float rata2(mahasiswa m){
    return (m.nilai1 + m.nilai2) / 2.0;
}

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 2. [mahasiswa.h]
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);
#endif // MAHASISWA_H_INCLUDED

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 3. [main.cpp]
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata-rata = " << rata2(mhs);
    return 0;
}

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Unguided 

### 1. [Soal]
#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    string nim;
    float uts, uas, tugas;
    float nilaiAkhir;
};

float nilaiAkhir(mahasiswa mhs) {
    return (0.3 * mhs.uts) + (0.4 * mhs.uas) + (0.3 * mhs.tugas);
}

int main() {
    mahasiswa mhs[10];
    int n;

    cout << "Masukan jumlah mahasiswa: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Data mahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        cin >> mhs[i].nama;
        cout << "NIM : ";
        cin >> mhs[i].nim;
        cout << "uts : ";
        cin >> mhs[i].uts;
        cout << "uas : ";
        cin >> mhs[i].uas;
        cout << "tugas : ";
        cin >> mhs[i].tugas;
        mhs[i].nilaiAkhir = nilaiAkhir(mhs[i]);
    }
    cout << "nilai akhir:" << endl;
    for (int i = 0; i < n; i++){
        cout << mhs[i].nama << " (" << mhs[i].nim << ") = " << mhs[i].nilaiAkhir << endl;
    }
}

#### Output:
<img width="1108" height="215" alt="Screenshot 2025-10-16 212209" src="https://github.com/user-attachments/assets/132332aa-0737-429d-8af6-d49da2e49779" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 3. [Soal]
#include <iostream> 
using namespace std;

void Array(int A[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) 
        cout << A[i][j] << " ";
    }
    cout << endl;
}

void tukarArray(int A1[3][3], int A2[3][3], int i, int j) {
    int n = A1[i][j];
    A1[i][j] = A2[i][j];
    A2[i][j] = n;
}

void tukarP(int &x, int &y) {
    int n = x; x = y; y = n;
}

int main() {
    int A1[3][3] = {{1,2,3}, {2,3,4}, {3,4,5}};
    int A2[3][3] = {{1,3,5}, {2,4,6}, {1,4,6}};
    int a = 12, b = 21;

    cout << "Array A1:" << endl; Array(A1);
    cout << "Array A2:" << endl; Array(A2);

    tukarArray(A1, A2, 2, 4);
    cout << "Setelah tukar posisi [2][4]:" << endl;
    cout << "Array A1:" << endl; Array(A1);
    cout << "Array A2:" << endl; Array(A2);
    cout << "Sebelum tukar nilai: a =" << a <<", b =" << b << endl;
    tukarP(a,b);
    cout << "Setelah tukar nilai: a =" << a <<", b =" << b << endl;
}

#### Output:
<img width="969" height="294" alt="Screenshot 2025-10-16 223147" src="https://github.com/user-attachments/assets/7dba1d9d-5f0c-4523-b921-550c7136b13c" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
https://www.programiz.com/cpp-programming/examples/add-matrix
https://www.programiz.com/cpp-programming/arrays
Modul 1 & 2 Pengenalan Bahasa C++

