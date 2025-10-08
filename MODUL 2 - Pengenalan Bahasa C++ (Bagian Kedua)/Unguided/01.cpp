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

//1,2 
//4,5 deklarasi fungsi main() dan membuat array (3) dengan ukuran 3*3
//A_ B_ untuk menyimpan matriks A dan B, hasil untuk menyimpan hasil operasi (penjumlahan, pengurangan, perkalian)

//8 untuk("input elemen matriks A")
//9 for i -> loop baris (0,1,2)
//10 for j -> loop kolom (0,1,2)
//11 cin >> A_matriks[i][j]; -> untuk input nilai ke [i][j]
//hasilnya: user menginput 3 angka perbaris (3 kali = 9 angka)

//16 untuk("input elemen matriks B")
//17 for i -> loop baris (0,1,2)
//18 for j -> loop kolom (0,1,2)
//19 cin >> A_matriks[i][j]; -> untuk input nilai ke [i][j]
//hasilnya: user menginput 3 angka perbaris (3 kali = 9 angka)

//27 menghitung hasil penjumlahan per elemen
//28 mencetak hasil dengan menggunakan \t (tab) agar tidak berantakan
//30 cout << endl; -> untuk memindahkan baris setelah selesai 1 baris matriks

//37 menghitung hasil pengurangan per elemen
//38 mencetak hasil dengan menggunakan \t (tab) agar tidak berantakan
//40 cout << endl; -> untuk memindahkan baris setelah selesai 1 baris matriks

//matriks_hasil[i][j] = 0; -> inisialisasi hasil ke 0
//for (int x = 0; x < 3; x++) -> untuk melakukan penjumlahan hasil kali baris A dan kolom B
//mencetak hasil dengan menggunakan \t (tab) agar tidak berantakan

//return 0; -> program selesai dengan nilai 0 = berhasil