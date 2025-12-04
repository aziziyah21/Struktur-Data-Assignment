# <h1 align="center">Laporan Praktikum Modul Tree - Bagian Pertama (10)</h1>
<p align="center">Tadzkiroh Aziziyah Haqia</p>

## Dasar Teori
Struktur Data Tree merupakan bentuk penyimpanan data yang tersusun secara hierarki. Setiap elemen itu di sebutnya node. Node paling atas itu dinamakan root dan dapat memiliki 2 anak, yaitu anak kiri dan kanan. Tree banyak digunakan karena mampu menyimpan data secara terstruktur sehingga proses pencarian, penambahan, dan pengolahan data dapat berjalan lebih cepat dibandingkan dengan struktur linear. Pada modul salah satu bentuk Tree yang paling sering digunakan adalah Binary Search Tree. Struktur ini memiliki aturan agar data berada di posisi yang tepat. Nilai yang lebih kecil dari root ditempatkan pada subtree kiri, sedangkan untuk nilai yang lebih besar ditempatkan pada subtree kanan. Aturan ini menjaga tree tetap terurut dan mempermudah proses pencarian karena setiap langkah akan mengarah lebih dekat ke data yang dicari.

Proses penambahan data dalam Binary Search Tree berjalan secara rekursif. Setiap data baru akan dibandingkan dengan nilai pada node yang sedang ditunjuk. Jika lebih kecil maka bergerak ke kiri, dan jika lebih besar akan bergerak ke kanan. Penambahan berhenti saat menemukan node kosong. Aturan ini membuat struktur tree terbentuk secara alami sesuai urutan input pengguna. Tree juga menyediakan beberapa cara untuk menelusuri seluruh node, yang disebut traversal. Traversal penting untuk mengetahui isi tree, bentuk tree, atau melakukan proses tertentu pada semua node.

Dalam modul terdapat 3 Traversal utama yang digunakan, yaitu:
• Inorder. Membaca subtree kiri, lalu root, lalu subtree kanan. Hasilnya urut dari nilai kecil ke besar. (Left-Root-Right)
• Preorder. Membaca root terlebih dahulu. Setelah itu subtree kiri dan subtree kanan. Traversal ini menunjukkan bentuk tree dari atas ke bawah. (Root-Left-Right)
• Postorder. Membaca subtree kiri lalu subtree kanan dan terakhir root. Traversal ini berguna untuk proses penghapusan atau pembongkaran tree karena memastikan seluruh subtree selesai diproses sebelum node induk. (Left-Right-Root)

Dari ketiga traversal tersebut memberikan perbedaan cara terhadap data di dalam tree. Inorder memberikan urutan terstruktur. Preorder memperlihatkan bentuk tree. Postorder membantu proses yang membutuhkan penyelesaian subtree terlebih dahulu. Dengan memahami aturan penambahan dan proses traversal dalam Binary Search Tree, jadi dapat diihat bagaimana tree mengatur data dengan efisien dan bagaimana setiap node diproses sesuai urutan tertentu.

## Guided

### 1. [bst.h]
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

### 2. [bst.cpp]
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


## Unguided No 1

### 1. [bstree.h]
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

### 2. [bstree.cpp]
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
<img width="987" height="92" alt="Screenshot 2025-12-01 105717" src="https://github.com/user-attachments/assets/2a367037-20e2-4bad-8ab4-08368c208e3a" />

Kode di atas itu cara membangun struktur dasar Binary Search Tree. Tree dibuat dengan node yang memiliki nilai dan 2 pointer untuk anak kiri dan kanan. Proses penambahan data dilakukan dengan aturan perbandingan. Nilai yang lebih kecil dari root bergerak ke subtree kiri (} else if(x < root->info){), sedangkan untuk nilai yang lebih besar akan bergerak ke subtree kanan (} else if(x > root->info){). Penambahan berhenti ketika menemukan posisi kosong. Setelah tree terbentuk, program menampilkan seluruh isi tree menggunakan traversal inorder. Traversal ini membaca node kiri lalu root kemudian kanan. Hasilnya selalu terurut karena mengikuti pola struktur Binary Search Tree.


## Unguided No 2

### 1. [bstree.h]
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

int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);

#endif

### 2. [bstree.cpp]
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

