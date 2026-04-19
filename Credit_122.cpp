#include <iostream>
using namespace std;

int main() {
    int admin = 0, harga, uangdp, minimaldp, persentase_dp, lamatenor, kategori;
    float bunga = 0, pokokpinjaman, totalbunga, totalpinjaman, angsuran;
    char ulang;
do {
    cout << "====================================\n";
    cout << "    SELAMAT DATANG DI PAK BILLI     \n";
    cout << "        SIMULATOR KREDIT HP         \n";
    cout << "====================================\n";
    cout << "Masukkan Harga HP  : "; cin >> harga;
    if (harga < 1000000) { // mengecek harga HP kurang dari 1jt atau nggak
        cout << "Error!! Minimal harga 1jt\n";
        return 0;
    }

    cout << "Masukkan Uang DP   : "; cin >> uangdp;
    minimaldp = 0.25 * harga;
    if (uangdp < minimaldp) { // mengecek DP minimal 25% dari harga HP
        cout << "Maaf, DP minimal adalah Rp" << minimaldp << endl;
        cout << "Pengajuan kredit ditolak";
        return 0;
    }

    persentase_dp = (uangdp * 100) / harga; // mengecek persentase DP untuk menentukan kategori, bunga dan admin
    int hasilpersentase = (persentase_dp - 1) / 20; // "-1" berguna untuk range persen masuk ke kategori yang sesuai
    switch (hasilpersentase) {
        case 1: // 25% - 40%
            kategori = 1;
            bunga = 2.5;
            admin = 50000;
            break;
        case 2: // 41% - 60%
            kategori = 2;
            bunga = 1.5;
            admin = 0;
            break;
        case 3: // 61% - 99%
        case 4: // 100%
            if (persentase_dp < 100) {
                kategori = 3;
                bunga = 0.5;
                admin = 0;
                break;
            } else {
                kategori = 4;
                bunga = 0;
                admin = 0;
                break;
            }
    }

    cout << "\n--- ANALISIS KREDIT ANDA ---\n";
    cout << "Harga barang     : Rp" << harga << endl;
    cout << "Uang Muka (DP)   : Rp" << uangdp << endl;
    cout << "Kategori (DP)    : DP ";
    if (kategori == 1) { // mengecek kategori DP dan menampilkan persen DP sesuai dengan kategori
        cout << "25% - 40%\n";
    } else if (kategori == 2) {
        cout << "41% - 60%\n";
    } else if (kategori == 3) {
        cout << "61% - 99%\n";
    } else {
        cout << "100%\n";
    }
    cout << "Suku Bunga       : " << bunga << "% per bulan\n";
    cout << "Biaya Admin      : Rp" << admin << endl;

    do{
        cout << "\nMasukkan Tenor (bulan, kelipatan 3): "; cin >> lamatenor;
        if (lamatenor % 3 != 0) {
            cout << "Input tidak valid! Tenor harus kelipatan 3\n";
        }
    } while(lamatenor % 3 != 0);

    pokokpinjaman = (harga - uangdp) + admin;
    totalbunga = pokokpinjaman * (bunga / 100) * lamatenor;
    totalpinjaman = pokokpinjaman + totalbunga;
    angsuran = totalpinjaman / lamatenor;
    cout << "\n--- RINCIAN ANGSURAN ---\n";
    cout << "Pokok Pinjaman   : Rp\t" << (int)pokokpinjaman << endl; // menggunakan (int) supaya membulatkan hasil ke bawah
    cout << "Total Bunga      : Rp\t" << (int)totalbunga << endl; // "/t atau disebut tab" untuk memberi spasi
    cout << "Total Pinjaman   : Rp\t" << (int)totalpinjaman << endl;
    cout << "Angsuran/Bulan   : Rp\t" << (int)angsuran << " (selama " << lamatenor << " bulan)\n";
    cout << "\n====================================\n";
    cout << "   Terima kasih telah berbelanja!   \n";
    cout << "====================================\n";
    
    cout << "\nApakah Anda ingin mengulang?(y/t): "; cin >> ulang; // fitur tambahan untuk mengulang program tanpa harus run ulang secara manual
} while (ulang == 'y' || ulang == 'Y');
}