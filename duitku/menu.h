#pragma once
namespace Menu {
	static int pilih;
	static char lanjut;

	void display() {
		system("cls");

		cout << "+======================================================+" << endl;
		cout << "|      Silahkan Pilih Transaksi Yang Anda Inginkan     |" << endl;
		cout << "|                                                      |" << endl;
		cout << "|    1.INFORMASI SALDO            4.TARIK SALDO        |" << endl;
		cout << "|    2.KIRIM UANG                 5.TRANSAKSI LAINYA   |" << endl;
		cout << "|    3.ISI SALDO                  6.KELUAR             |" << endl;
		cout << "|                                                      |" << endl;
		cout << "+======================================================+" << endl;
		cout << endl;
		cout << "pilihan : ";
		cin >> pilih;

		cout << endl;
		system("cls");
	}

	void displayMenu2() {

		cout << "+======================================================+" << endl;
		cout << "|                      MENU LAINYA                     |" << endl;
		cout << "|      Silahkan Pilih Transaksi Yang Anda Inginkan     |" << endl;
		cout << "|                                                      |" << endl;
		cout << "|    1.TELEKOMUNIKASI             4.AKUN PROFIL        |" << endl;
		cout << "|    2.BELI/BAYAR TAGIHAN         5.KEMBALI            |" << endl;
		cout << "|    3.TRANSPORTASI               6.KELUAR             |" << endl;
		cout << "|                                                      |" << endl;
		cout << "+======================================================+" << endl;
		cout << endl;
		cout << "pilihan : ";
		cin >> pilih;

	}

	void displayMenuTelekomunikasi() {
		system("cls");
		cout << "+======================================================+" << endl;
		cout << "|                  MENU TELEKOMUNIKASI                 |" << endl;
		cout << "|      Silahkan Pilih Transaksi Yang Anda Inginkan     |" << endl;
		cout << "|                                                      |" << endl;
		cout << "|    1.ISI PULSA                  3.KEMBALI            |" << endl;
		cout << "|    2.ISI PAKET DATA             4.KELUAR             |" << endl;
		cout << "|                                                      |" << endl;
		cout << "+======================================================+" << endl;
		cout << endl;
		cout << "pilihan : ";
		cin >> pilih;
	}

	void displayMenuBayar() {
		system("cls");
		cout << "+======================================================+" << endl;
		cout << "|                MENU BELI/BAYAR TAGIHAN               |" << endl;
		cout << "|      Silahkan Pilih Transaksi Yang Anda Inginkan     |" << endl;
		cout << "|                                                      |" << endl;
		cout << "|    1.INTERNET                   4.PAJAK              |" << endl;
		cout << "|    2.PENDIDIKAN                 5.KEMBALI            |" << endl;
		cout << "|    3.LISTRIK                    6.KELUAR             |" << endl;
		cout << "|                                                      |" << endl;
		cout << "+======================================================+" << endl;
		cout << endl;
		cout << "pilihan : ";
		cin >> pilih;
	}

	void displayMenuTransportasi() {

		system("cls");
		cout << "+======================================================+" << endl;
		cout << "|                   MENU TRANSPORTASI                  |" << endl;
		cout << "|      Silahkan Pilih Transaksi Yang Anda Inginkan     |" << endl;
		cout << "|                                                      |" << endl;
		cout << "|    1.KAPAL         4.TAKSI         7.BAHAN BAKAR     |" << endl;
		cout << "|    2.PARKIR        5.BIS           8.KEMBALI         |" << endl;
		cout << "|    3.KERETA        6.PESAWAT       9.KELUAR          |" << endl;
		cout << "|                                                      |" << endl;
		cout << "+======================================================+" << endl;
		cout << endl;
		cout << "pilihan : ";
		cin >> pilih;
		system("cls");
	}

	void displayMenuAkun() {
		system("cls");
		cout << "+======================================================+" << endl;
		cout << "|                   MENU AKUN PROFIL                   |" << endl;
		cout << "|      Silahkan Pilih Transaksi Yang Anda Inginkan     |" << endl;
		cout << "|                                                      |" << endl;
		cout << "|    1.INFORMASI AKUN             3.KEMBALI            |" << endl;
		cout << "|    2.GANTI PIN                  4.KELUAR             |" << endl;
		cout << "|                                                      |" << endl;
		cout << "+======================================================+" << endl;
		cout << "pilihan : ";
		cin >> pilih;
		system("cls");
	}

}
