#include <iostream>
using namespace std;

void tukar (int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in ptr (address of a): " << ptr << endl; 
    cout << "Value pointed to by ptr: " << *ptr << endl; //ditunjuk pointer yg isinya 20

    tukar(&a, &b); //&a->*
    cout << "After swapping, value of a=" << a << " and b=" << b << endl; //berhasil ditukar

    return 0;
}