#include <iostream>
using namespace std;

int main() {
    int i = 0;
    int j = 20;

    while (i <= 10) {
        cout << i << "-";
        i++;
    }

    cout << endl;

    do { // Mengecek, kalo bener yaudah stop, kalo salah ya lanjut di cek lagi
        cout << j << "-";
        j++;
    } while (j <= 10); 
    
}