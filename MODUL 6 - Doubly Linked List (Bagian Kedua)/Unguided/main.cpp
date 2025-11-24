#include "dll.h"

#include <iostream>
using namespace std;

int main() {
List L;
createList(L);

infotype ken1 = {"D001", "Hitam", 90};
infotype ken2 = {"D002", "Putih", 70};
infotype ken3 = {"D003", "Merah", 80};
infotype ken4 = {"D004", "Kuning", 90};

insertFirst(L, alokasi(ken1));
insertFirst(L, alokasi(ken2));
insertLast(L, alokasi(ken3));
insertLast(L, alokasi(ken4));

//no1
//cout << "Data kendaraan" << endl;
//printInfo(L);

//no2
//string cari;
//cout << "Masukan No Polisi yang dicari" << endl; //no2
//cin >> cari;

//address pCari = findElm(L, cari);

//if (pCari != NULL) {
//    cout << "Nomor Polisi : " << pCari->info.noPolisi << endl;
//    cout << "Warna : " << pCari->info.warna << endl;
//    cout << "Tahun : " << pCari->info.tahun << endl;
//}

//no3
string cari;
cout << "Masukan No Polisi yang akan dihapus" << endl; //no2
cin >> cari;
address p = findElm(L, cari);

if (p != NULL) {
    address hapus; 

    if (p == L.first){
        deleteFirst(L, hapus);
    } else if (p == L.last) {
        deleteLast(L, hapus);
    } else {
        deleteAfter(L, p->prev, hapus);
    }

    dealokasi(hapus);
}

printInfo(L);

return 0;

}