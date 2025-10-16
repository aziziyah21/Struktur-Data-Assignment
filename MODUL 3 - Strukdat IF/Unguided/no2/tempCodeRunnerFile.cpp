#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namaPelajaran = "Struktur Data";
    string kodePelajaran = "STD";

    pelajaran pel = create_pelajaran(namaPelajaran, kodePelajaran);
    tampil_pelajaran(pel);

    return 0;
}