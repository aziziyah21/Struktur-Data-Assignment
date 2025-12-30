#include "circularlist.h"

void createList(List &L){
L.first = NULL;
}

address alokasi(mahasiswa x){
address P = new ElmList;
P->info = x;
P->next = NULL;
return P;
}

void dealokasi(address &P){
delete P;
P = NULL;
}

void insertFirst(List &L, address P){
if(L.first == NULL){
L.first = P;
P->next = P;
} else {
address Q = L.first;
while(Q->next != L.first){
Q = Q->next;
}
P->next = L.first;
Q->next = P;
L.first = P;
}
}

void insertLast(List &L, address P){
if(L.first == NULL){
L.first = P;
P->next = P;
} else {
address Q = L.first;
while(Q->next != L.first){
Q = Q->next;
}
Q->next = P;
P->next = L.first;
}
}

void insertAfter(List &L, address Prec, address P){
if(Prec != NULL){
P->next = Prec->next;
Prec->next = P;
}
}

void deleteFirst(List &L, address &P){
if(L.first == NULL){
P = NULL;
} else if(L.first->next == L.first){
P = L.first;
L.first = NULL;
} else {
address Q = L.first;
while(Q->next != L.first){
Q = Q->next;
}
P = L.first;
L.first = L.first->next;
Q->next = L.first;
P->next = NULL;
}
}

void deleteLast(List &L, address &P){
if(L.first == NULL){
P = NULL;
} else if(L.first->next == L.first){
P = L.first;
L.first = NULL;
} else {
address Q = L.first;
address R = NULL;
while(Q->next != L.first){
R = Q;
Q = Q->next;
}
R->next = L.first;
P = Q;
P->next = NULL;
}
}

void deleteAfter(List &L, address Prec, address &P){
if(Prec != NULL && Prec->next != L.first){
P = Prec->next;
Prec->next = P->next;
P->next = NULL;
}
}

address findElm(List L, mahasiswa x){
if(L.first == NULL){
return NULL;
}
address P = L.first;
do{
if(P->info.nim == x.nim){
return P;
}
P = P->next;
} while(P != L.first);
return NULL;
}
void printInfo(List L){
    if(L.first == NULL){
        cout << "List kosong" << endl;
    } else {
        address P = L.first;
        int i = 1;
        cout << "Data Mahasiswa" << endl;
        do{
            cout << "Mahasiswa ke-" << i << endl;
            cout << "Nama          : " << P->info.nama << endl;
            cout << "NIM           : " << P->info.nim << endl;
            cout << "P/L           : " << P->info.jenis_kelamin << endl;
            cout << "IPK           : " << P->info.ipk << endl;
            cout << endl;
            P = P->next;
            i++;
        } while(P != L.first);
    }
}
