/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main() {
    const int MAKS = 1000;
    char teks[MAKS];
    char hasil[MAKS];

    cout << "Masukkan teks: ";
    cin.getline(teks, MAKS);

    // Menghitung panjang teks secara manual (tanpa strlen)
    int panjang = 0;
    while (teks[panjang] != '\0') {
        panjang++;
    }

   char hurufSebelumnya = '\0'; // menyimpan huruf ASLI terakhir yang berupa alfabet
    bool sudahAdaHurufPertama = false;

    for (int i = 0; i < panjang; i++) {
        char c = teks[i];

        // Cek apakah c adalah huruf (besar atau kecil), tanpa isalpha()
        bool hurufBesar = (c >= 'A' && c <= 'Z');
        bool hurufKecil = (c >= 'a' && c <= 'z');

        if (!hurufBesar && !hurufKecil) {
            // Bukan huruf (spasi, angka, dll), dibiarkan apa adanya
            hasil[i] = c;
            continue;
        }

        if (!sudahAdaHurufPertama) {
            // Huruf pertama tidak mengalami perubahan
            hasil[i] = c;
            hurufSebelumnya = c;
            sudahAdaHurufPertama = true;
        } else {
            // Menentukan nilai posisi alfabet (A/a = 1, ..., Z/z = 26) secara manual
            int nilaiSebelum, nilaiSekarang;

            if (hurufSebelumnya >= 'A' && hurufSebelumnya <= 'Z') {
                nilaiSebelum = hurufSebelumnya - 'A' + 1;
            } else {
                nilaiSebelum = hurufSebelumnya - 'a' + 1;
            }

            if (hurufBesar) {
                nilaiSekarang = c - 'A' + 1;
            } else {
                nilaiSekarang = c - 'a' + 1;
            }

            // Rumus pergeseran dengan wrap-around modulo 26
            int nilaiBaru = ((nilaiSekarang + nilaiSebelum - 1) % 26) + 1;

            // Mengubah nilai posisi kembali menjadi huruf, sesuai case aslinya
            char basis = hurufBesar ? 'A' : 'a';
            char terenkripsi = (char)((nilaiBaru - 1) + basis);

            hasil[i] = terenkripsi;
            hurufSebelumnya = c; // tetap memakai huruf ASLI sebagai acuan geser berikutnya
        }
    }

    hasil[panjang] = '\0'; // menutup string hasil secara manual

    cout << "Hasil sandi : " << hasil << endl;

    return 0;
}