/* 
    Soal 2
    Nama: Faiz Haidar
    NIM: 230401010232  
    Kelas: IF102
    Mata Kuliah: Algoritma Pemrograman
*/

#include <iostream>
using namespace std;

int main() {
    char ulang;

    do {
        int pilihan;
        bool valid = false; // Variabel untuk memeriksa apakah input valid

        // Loop sampai input valid
        while (!valid) {
            cout << "Silahkan pilih (1-3) jumlah uang yang akan anda ambil:\n";
            cout << "1. 100.000\n";
            cout << "2. 250.000\n";
            cout << "3. 500.000\n";
            cout << "Pilihan: ";
            cin >> pilihan;

            // Menggunakan switch case untuk memilih pilihan
            switch (pilihan) {
                case 1:
                    cout << "\nSilahkan ambil uang 100.000 anda\n";
                    valid = true; // Input valid, keluar dari loop validasi
                    break;
                case 2:
                    cout << "\nSilahkan ambil uang 250.000 anda\n";
                    valid = true;
                    break;
                case 3:
                    cout << "\nSilahkan ambil uang 500.000 anda\n";
                    valid = true;
                    break;
                default:
                    cout << "\nPilihan tidak valid. Silahkan pilih angka 1-3.\n";
                    break;
            }
        }

        cout << "\nApakah anda ingin melakukan transaksi lagi (Y/N): ";
        cin >> ulang;

    } while (ulang == 'Y' || ulang == 'y');

    cout << "\nTerima kasih telah menggunakan layanan ATM kami.\n";

    return 0;
}
