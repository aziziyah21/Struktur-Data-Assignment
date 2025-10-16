#include <iostream> 
using namespace std;

void Array(int A[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) 
        cout << A[i][j] << " ";
    }
    cout << endl;
}

void tukarArray(int A1[3][3], int A2[3][3], int i, int j) {
    int n = A1[i][j];
    A1[i][j] = A2[i][j];
    A2[i][j] = n;
}

void tukarP(int &x, int &y) {
    int n = x; x = y; y = n;
}

int main() {
    int A1[3][3] = {{1,2,3}, {2,3,4}, {3,4,5}};
    int A2[3][3] = {{1,3,5}, {2,4,6}, {1,4,6}};
    int a = 12, b = 21;

    cout << "Array A1:" << endl; Array(A1);
    cout << "Array A2:" << endl; Array(A2);

    tukarArray(A1, A2, 2, 4);
    cout << "Setelah tukar posisi [2][4]:" << endl;
    cout << "Array A1:" << endl; Array(A1);
    cout << "Array A2:" << endl; Array(A2);
    cout << "Sebelum tukar nilai: a =" << a <<", b =" << b << endl;
    tukarP(a,b);
    cout << "Setelah tukar nilai: a =" << a <<", b =" << b << endl;
}