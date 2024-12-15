/*
    Soal 3 UTS
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
        char jenisSusu, ukuranSusu;
        int hargaSusu, jumlahSusu;

        cout << "TOKO KELONTONG KERONCONGAN" << endl;
        cout << "--------------------------" << endl;

        cout << "A. Susu Dancow" << endl;
        cout << "   1. Ukuran Kecil" << endl;
        cout << "   2. Ukuran Sedang" << endl;
        cout << "   3. Ukuran Besar" << endl;

        cout << "B. Susu Bendera" << endl;
        cout << "   1. Ukuran Kecil" << endl;
        cout << "   2. Ukuran Sedang" << endl;
        cout << "   3. Ukuran Besar" << endl;

        cout << "C. Susu SGM" << endl;
        cout << "   1. Ukuran Kecil" << endl;
        cout << "   2. Ukuran Sedang" << endl;
        cout << "   3. Ukuran Besar" << endl;

        cout << endl;

        while (true)
        {
            // Proses Input
            cout << "Masukkan Jenis Susu: ";
            cin >> jenisSusu;

            if (jenisSusu == 'A' || jenisSusu == 'a')
            {
                while (true)
                {
                    cout << "Masukkan Ukuran Susu: ";
                    cin >> ukuranSusu;

                    if (ukuranSusu == '1')
                    {
                        hargaSusu = 15000;
                        break;
                    }
                    else if (ukuranSusu == '2')
                    {
                        hargaSusu = 20000;
                        break;
                    }
                    else if (ukuranSusu == '3')
                    {
                        hargaSusu = 25000;
                        break;
                    }
                    else
                    {
                        cout << "Ukuran Susu Tidak Tersedia, silakan input kembali.\n";
                    }
                }
                cout << "Harga Susu: " << hargaSusu << endl;
                cout << "Jumlah Yang dibeli : ";
                cin >> jumlahSusu;

                cout << "Harga Yang Harus dibayar Sebesar Rp. " << hargaSusu * jumlahSusu << endl;
                break;
            }
            else if (jenisSusu == 'B' || jenisSusu == 'b')
            {
                while (true)
                {
                    cout << "Masukkan Ukuran Susu: ";
                    cin >> ukuranSusu;

                    if (ukuranSusu == '1')
                    {
                        hargaSusu = 13500;
                        break;
                    }
                    else if (ukuranSusu == '2')
                    {
                        hargaSusu = 17500;
                        break;
                    }
                    else if (ukuranSusu == '3')
                    {
                        hargaSusu = 20000;
                        break;
                    }
                    else
                    {
                        cout << "Ukuran Susu Tidak Tersedia, silakan input kembali.\n";
                    }
                }
                cout << "Harga Susu: " << hargaSusu << endl;
                cout << "Jumlah Yang dibeli : ";
                cin >> jumlahSusu;

                cout << "Harga Yang Harus dibayar Sebesar Rp. " << hargaSusu * jumlahSusu << endl;
                break;
            }
            else if (jenisSusu == 'C' || jenisSusu == 'c')
            {
                while (true)
                {
                    cout << "Masukkan Ukuran Susu: ";
                    cin >> ukuranSusu;

                    if (ukuranSusu == '1')
                    {
                        hargaSusu = 15000;
                        break;
                    }
                    else if (ukuranSusu == '2')
                    {
                        hargaSusu = 18500;
                        break;
                    }
                    else if (ukuranSusu == '3')
                    {
                        hargaSusu = 22000;
                        break;
                    }
                    else
                    {
                        cout << "Ukuran Susu Tidak Tersedia, silakan input kembali.\n";
                    }
                }
                cout << "Harga Susu: " << hargaSusu << endl;
                cout << "Jumlah Yang dibeli : ";
                cin >> jumlahSusu;

                cout << "Harga Yang Harus dibayar Sebesar Rp. " << hargaSusu * jumlahSusu << endl;
                break;
            }
            else
            {
                cout << "Jenis Susu Tidak Tersedia." << endl;
            }
        }

        cout << "\nIngin Hitung Transaksi Lainnya (Y/N)?: ";
        cin >> ulang;

        cout << endl;

    } while (ulang == 'Y' || ulang == 'y');
}