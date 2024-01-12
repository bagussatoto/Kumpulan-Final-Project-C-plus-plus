#include <iostream>
using namespace std;

int main()
{
    char nama[30], pembeli[30];
    int harga, jumlah, total, jumtotal, kembalian, potongan, jumbayar;
    string input, kode;
    awal:
    cout << "      TOKO MAS BAGUS         " << endl;
    cout << "=============================" << endl;
    cout << "Nama Pembeli  :";
    cin >> pembeli;
    cout << "Pilihan Barang Yang Tersedia" << endl;
    cout << "001 - Laptop Acer RAM 4GB - RP.6.000.000" << endl;
    cout << "002 - Mouse Wireless - RP.350.000" << endl;
    cout << "003 - Mikrotik RB941 - RP.700.000" << endl;


    cout << endl;
    cout << endl;
    cout << "Barang yang dipilih    :";
    cin >> kode;
    cout << "Jumlah Beli            :";
    cin >> jumlah;

    if (kode == "001") {
        cout << "Laptop Acer RAM 4GB";
        harga = 6000000;
    }
    else if (kode == "002") {
        cout << "Mouse Wireless";
        harga = 350000;
    }
    else if (kode == "001") {
        cout << "Mikrotik RB941";
        harga = 700000;
    }
    else {
        cout << "Barang yang dipilih tidak tersedia";
    }

    cout << endl;
    cout << "=============================" << endl;
    cout << "Struk Pembayaran" << endl;
    cout << "=============================" << endl;
    cout << "Nama Pembeli       :" << pembeli << endl;
    cout << "Harga              :" << harga << endl;
    cout << "Jumlah             :" << jumlah << endl;


    total = harga * jumlah;

    cout << "Total              :" << total << endl;

    cout << endl;

    if (total > 100000 || total < 500000) {
        potongan = 0.05 * total;
    } 
    else if (total > 500000) {
        potongan = 0.10 * total;
    }
    else {
        potongan = 0;
    }

    cout << "Potongan            :" << potongan << endl;
    cout << "==============================" << endl;

    jumtotal = total - potongan;

    cout << "Total keseluruhan   :" << jumtotal << endl;
    cout << "Uang Bayar          :";
    cin >> jumbayar;

    kembalian = jumbayar - jumtotal;

    cout << "Uang Kembalian      : " << kembalian << endl;
    cout << "=============================" << endl;

    cout << "Mau Input Lagi [Y/N] :";
    cin >> input;

    if (input == "y" || input == "Y") {
        goto awal;
    }
    else {
        system("pause");
        return 0;

    }

}
    