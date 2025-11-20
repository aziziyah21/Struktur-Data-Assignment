#include "SLLInventory.h"

#include <iostream>
using namespace std;

void createList(linkedlist &List) {
    List.head = NULL;
}

float hitungHargaAkhir(float harga, float diskon) {
    return harga * (1 - (diskon / 100));
}

Node *createList(string nama, string sku, int jumlah, float harga, float diskon) {
    Node *newNode = new Node;
    newNode->info.Nama = nama;
    newNode->info.SKU = sku;
    newNode->info.Jumlah = jumlah;
    newNode->info.HargaSatuan = harga;
    newNode->info.DiskonPersen = diskon;
    newNode->info.HargaAkhir = hitungHargaAkhir(harga, diskon);
    newNode->next = NULL;
    return newNode;
}

void insertFirst(linkedlist &List, Node *newNode) {
    newNode->next = List.head;
    List.head = newNode;
}

void insertLast(linkedlist &List, Node *newNode) {
    if (List.head == NULL) {
        List.head = newNode;
    } else {
        Node *p = List.head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newNode;
    }
}

void deleteFirst(linkedlist &List) {
    if (List.head != NULL) {
        Node *temp = List.head;
        List.head = List.head->next;
        delete temp;
    }
}

void deleteLast(linkedlist &List) {
    if (List.head == NULL) return;
    if (List.head->next == NULL) {
        delete List.head;
        List.head = NULL;
        return;
    }

    Node *p = List.head;
    while (p->next->next != NULL) {
        p = p->next;
    }

    delete p->next;
    p->next = NULL;
}

void deleteAfter(linkedlist &List, int pos) {
    if (pos == 1) {
        deleteFirst(List);
        return;
    }

    Node *p = List.head;
    for (int i = 1; i < pos - 1; i++) {
        if (p == NULL) return;
        p = p->next;
    }

    if (p->next != NULL) {
        Node *temp = p->next;
        p->next = temp->next;
        delete temp;
    }
}

void updateAtPos(linkedlist &List, int pos, string nama, string sku, int jumlah, float harga, float diskon) {
    Node *p = List.head;
    for (int i = 1; i < pos; i++) {
        if (p == NULL) return;
        p = p->next;
    }

    p->info.Nama = nama;
    p->info.SKU = sku;
    p->info.Jumlah = jumlah;
    p->info.HargaSatuan = harga;
    p->info.DiskonPersen = diskon;
    p->info.HargaAkhir = hitungHargaAkhir(harga, diskon);
}

void printList(linkedlist List) {
    Node *p = List.head;
    int i = 1;
    while (p != NULL) {
        cout << i << ". "
             << p->info.Nama << " | SKU: " << p->info.SKU
             << " | Harga: " << p->info.HargaAkhir
             << " | Jumlah: " << p->info.Jumlah << endl;
        p = p->next;
        i++;
    }
    cout << endl;
}

void searchRentang(linkedlist List, float minH, float maxH) {
    Node* p = List.head;
    while (p != NULL) {
        if (p->info.HargaAkhir >= minH && p->info.HargaAkhir <= maxH) {
            cout << p->info.Nama << " | HargaAkhir: " << p->info.HargaAkhir << endl;
        }
        p = p->next;
    }
}

void findMaxHarga(linkedlist List) {
    if (List.head == NULL) return;
    
    Node *p = List.head;
    Node *maxNode = List.head;

    while (p != NULL) {
        if (p->info.HargaAkhir > maxNode->info.HargaAkhir) {
            maxNode = p;
        }
        p = p->next;
    }

    cout << "Produk harga tertinggi: " << maxNode->info.Nama 
         << " | Harga: " << maxNode->info.HargaAkhir << endl;
}