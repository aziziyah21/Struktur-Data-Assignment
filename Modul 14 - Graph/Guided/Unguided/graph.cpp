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
