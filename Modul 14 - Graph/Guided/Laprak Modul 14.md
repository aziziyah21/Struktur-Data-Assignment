# <h1 align="center">Laporan Praktikum Modul Graph (14)</h1>
<p align="center">Tadzkiroh Aziziyah Haqia</p>

## Dasar Teori
Graph tidak berarah adalah jenis graph yang edge tidak memiliki arah.
Jika ada edge yang menghubungkan node A dan node B, maka:
A terhubung ke B
B juga terhubung ke A
Hubungan antar node bersifat dua arah atau simetris.
Graph tipe ini umum digunakan untuk menunjukkan hubungan timbal balik seperti pertemanan atau jalan yang bisa ditempuh dua arah.

Salah satu cara merepresentasikan graph adalah dengan menggunakan Multi Linked List.
Representasi ini terdiri dari:
- List node yang menyimpan semua node dalam graph
- List edge yang menyimpan daftar node yang terhubung dengan node tertentu
Kelebihan dari Multi Linked List adalah bisa dinamis, sehingga jumlah node dan edge bisa berubah tanpa perlu mengatur ulang ukuran memori.

Struktur data graph tidak berarah terdiri dari beberapa komponen utama:
- ElmNode, menyimpan informasi node, status kunjungan, pointer ke edge pertama, dan pointer ke node berikutnya
- ElmEdge, menyimpan pointer ke node tujuan dan pointer ke edge berikutnya
- Graph, menyimpan pointer ke node pertama
Struktur ini memungkinkan graph direpresentasikan secara efisien dengan menggunakan pointer.

Beberapa operasi dasar yang bisa dilakukan pada graph antara lain:
- CreateGraph: Membuat graph kosong
- InsertNode: Menambahkan node ke dalam graph
- ConnectNode: Menghubungkan dua node dengan edge
- FindNode: Mencari node tertentu dalam graph
- PrintInfoGraph: Menampilkan seluruh isi graph beserta hubungan antar node

Penelusuran graph adalah proses mengunjungi semua node dalam graph dengan aturan tertentu.
Metode penelusuran yang digunakan dalam praktikum ini adalah:
a. Depth First Search (DFS)
DFS menelusuri graph dengan cara mengunjungi satu node, lalu melanjutkan ke node tetangganya secara rekursif sampai sejauh mungkin sebelum menuju node berikutnya.
Metode ini menggunakan prinsip stack atau rekursi.
b. Breadth First Search (BFS)
BFS menelusuri graph dengan cara mengunjungi node berdasarkan tingkat atau level.
Penelusuran dimulai dari node awal, lalu ke semua node tetangga terdekat sebelum melanjutkan ke level berikutnya. Metode ini menggunakan struktur data queue.

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


## Unguided

### 1. [graph.h]
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph X);
adrEdge AlokasiEdge(adrNode N);

void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

void ResetVisited(Graph &G);
void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif

Pada file header ini berperan sebagai Abstract Data Type (ADT) yang mengatur struktur data dan bentuk fungsi yang digunakan dalam program. Dalam file ini, dideklarasikan tipe data infoGraph sebagai karakter untuk menyimpan label dari node, serta tipe pointer adrNode dan adrEdge yang digunakan untuk merujuk ke struktur node dan edge. Selain itu, juga didefinisikan struktur ElmNode, ElmEdge, dan Graph, serta fungsi-fungsi dasar seperti pembuatan graph, penambahan node, penghubungan node, pencarian node, serta penelusuran graph menggunakan DFS dan BFS.

### 2. [graph.cpp]
#include "graph.h"
#include <iostream>

using namespace std;

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode AlokasiNode(infoGraph X) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = X;
    nodeBaru->visited = 0;
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

adrEdge AlokasiEdge(adrNode N) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = N;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode nodeBaru = AlokasiNode(X);
    if (G.first == NULL) {
        G.first = nodeBaru;
    } else {
        adrNode nodeBantu = G.first;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

adrNode FindNode(Graph G, infoGraph X) {
    adrNode nodeBantu = G.first;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == X) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge Edge1 = AlokasiEdge(N2);
    Edge1->Next = N1->firstEdge;
    N1->firstEdge = Edge1;

    adrEdge Edge2 = AlokasiEdge(N1);  
    Edge2->Next = N2->firstEdge;  
    N2->firstEdge = Edge2;  

}

void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.first;
    while (nodeBantu != NULL) {
    cout << nodeBantu->info << " : ";
    adrEdge Edge = nodeBantu->firstEdge;
    while (Edge != NULL) {
        cout << Edge->Node->info << " ";
        Edge = Edge->Next;
    }
    cout << endl;
    nodeBantu = nodeBantu->Next;
    }
}

void ResetVisited(Graph &G) {
    adrNode nodeBantu = G.first;
    while (nodeBantu != NULL) {
        nodeBantu->visited = 0;
        nodeBantu = nodeBantu->Next;
    }
}

