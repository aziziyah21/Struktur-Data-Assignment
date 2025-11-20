# <h1 align="center">Laporan Praktikum Modul Stack (7)</h1>
<p align="center">Tadzkiroh Aziziyah Haqia</p>

## Dasar Teori
Stack adalah struktur data yang cara kerjanya itu seperti menumpuk barang. Hanya bisa menambah data di bagian atas dan mengambil data juga dari atas. Urutannya mengikuti prinsip LIFO. Data terakhir yang masuk akan jadi data pertama yang keluar. Di dalam stack terdapat array untuk menyimpan nilai dan ada variabel TOP untuk menandai posisi elemen paling atas. Kalau stack kosong maka TOP bernilai -1. Operasi dasar yang biasanya dipakai yaitu push untuk menambah data, pop untuk mengambil data, isEmpty untuk mengecek apakah stack kosong, dan isFull untuk mengecek apakah stack penuh. Semua operasi ini selalu bekerja di bagian TOP. Stack juga sering ditambah fungsi print untuk menampilkan isi dari atas ke bawah, serta fungsi pembalik yang memindahkan data ke stack lain agar urutannya terbalik. Struktur data ini dipakai karena sederhana, cepat, dan cocok untuk kasus seperti undo, history, atau proses perhitungan yang butuh urutan balik.

## Guided 1

### 1. [Stack.h]
#ifndef STACK
#define STACK
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;

struct node {
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack lisStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru); 
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya. Ini berisi tentang deklarasi dalam struktur data serta fungsi yang akan digunakan pada program. Tujuannya dari fungsi-fungsi tersebut adalah untuk memanggil main.cpp

### 2. [Stack.cpp]
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya. Ini berisi penerapan dari semua fungsi yang sudah dideklarasikan pada listSepatu.h. Dengan menggunakan pointer agar fungsi dapat bekerja untuk menelusuri node satu per satu.

### 3. [main.cpp]
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);
    
    return 0;
}

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya. Ini bertujuan untuk menjalankan program. Program ini menunjukkan bagaimana linked list bekerja secara dinamis, yang dimana setiap node nya terhubung melalui pointer, bukan array tetap.

## Guided 2

### 1. [Stack.h]
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

// Ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable {
    int data[MAX];
    int top; // -1 = kosong
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya. Ini berisi tentang deklarasi dalam struktur data serta fungsi yang akan digunakan pada program. Tujuannya dari fungsi-fungsi tersebut adalah untuk memanggil main.cpp

### 2. [Stack.cpp]
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s) {
    return s.top == -1;
}

bool isFull(stackTable s) {
    return s.top == MAX - 1;
}

void createStack(stackTable &s) {
    s.top = -1;
}

void push(stackTable &s, int angka) {
    if (isFull(s)) {
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s) {
    if (isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi) {
    if (isEmpty(s)) {
        cout << "Stack kosong!" << endl;
        return;
    }
    if (posisi <= 0) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    // index = top - (posisi - 1)
    int idx = s.top - (posisi - 1);
    if (idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s) {
    if (isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; --i) {
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data) {
    if (isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    cout << "Mencari data " << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for (int i = s.top; i >= 0; --i) {
        if (s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if (!found) {
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya. Ini berisi penerapan dari semua fungsi yang sudah dideklarasikan pada listSepatu.h. Dengan menggunakan pointer agar fungsi dapat bekerja untuk menelusuri node satu per satu.

### 3. [main.cpp]
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    // Posisi dihitung dari TOP (1-based)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya. Ini bertujuan untuk menjalankan program. Program ini menunjukkan bagaimana linked list bekerja secara dinamis, yang dimana setiap node nya terhubung melalui pointer, bukan array tetap.

## Unguided No 1

### 1. [Stack.h]
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

### 2. [Stack.cpp]
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

### 1. [Stack.h]
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

### 2. [Stack.cpp]
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

### 1. [Stack.h]
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

### 2. [Stack.cpp]
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


