#include "queue.h"
#include <iostream>
using namespace std;

int main(){
    Queue Q;

    createQueue(Q);
    enQueue(Q, 5);
    enQueue(Q, 2);
    enQueue(Q, 7);
    enQueue(Q, 4);

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    printInfo(Q);

    deQueue(Q);
    deQueue(Q);

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    printInfo(Q);

    return 0;
}