#include <iostream>
using namespace std;

void tukar_pointer (int *x, int *y, int *z) {
    int temp;
    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

void tukar_reference (int &x, int &y, int &z) {
    int temp;
    temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a = 12, b = 18, c = 26;
    cout << "Nilai sebelum di tukar: "<< a <<", "<< b <<", "<< c << endl;
    tukar_pointer(&a, &b, &c); //&a->*
    cout << "After swapping pointer, value of a=" << a << " b=" << b << " and c=" << c << endl; //berhasil ditukar
    tukar_reference(a, b, c);
    cout << "After swapping reference, value of a=" << a << " b=" << b << " and c=" << c << endl;

    return 0;
}