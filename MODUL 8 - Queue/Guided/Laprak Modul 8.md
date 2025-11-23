# <h1 align="center">Laporan Praktikum Modul Queue (8)</h1>
<p align="center">Tadzkiroh Aziziyah Haqia</p>

## Dasar Teori
Queue atau antrian adalah struktur data linear yang bekerja dengan prinsip FIFO(First In First Out), -> elemen yang pertama masuk akan menjadi elemen pertama yang dikeluarkan. Konsep ini mirip antrean di loket pelayanan, orang pertama dalam baris akan dilayani dulu. Nah, dalam pemrograman, struktur data queue dapat diimplementasikan menggunakan linked list serta array(tergantung kebutuhan memory dan fleksibilitas struktur) 
Secara umum, queue memiliki dua operasi utama:
1. Enqueue, yaitu menambahkan data pada bagian tail (belakang).
2. Dequeue, yaitu menghapus data pada bagian head (depan). 

Kalo direpresentasi menggunakan linked list, setiap elemen direpresentasikan sebagai node dengan atribut (info) dan pointer (next), sementara struktur queue memuat dari pointer (head) dan (tail) sebagai penanda batas antrian. Ini yang bersifat dinamis, sehingga jumlah elemen bergantung pada ketersediaan memori. 
Nahh, kalo direpresentasi menggunakan array, ini bersifat statis, sehingga jumlah elemen terbatas. 
Di modul terdapat beberapa variasi implementasi, seperti:
-Alternatif 1: head tetap, tail bergerak (elemen digeser saat penghapusan).
-Alternatif 2: head dan tail bergerak, tetapi dapat terjadi kondisi penuh semu sehingga perlu pergeseran manual.
-Alternatif 3 (Circular Queue): indeks head dan tail berputar seperti buffer sehingga tidak perlu pergeseran elemen dan lebih efisien. 

## Guided 1

### 1. [queue.h]
// guided 1 queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void CreateQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif

### 2. [queue.cpp]
// guided 1 queue.cpp
#include "queue.h"
using namespace std;

void CreateQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) { 
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) { //buat looping (katanya)
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) { 
        deQueue(Q); //selama q ga kosong
    }
}

### 3. [main.cpp]
// guided 1 main.cpp
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}

### [output]
<img width="1920" height="1080" alt="Screenshot (58)" src="https://github.com/user-attachments/assets/e6261c8e-d677-405f-a21f-24806f4ac2e2" />

Kode di atas adalah implementasi yang menggunakan linked list. Setiap elemen disimpan sebagai node yang berisi nama dan pointer next, sehingga penambahan dan penghapusan elemen dilakukan secara dinamis. Terus pada operasi enQueue menambahkan data pada bagian belakang (tail), sedangkan operasi deQueue menghapus data dari bagian depan (head). Nahh itu sesuai dengan prinsip FIFO (First In First Out). Lalu, fungsi viewQueue digunakan untuk menampilkan seluruh isi antrian, dan fungsi clearQueue menghapus semua elemen hingga queue kosong. Jadi, dari kode program ini, dapat dilihat bagaimana pointer membuat queue fleksibel dalam pengelolaan data tanpa perlu menggeser indeks.

## Guided 2

### 1. [queue.h]
// guided2 queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue{
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q); //terbentuk queue dengan head = -1 dan tail = -1 
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif

### 2. [queue.cpp]
// guided2 queue.cpp
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

// //isFull implmenetasi 1 & 2
// bool isFull(queue Q){
//     if(Q.tail == MAKSIMAL - 1){
//         return true;
//     } else {
//         return false;
//     }
// }

//isFull implementasi 3
bool isFull(queue Q){
    if((Q.tail + 1) % MAKSIMAL == Q.head){
        return true;
    } else {
        return false;
    }
}

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 
// //enqueue implementasi 1 & 2
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail++;
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//enQueue implementasi 3
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //dequeue implementasi 1
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         for(int i = 0; i < Q.tail; i++){
//             Q.nama[i] =  Q.nama[i+1];
//         }
//         Q.tail--;
//         if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

//deQueue implementasi 3
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
        }
    }
}

// //viewQueue implementasi 1 & 2
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         for(int i = Q.head; i <= Q.tail; i++){
//             cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
//         }
//     }
//     cout << endl;
// }

//viewQueue implementasi 3
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        int i = Q.head;
        int count = 1;
        while(true){
            cout << count << ". " << Q.nama[i] << endl;
            if(i == Q.tail){
                break;
            }
            i = (i + 1) % MAKSIMAL;
            count++;
        }   
    }
}

### 3. [main.cpp]
// guided2 main.cpp
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}

### [output]
<img width="1920" height="1080" alt="Screenshot (59)" src="https://github.com/user-attachments/assets/c5894a91-82e3-465a-92a0-9c62a65cd656" />