int hitungJumlahNode(address root){
    if(root == Nil){
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root){
    if(root == Nil){
        return 0;
    }
    return root->info 
        + hitungTotalInfo(root->left) 
        + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root, int start){
    if(root == Nil){
        return start - 1;
    }
    int kiri = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start +1);
    if(kiri > kanan){
        return kiri;
    }
    return kanan;
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

    cout << endl;
    cout << "Kedalaman: " << hitungKedalaman(root, 0) << endl;
    cout << "Jumlah node: " << hitungJumlahNode(root) << endl;
    cout << "Total: " << hitungTotalInfo(root) << endl;

    return 0;
}

### [output]
<img width="1055" height="159" alt="Screenshot 2025-12-01 113035" src="https://github.com/user-attachments/assets/708b3673-2ee7-47b2-a4a6-ae2dae567f05" />

Kode di atas itu menambahkan fungsi untuk menghitung informasi dari tree. Fungsi petama menghitung kedalaman tree untuk mengetahui level terdalam yang dimiliki tree. Prosesnya berjalan rekursif dengan membandingkan kedalaman subtree kiri dan kanan. Fungsi kedua menghitung jumlah node dengan cara menjumlahkan seluruh node di subtree kiri dan kanan lalu menambah satu untuk node saat ini. Fungsi ketiga menghitung total nilai dari seluruh node, yaitu dengan menjumlahkan nilai root dengan nilai dari subtree kiri dan kanan. Latihan ini membantu memahami bagaimana tree dapat dianalisis.


## Unguided No 3

### 1. [bstree.h]
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

int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);

void printPreorder(address root);
void printPostorder(address root);

#endif

### 2. [bstree.cpp]
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

int hitungJumlahNode(address root){
    if(root == Nil){
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root){
    if(root == Nil){
        return 0;
    }
    return root->info + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungKedalaman(address root, int start){
    if(root == Nil){
        return start - 1;
    }
    int kiri = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start +1);
    if(kiri > kanan){
        return kiri;
    }
    return kanan;
}

void printPreorder(address root){
    if(root != Nil){
        cout << root->info << " - ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

void printPostorder(address root){
    if(root != Nil){
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->info << " - ";
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

    cout << "Inorder: ";
    printInorder(root);
    cout << endl;

    cout << "Preorder: ";
    printPreorder(root);
    cout << endl;

    cout << "Postorder: ";
    printPostorder(root);
    cout << endl;

    return 0;
}

### [output]
<img width="1007" height="140" alt="Screenshot 2025-12-04 133019" src="https://github.com/user-attachments/assets/5b18803e-4efc-4f6e-8ef7-1c2b4acd9cd1" />

Kode di atas itu akan print dua traversal tambahan yaitu preorder dan postorder. Traversal preorder itu membaca root terlebih dahulu, lalu subtree kiri dan subtree kanan. Traversal ini menunjukkan bentuk tree dari atas ke bawah. Traversal postorder itu membaca subtree kiri lalu subtree kanan dan terakhir root. Traversal ini digunakan saat proses yang memerlukan penyelesaian subtree sebelum root, misalnya saat menghapus seluruh node tree. Dengan memiliki tiga traversal. Inorder, preorder, dan postorder. Program dapat menampilkan isi tree dalam urutan terurut, atau dalam urutan pemrosesan subtree. Ini membuat tree jadi lebih mudah untuk dipahami.


## Kesimpulan
Dari ketiga implementasi Tree yang sudah dibuat, Struktur Binary Search Tree mempermudah penyimpanan dan penelusuran data karena setiap nilai ditempatkan berdasarkan aturan perbandingan. Tree yang terbentuk dapat dibaca menggunakan beberapa metode traversal untuk menampilkan isi data dari sudut yang berbeda. Di latihan nomor 1, Inorder memberi hasil terurut. Lalu, di nomor 3, Preorder membantu melihat bentuk struktur tree dan Postorder digunakan saat memproses subtree sampai selesai. Di latihan nomor 2 ini terdapat tambahan perhitungan jumlah node, total nilai, dan kedalaman membantu memahami karakteristik tree yang terbentuk dari urutan input. Dari ketiga latihan ini tuh mempelajari proses bagaimana tree dibuat, menelusuri data, serta bagaimana informasi penting dari tree dihitung.

## Referensi
https://www.geeksforgeeks.org/cpp/binary-tree-in-cpp/
https://www.programiz.com/dsa/trees
Modul 10 Tree
