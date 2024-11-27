/* 
    Soal 3
    Faiz Haidar
    230401010232  
*/

#include <iostream>
using namespace std;

// Fungsi untuk memeriksa apakah bilangan adalah prima,
bool isPrime(int n) {
    if (n <= 1) return false; // Bilangan <= 1 bukan prima
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) return false; // Jika ada pembagi selain 1 dan dirinya sendiri
    }
    return true; // Jika tidak ada pembagi, maka bilangan prima
}

int main() {
    char ulang;
    do {
        int bilangan;

        // Input bilangan
        cout << "Masukkan bilangan: ";
        cin >> bilangan;

        // Menentukan ganjil atau genap
        if (bilangan % 2 == 0) {
            cout << bilangan << " adalah bilangan genap.\n";
        } else {
            cout << bilangan << " adalah bilangan ganjil.\n";
        }

        // Menentukan positif atau negatif
        if (bilangan > 0) {
            cout << bilangan << " adalah bilangan positif.\n";
        } else if (bilangan < 0) {
            cout << bilangan << " adalah bilangan negatif.\n";
        } else {
            cout << bilangan << " adalah bilangan nol (bukan positif atau negatif).\n";
        }

        // Menentukan apakah bilangan adalah prima
        if (isPrime(bilangan)) {
            cout << bilangan << " adalah bilangan prima.\n";
        } else {
            cout << bilangan << " bukan bilangan prima.\n";
        }

        cout << "\nIngin mengulang program ini (Y/N): ";
        cin >> ulang;

        cout << endl;
    } while (ulang == 'Y' || ulang == 'y');

    return 0;
}
