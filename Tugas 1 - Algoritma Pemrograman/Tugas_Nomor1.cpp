/* 
    Soal 1
    Nama: Faiz Haidar
    NIM: 230401010232  
    Kelas: IF102
    Mata Kuliah: Algoritma Pemrograman
*/

#include <iostream>
using namespace std;

int main() {
    int nilai, parameter, baris, baris2;
    cout << endl;
    cout << "Masukkan jumlah baris: ";
    cin >> nilai;
    if (nilai % 2 != 0) // mengecek jika nilai bukan genap
    {
        for (parameter = 1; parameter <= nilai; parameter++) {
            // mengecek jika baris tengah (nilai/2 + 1)
            if (parameter == (nilai / 2 + 1)) {
                for (baris = 0; baris < nilai; baris++) {
                    cout << "*";
                }
            } else {
                for (baris2 = 0; baris2 < nilai / 2; baris2++) {
                    cout << " "; // Spasi untuk membuat * di tengah
                }
                cout << "*";
            }
            cout << endl;
        }
    } else {
        cout << "Jumlah baris harus ganjil" << endl;
    }

    cout << endl;

    // sintaks berikut untuk melanjutkan program atau tidak
    char lanjut;
    cout << "Melanjutkan program? Y/N: ";
    cin >> lanjut;

    // kondisi jika Y maka menjalankan kembali fungsi main, jika N maka program berhenti
    if (lanjut == 'Y' || lanjut == 'y') {
        main();
    } else if(lanjut == 'N' || lanjut == 'n') {
        cout << "Terima kasih telah menggunakan Progam ini." << endl;
        return 0;
    }
    
}
