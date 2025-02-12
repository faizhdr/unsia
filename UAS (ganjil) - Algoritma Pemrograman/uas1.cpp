/*
    Soal 1 UAS
    Nama: Faiz Haidar
    NIM: 230401010232
    Kelas: IF102
    Mata Kuliah: Algoritma Pemrograman
*/

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Struktur untuk menyimpan data mahasiswa
struct Mahasiswa {
    string nama;
    double tugas, uts, uas, akhir;
    char grade;
};

// Fungsi untuk menghitung nilai akhir
double hitungNilaiAkhir(double tugas, double uts, double uas) {
    return (tugas * 0.3) + (uts * 0.3) + (uas * 0.4);
}

// Fungsi untuk menentukan grade berdasarkan nilai akhir
char tentukanGrade(double nilai) {
    if (nilai >= 85) return 'A';
    else if (nilai >= 75) return 'B';
    else if (nilai >= 65) return 'C';
    else if (nilai >= 50) return 'D';
    else return 'E';
}

int main() {
    int jumlahMahasiswa;
    char ulang;

    do {
        cout << "PROGRAM HITUNG NILAI AKHIR\n";
        cout << "MATERI PEMROGRAMMAN C++\n";
        cout << "Masukkan Jumlah Mahasiswa: ";
        cin >> jumlahMahasiswa;
        cin.ignore();

        vector<Mahasiswa> daftarMahasiswa(jumlahMahasiswa);

        // Input data mahasiswa
        for (int i = 0; i < jumlahMahasiswa; i++) {
            cout << "\nMahasiswa Ke-" << i + 1 << endl;
            cout << "Nama Mahasiswa : ";
            getline(cin, daftarMahasiswa[i].nama);
            cout << "Nilai Tugas    : ";
            cin >> daftarMahasiswa[i].tugas;
            cout << "Nilai UTS      : ";
            cin >> daftarMahasiswa[i].uts;
            cout << "Nilai UAS      : ";
            cin >> daftarMahasiswa[i].uas;
            cin.ignore();

            // Hitung nilai akhir dan grade
            daftarMahasiswa[i].akhir = hitungNilaiAkhir(daftarMahasiswa[i].tugas, daftarMahasiswa[i].uts, daftarMahasiswa[i].uas);
            daftarMahasiswa[i].grade = tentukanGrade(daftarMahasiswa[i].akhir);
        }

        // Tampilkan hasil
        cout << "\nDAFTAR NILAI\n";
        cout << "MATERI : PEMROGRAMMAN C++\n";
        cout << "-----------------------------------------------------------\n";
        cout << "No.  Nama                Nilai                      Grade\n";
        cout << "     Mahasiswa           --------------------------\n";
        cout << "                        Tugas   UTS     UAS    Akhir\n";
        cout << "-----------------------------------------------------------\n";

        for (int i = 0; i < jumlahMahasiswa; i++) {
            cout << setw(3) << i + 1 << "  " 
                 << left << setw(18) << daftarMahasiswa[i].nama 
                 << right << setw(6) << daftarMahasiswa[i].tugas 
                 << setw(8) << daftarMahasiswa[i].uts 
                 << setw(8) << daftarMahasiswa[i].uas 
                 << setw(8) << fixed << setprecision(2) << daftarMahasiswa[i].akhir 
                 << setw(6) << daftarMahasiswa[i].grade << endl;
        }

        cout << "-----------------------------------------------------------\n";
        cout << "\nIngin menjalankan program dari awal (y/n)? ";
        cin >> ulang;
        cin.ignore();
        cout << endl;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "Program selesai.\n";
    return 0;
}