Kode di atas adalah implementasi yang menggunakan array statis dengan konsep circular queue, sehingga head dan tail dapat berputar mengikuti kapasitas array tanpa perlu menggeser elemen. Operasi enQueue menambahkan data pada bagian tail, sedangkan deQueue menghapus data dari head, Nahh itu sesuai dengan prinsip FIFO (First In First Out). Fungsi isFull dan isEmpty digunakan untuk mengecek kondisi antrian sebelum operasi dilakukan, dan viewQueue menampilkan seluruh elemen dengan menelusuri indeks secara melingkar. Jadi, dari kode program ini menunjukkan bagaimana queue dapat bekerja secara efisien meskipun menggunakan array berkapasitas tetap.

## Unguided No 1

### 1. [queue.h]
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX = 5;
typedef int infotype;

struct Queue{
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmpty(Queue &Q);
bool isFull(Queue &Q);
void enQueue(Queue &Q, infotype x);
void deQueue(Queue &Q);
void printInfo(Queue &Q);

#endif

### 2. [queue.cpp]
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q){
   Q.head = 0;
   Q.tail = -1;
}

bool isEmpty(Queue &Q){
    if(Q.tail < Q.head){
        return true;
    } else {
        return false;
    }
}

bool isFull(Queue &Q){
    if(Q.tail == MAX - 1){
        return true;
    } else {
        return false;
    }
}

void enQueue(Queue &Q, infotype x){
    if(isFull(Q)){
        cout << "Queue penuh" << endl;
    } else {
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

void deQueue(Queue &Q){
    if(isEmpty(Q)){
        cout << "Queue kosong" << endl;
        return;
    } else {
        cout << "Mengahapus data " << Q.info[Q.head] << "..." << endl;
        if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
            Q.head = 0;
            Q.tail = -1;
        } else {
            Q.head++;
        }
    }
}

void printInfo(Queue &Q){
    if(isEmpty(Q)){
        cout << Q.head << " " << Q.tail << " empty queue" << endl;
    }else{
        cout << Q.head << " " << Q.tail << " " << endl;
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i];
            if(i < Q.tail) cout << " ";
        }
        cout << "" << endl;
    }
}

### 3. [main.cpp]
#include "queue.h"
#include <iostream>
using namespace std;

int main(){
    Queue Q;

    createQueue(Q);
    enQueue(Q, 5);
    enQueue(Q, 2);
    enQueue(Q, 7);
    enQueue(Q, 4);

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    printInfo(Q);

    deQueue(Q);
    deQueue(Q);

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    printInfo(Q);

    return 0;
}

### [output]
<img width="1018" height="231" alt="Screenshot 2025-11-22 184516" src="https://github.com/user-attachments/assets/b7dbc4c1-c6b2-4b4f-b7d1-fd6c0dc83ca5" />

Kode di atas adalah implementasi yang menggunakan array statis dengan ukuran max 5 elemen. Untuk posisi data diatur menggunakan indeks head (elemen depan) dan tail (elemen belakang). Operasi enQueue menambahkan data ke bagian belakang sampai kapasitas terpenuhi, sedangkan operasi deQueue menghapus data dari bagian depan sesuai prinsip FIFO (First In First Out). Fungsi isEmpty dan isFull itu untuk memastikan kondisi antrian sebelum operasi dilakukan, dan printInfo menampilkan isi queue berdasarkan indeks dari head sampai tail. Jadi, dari implementasi ini tipe queue linear (karena indeks tidak berputar seperti circular queue dan elemen bergeser melalui perubahan pointer indeks saja).

## Unguided No 2

### 1. [queue.h]
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX = 5;
typedef int infotype;

struct Queue{
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmpty(Queue &Q);
bool isFull(Queue &Q);
void enQueue(Queue &Q, infotype x);
void deQueue(Queue &Q);
void printInfo(Queue &Q);

#endif

### 2. [queue.cpp]
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q){
   Q.head = 0;
   Q.tail = -1;
}

bool isEmpty(Queue &Q){
    if(Q.tail < Q.head){
        return true;
    } else {
        return false;
    }
}

bool isFull(Queue &Q){
    if(Q.tail == MAX - 1){
        return true;
    } else {
        return false;
    }
}

void enQueue(Queue &Q, infotype x){
    if(isFull(Q)){
        cout << "Queue sudah penuh" << endl;
    } else {
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

void deQueue(Queue &Q){
    if(isEmpty(Q)){
        cout << "Queue kosong" << endl;
        return;
    } else {
        cout << "Mengahapus data " << Q.info[Q.head] << "..." << endl;
        if(Q.head == Q.tail){
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head++;
        }
    }
}

void printInfo(Queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    }else{
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.info[i] << endl;
        }
    }
    cout << endl;
}

### 3. [main.cpp]
#include "queue.h"
#include <iostream>
using namespace std;

int main(){
    Queue Q;

    createQueue(Q);
    enQueue(Q, 5);
    enQueue(Q, 2);
    enQueue(Q, 7);
    enQueue(Q, 4);

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    printInfo(Q);

    deQueue(Q);
    deQueue(Q);

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    printInfo(Q);

    return 0;
}

