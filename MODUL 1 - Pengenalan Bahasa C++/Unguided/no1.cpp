#include <iostream>
using namespace std;

int main() {
    float a, b;
    cout << "Bilangan1: ";
    cin >> a;
    cout << "Bilangan2: ";
    cin >> b;

    //aritmatika
    cout << "Penjumlahan: " << a + b << endl;
    cout << "Pengurangan: " << a - b << endl;
    cout << "Perkalian: " << a * b << endl;
    cout << "Pembagian: " << a / b << endl;
    
    //atau
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    
    return 0;
}
