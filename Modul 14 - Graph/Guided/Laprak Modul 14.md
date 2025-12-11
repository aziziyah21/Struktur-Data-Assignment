# <h1 align="center">Laporan Praktikum Modul Graph (14)</h1>
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

### 1. [graph.h]
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info; //Menyimpan data node (misal: char/int).
    int visited; //Penanda untuk traversal (0/1) (Penanda apakah node sudah dikunjungi)
    adrEdge firstEdge; //Pointer ke edge pertama yang terhubung.
    adrNode Next; // Pointer ke node berikutnya dalam graph
};

struct ElmEdge {
    adrNode Node; //Pointer yang menunjuk ke lokasi node tujuan.
    adrEdge Next; //Pointer ke edge berikutnya (jika satu node memiliki banyak cabang).
};

struct Graph {
    adrNode First; //Pointer ke node pertama dalam list graph.
};

void CreateGraph(Graph &G); //prosedur untuk mengeset first dari graph sebagai NOUL
adrNode AlokasiNode(infoGraph data); //alokasi Node baru
adrEdge AlokasiEdge(adrNode nodeTujuan); //alokasi Edge baru

void InsertNode(Graph &G, infoGraph data); //Menambahkan Node ke dalam Graph
adrNode FindNode(Graph G, infoGraph data); //function untuk mencari alamat Node berdasarkan infonya
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2); //prosedur untuk menghubungkan dua Node (Undirected Graph)
void DisconnectNode(adrNode node1, adrNode node2); //prosedur untuk memutuskan hubungan dua node
void DeleteNode(Graph &G, infoGraph X); //prosedur untuk menghapus Rode X beserta semua edge yang berhubungan dengannya

void PrintInfoGraph(Graph G); //Menampilkan isi Graph (Adjacency List)
void ResetVisited(Graph &G); //Reset status visited sebelum traversal
void PrintBFS(Graph G, infoGraph StartInfo); //traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintDFS(Graph G, infoGraph StartInfo); //Traversal Depth First Search / DFS (Menggunakan Stack)

#endif

### 2. [graph.cpp]
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}

### 3. [main.cpp]
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    //hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A'); //BFS
    PrintDFS(G, 'A'); //DFS
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL){
        cout << "Node E berhasil terhapus" << endl;
    } else {
        cout << "Node E tidak berhasil terhapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A'); //BFS
    PrintDFS(G, 'A'); //DFS

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
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 2);
    insertNode(root, 1);
    insertNode(root, 3);
    insertNode(root, 5);
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
<img width="1148" height="138" alt="Screenshot 2025-12-05 151054" src="https://github.com/user-attachments/assets/47072aa1-e471-4c3b-a01f-632d084a866f" />

Kode di atas itu akan print dua traversal tambahan yaitu preorder dan postorder. Traversal preorder itu membaca root terlebih dahulu, lalu subtree kiri dan subtree kanan. Traversal ini menunjukkan bentuk tree dari atas ke bawah. Traversal postorder itu membaca subtree kiri lalu subtree kanan dan terakhir root. Traversal ini digunakan saat proses yang memerlukan penyelesaian subtree sebelum root, misalnya saat menghapus seluruh node tree. Dengan memiliki tiga traversal. Inorder, preorder, dan postorder. Program dapat menampilkan isi tree dalam urutan terurut, atau dalam urutan pemrosesan subtree. Ini membuat tree jadi lebih mudah untuk dipahami.


## Kesimpulan
Dari ketiga implementasi Tree yang sudah dibuat, Struktur Binary Search Tree mempermudah penyimpanan dan penelusuran data karena setiap nilai ditempatkan berdasarkan aturan perbandingan. Tree yang terbentuk dapat dibaca menggunakan beberapa metode traversal untuk menampilkan isi data dari sudut yang berbeda. Di latihan nomor 1, Inorder memberi hasil terurut. Lalu, di nomor 3, Preorder membantu melihat bentuk struktur tree dan Postorder digunakan saat memproses subtree sampai selesai. Di latihan nomor 2 ini terdapat tambahan perhitungan jumlah node, total nilai, dan kedalaman membantu memahami karakteristik tree yang terbentuk dari urutan input. Dari ketiga latihan ini tuh mempelajari proses bagaimana tree dibuat, menelusuri data, serta bagaimana informasi penting dari tree dihitung.

## Referensi
https://www.geeksforgeeks.org/cpp/binary-tree-in-cpp/
https://www.programiz.com/dsa/trees
Modul 10 Tree
