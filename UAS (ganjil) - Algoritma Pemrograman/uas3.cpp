/*
    Soal 3 UAS
    Nama: Faiz Haidar
    NIM: 230401010232
    Kelas: IF102
    Mata Kuliah: Algoritma Pemrograman
*/

#include <iostream>
#include <cctype> // Untuk toupper()
#include <iomanip>

using namespace std;

// fungsi tarif
int tarif(char kodeBuku, int banyakPinjam, int *tarifSewa) {
    kodeBuku = toupper(kodeBuku);
    if (kodeBuku == 'C') {
        *tarifSewa = 500;
    } else if (kodeBuku == 'K') {
        *tarifSewa = 700;
    } else if (kodeBuku == 'N') {
        *tarifSewa = 1000;
    }

    return banyakPinjam * (*tarifSewa); // Mengembalikan jumlah bayar
}

int main () {
    string nama;
    char kodeBuku, ulang;
    int banyakPinjam, tarifSewa;

    do {

        // menu
        cout << "---------------------------------------\n";
        cout << "kode        Jenis Buku            Tarif\n";
        cout << "---------------------------------------\n";
        cout << " C     kumpulan Cerita Pendek      500 \n";
        cout << " K            Komik                700 \n";
        cout << " N            Novel               1000 \n";
        cout << "---------------------------------------\n";

        cout << "Nama Penyewa Buku  : ";
        cin >> nama;
        
        do {
            cout << "Kode Buku [C/K/N]  : ";
            cin >> kodeBuku;
            kodeBuku = toupper(kodeBuku); // Konversi ke huruf besar
    
            if (kodeBuku != 'C' && kodeBuku != 'K' && kodeBuku != 'N') {
                cout << "Kode buku tidak valid! Silakan masukkan ulang.\n";
            }
        } while (kodeBuku != 'C' && kodeBuku != 'K' && kodeBuku != 'N');

        cout << "Banyak Pinjam      : ";
        cin >> banyakPinjam;

        int jumlahBayar = tarif(kodeBuku, banyakPinjam, &tarifSewa);
        cout << endl;

        // output
        cout << "Tarif Sewa     : " << tarifSewa << endl;
        cout << "Jenis Buku     : " << kodeBuku << endl;
        cout << endl;
        cout << "Penyewa dengan Nama " << nama << endl;
        cout << "Jumlah Bayar Penyewaan " << jumlahBayar << endl;


        // Pilihan untuk mengulang program
        cout << "Ingin menghitung lagi? (y/n): ";
        cin >> ulang;
        cout << endl;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "Program selesai.\n";
    return 0;
    
}