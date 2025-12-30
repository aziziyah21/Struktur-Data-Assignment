#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <iostream>
#include <string>

using namespace std;

struct mahasiswa {
string nama;
string nim;
char jenis_kelamin;
float ipk;
};

typedef struct ElmList* address;

struct ElmList {
mahasiswa info;
address next;
};

struct List {
address first;
};

void createList(List &L);
address alokasi(mahasiswa x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void insertAfter(List &L, address Prec, address P);
void insertLast(List &L, address P);
void deleteFirst(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteLast(List &L, address &P);
address findElm(List L, mahasiswa x);
void printInfo(List L);

#endif