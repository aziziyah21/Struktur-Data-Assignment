#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;

    for (int i = a; i > 0; i--) 
    {
        for (int x = 0; x < a-i; x++)
        {
            cout << "  ";
        }
        for (int y = i; y > 0; y--)
        {
            cout << y << " ";
        }
        cout << "* ";
        for (int z = 1; z <= i; z++)
        {
            cout << z << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < a; i++)
    {
        cout << "  ";
    }
    cout << "*" << endl;
}
