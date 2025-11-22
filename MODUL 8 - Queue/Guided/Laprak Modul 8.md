# <h1 align="center">Laporan Praktikum Modul Queue (8)</h1>
<p align="center">Tadzkiroh Aziziyah Haqia</p>

## Dasar Teori
Stack adalah struktur data yang cara kerjanya itu seperti menumpuk barang. Hanya bisa menambah data di bagian atas dan mengambil data juga dari atas. Urutannya mengikuti prinsip LIFO. Data terakhir yang masuk akan jadi data pertama yang keluar. Di dalam stack terdapat array untuk menyimpan nilai dan ada variabel TOP untuk menandai posisi elemen paling atas. Kalau stack kosong maka TOP bernilai -1. Operasi dasar yang biasanya dipakai yaitu push untuk menambah data, pop untuk mengambil data, isEmpty untuk mengecek apakah stack kosong, dan isFull untuk mengecek apakah stack penuh. Semua operasi ini selalu bekerja di bagian TOP. Stack juga sering ditambah fungsi print untuk menampilkan isi dari atas ke bawah, serta fungsi pembalik yang memindahkan data ke stack lain agar urutannya terbalik. Struktur data ini dipakai karena sederhana, cepat, dan cocok untuk kasus seperti undo, history, atau proses perhitungan yang butuh urutan balik.

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

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya. Ini berisi tentang deklarasi dalam struktur data serta fungsi yang akan digunakan pada program. Tujuannya dari fungsi-fungsi tersebut adalah untuk memanggil main.cpp

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

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya. Ini berisi penerapan dari semua fungsi yang sudah dideklarasikan pada listSepatu.h. Dengan menggunakan pointer agar fungsi dapat bekerja untuk menelusuri node satu per satu.

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

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya. Ini bertujuan untuk menjalankan program. Program ini menunjukkan bagaimana linked list bekerja secara dinamis, yang dimana setiap node nya terhubung melalui pointer, bukan array tetap.

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

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya. Ini berisi tentang deklarasi dalam struktur data serta fungsi yang akan digunakan pada program. Tujuannya dari fungsi-fungsi tersebut adalah untuk memanggil main.cpp

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

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya. Ini berisi penerapan dari semua fungsi yang sudah dideklarasikan pada listSepatu.h. Dengan menggunakan pointer agar fungsi dapat bekerja untuk menelusuri node satu per satu.

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

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya. Ini bertujuan untuk menjalankan program. Program ini menunjukkan bagaimana linked list bekerja secara dinamis, yang dimana setiap node nya terhubung melalui pointer, bukan array tetap.

## Unguided No 1

### 1. [queue.h]
#ifndef STACK_H
#define STACK_H
#define Nil NULL

#include <iostream>
using namespace std;

const int MAX = 20;

typedef int infotype;

struct Stack {
    infotype data[MAX];
    int top; 
};

bool isEmpty(Stack S);
bool isFull(Stack S);
void createStack(Stack &S);

void push(Stack &S, infotype x);
void pushAscending(Stack &S, infotype x);
void pop(Stack &S, infotype &x);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 2. [queue.cpp]
#include "stack.h"

#include <iostream>
using namespace std;

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.data[S.top] = x;
        cout << "Data " << x << " berhasil ditambahkan ke dalam stack!" << endl;
    }
}

void pushAscending(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
        return;
    }

    Stack temp;
    createStack(temp);
    while (isEmpty(S) == false && S.data[S.top] < x) {
        int val;
        pop(S, val);
        push(temp, val);
    }

    push(S, x);
    while (isEmpty(temp) == false) {
        int val;
        pop(temp, val);
        push(S, val);
    }

    cout << "Data " << x << " berhasil dimasukkan secara ascending!" << endl;
}

void pop(Stack &S, infotype &x) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        int val = S.data[S.top];
        S.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; --i) {
            cout << S.data[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (isEmpty(S)) 
    return;

    Stack temp;
    createStack(temp);

    while (isEmpty(S) == false) {
        int x = S.data[S.top];
        pop(S, x);
        push(temp, x);
    }

    S = temp;
}

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 3. [main.cpp]
#include "stack.h"

#include <iostream>
using namespace std;

int main() {
    Stack S;
    createStack(S);

    int x;
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S, x);
    push(S, 2);
    push(S, 3);
    pop(S, x);
    push(S, 9);

    cout << "--- Isi stack sekarang ---" << endl;
    printInfo(S);

    balikStack(S);
    cout << "--- Setelah dibalik ---" << endl;
    printInfo(S);

    return 0;
}
### [output]
<img width="1253" height="508" alt="Screenshot 2025-11-20 211040" src="https://github.com/user-attachments/assets/f9594be6-f01b-4f57-ba7e-6fadb49274b5" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya. Program listSepatu adalah hasil modifikasi dari listBuah. Perbedaan utamanya hanya pada konteks data, tetapi untuk struktur data dan logika linked list tetap sama dan semua operasi (insert, delete, update, search) juga sama.

## Unguided No 2

### 1. [queue.h]
#ifndef STACK_H
#define STACK_H
#define Nil NULL

#include <iostream>
using namespace std;

const int MAX = 20;

typedef int infotype;

struct Stack {
    infotype data[MAX];
    int top; 
};

bool isEmpty(Stack S);
bool isFull(Stack S);
void createStack(Stack &S);

void push(Stack &S, infotype x);
void pushAscending(Stack &S, infotype x);
void pop(Stack &S, infotype &x);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 2. [queue.cpp]
#include "stack.h"

