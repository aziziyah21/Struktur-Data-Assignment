#include "SLLInventory.h"

#include <iostream>
using namespace std;

int main() {
    List L;
    createList(L);

    insertLast(L, createNode("Senja di Kota", "Nona Band", 210, 150, 4.2));
    insertLast(L, createNode("Langkahmu", "Delta", 185, 320, 4.8));
    insertLast(L, createNode("Hujan Minggu", "Arka", 240, 90, 3.9));

    cout << "--- DATA AWAL LIST ---" << endl;
    printList(List);

    deleteFirst(List);
    cout << "--- LIST SETELAH DILAKUKAN DELETE POSISI 3 ---" << endl;
    printList(List);

    updateAtPos(List, 2, "Pelita-Updated", "Luna", 200, 260, 4.5);
    cout << "--- SETELAH DILAKUKAN UPDATE POSISI KE 2 ---" << endl;
    printList(List);

    cout << "--- PENCARIAN RENTANG BERDASARKAN POPULARITY SCORE ---" << endl;
    searchRentang(List, 150.0, 300.0);

    return 0;
}
