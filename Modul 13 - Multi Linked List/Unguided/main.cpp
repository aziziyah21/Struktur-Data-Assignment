#include "circularlist.h"

mahasiswa createData(string nama, string nim, char jenis_kelamin, float ipk){
mahasiswa x;
x.nama = nama;
x.nim = nim;
x.jenis_kelamin = jenis_kelamin;
x.ipk = ipk;
return x;
}

int main(){
List L;
address P1, P2;
mahasiswa x;

createList(L);

P1 = alokasi(createData("Danu", "04", 'L', 4.0));
insertFirst(L, P1);

P1 = alokasi(createData("Fahmi", "06", 'L', 3.45));
insertLast(L, P1);

P1 = alokasi(createData("Bobi", "02", 'L', 3.71));
insertLast(L, P1);

P1 = alokasi(createData("Ali", "01", 'L', 3.3));
insertFirst(L, P1);

P1 = alokasi(createData("Gita", "07", 'P', 3.75));
insertLast(L, P1);

x.nim = "03";
P1 = findElm(L, x);
if(P1 != NULL){
    P2 = alokasi(createData("Cindi", "03", 'P', 3.5));
    insertAfter(L, P1, P2);
}

x.nim = "02";
P1 = findElm(L, x);
if(P1 != NULL){
    P2 = alokasi(createData("Hilmi", "08", 'P', 3.3));
    insertAfter(L, P1, P2);
}

x.nim = "04";
P1 = findElm(L, x);
if(P1 != NULL){
    P2 = alokasi(createData("Eli", "05", 'P', 3.4));
    insertAfter(L, P1, P2);
}

printInfo(L);
return 0;

}