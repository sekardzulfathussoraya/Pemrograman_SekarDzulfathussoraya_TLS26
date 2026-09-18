/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main() {
    int N, K;
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai awal K: ";
    cin >> K;

    bool* aktif = new bool[N];
    for (int i = 0; i < N; i++) {
        aktif[i] = true;
    }

    int sisa = N;
    int idx = 0; // posisi astronot nomor 1

    cout << "Urutan astronot yang dieliminasi: ";

    while (sisa > 1) {
        int hitungan = 1;
        while (hitungan < K) {
            idx = (idx + 1) % N;
            if (aktif[idx]) {
                hitungan++;
            }
        }

        int nomorDieliminasi = idx + 1;
        cout << nomorDieliminasi;
        sisa--;
        if (sisa > 0) {
            cout << ", ";
        }

        aktif[idx] = false;

        // aturan perubahan K
        if (nomorDieliminasi % 2 == 0) {
            K = K + 2;
        } else {
            K = K - 1;
        }
        if (K < 2) {
            K = 2;
        }

        // titik awal hitungan berikutnya
        int next = (idx + 1) % N;
        while (!aktif[next]) {
            next = (next + 1) % N;
        }
        idx = next;
    }

    cout << endl;

    int terakhir = -1;
    for (int i = 0; i < N; i++) {
        if (aktif[i]) {
            terakhir = i + 1;
        }
    }

    cout << "Astronot terakhir yang bertahan (manusia asli): " << terakhir << endl;

    delete[] aktif;
    return 0;
}