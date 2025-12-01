# <h1 align="center">Laporan Praktikum Modul Tree (10)</h1>
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

## Guided

### 1. [queue.h]
#ifndef BST_H
#define BST_H
#define Nil NULL 

using namespace std;

typedef struct BST *node; //alias pointer = node

struct BST{ //nama struct nya BST
    int angka;
    node left;
    node right;
};

typedef node BinTree; //alias tree = BinTree (merujuk ke node root dari BST)

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif

### 2. [queue.cpp]
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}

### 3. [main.cpp]
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}

Kode di atas adalah implementasi yang menggunakan linked list. Setiap elemen disimpan sebagai node yang berisi nama dan pointer next, sehingga penambahan dan penghapusan elemen dilakukan secara dinamis. Terus pada operasi enQueue menambahkan data pada bagian belakang (tail), sedangkan operasi deQueue menghapus data dari bagian depan (head). Nahh itu sesuai dengan prinsip FIFO (First In First Out). Lalu, fungsi viewQueue digunakan untuk menampilkan seluruh isi antrian, dan fungsi clearQueue menghapus semua elemen hingga queue kosong. Jadi, dari kode program ini, dapat dilihat bagaimana pointer membuat queue fleksibel dalam pengelolaan data tanpa perlu menggeser indeks.


## Unguided No 1

### 1. [queue.h]
#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

using namespace std;

typedef int infotype;

struct Node{
    infotype info;
    Node *left;
    Node *right;
};

typedef Node* address;

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void printInorder(address root);

#endif

### 2. [queue.cpp]
#include "bstree.h"
#include <iostream>
using namespace std;

address alokasi(infotype x){
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void insertNode(address &root, infotype x){
    if(root == Nil){
        root = alokasi(x);
    } else if(x < root->info){
        insertNode(root->left, x);
    } else if(x > root->info){
        insertNode(root->right, x);
    }
} 

address findNode(infotype x, address root){
    if(root == Nil)
    return Nil;
    if(root->info == x)
    return root;
    if(x < root->info)
    return findNode(x, root->left);
    return findNode(x, root->right);
}

void printInorder(address root){
    if(root != Nil){
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right); 
    }
}

### 3. [main.cpp]
#include "bstree.h"
#include <iostream>
using namespace std;

int main(){
    cout << "Hello World" << endl;

    address root = Nil;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);

    printInorder(root);

    return 0;
}

### [output]
<img width="987" height="92" alt="Screenshot 2025-12-01 105717" src="https://github.com/user-attachments/assets/8646dd2e-5724-484c-be8c-72cbf18a2863" />

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