### [output]
<img width="1052" height="303" alt="Screenshot 2025-11-23 103927" src="https://github.com/user-attachments/assets/be1fcfb2-7b1c-479d-b10e-85ed66f772a8" />

Kode di atas adalah implementasi yang menggunakan array statis dengan kapasitas max 5 elemen. Data disimpan dalam array (info[]), terus kalo variabel head dan tail untuk menentukan posisi elemen paling depan dan belakang dalam antrian. Operasi enQueue menambahkan elemen ke bagian tail, sedangkan operasi deQueue menghapus elemen dari head, sesuai prinsip FIFO (First In First Out). Kalo kondisi penuh dan kosong maka dicek menggunakan fungsi isFull dan isEmpty. Jika elemen terakhir dihapus, head dan tail di-reset menjadi -1 (untuk menandai queue kosong). Fungsi printInfo menampilkan isi antrian berdasarkan indeks dari head sampai tail. Jadi dari implementasi ini juga bersifat queue linear, sehingga indeks tidak berputar dan hanya bergeser dengan increment.

## Unguided No 3

### 1. [queue.h]
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX = 5;
typedef int infotype;

struct Queue{
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmpty(Queue &Q);
bool isFull(Queue &Q);
void enQueue(Queue &Q, infotype x);
void deQueue(Queue &Q);
void printInfo(Queue &Q);

#endif

### 2. [queue.cpp]
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q){
   Q.head = 0;
   Q.tail = -1;
}

bool isEmpty(Queue &Q){
    if(Q.tail < Q.head){
        return true;
    } else {
        return false;
    }
}

bool isFull(Queue &Q){
    if(Q.tail == MAX - 1){
        return true;
    } else {
        return false;
    }
}

void enQueue(Queue &Q, infotype x){
    if(isFull(Q)){
        cout << "Queue sudah penuh" << endl;
    } else {
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

void deQueue(Queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.info[Q.head] << "..." << endl;
        if(Q.head == Q.tail){
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAX; // bergerak melingkar
        }
    }
}

void printInfo(Queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        int i = Q.head;
        int count = 1;
        while(true){
            cout << count << ". " << Q.info[i] << endl;
            if(i == Q.tail){
                break;
            }
            i = (i + 1) % MAX;
            count++;
        }   
    }
}

### 3. [main.cpp]
#include "queue.h"
#include <iostream>
using namespace std;

int main(){
    Queue Q;

    createQueue(Q);
    enQueue(Q, 5);
    enQueue(Q, 2);
    enQueue(Q, 7);
    enQueue(Q, 4);

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    printInfo(Q);

    deQueue(Q);
    deQueue(Q);

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    printInfo(Q);

    return 0;
}

### [output]
<img width="1004" height="266" alt="Screenshot 2025-11-23 104501" src="https://github.com/user-attachments/assets/867b587d-85bc-4c90-a79f-c36beaaf1118" />

Kode di atas adalah implementasi yang menggunakan array statis namun dengan mekanisme circular queue. Dengan metode ini, indeks head dan tail dapat berputar kembali ke indeks awal menggunakan operasi modulo (% MAX), sehingga ruang array tetap dapat digunakan meskipun elemen depan sudah dihapus. Operasi enQueue menambahkan data pada posisi tail, sedangkan deQueue menghapus data dari posisi head, sesuai prinsip FIFO (First In First Out). Apabila elemen terakhir dihapus, nilai head dan tail di-reset menjadi -1 (untuk menandai queue kembali kosong). Fungsi printInfo menampilkan seluruh elemen dengan mengecek setiap indeks secara melingkar mulai dari head hingga tail. Jadi, dengan ini queue menjadi lebih efisien dibanding queue linear karena tidak memerlukan pergeseran elemen saat terjadi operasi penghapusan.

## Kesimpulan
Dari ketiga implementasi queue yang sudah dibuat, dapat disimpulkan bahwa queue adalah struktur data linear yang kerjanya mirip dengan prinsip FIFO (First In First Out), elemen pertama yang masuk akan menjadi elemen pertama yang keluar. Lalu, pada implementasi nomor 1 dan 2, queue menggunakan array linear sehingga indeks bergerak maju seiring operasi enQueue dan deQueue, namun ruang array tidak dapat digunakan kembali setelah elemen dihapus. Sedangkan pada nomor 3 itu menggunakan circular queue, dimana head dan tail bergerak secara melingkar menggunakan operasi modulo (% MAX), sehingga ruang array tetap dapat digunakan meskipun elemen depan sudah dihapus. Dengan begitu, ketiga implementasi menerapkan operasi dasar enQueue, deQueue, dan pengecekan kondisi queue, implementasi circular queue lebih optimal dalam pemanfaatan ruang penyimpanan dibandingkan queue linear.

## Referensi
https://www.w3schools.com/cpp/cpp_queues.asp
https://www.w3schools.com/cpp/cpp_deque.asp
https://www.programiz.com/cpp-programming/queue
Modul 8 Queue
