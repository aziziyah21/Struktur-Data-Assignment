#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukan input: ";
    cin >> n;

    for (int i = n; i >= 1; i--) {
        for (int j = i; j >= 1; j--) cout << j << " ";
        cout << "* "; //kiri

        for (int j = 1; j <= i; j++) cout << j << " ";
        cout << endl;
    }
    cout << "*" << endl;
    return 0;
}