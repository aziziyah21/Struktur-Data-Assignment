#ifndef STACK_H
#define STACK_H
#define Nil NULL

#include <iostream>
using namespace std;

const int MAX = 20;

typedef int infotype;

struct Stack {
    infotype data[MAX];
    int top; 
};

bool isEmpty(Stack S);
bool isFull(Stack S);
void createStack(Stack &S);

void push(Stack &S, infotype x);
void pushAscending(Stack &S, infotype x);
void pop(Stack &S, infotype &x);
void printInfo(Stack S);
void balikStack(Stack &S);
void inputUsingStream(Stack &S);

#endif
