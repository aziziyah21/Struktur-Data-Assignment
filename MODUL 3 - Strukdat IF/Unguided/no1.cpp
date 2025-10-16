#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    string nim;
    float uts, uas, tugas;
    float nilaiAkhir;
};

float nilaiAkhir(mahasiswa mhs) {
    return (0.3 * mhs.uts) + (0.4 * mhs.uas) + (0.3 * mhs.tugas);
}

int main() {
    mahasiswa mhs[10];
    int n;

    cout << "Masukan jumlah mahasiswa: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Data mahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        cin >> mhs[i].nama;
        cout << "NIM : ";
        cin >> mhs[i].nim;
        cout << "uts : ";
        cin >> mhs[i].uts;
        cout << "uas : ";
        cin >> mhs[i].uas;
        cout << "tugas : ";
        cin >> mhs[i].tugas;
        mhs[i].nilaiAkhir = nilaiAkhir(mhs[i]);
    }
    cout << "nilai akhir:" << endl;
    for (int i = 0; i < n; i++){
        cout << mhs[i].nama << " (" << mhs[i].nim << ") = " << mhs[i].nilaiAkhir << endl;
    }
}