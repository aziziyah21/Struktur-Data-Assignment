#include "stack.h"

#include <sstream>
#include <iostream>
using namespace std;

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.data[S.top] = x;
        cout << "Data " << x << " berhasil ditambahkan ke dalam stack!" << endl;
    }
}

void pushAscending(Stack &S, infotype x) {
    if (isFull(S)) {
        cout << "Stack penuh!" << endl;
        return;
    }

    int i = S.top;
    while (i >= 0 && S.data[i] > x) { 
        S.data[i+1] = S.data[i];
        i--;
    }
    S.data[i+1] = x;
    S.top++;
    cout << "Data " << x << " berhasil dimasukkan secara ascending!" << endl;
}

void pop(Stack &S, infotype &x) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        x = S.data[S.top];
        S.top--;
        cout << "Data " << x << " berhasil dihapus dari stack!" << endl;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; --i) {
            cout << S.data[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (isEmpty(S)) 
    return;

    Stack temp;
    createStack(temp);
    infotype x;
    while (isEmpty(S) == false) {
        pop(S, x);
        push(temp, x);
    }

    S = temp;
}

void inputUsingStream(Stack &S) {
    int x;
    while (true) {
        cin >> x;
        if (x == 0) break;
        if (!isFull(S)) push(S, x);
    }
}
