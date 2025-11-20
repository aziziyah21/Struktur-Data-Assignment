#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct Song {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating;
};

struct Node {
    Song info;
    Address *next;
    Address *prev;
};

struct List {
    Address *head;
    Address *tail;
};

bool isEmpty(List L);
void createList(List &L);

void insertFirst(List L, Node newNode);
void insertLast(List &L, Node newNode);
void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, int address);

void updateAtPos(linkedlist &List, int pos, string nama, string sku, int jumlah, float harga, float diskon);
void printList(linkedlist List);
void searchRentang(linkedlist List, float minH, float maxH);
void findMaxHarga(linkedlist List)

#endif