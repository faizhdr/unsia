/*
    Soal 4 UTS
    Nama: Faiz Haidar
    NIM: 230401010232
    Kelas: IF102
    Mata Kuliah: Algoritma Pemrograman
*/

#include <iostream>
using namespace std;

int main() {
    int baris = 5, kolom = 5;

    for (int i = 1; i <= baris; i++) {       
        for (int j = 1; j <= kolom; j++) {    
            cout << i * j << "\t";            
        }
        cout << endl;                        
    }

    return 0;
}
