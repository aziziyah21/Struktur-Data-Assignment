#include <iostream>

bool IsEmpty(List L){
    return (L.first==NULL);
}

void createList(List &L){
    L.first=NULL;
}

address Alokasi(infotype x){
    address P = new ElmtList;
    if (P != NULL){
        p(info) = x;
        p(next) = NULL;
    }
    return P;
}

void Dealokasi(addess &P){
    delete P;
    P=NULL;
}

void InsertFirst(List &L, address P){
    if (P !=)
}