#include <iostream>
using namespace std;

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.data[S.top] = x;
        cout << "Data " << x << " berhasil ditambahkan ke dalam stack!" << endl;
    }
}

void pushAscending(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
        return;
    }

    int i = S.top;
    while (i >= 0 && S.data[i] > x) { 
        S.data[i+1] = S.data[i];
        i--;
    }
    S.data[i+1] = x;
    S.top++;
    cout << "Data " << x << " berhasil dimasukkan secara ascending!" << endl;
}

void pop(Stack &S, infotype &x) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        x = S.data[S.top];
        S.top--;
        cout << "Data " << x << " berhasil dihapus dari stack!" << endl;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; --i) {
            cout << S.data[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (isEmpty(S)) 
    return;

    Stack temp;
    createStack(temp);
    infotype x;
    while (isEmpty(S) == false) {
        pop(S, x);
        push(temp, x);
    }

    S = temp;
}

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 3. [main.cpp]
#include "stack.h"

#include <iostream>
using namespace std;

int main() {
    Stack S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    cout << "--- Isi stack sekarang ---" << endl;
    printInfo(S);

    balikStack(S);
    cout << "--- Setelah dibalik ---" << endl;
    printInfo(S);

       return 0;
}

### [output]
<img width="1254" height="554" alt="Screenshot 2025-11-20 213449" src="https://github.com/user-attachments/assets/c8a39396-a0ba-414a-9e0b-00e4922c198c" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya. Program listSepatu adalah hasil modifikasi dari listBuah. Perbedaan utamanya hanya pada konteks data, tetapi untuk struktur data dan logika linked list tetap sama dan semua operasi (insert, delete, update, search) juga sama.

## Unguided No 3

### 1. [queue.h]
#ifndef STACK_H
#define STACK_H
#define Nil NULL

#include <iostream>
using namespace std;

const int MAX = 20;

typedef int infotype;

struct Stack {
    infotype data[MAX];
    int top; 
};

bool isEmpty(Stack S);
bool isFull(Stack S);
void createStack(Stack &S);

void push(Stack &S, infotype x);
void pushAscending(Stack &S, infotype x);
void pop(Stack &S, infotype &x);
void printInfo(Stack S);
void balikStack(Stack &S);
void inputUsingStream(Stack &S);

#endif

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 2. [queue.cpp]
#include "stack.h"

#include <sstream>
#include <iostream>
using namespace std;

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.data[S.top] = x;
        cout << "Data " << x << " berhasil ditambahkan ke dalam stack!" << endl;
    }
}

void pushAscending(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
        return;
    }

    int i = S.top;
    while (i >= 0 && S.data[i] > x) { 
        S.data[i+1] = S.data[i];
        i--;
    }
    S.data[i+1] = x;
    S.top++;
    cout << "Data " << x << " berhasil dimasukkan secara ascending!" << endl;
}

void pop(Stack &S, infotype &x) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        x = S.data[S.top];
        S.top--;
        cout << "Data " << x << " berhasil dihapus dari stack!" << endl;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; --i) {
            cout << S.data[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (isEmpty(S)) 
    return;

    Stack temp;
    createStack(temp);
    infotype x;
    while (isEmpty(S) == false) {
        pop(S, x);
        push(temp, x);
    }

    S = temp;
}

void inputUsingStream(Stack &S) {
    int x;
    while (true) {
        cin >> x;
        if (x == 0) break;
        if (!isFull(S)) push(S, x);
    }
}

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 3. [main.cpp]
#include "stack.h"

#include <iostream>
using namespace std;

int main() {
    cout << "--- 4 7 2 9 6 0 1 ---" << endl;

    Stack S;
    createStack(S);

    cout << "--- Isi stack sekarang ---" << endl;
    printInfo(S);

    balikStack(S);
    cout << "--- Setelah dibalik ---" << endl;
    printInfo(S);

    cout << "--- inputUsingStream ---" << endl;
    createStack(S);
    inputUsingStream(S);
    printInfo(S);
    
    return 0;
}

### [output]
<img width="1261" height="754" alt="Screenshot 2025-11-20 220439" src="https://github.com/user-attachments/assets/81ab04f3-25a0-406d-893c-503d8af66bb5" />

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya. Program listSepatu adalah hasil modifikasi dari listBuah. Perbedaan utamanya hanya pada konteks data, tetapi untuk struktur data dan logika linked list tetap sama dan semua operasi (insert, delete, update, search) juga sama.

## Kesimpulan
listBuah dan listSepatu sama-sama menunjukkan bahwa Singly Linked List merupakan struktur data dinamis yang memungkinkan penambahan, penghapusan, dan juga pembaruan data tanpa batasan ukuran tetap. Intinya pengelolaan struktur ini terletak pada penggunaan pointer yang menghubungkan setiap node satu sama lain, sehingga data dapat diatur. Dengan sedikit penyesuaian pada nama struktur dan jenis data yang digunakan, konsep linked list ini dapat diterapkan untuk berbagai kebutuhan pengelolaan data. Penerapan struktur data ini juga banyak digunakan dalam kehidupan nyata, seperti basis data, inventori, dan aplikasi yang membutuhkan pengaturan data secara dinamis dan efisien.

## Referensi
(https://www.w3schools.com/cpp/default.asp)
https://www.geeksforgeeks.org/dsa/singly-linked-list-tutorial/
Modul 4 & 5 Singly Linked List


