#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H
#define Nil NULL

#include <iostream>
using namespace std;

struct Product {
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen;
    float HargaAkhir;
};

struct Node {
    Product info;
    Node *next;
};

struct linkedlist {
    Node *head;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
float hitungHargaAkhir(float harga, float diskon);
Node createNode(string nama, string sku, int jumlah, float harga, float diskon);

void insertFirst(linkedlist List, Node newNode);
void insertLast(linkedlist &List, Node newNode);
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, int address);

void updateAtPos(linkedlist &List, int pos, string nama, string sku, int jumlah, float harga, float diskon);
void printList(linkedlist List);
void searchRentang(linkedlist List, float minH, float maxH);
void findMaxHarga(linkedlist List)

#endif