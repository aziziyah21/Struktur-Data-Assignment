#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct elmtList *address;

struct elmtList{
    infotype info;
    address next;
};

struct List{
    address first;
};

bool IsEmpty(List L);
void createList(List &L);
address Alokasi(infotype x);
void Dealokasi(address &P);
void InsertFirst(List &L, address &P);
void DeleteFirst(List &L, address &P);
void PrintInfo(List L);

#endif