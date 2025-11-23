#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q){
   Q.head = 0;
   Q.tail = -1;
}

bool isEmpty(Queue &Q){
    if(Q.tail < Q.head){
        return true;
    } else {
        return false;
    }
}

bool isFull(Queue &Q){
    if(Q.tail == MAX - 1){
        return true;
    } else {
        return false;
    }
}

void enQueue(Queue &Q, infotype x){
    if(isFull(Q)){
        cout << "Queue penuh" << endl;
    } else {
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

void deQueue(Queue &Q){
    if(isEmpty(Q)){
        cout << "Queue kosong" << endl;
        return;
    } else {
        cout << "Mengahapus data " << Q.info[Q.head] << "..." << endl;
        if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
            Q.head = 0;
            Q.tail = -1;
        } else {
            Q.head++;
        }
    }
}

void printInfo(Queue &Q){
    if(isEmpty(Q)){
        cout << Q.head << " " << Q.tail << " empty queue" << endl;
    }else{
        cout << Q.head << " " << Q.tail << " " << endl;
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i];
            if(i < Q.tail) cout << " ";
        }
        cout << "" << endl;
    }
}