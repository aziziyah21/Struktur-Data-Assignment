# <h1 align="center">Laporan Praktikum Modul Doubly Linked List (Bagian Kedua) (6)</h1>
<p align="center">Tadzkiroh Aziziyah Haqia</p>

## Dasar Teori
Doubly Linked List adalah struktur data yang terdiri dari rangkaian node. Setiap node nya itu menyimpan data serta dua pointer yang mengarah ke node sebelum dan sesudahnya. Dalam struktur ini bergerak maju dan mundur dalam list. Doubly Linked List memakai dua pointer utama pada list, yaitu first(menunjuk elemen paling awal) dan last(menunjuk elemen paling akhir). Bentuk dua arah ini memberi fleksibilitas dalam penelusuran dan pengelolaan data. Struktur ini berguna untuk aplikasi yang sering menambah atau menghapus data di berbagai posisi karena perubahan hanya membutuhkan penyesuaian pointer di sekeliling node tersebut. Doubly Linked List lebih fleksibel daripada Single Linked List karena memungkinkan navigasi dua arah, tetapi membutuhkan memori lebih(karena setiap node menyimpan dua pointer). Jadi, pada struktur ini digunakan saat program perlu mengatur data berurutan yang dapat berubah dengan cepat.

## Guided 

### 1. [dll_hapus.cpp]
#include <iostream> 
using namespace std; 
#define Nil NULL 

typedef int infotype; // Definisikan tipe data infotype sebagai integer untuk menyimpan informasi elemen
typedef struct elmlist *address; // Definisikan tipe address sebagai pointer ke struct elmlist

struct elmlist { 
    infotype info; // Deklarasikan field info untuk menyimpan data elemen
    address next;   
    address prev; 
}; 

struct List { 
    address first; 
    address last;
}; 

address alokasi(infotype x) { // Definisikan fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P->info = x; P->next = Nil; P->prev = Nil; return P; // Set nilai info, next, prev, dan kembalikan pointer
} 
void dealokasi(address &P) { delete P; P = Nil; } // Definisikan fungsi dealokasi untuk mengosongkan memori elemen
void insertFirst(List &L, address P) { 
    P->next = L.first; P->prev = Nil; // Set pointer next P ke first saat ini dan prev ke Nil
    if (L.first != Nil) L.first->prev = P; else L.last = P; // Jika list tidak kosong, update prev first; jika kosong, set last ke P
    L.first = P; // Update first list menjadi P
}

void printInfo(List L) { 
    address P = L.first; while (P != Nil) { cout << P->info << " "; P = P->next; } cout << endl; // Loop melalui list dan cetak info setiap elemen
} 
void deleteFirst(List &L, address &P) { 
    P = L.first; L.first = L.first->next; // Set P ke first dan update first ke next-nya
    if (L.first != Nil) L.first->prev = Nil; else L.last = Nil; // Jika list tidak kosong, set prev first baru ke Nil; jika kosong, set last ke Nil
    P->next = Nil; P->prev = Nil; // Kosongkan pointer next dan prev P
}

void deleteLast(List &L, address &P) { 
    P = L.last; L.last = L.last->prev; // Set P ke last dan update last ke prev-nya
    if (L.last != Nil) L.last->next = Nil; else L.first = Nil; // Jika list tidak kosong, set next last baru ke Nil; jika kosong, set first ke Nil
    P->prev = Nil; P->next = Nil; // Kosongkan pointer prev dan next P
} 
    
void deleteAfter(List &L, address &P, address R) { 
    P = R->next; R->next = P->next; // Set P ke next R dan update next R ke next P
    if (P->next != Nil) P->next->prev = R; else L.last = R; // Jika ada next P, update prev-nya ke R; jika tidak, set last ke R
    P->prev = Nil; P->next = Nil; // Kosongkan pointer prev dan next P
} 

int main() { 
    List L; L.first = Nil; L.last = Nil; 
    insertFirst(L, alokasi(1)); insertFirst(L, alokasi(2)); insertFirst(L, alokasi(3)); // Sisipkan elemen 1, 2, 3 di awal list
    printInfo(L);
    address P; deleteFirst(L, P); dealokasi(P); // Deklarasikan P, hapus first, dealokasi P
    deleteAfter(L, P, L.first); dealokasi(P); // Hapus setelah first, dealokasi P
    printInfo(L); 
    return 0; 
}

### 2. [dll_insert.cpp]
#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype; // Definisikan tipe data infotype sebagai integer untuk menyimpan informasi elemen
typedef struct elmlist *address; // Definisikan tipe address sebagai pointer ke struct elmlist

