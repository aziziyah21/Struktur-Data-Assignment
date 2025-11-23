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
        cout << "Queue sudah penuh" << endl;
    } else {
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

void deQueue(Queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.info[Q.head] << "..." << endl;
        if(Q.head == Q.tail){
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAX; // bergerak melingkar
        }
    }
}

void printInfo(Queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        int i = Q.head;
        int count = 1;
        while(true){
            cout << count << ". " << Q.info[i] << endl;
            if(i == Q.tail){
                break;
            }
            i = (i + 1) % MAX;
            count++;
        }   
    }
}