void PrintBFS(Graph G, adrNode N) {
    adrNode Q[50];
    int front = 0;
    int rear = 0;

    N->visited = 1;
    Q[rear++] = N;

    while (front < rear) {
        adrNode nodeBantu = Q[front++];
        cout << nodeBantu->info << " ";

        adrEdge E = nodeBantu->firstEdge;
        while (E != NULL) {
            if (E->Node->visited == 0) {
                E->Node->visited = 1;
                Q[rear++] = E->Node;
            }
            E = E->Next;
        }
    }
}

void PrintDFS(Graph G, adrNode N) {
    if (N == NULL) return;

    N->visited = 1;
    cout << N->info << " ";

    adrEdge E = N->firstEdge;
    while (E != NULL) {
        if (E->Node->visited == 0) {
            PrintDFS(G, E->Node);
        }
        E = E->Next;
    }
}

File graph.cpp berisi pembuatan fungsi-fungsi yang sudah dideklarasikan di graph.h. Fungsi CreateGraph digunakan untuk membuat graph kosong dengan cara mengatur pointer first menjadi NULL. Memori untuk node dan edge dialokasikan melalui fungsi AlokasiNode dan AlokasiEdge, di mana setiap node menyimpan informasi, status kunjungan, dan daftar edge, sedangkan edge menyimpan node tujuannya. Menambahkan node ke dalam graph dilakukan oleh fungsi InsertNode, sedangkan mencari node tertentu dilakukan dengan fungsi FindNode. Hubungan antar node dibuat dengan fungsi ConnectNode yang membuat dua edge karena graph bersifat tidak berarah. Proses penelusuran graph diimplementasikan melalui fungsi PrintDFS dan PrintBFS, di mana DFS menggunakan cara rekursif untuk menelusuri graph secara mendalam, sedangkan BFS menggunakan struktur antrian untuk menelusuri graph secara melebar. Sebelum proses penelusuran dimulai, fungsi ResetVisited digunakan untuk mengatur kembali status kunjungan semua node.

### 3. [main.cpp]
#include "graph.h"
#include <iostream>

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
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');
    adrNode E = FindNode(G, 'E');
    adrNode F = FindNode(G, 'F');
    adrNode nG = FindNode(G, 'G'); //nG->biar ga bentrok sama Graph G
    adrNode H = FindNode(G, 'H');

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, nG);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(nG, H);

    PrintInfoGraph(G);

    ResetVisited(G);
    cout << "DFS: ";
    PrintDFS(G, A);
    cout << endl;

    ResetVisited(G);
    cout << "BFS: ";
    PrintBFS(G, A);
    cout << endl;

    return 0;
}

nahh main.cpp ini program utama yang digunakan untuk menguji implementasi ADT graph. Di dalam file ini, graph diinisialisasi terlebih dahulu menggunakan fungsi CreateGraph. Selanjutnya, node dari A hingga H ditambahkan ke dalam graph dengan fungsi InsertNode. Setelah itu, alamat masing-masing node dicari menggunakan fungsi FindNode agar memudahkan dalam menghubungkan antar node. Hubungan antar node dibuat menggunakan fungsi ConnectNode sesuai dengan struktur graph yang diinginkan. Setelah graph berhasil dibuat, program menampilkan isi graph melalui fungsi PrintInfoGraph. Lalu, program melakukan penelusuran graph menggunakan metode Depth First Search (DFS) dan Breadth First Search (BFS) mulai dari node A. Sebelum proses penelusuran dilakukan, fungsi ResetVisited dipanggil untuk mengembalikan status kunjungan node ke kondisi awal.

### [output]
<img width="946" height="267" alt="image" src="https://github.com/user-attachments/assets/c5ca6988-64dd-4e54-b00c-f7d44f3ee776" />

Kode di atas itu menampilkan adjacency list yang menunjukkan hubungan antar node dalam graf tidak berarah, di mana urutan tetangga tergantung pada urutan penyimpanan edge. Hasil pencarian DFS dari node A menghasilkan urutan A C G H F E B D karena penelusuran dilakukan sampai ke node terdalam terlebih dahulu sebelum beralih ke cabang lain. Sementara itu, hasil BFS menghasilkan urutan A C B G F E D H karena penelusuran dilakukan secara bertahap per level menggunakan antrian. Perbedaan urutan hasil DFS dan BFS disebabkan oleh metode penelusuran yang berbeda serta urutan edge dalam graf.


## Kesimpulan
Dari ketiga implementasi percobaan ituu, dapat disimpulkan bahwa struktur data graf tidak berarah bisa diimplementasikan dengan menggunakan beberapa linked list. Metode ini memanfaatkan pointer untuk merepresentasikan node dan edge. Program berhasil menampilkan hubungan antar node dalam bentuk adjacency list serta melakukan pencarian pada graf menggunakan metode Depth First Search (DFS) dan Breadth First Search (BFS). Perbedaan urutan hasil dari kedua metode tersebut menunjukkan cara kerja masing-masing, yaitu DFS mengunjungi node secara mendalam sedangkan BFS mengunjungi node secara lebar, sesuai dengan teori yang telah dipelajari.

## Referensi
https://www.geeksforgeeks.org/cpp/implementation-of-graph-in-cpp/
https://medium.com/@itsvinayyay/graphs-data-structure-in-c-ab7b4205f41a
Modul 14 Graph
