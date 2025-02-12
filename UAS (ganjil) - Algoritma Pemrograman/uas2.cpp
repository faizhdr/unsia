/*
    Soal 2 UAS
    Nama: Faiz Haidar
    NIM: 230401010232
    Kelas: IF102
    Mata Kuliah: Algoritma Pemrograman
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Fungsi untuk menghitung diskon
double potong(double totalBelanja) {
    double diskon = 0.0;

    if (totalBelanja >= 1000000 && totalBelanja <= 5000000) {
        diskon = 0.20 * totalBelanja; // Diskon 20%
    } else if (totalBelanja > 5000000) {
        diskon = 0.35 * totalBelanja; // Diskon 35%
    }

    return diskon;
}

int main() {
    double totalBelanja, totalDiskon, totalBayar;
    char ulang;

    do {
        cout << "PROGRAM HITUNG DISKON PEMBELIAN\n";
        cout << "----------------------------------\n";
        cout << "Masukkan total belanja (Rp): ";
        cin >> totalBelanja;

        // Panggil fungsi untuk menghitung diskon
        totalDiskon = potong(totalBelanja);
        totalBayar = totalBelanja - totalDiskon;

        // Tampilkan hasil
        cout << fixed << setprecision(2);
        cout << "\nTotal Belanja  : Rp " << totalBelanja << endl;
        cout << "Diskon         : Rp " << totalDiskon << endl;
        cout << "Total Bayar    : Rp " << totalBayar << endl;
        cout << "----------------------------------\n";

        // Pilihan untuk mengulang program
        cout << "Ingin menghitung lagi? (y/n): ";
        cin >> ulang;
        cout << endl;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "Program selesai.\n";
    return 0;
}
