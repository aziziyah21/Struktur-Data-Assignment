//
//
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Membiarkan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //Mendefinisikan alias address sbg pointer ke struct node

struct node{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif