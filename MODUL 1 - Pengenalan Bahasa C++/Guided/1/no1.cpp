#include <iostream>
using namespace std;

int main() {
    float a, b;
    cout << "Masukan bilangan1: ";
    cin >> a;
    cout << "Masukan bilangan2: ";
    cin >> b;

    cout << "Hasil penjumlahan: " << a + b << endl;
    cout << "Hasil pengurangan: " << a - b << endl;
    cout << "Hasil perkalian: " << a * b << endl;
    if (b != 0)
       cout << "Hasil pembagian: " << a / b << endl;
    else
       cout << "Pembagian nol tidak dapat dilakukan." << endl;

    return 0;
}