struct elmlist {
    infotype info; // Deklarasikan field info untuk menyimpan data elemen
    address next;
    address prev;
};

struct List { 
    address first; 
    address last; 
}; 

void insertFirst(List &L, address P) { 
    P->next = L.first; // Set pointer next dari P ke elemen pertama saat ini
    P->prev = Nil; // Set pointer prev dari P ke Nil karena menjadi elemen pertama
    if (L.first != Nil) L.first->prev = P; // Jika list tidak kosong, set prev elemen pertama lama ke P
    else L.last = P; // Jika list kosong, set last juga ke P
    L.first = P; // Update first list menjadi P
} 

void insertLast(List &L, address P) { 
    P->prev = L.last; // Set pointer prev dari P ke elemen terakhir saat ini
    P->next = Nil; // Set pointer next dari P ke Nil karena menjadi elemen terakhir
    if (L.last != Nil) L.last->next = P; // Jika list tidak kosong, set next elemen terakhir lama ke P
    else L.first = P; // Jika list kosong, set first juga ke P
    L.last = P; // Update last list menjadi P
} 

void insertAfter(List &L, address P, address R) { // Definisikan fungsi insertAfter untuk menyisipkan elemen setelah R
    P->next = R->next; // Set pointer next dari P ke elemen setelah R
    P->prev = R; // Set pointer prev dari P ke R
    if (R->next != Nil) R->next->prev = P; // Jika ada elemen setelah R, set prev elemen tersebut ke P
    else L.last = P; // Jika R adalah terakhir, update last menjadi P
    R->next = P; // Set next dari R ke P
}

address alokasi(infotype x) { // Definisikan fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P->info = x; // Set info elemen dengan nilai x
    P->next = Nil; // Set next elemen ke Nil
    P->prev = Nil; // Set prev elemen ke Nil
    return P; 
} 

void printInfo(List L) { // Definisikan fungsi printInfo untuk mencetak isi list
    address P = L.first; // Set P ke elemen pertama list
    while (P != Nil) { // Loop selama P tidak Nil
        cout << P->info << " "; // Cetak info dari P 
        P = P->next; // Pindah ke elemen berikutnya
    } 
    cout << endl; 
}

int main() { 
    List L; 
    L.first = Nil; 
    L.last = Nil;
    address P1 = alokasi(1); 
    insertFirst(L, P1); 
    address P2 = alokasi(2); 
    insertLast(L, P2); 
    address P3 = alokasi(3); 
    insertAfter(L, P3, P1); 
    printInfo(L); 
    return 0; 
}

## Unguided

### 1. [dll.h]
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
using namespace std;

struct Kendaraan {
    string noPolisi;
    string warna;
    int tahun;
};

typedef Kendaraan infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(List &L, address P, address R);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);

address findElm(List L, string noPolisi);
void printInfo(List L);

#endif

### 2. [dll.cpp]
#include "dll.h"

void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

//no 1,2,3
void insertFirst(List &L, address P) { 
    P->next = L.first; 
    P->prev = NULL;
    if (L.first != NULL) L.first->prev = P;
    else L.last = P;
    L.first = P; 
} 

//no 1,2,3
void insertLast(List &L, address P) { 
    P->prev = L.last; 
    P->next = NULL; 
    if (L.last != NULL) L.last->next = P; 
    else L.first = P; 
    L.last = P; 
} 

void insertAfter(List &L, address P, address R) {
    P->next = R->next;
    P->prev = R;
    if (R->next != NULL) R->next->prev = P;
    else L.last = P;
    R->next = P;
}

//no 3
void deleteFirst(List &L, address &P) {
    P = L.first;
    if (P != NULL) {
        L.first = P->next;
        if (L.first != NULL){
            L.first->prev = NULL;
        } else {
            L.last = NULL;
            P->next = NULL;
            P->prev = NULL;
        }
    }
}

//no 3
void deleteLast(List &L, address &P) {
    P = L.last;
    if (P != NULL) {
        L.last = P->prev;
        if (L.last != NULL){
            L.last->next = NULL;
        }else{
            L.first = NULL;
            P->next = NULL;
            P->prev = NULL;
        }
    }
}

//no 3
void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != NULL){
            P->next->prev = Prec;
        }else{
            L.last = Prec;
            P->next = NULL;
            P->prev = NULL;
        }
    }
}

