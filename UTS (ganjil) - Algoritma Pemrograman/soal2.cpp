/*
    Soal 2 UTS
    Nama: Faiz Haidar
    NIM: 230401010232
    Kelas: IF102
    Mata Kuliah: Algoritma Pemrograman
*/

#include <iostream>
using namespace std;

int main()
{
    char ulang;
    do
    {
        int honor = 3500000;
        string nama;
        int jabatan, pendidikan, jamKerja, jamLembur, honorLembur = 0;
        int hasil1, hasil2, hasil3;
        bool valid1 = false, valid2 = false;

        cout << endl;
        cout << "Program Hitung Honor Karyawan Kontrak PT. DINGIN DAMAI";
        cout << endl;

        cout << "Nama Karyawan          : ";
        cin >> nama;

        while (!valid1)
        {
            // Input Golongan
            cout << "Golongan               : ";
            cin >> jabatan;

            // Cek apakah input valid menggunakan integer atau character
            if (cin.fail())
            {                           
                cin.clear();            
                cin.ignore(1000, '\n');
                cout << "\nInput tidak valid. Masukkan angka 1-3.\n";
                continue;
            }

            switch (jabatan)
            {
            case 1:
                hasil1 = (5.0 / 100) * honor;
                valid1 = true; // Input valid, keluar dari loop validasi
                break;
            case 2:
                hasil1 = (10.0 / 100) * honor;
                valid1 = true;
                break;
            case 3:
                hasil1 = (15.0 / 100) * honor;
                valid1 = true;
                break;
            default:
                cout << "\nPilihan tidak valid. Silahkan pilih angka 1-3.\n";
                break;
            }
        }

        while (!valid2)
        {
            // Input Pendidikan
            cout << "Pendidikan (SMU/D3/S1) : ";
            cin >> pendidikan;

            // Cek apakah input valid menggunakan integer atau character
            if (cin.fail())
            {                           
                cin.clear();            
                cin.ignore(1000, '\n');
                cout << "\nInput tidak valid. Masukkan angka 1-3.\n";
                continue;
            }

            switch (pendidikan)
            {
            case 1:
                hasil2 = (2.5 / 100) * honor;
                valid2 = true; // Input valid, keluar dari loop validasi
                break;
            case 2:
                hasil2 = (5.0 / 100) * honor;
                valid2 = true;
                break;
            case 3:
                hasil2 = (7.5 / 100) * honor;
                valid2 = true;
                break;
            default:
                cout << "\nPilihan tidak valid. Silahkan pilih angka 1-3.\n";
                break;
            }
        }

        // Input Jam Kerja
        cout << "Jumlah Jam Kerja       : ";
        cin >> jamKerja;

        if (jamKerja > 8)
        {
            jamLembur = jamKerja - 8;
            honorLembur = jamLembur * 12500;
        }

        cout << endl;
        cout << "Nama Karyawan: " << nama << endl;
        cout << endl;

        cout << "Honor yang diterima\n";
        cout << "Honor Tetap            Rp. " << honor << endl;
        cout << "Tunjangan Jabatan      Rp. " << hasil1 << endl;
        cout << "Tunjangan Pendidikan   Rp. " << hasil2 << endl;
        cout << "Honor Lembur           Rp. " << honorLembur << endl;
        cout << "                       ----------------------+" << endl;
        cout << "Honor Yang Diterima    Rp. " << honor + hasil1 + hasil2 + honorLembur << endl;

        cout << "\nHitung ulang Honor Karyawan Lainnya (Y/N)?: ";
        cin >> ulang;

        cout << endl;
    } while (ulang == 'Y' || ulang == 'y');

    return 0;
}
