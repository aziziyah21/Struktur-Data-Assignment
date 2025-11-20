#include "stack.h"

#include <iostream>
using namespace std;

int main() {
    cout << "--- 4 7 2 9 6 0 1 ---" << endl;

    Stack S;
    createStack(S);

    cout << "--- Isi stack sekarang ---" << endl;
    printInfo(S);

    balikStack(S);
    cout << "--- Setelah dibalik ---" << endl;
    printInfo(S);

    cout << "--- inputUsingStream ---" << endl;
    createStack(S);
    inputUsingStream(S);
    printInfo(S);
    
    return 0;
}
