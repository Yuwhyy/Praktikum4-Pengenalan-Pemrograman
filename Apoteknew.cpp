#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Obat {
    string nama;
    int stok;
    int batasMinimum;
};

int main() {
    vector<Obat> daftarObat;
    string namaObat;
    int stok, batasMin = 10; 
    char lanjut;

    cout << "=== PROGRAM APOTEK - INPUT STOK OBAT ===" << endl;

    do {
        cout << "\nMasukkan nama obat: ";
        getline(cin, namaObat);

        cout << "Masukkan stok obat: ";
        cin >> stok;

        // Gunakan batas minimum tetap = 10 (sesuai soal)
        Obat o;
        o.nama = namaObat;
        o.stok = stok;
        o.batasMinimum = batasMin;
        daftarObat.push_back(o);

        cin.ignore(); // bersihkan buffer

        cout << "Tambah obat lagi? (y/n): ";
        cin >> lanjut;
        cin.ignore();

    } while (lanjut == 'y' || lanjut == 'Y');

    // Tampilkan hasil dan peringatan jika stok di bawah batas
    cout << "\n=== DAFTAR STOK OBAT ===" << endl;
    for (const auto& o : daftarObat) {
        cout << "- " << o.nama 
             << " | Stok: " << o.stok 
             << " | Batas Minimum: " << o.batasMinimum;
        
        if (o.stok < o.batasMinimum) {
            cout << " STOK RENDAH!";
        }
        cout << endl;
    }

    return 0;
}