#include <iostream>
using namespace std;

string satuan[] = {"nol","satu","dua","tiga","empat","lima","enam","tujuh","delapan","sembilan"};
string belasan[] = {"sebelas","dua belas","tiga belas","empat belas","lima belas","enam belas","tujuh belas","delapan belas","sembilan belas"};
string puluhan[] = {"","sepuluh","dua puluh","tiga puluh","empat puluh","lima puluh","enam puluh","tujuh puluh","delapan puluh","sembilan puluh"};

int main() {
    int n;
    cout << "Masukan angka dari 0 - 100: ";
    cin >> n;

    cout << n << " = ";

    if (n < 10) {
        cout << satuan[n];
    }
    else if (n < 20) {
        cout << belasan [n-10];
    }
    else if (n < 100) {
        int a = n / 10;
        int b = n % 10;
        cout << puluhan[a];
        if (b != 0) {
            cout << " " << satuan[b];
        }
    }
    else if (n == 100) {
        cout << "seratus";
    }
    else {
        cout << "tidak bisa, harus 0 sampai 100 aja yah";
    }
    cout << endl;

    return 0;
}
