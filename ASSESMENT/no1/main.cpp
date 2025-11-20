#include "SLLInventory.h"

#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    createList(List);

    insertLast(List, createNode("Pulpen", "A001", 20, 2500, 0));
    insertLast(List, createNode("Buku Tulis", "A002", 15, 5000, 10));
    insertLast(List, createNode("Penghapus", "A003", 30, 1500, 0));

    cout << "--- DATA AWAL LIST ---" << endl;
    printList(List);

    deleteFirst(List);
    cout << "--- LIST SETELAH DILAKUKAN DELETE FIRST ---" << endl;
    printList(List);

    updateAtPos(List, 2, "A010-Updated", "Stabilo", 40, 9000, 5);
    cout << "--- SETELAH DILAKUKAN UPDATE POSISI KE 2 ---" << endl;
    printList(List);

    cout << "--- PENCARIAN RENTANG HARGA 2000 - 7000 ---" << endl;
    searchRentang(List, 2000, 7000);

    cout << "\n--- HARGA TERTINGGI ---" << endl;
    findMaxHarga(List);

    return 0;
}
