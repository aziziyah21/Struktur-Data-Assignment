#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAX = 5;
typedef int infotype;

struct Queue{
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmpty(Queue &Q);
bool isFull(Queue &Q);
void enQueue(Queue &Q, infotype x);
void deQueue(Queue &Q);
void printInfo(Queue &Q);

#endif