# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Tadzkiroh Aziziyah Haqia</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

## Guided 

### 1. [Nama Topik]

C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code guided praktikan" << endl;
    return 0;
}

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Unguided 

### 1. [Soal]

#include <iostream>
using namespace std;

int main() {
    float a, b;
    cout << "Bilangan1: ";
    cin >> a;
    cout << "Bilangan2: ";
    cin >> b;

    //aritmatika
    cout << "Penjumlahan: " << a + b << endl;
    cout << "Pengurangan: " << a - b << endl;
    cout << "Perkalian: " << a * b << endl;
    cout << "Pembagian: " << a / b << endl;
    
    //atau
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    
    return 0;
}

#### Output:
<img width="934" height="302" alt="Screenshot 2025-10-01 223618" src="https://github.com/user-attachments/assets/284a82dc-9a0a-4762-a4cc-f190a942dff3" />


Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)

### 2. [Soal]
#include <iostream>
using namespace std;

string satuan[] = {"nol","satu","dua","tiga","empat","lima","enam","tujuh","delapan","sembilan"};
string belasan[] = {"sebelas","dua belas","tiga belas","empat belas","lima belas","enam belas","tujuh belas","delapan belas","sembilan belas"};
string puluhan[] = {"","sepuluh","dua puluh","tiga puluh","empat puluh","lima puluh","enam puluh","tujuh puluh","delapan puluh","sembilan puluh"};

int main() {
    int n;
    cout << "Masukan angka dari 0 - 100: ";
    cin >> n;

    cout << n << " = ";

    if (n < 10) {
        cout << satuan[n];
    }
    else if (n < 20) {
        cout << belasan [n-10];
    }
    else if (n < 100) {
        int a = n / 10;
        int b = n % 10;
        cout << puluhan[a];
        if (b != 0) {
            cout << " " << satuan[b];
        }
    }
    else if (n == 100) {
        cout << "seratus";
    }
    else {
        cout << "tidak bisa, harus 0 sampai 100 aja yah";
    }
    cout << endl;

    return 0;
}

#### Output:
<img width="1031" height="134" alt="Screenshot 2025-10-01 220438" src="https://github.com/user-attachments/assets/3252661c-dc41-4531-8093-741ede5a0841" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 3. [Soal]
#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;

    for (int i = a; i > 0; i--) 
    {
        for (int x = 0; x < a-i; x++)
        {
            cout << "  ";
        }
        for (int y = i; y > 0; y--)
        {
            cout << y << " ";
        }
        cout << "* ";
        for (int z = 1; z <= i; z++)
        {
            cout << z << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < a; i++)
    {
        cout << "  ";
    }
    cout << "*" << endl;
}

#### Output:
<img width="937" height="218" alt="Screenshot 2025-10-01 223520" src="https://github.com/user-attachments/assets/8c4dcbe6-1b31-4228-9263-6d3604aa7821" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
(https://www.w3schools.com/cpp/cpp_arrays.asp
https://www.w3schools.com/cpp/
https://id.wikipedia.org/wiki/C%2B%2B
Modul 1 Pengenalan Bahasa C++)