//no 2
address findElm(List L, string noPolisi) {
    address P = L.first;
    while (P != NULL && P->info.noPolisi != noPolisi) {
        P = P->next;
    }
    return P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << "Nomor Polisi : " << P->info.noPolisi << endl;
        cout << "Warna : " << P->info.warna << endl;
        cout << "Tahun : " << P->info.tahun << endl;
        cout << endl;
        P = P->next;
    }
}

### 3. [main.cpp]
#include "dll.h"

#include <iostream>
using namespace std;

int main() {
List L;
createList(L);

infotype ken1 = {"D001", "Hitam", 90};
infotype ken2 = {"D002", "Putih", 70};
infotype ken3 = {"D003", "Merah", 80};
infotype ken4 = {"D004", "Kuning", 90};

insertFirst(L, alokasi(ken1));
insertFirst(L, alokasi(ken2));
insertLast(L, alokasi(ken3));
insertLast(L, alokasi(ken4));

//no1
//cout << "Data kendaraan" << endl;
//printInfo(L);

//no2
//string cari;
//cout << "Masukan No Polisi yang dicari" << endl; //no2
//cin >> cari;

//address pCari = findElm(L, cari);

//if (pCari != NULL) {
//    cout << "Nomor Polisi : " << pCari->info.noPolisi << endl;
//    cout << "Warna : " << pCari->info.warna << endl;
//    cout << "Tahun : " << pCari->info.tahun << endl;
//}

//no3
string cari;
cout << "Masukan No Polisi yang akan dihapus" << endl; //no2
cin >> cari;
address p = findElm(L, cari);

if (p != NULL) {
    address hapus; 

    if (p == L.first){
        deleteFirst(L, hapus);
    } else if (p == L.last) {
        deleteLast(L, hapus);
    } else {
        deleteAfter(L, p->prev, hapus);
    }

    dealokasi(hapus);
}

printInfo(L);

return 0;

}

### 1. [output] 
<img width="1211" height="418" alt="Screenshot 2025-11-24 144828" src="https://github.com/user-attachments/assets/837d5095-8b2d-4b78-b16e-9cd2730f2dcf" />

### 2. [output] 
<img width="1165" height="156" alt="Screenshot 2025-11-24 151104" src="https://github.com/user-attachments/assets/88991b32-fcc8-43cd-8959-34fb95982f20" />

### 3. [output] 
<img width="1174" height="337" alt="Screenshot 2025-11-24 154431" src="https://github.com/user-attachments/assets/171f5e4b-94de-4b17-bc21-24ff9538d83b" />

Program memakai struct Kendaraan untuk menyimpan nomor polisi, warna, dan tahun. Node DLL menyimpan data ini bersama pointer next dan prev agar kamu bisa bergerak maju dan mundur dalam list. List punya pointer first dan last untuk menandai awal data dan akhir data. createList(membuat list kosong). alokasi(membuat node baru dan menyiapkan pointer next&prev). dealokasi(menghapus node dari memori). printInfo menampilkan seluruh isi list.
insertFirst dan insertLast menambah node didepan atau dibelakang list. Dua fungsi ini digunakan dinomor 1&2, untuk mengatur ulang pointer agar rantai node tetap terhubung. insertAfter(menyisipkan data setelah node tertentu). 
deleteFirst, deleteLast, dan deleteAfter digunakan dinomor 3, untuk menghapus node berdasarkan posisi. Program memindahkan pointer agar list tetap rapi setelah penghapusan. 
findElm digunakan dinomor 2 untuk mencari data berdasarkan nomor polisi. 

Di bagian main, program membuat empat data kendaraan, memasukkannya ke DLL, lalu pengguna akan mengetik nomor polisi yang ingin dihapus. 
Program mencari node itu, menentukan posisinya, menghapus dengan fungsi yang sesuai, lalu menampilkan sisa data.

## Kesimpulan
Program ini untuk membentuk struktur data yang bisa menambah, mencari, dan menghapus data kendaraan. Saat menyimpan data dalam node yang saling terhubung lewat pointer next dan prev. Setiap akan menjalankan operasi update pointer itun agar list tetap teratur. Pada program utama nya menunjukkan alur lengkap. Lalu, Data dibuat juga ditambah ke list. Pengguna memasukan nomor polisi yang akan dihapus, lalu nomor polisi ditemukan untuk dihapus. Program mencari posisi data lalu menghapus sesuai posisinya. Jadi, untuk hasil akhirnya itu akan  menampilkan list yang sudah diperbarui.

## Referensi
https://www.ibm.com/docs/en/zos/2.4.0?topic=bd-writing-your-c-dll-code
Modul 6 Doubly Linked List
