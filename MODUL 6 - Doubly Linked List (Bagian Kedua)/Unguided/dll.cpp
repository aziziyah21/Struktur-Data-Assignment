#include "dll.h"

void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

//no 1,2,3
void insertFirst(List &L, address P) { 
    P->next = L.first; 
    P->prev = NULL;
    if (L.first != NULL) L.first->prev = P;
    else L.last = P;
    L.first = P; 
} 

//no 1,2,3
void insertLast(List &L, address P) { 
    P->prev = L.last; 
    P->next = NULL; 
    if (L.last != NULL) L.last->next = P; 
    else L.first = P; 
    L.last = P; 
} 

void insertAfter(List &L, address P, address R) {
    P->next = R->next;
    P->prev = R;
    if (R->next != NULL) R->next->prev = P;
    else L.last = P;
    R->next = P;
}

//no 3
void deleteFirst(List &L, address &P) {
    P = L.first;
    if (P != NULL) {
        L.first = P->next;
        if (L.first != NULL){
            L.first->prev = NULL;
        } else {
            L.last = NULL;
            P->next = NULL;
            P->prev = NULL;
        }
    }
}

//no 3
void deleteLast(List &L, address &P) {
    P = L.last;
    if (P != NULL) {
        L.last = P->prev;
        if (L.last != NULL){
            L.last->next = NULL;
        }else{
            L.first = NULL;
            P->next = NULL;
            P->prev = NULL;
        }
    }
}

//no 3
void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != NULL){
            P->next->prev = Prec;
        }else{
            L.last = Prec;
            P->next = NULL;
            P->prev = NULL;
        }
    }
}

//no 2
address findElm(List L, string noPolisi) {
    address P = L.first;
    while (P != NULL && P->info.noPolisi != noPolisi) {
        P = P->next;
    }
    return P;
}

void printInfo(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << "Nomor Polisi : " << P->info.noPolisi << endl;
        cout << "Warna : " << P->info.warna << endl;
        cout << "Tahun : " << P->info.tahun << endl;
        cout << endl;
        P = P->next;
    }
}