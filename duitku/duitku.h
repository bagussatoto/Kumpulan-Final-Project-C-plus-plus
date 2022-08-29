#pragma once
#include <fstream>
#include <string>
namespace Duitku {
	long saldo = 0, pengeluaran = 0;
	int no_telfon, id;
	string gantipin = "123123", verifikasipin, kodepembayaran;

	void gantiPin() {
		fstream fin("pin.txt");
		fin << gantipin;
		fin.close();
	}

	void getPin() {
		string line;
		fstream fin("pin.txt");
		getline(fin, line);
		if (line != "") {
			gantipin = line;
		}
		fin.close();
	}

	void simpanSaldo() {
		fstream fin("saldo.txt");
		fin << saldo;
		fin.close();
	}

	void getSaldo() {
		string line;
		fstream fin("saldo.txt");
		getline(fin, line);
		if (line != "") {
			saldo = stol(line, nullptr, 10);
		}
		fin.close();
	}

	void infoSaldo() {
		cout << "+=================+" << endl;
		cout << "| INFORMASI SALDO |" << endl;
		cout << "+=================+" << endl;
	}

	void inputRek() {
		cout << "\nMasukkan Jumlah Transfer : Rp.";
		cin >> pengeluaran;
		if (pengeluaran > saldo)
		{
			cout << "\n>>  Maaf saldo anda tidak cukup <<" << endl;
			cout << "--------- Transaksi Gagal ---------\n";
		}
		else
		{
			saldo -= pengeluaran;
			cout << "\n>> Transfer senilai Rp. " << pengeluaran << "," << endl;
			cout << "--------- Transaksi Berhasil ---------\n";
		}
	}

	void transfer() {

	tf:

		cout << "+============+" << endl;
		cout << "| KIRIM UANG |" << endl;
		cout << "+============+" << endl;
		cout << endl;
		long no_rek;
		cout << "Masukkan nomor rekening : ";
		cin >> no_rek;
		//input nomor rekening masing-masing
		switch (no_rek)
		{
		case 12345:
		case 123456:
			inputRek();
			break;
		default:

			cout << "\nNomor rekening tidak di temukan" << endl;
			system("pause");
			system("cls");
			goto tf;
			break;
		}
		simpanSaldo();
	}

	void isiSaldo() {
		cout << "+===========+" << endl;
		cout << "| ISI SALDO |" << endl;
		cout << "+===========+" << endl;
		cout << endl;
		cout << "Jumlah Deposit Rp.";
		long jmlsetor=0;
		cin >> jmlsetor;
		saldo += jmlsetor;

		cout << "\n>> Deposit senilai Rp. " << jmlsetor << "," << endl;
		cout << "--------- Transaksi Berhasil ---------\n";
		simpanSaldo();
	}

	void tarikSaldo() {
		cout << "+=============+" << endl;
		cout << "| TARIK SALDO |" << endl;
		cout << "+=============+" << endl;
		cout << endl;
		cout << "Jumlah Penarikan : Rp.";
		cin >> pengeluaran;
		if (pengeluaran <= saldo) {
			saldo -= pengeluaran;
			cout << "\n>> Penarikan senilai Rp. " << pengeluaran << "," << endl;
			cout << "--------- Transaksi Berhasil ---------\n";
		}
		else {
			cout << "\n>>  Maaf saldo anda tidak cukup <<" << endl;
			cout << "--------- Transaksi Gagal ---------\n";
		}
		simpanSaldo();
	}

	void isiPulsa()
	{
	pulsa:

		system("cls");
		cout << "+=================+" << endl;
		cout << "| ISI ULANG PULSA |" << endl;
		cout << "+=================+" << endl;
		cout << endl;
		cout << "Masukkan nomor telepon : ";
		cin >> no_telfon;
		cout << endl;
		cout << "Pilih berapa pulsa yang ingin anda beli" << endl;
		cout << "1. Pulsa 5.000 = Rp.7.000" << endl;
		cout << "2. Pulsa 10.000 = Rp.12.000" << endl;
		cout << "3. Pulsa 15.000 = Rp.17.000" << endl;
		cout << "4. Pulsa 20.000 = Rp.21.000" << endl;
		cout << endl;
		cout << "pilihan : ";
		cin >> Menu::pilih;
		switch (Menu::pilih)
		{
			//isi pulsa 5k
		case 1:

			if (7000 > saldo)
			{
				cout << "\n>>  Maaf saldo anda tidak cukup <<" << endl;
				cout << "--------- Transaksi Gagal ---------\n";
			}
			else
			{
				saldo -= 7000;
				cout << "\n>> Pembelian pulsa senilai Rp. 7.000, <<" << endl;
				cout << "--------- Transaksi Berhasil ---------\n";
			}
			break;

			//isi pulsa 10k
		case 2:

			if (12000 > saldo)
			{
				cout << "\n>>  Maaf saldo anda tidak cukup <<" << endl;
				cout << "--------- Transaksi Gagal ---------\n";
			}
			else
			{
				saldo -= 12000;
				cout << "\n>> Pembelian pulsa senilai Rp. 12.000, <<" << endl;
				cout << "--------- Transaksi Berhasil ---------\n";
			}
			break;

			//isi pulsa 15k
		case 3:

			if (16000 > saldo)
			{
				cout << "\n>>  Maaf saldo anda tidak cukup <<" << endl;
				cout << "--------- Transaksi Gagal ---------\n";
			}
			else
			{
				saldo -= 16000;
				cout << "\n>> Pembelian pulsa senilai Rp. 16.000, <<" << endl;
				cout << "--------- Transaksi Berhasil ---------\n";
			}

			break;

			//isi pulsa 20k
		case 4:

			if (21000 > saldo)
			{
				cout << "\n>>  Maaf saldo anda tidak cukup <<" << endl;
				cout << "--------- Transaksi Gagal ---------\n";
			}
			else
			{
				saldo -= 21000;
				cout << "\n>> Pembelian pulsa senilai Rp. 21.000, <<" << endl;
				cout << "--------- Transaksi Berhasil ---------\n";
			}

			break;

		default:

			cout << "\nPilihan yang anda masukan salah, pilih lagi    !!" << endl;
			system("pause");
			goto pulsa;

			break;
		}
		simpanSaldo();
	}

	void isiPaketData()
	{
	paketdata:

		system("cls");
		cout << "+======================+" << endl;
		cout << "| ISI ULANG PAKET DATA |" << endl;
		cout << "+======================+" << endl;
		cout << endl;
		cout << "Masukkan nomor telepon : ";
		cin >> no_telfon;
		cout << endl;
		cout << "Pilih berapa paket yang ingin anda beli" << endl;
		cout << "1. Paket data 250MB berlaku 7 hari = Rp.10.500" << endl;
		cout << "2. Paket data 500MB berlaku 30 hari = Rp.13.500" << endl;
		cout << "3. Paket data 750MB berlaku 30 hari = Rp.17.900" << endl;
		cout << endl;
		cout << "pilihan : ";
		cin >> Menu::pilih;
		switch (Menu::pilih)
		{
			//Paket data 250MB berlaku 7 hari = Rp.10.500
		case 1:

			if (10500 > saldo)
			{
				cout << "\n>>  Maaf saldo anda tidak cukup <<" << endl;
				cout << "--------- Transaksi Gagal ---------\n";
			}
			else
			{
				saldo -= 105000;
				cout << "\n>> Pembelian pulsa senilai Rp. 10.500, <<" << endl;
				cout << "--------- Transaksi Berhasil ---------\n";
			}

			break;

			//2. Paket data 500MB berlaku 30 hari = Rp.13.500
		case 2:

			if (13.500 > saldo)
			{
				cout << "\n>>  Maaf saldo anda tidak cukup <<" << endl;
				cout << "--------- Transaksi Gagal ---------\n";
			}
			else
			{
				saldo -= 13500;
				cout << "\n>> Pembelian pulsa senilai Rp. 13.500, <<" << endl;
				cout << "--------- Transaksi Berhasil ---------\n";
			}

			break;

			//3. Paket data 750MB berlaku 30 hari = Rp.17.900
		case 3:

			if (17900 > saldo)
			{
				cout << "\n>>  Maaf saldo anda tidak cukup <<" << endl;
				cout << "--------- Transaksi Gagal ---------\n";
			}
			else
			{
				saldo -= 17900;
				cout << "\n>> Pembelian pulsa senilai Rp. 17.900, <<" << endl;
				cout << "--------- Transaksi Berhasil ---------\n";
			}

			break;

		default:

			cout << "\n>> Pilihan yang anda masukan salah, Pilih lagi   !!" << endl;
			system("pause");
			goto paketdata;

			break;
		}
		simpanSaldo();
	}

	void internet()
	{

	provider:

		system("cls");
		cout << "+========================+" << endl;
		cout << "| LIST PROVIDER INTERNET |" << endl;
		cout << "+========================+" << endl;
		cout << endl;
		cout << "1. Biznet Home" << endl;
		cout << "2. Indihome Speedy" << endl;
		cout << "3. XL HOME" << endl;
		cout << endl;
		cout << "pilihan : ";
		cin >> Menu::pilih;
		switch (Menu::pilih)
		{
			//1. Biznet home
		case 1:

			cout << "Masukkan ID pelanggan  :  ";
			cin >> id;
			if (id == 123456789)
			{
				if (saldo < 200000)
				{
					cout << "\n>>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "--------- Transaksi Gagal ---------\n";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 200.000,-" << endl;
					cout << "--------- Transaksi Berhasil ---------\n";
					saldo -= 200000;
				}
			}
			else if (id == 987654321)
			{
				if (saldo < 350000)
				{
					cout << "\n>>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "--------- Transaksi Gagal ---------\n";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 350.000,-" << endl;
					cout << "--------- Transaksi Berhasil ---------\n";
					saldo -= 350000;
				}
			}
			else
			{
				system("cls");
				cout << "\n---! Kode Pembayaran Salah !---";
				system("puase");
				goto provider;
			}
			simpanSaldo();
			break;

			//2. Indihome Speedy
		case 2:

			cout << "\n\nMasukkan ID pelanggan :  ";
			cin >> id;
			if (id == 123456789)
			{
				if (saldo < 200000)
				{
					cout << "\n>>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "--------- Transaksi Gagal ---------\n";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 200.000,-" << endl;
					cout << "--------- Transaksi Berhasil ---------\n";
					saldo -= 200000;
				}
			}
			else if (id == 987654321)
			{
				if (saldo < 350000)
				{
					cout << ">>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "--------- Transaksi Gagal ---------\n";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 350.000,-" << endl;
					cout << "--------- Transaksi Berhasil ---------\n";
					saldo -= 350000;
				}
			}
			else
			{
				system("cls");
				cout << "\n---! Kode Pembayaran Salah !---\n";
				goto provider;
			}
			simpanSaldo();
			break;

			//Xl home
		case 3:

			cout << "Masukkan ID pelanggan :  ";
			cin >> id;
			if (id == 123456789)
			{
				if (saldo < 200000)
				{
					cout << ">>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "--------- Transaksi Gagal ---------\n";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 200.000,-" << endl;
					cout << "--------- Transaksi Berhasil ---------\n";
					saldo -= 200000;
				}
			}
			else if (id == 987654321)
			{
				if (saldo < 350000)
				{
					cout << ">>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "--------- Transaksi Gagal ---------\n";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 350.000,-" << endl;
					cout << "--------- Transaksi Berhasil ---------\n";
					saldo -= 350000;
				}
			}
			else
			{
				system("cls");
				cout << "\n---! Kode Pembayaran Salah !---\n";
				goto provider;
			}
			simpanSaldo();
			break;

		default:

			cout << "\n>> Pilihan yang anda masukan salah, Pilih lagi   !!" << endl;
			system("pause");
			goto provider;
			break;
		}
	}

	void pendidikan()
	{

	pendidikan:

		int nisn;
		system("cls");
		cout << "+==============+" << endl;
		cout << "| LIST SEKOLAH |" << endl;
		cout << "+==============+" << endl;
		cout << endl;
		cout << "1. SMAN 1 Yokyakarta" << endl;
		cout << "2. SMAN 2 Yokyakarta" << endl;
		cout << "3. SMAN 3 Yokyakarta" << endl;
		cout << endl;
		cout << "pilihan : ";
		cin >> Menu::pilih;
		system("cls");
		switch (Menu::pilih)
		{
			//1. SMAN 1 Yokyakarta
		case 1:

			cout << "Masukkan NISN" << endl;
			cin >> nisn;
			if (nisn == 123456789)
			{
				if (saldo < 200000)
				{
					cout << "\n>>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "--------- Transaksi Gagal ---------\n";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 200.000,-" << endl;
					cout << "--------- Transaksi Berhasil ---------\n";
					saldo -= 200000;
				}
			}
			else if (nisn == 987654321)
			{
				if (saldo < 350000)
				{
					cout << "\n>>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "--------- Transaksi Gagal ---------\n";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 350.000,-" << endl;
					cout << "--------- Transaksi Berhasil ---------\n";
					saldo -= 350000;
				}
			}
			else
			{
				system("cls");
				cout << "\n---! Kode Pembayaran Salah !---";
				goto pendidikan;
			}
			simpanSaldo();
			break;


			//2. SMAN 2 Yokyakarta
		case 2:

			cout << "Masukkan NISN" << endl;
			cin >> nisn;
			if (nisn == 123456789)
			{
				if (saldo < 200000)
				{
					cout << "\n>>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "--------- Transaksi Gagal ---------\n";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 200.000,-" << endl;
					cout << "--------- Transaksi Berhasil ---------\n";
					saldo -= 200000;
				}
			}
			else if (nisn == 987654321)
			{
				if (saldo < 350000)
				{
					cout << "\n>>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "--------- Transaksi Gagal ---------\n";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 350.000,-" << endl;
					cout << "--------- Transaksi Berhasil ---------\n";
					saldo -= 350000;
				}
			}
			else
			{
				system("cls");
				cout << "\n---! Kode Pembayaran Salah !---";
				goto pendidikan;
			}
			simpanSaldo();
			break;

			//3. SMAN 3 Yokyakarta
		case 3:

			cout << "Masukkan NISN" << endl;
			cin >> nisn;
			if (nisn == 123456789)
			{
				if (saldo < 200000)
				{
					cout << "\n>>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "--------- Transaksi Gagal ---------\n";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 200.000,-" << endl;
					cout << "--------- Transaksi Berhasil ---------\n";
					saldo -= 200000;
				}
			}
			else if (nisn == 987654321)
			{
				if (saldo < 350000)
				{
					cout << "\n>>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "--------- Transaksi Gagal ---------\n";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 350.000,-" << endl;
					cout << "--------- Transaksi Berhasil ---------\n";
					saldo -= 350000;
				}
			}
			else
			{
				system("cls");
				cout << "\n---! Kode Pembayaran Salah !---";
				goto pendidikan;
			}
			simpanSaldo();
			break;

		default:

			cout << "\n>> Pilihan yang anda masukan salah, Pilih lagi   !!" << endl;
			system("pause");
			goto pendidikan;

			break;
		}
	}

	void listrik()
	{
	listrik:
		system("cls");
		cout << "+=========+" << endl;
		cout << "| LISTRIK |" << endl;
		cout << "+=========+" << endl;
		cout << endl;
		cout << "1. PLN Postpaid" << endl;
		cout << "2. PLN Non Tagihan Listrik" << endl;
		cout << "3. PLN Prepaid" << endl;
		cout << endl;
		cout << "pilihan : ";
		cin >> Menu::pilih;
		system("cls");
		switch (Menu::pilih)
		{
			//1. PLN Postpaid
		case 1:

			cout << "Masukkan ID Pelanggan" << endl;
			cin >> id;
			if (id == 123456789)
			{
				if (saldo < 200000)
				{
					cout << ">>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "--------- Transaksi Gagal ---------\n";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 200.000,-" << endl;
					cout << "--------- Transaksi Berhasil ---------\n";
					saldo -= 200000;
				}
			}
			else if (id == 987654321)
			{
				if (saldo < 350000)
				{
					cout << ">>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "--------- Transaksi Gagal ---------\n";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 350.000,-" << endl;
					cout << "--------- Transaksi Berhasil ---------\n";
					saldo -= 350000;
				}
			}
			else
			{
				system("cls");
				cout << "\n---! Kode Pembayaran Salah !---\n";
				goto listrik;
			}
			break;
			simpanSaldo();

			//2. PLN Non Tagihan Listrik
		case 2:

			cout << "Masukkan ID Pelanggan" << endl;
			cin >> id;
			if (id == 123456789)
			{
				if (saldo < 200000)
				{
					cout << ">>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "--------- Transaksi Gagal ---------\n";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 200.000,-" << endl;
					cout << "--------- Transaksi Berhasil ---------\n";
					saldo -= 200000;
				}
			}
			else if (id == 987654321)
			{
				if (saldo < 350000)
				{
					cout << ">>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "--------- Transaksi Gagal ---------\n";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 350.000,-" << endl;
					cout << "--------- Transaksi Berhasil ---------\n";
					saldo -= 350000;
				}
			}
			else
			{
				system("cls");
				cout << "\n---! Kode Pembayaran Salah !---\n";
				goto listrik;
			}
			break;
			simpanSaldo();

			//3. PLN Prepaid
		case 3:

			cout << "Masukkan ID Pelanggan" << endl;
			cin >> id;
			if (id == 123456789)
			{
				if (saldo < 200000)
				{
					cout << ">>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "--------- Transaksi Gagal ---------\n";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 200.000,-" << endl;
					cout << "--------- Transaksi Berhasil ---------\n";
					saldo -= 200000;
				}
			}
			else if (id == 987654321)
			{
				if (saldo < 350000)
				{
					cout << ">>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "--------- Transaksi Gagal ---------\n";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 350.000,-" << endl;
					cout << "--------- Transaksi Berhasil ---------\n";
					saldo -= 350000;
				}
			}
			else
			{
				system("cls");
				cout << "\n---! Kode Pembayaran Salah !---\n";
				goto listrik;
			}
			break;
			simpanSaldo();

		default:

			cout << "\n>> Pilihan yang anda masukan salah, Pilih lagi   !!" << endl;
			system("pause");
			goto listrik;

			break;
		}
	}

	void pajak() {

	pajak:

		system("cls");
		cout << "+===================+" << endl;
		cout << "| PENERIMAAN NEGARA |" << endl;
		cout << "+===================+" << endl;
		cout << endl;
		cout << "1. Penerimaan Negara Bukan Pajak" << endl;
		cout << "2. Pajak Online" << endl;
		cout << "3. Direktorat Jendral Bea dan Cukai" << endl;
		cout << endl;
		cout << "pilihan : ";
		cin >> Menu::pilih;
		system("cls");
		switch (Menu::pilih)
		{
			//1. Penerimaan Negara Bukan Pajak
		case 1:

			cout << "Masukkan Nomer Pajak" << endl;
			cin >> id;
			if (id == 123456789)
			{
				if (saldo < 200000)
				{
					cout << ">>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "\n--------- Transaksi Gagal ---------";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 200.000,-";
					cout << "\n--------- Transaksi Berhasil ---------";
					saldo -= 200000;
				}
			}
			else if (id == 987654321)
			{
				if (saldo < 350000)
				{
					cout << ">>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "\n--------- Transaksi Gagal ---------";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 350.000,-";
					cout << "\n--------- Transaksi Berhasil ---------";
					saldo -= 350000;
				}
			}
			else
			{
				system("cls");
				cout << "---! Kode Pembayaran Salah !---\n";
				goto pajak;
			}
			simpanSaldo();
			break;

			//2. Pajak Online
		case 2:

			cout << "Masukkan Nomer Pajak" << endl;
			cin >> id;
			if (id == 123456789)
			{
				if (saldo < 200000)
				{
					cout << ">>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "\n--------- Transaksi Gagal ---------";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 200.000,-";
					cout << "\n--------- Transaksi Berhasil ---------";
					saldo -= 200000;
				}
			}
			else if (id == 987654321)
			{
				if (saldo < 350000)
				{
					cout << ">>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "\n--------- Transaksi Gagal ---------";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 350.000,-";
					cout << "\n--------- Transaksi Berhasil ---------";
					saldo -= 350000;
				}
			}
			else
			{
				system("cls");
				cout << "---! Kode Pembayaran Salah !---\n";
				goto pajak;
			}
			simpanSaldo();
			break;

			//3.  Direktorat Jendral Bea dan Cukai
		case 3:

			cout << "Masukkan Nomer Pajak" << endl;
			cin >> id;
			if (id == 123456789)
			{
				if (saldo < 200000)
				{
					cout << ">>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "\n--------- Transaksi Gagal ---------";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 200.000,-";
					cout << "\n--------- Transaksi Berhasil ---------";
					saldo -= 200000;
				}
			}
			else if (id == 987654321)
			{
				if (saldo < 350000)
				{
					cout << ">>  Maaf saldo anda tidak cukup <<" << endl;
					cout << "\n--------- Transaksi Gagal ---------";
				}
				else
				{
					cout << "\n>> Pembayaran senilai Rp. 350.000,-";
					cout << "\n--------- Transaksi Berhasil ---------";
					saldo -= 350000;
				}
			}
			else
			{
				system("cls");
				cout << "---! Kode Pembayaran Salah !---\n";
				goto pajak;
			}
			simpanSaldo();
			break;

		default:

			cout << "Pilihan yang anda masukan salah" << endl;
			cout << "Pilih lagi!!" << endl;
			goto pajak;

			break;
		}
	}

	void kapal() {
	kapal:

		cout << "\nMasukan Kode Pembayaran : ";
		cin >> kodepembayaran;

		if (kodepembayaran == "1a2b3c")
		{
			if (saldo < 150000)
			{
				cout << "Saldo tidak mencukupi\n";
			}
			else
			{
				cout << "\n>> Pembayaran senilai Rp. 150.000,-";
				cout << "\n--------- Transaksi Berhasil ---------";
				saldo -= 150000;
			}
		}
		else if (kodepembayaran == "4d5e6f")
		{
			if (saldo < 200000)
			{
				cout << "Saldo tidak mencukupi\n";

			}
			else
			{
				cout << "\n>> Pembayaran senilai Rp. 200.000,-";
				cout << "\n--------- Transaksi Berhasil ---------";
				saldo -= 200000;
			}
		}
		else if (kodepembayaran == "7g8h9i")
		{
			if (saldo < 250000)
			{
				cout << "Saldo tidak mencukupi\n";

			}
			else
			{
				cout << "\n>> Pembayaran senilai Rp. 250.000,-";
				cout << "\n--------- Transaksi Berhasil ---------";
				saldo -= 250000;
			}
		}
		else
		{
			system("cls");
			cout << "---! Kode Pembayaran Salah !---\n";
			goto kapal;
		}
		simpanSaldo();

	}

	void parkir() {
	parkir:

		cout << "\nMasukan Kode Pembayaran : ";
		cin >> kodepembayaran;

		if (kodepembayaran == "1a2b3c")
		{
			if (saldo < 2500)
			{
				cout << "Saldo tidak mencukupi\n";

			}
			else
			{
				cout << "\n>> Pembayaran senilai Rp. 2500,-";
				cout << "\n--------- Transaksi Berhasil ---------";
				saldo -= 2500;
			}
		}
		else if (kodepembayaran == "4d5e6f")
		{
			if (saldo < 5000)
			{
				cout << "Saldo tidak mencukupi\n";

			}
			else
			{
				cout << "\n>> Pembayaran senilai Rp. 5000,-";
				cout << "\n--------- Transaksi Berhasil ---------";
				saldo -= 5000;
			}
		}
		else if (kodepembayaran == "7g8h9i")
		{
			if (saldo < 6000)
			{
				cout << "Saldo tidak mencukupi\n";

			}
			else
			{
				cout << "\n>> Pembayaran senilai Rp. 6000,-";
				cout << "\n--------- Transaksi Berhasil ---------";
				saldo -= 6000;
			}
		}
		else
		{
			system("cls");
			cout << "---! Kode Pembayaran Salah !---\n";
			goto parkir;
		}
		simpanSaldo();
	}

	void kereta() {
	kereta:

		cout << "\nMasukan Kode Pembayaran : ";
		cin >> kodepembayaran;

		if (kodepembayaran == "1a2b3c")
		{
			if (saldo < 150000)
			{
				cout << "Saldo tidak mencukupi\n";
			}
			else
			{
				cout << "\n>> Pembayaran senilai Rp. 150.000,-";
				cout << "\n--------- Transaksi Berhasil ---------";
				saldo -= 150000;
			}
		}
		else if (kodepembayaran == "4d5e6f")
		{
			if (saldo < 200000)
			{
				cout << "Saldo tidak mencukupi\n";

			}
			else
			{
				cout << "\n>> Pembayaran senilai Rp. 200.000,-";
				cout << "\n--------- Transaksi Berhasil ---------";
				saldo -= 200000;
			}
		}
		else if (kodepembayaran == "7g8h9i")
		{
			if (saldo < 250000)
			{
				cout << "Saldo tidak mencukupi\n";
				
			}
			else
			{
				cout << "\n>> Pembayaran senilai Rp. 250.000,-";
				cout << "\n--------- Transaksi Berhasil ---------";
				saldo -= 250000;
			}
		}
		else
		{
			system("cls");
			cout << "---! Kode Pembayaran Salah !---\n";
			goto kereta;
		}
		simpanSaldo();
	}

	void taksi() {
	taksi:
		cout << "\nMasukan Kode Pembayaran : ";
		cin >> kodepembayaran;

		if (kodepembayaran == "1a2b3c")
		{
			if (saldo < 10000)
			{
				cout << "Saldo tidak mencukupi\n";
			}
			else
			{
				cout << "\n>> Pembayaran senilai Rp. 10.000,-";
				cout << "\n--------- Transaksi Berhasil ---------";
				saldo -= 10000;
			}
		}
		else if (kodepembayaran == "4d5e6f")
		{
			if (saldo < 15000)
			{
				cout << "Saldo tidak mencukupi\n";
			}
			else
			{
				cout << "\n>> Pembayaran senilai Rp. 15.000,-";
				cout << "\n--------- Transaksi Berhasil ---------";
				saldo -= 15000;
			}
		}
		else if (kodepembayaran == "7g8h9i")
		{
			if (saldo < 20000)
			{
				cout << "Saldo tidak mencukupi\n";
			}
			else
			{
				cout << "\n>> Pembayaran senilai Rp. 20.000,-";
				cout << "\n--------- Transaksi Berhasil ---------";
				saldo -= 20000;
			}
		}
		else
		{
			system("cls");
			cout << "---! Kode Pembayaran Salah !---\n";
			goto taksi;
		}
		simpanSaldo();
	}

	void bis() {
	bis:

		cout << "\nMasukan Kode Pembayaran : ";
		cin >> kodepembayaran;

		if (kodepembayaran == "1a2b3c")
		{
			if (saldo < 100000)
			{
				cout << "Saldo tidak mencukupi\n";

			}
			else
			{
				cout << "\n>> Pembayaran senilai Rp. 100.000,-";
				cout << "\n--------- Transaksi Berhasil ---------";
				saldo -= 100000;
			}
		}
		else if (kodepembayaran == "4d5e6f")
		{
			if (saldo < 125000)
			{
				cout << "Saldo tidak mencukupi\n";
			}
			else
			{
				cout << "\n>> Pembayaran senilai Rp. 125.000,-";
				cout << "\n--------- Transaksi Berhasil ---------";
				saldo -= 125000;
			}
		}
		else if (kodepembayaran == "7g8h9i")
		{
			if (saldo < 150000)
			{
				cout << "Saldo tidak mencukupi\n";
			}
			else
			{
				cout << "\n>> Pembayaran senilai Rp. 150.000,-";
				cout << "\n--------- Transaksi Berhasil ---------";
				saldo -= 150000;
			}
		}
		else
		{
			system("cls");
			cout << "---! Kode Pembayaran Salah !---\n";
			goto bis;
		}
		simpanSaldo();
	}

	void pesawat() {

	pesawat:

		cout << "\nMasukan Kode Pembayaran : ";
		cin >> kodepembayaran;

		if (kodepembayaran == "1a2b3c")
		{
			if (saldo < 1000000)
			{
				cout << "Saldo tidak mencukupi\n";

			}
			else
			{
				cout << "\n>> Pembayaran senilai Rp. 1.000.000,-";
				cout << "\n--------- Transaksi Berhasil ---------";
				saldo -= 1000000;
			}
		}
		else if (kodepembayaran == "4d5e6f")
		{
			if (saldo < 1500000)
			{
				cout << "Saldo tidak mencukupi\n";

			}
			else
			{
				cout << "\n>> Pembayaran senilai Rp. 1.500.000,-";
				cout << "\n--------- Transaksi Berhasil ---------";
				saldo -= 1500000;
			}
		}
		else if (kodepembayaran == "7g8h9i")
		{
			if (saldo < 2000000)
			{
				cout << "Saldo tidak mencukupi\n";

			}
			else
			{
				cout << "\n>> Pembayaran senilai Rp. 2000.000,-";
				cout << "\n--------- Transaksi Berhasil ---------";
				saldo -= 2000000;
			}
		}
		else
		{
			system("cls");
			cout << "---! Kode Pembayaran Salah !---\n";
			goto pesawat;
		}
		simpanSaldo();
	}

	void bahanbakar() {

	bahanbakar:

		cout << "\nMasukan Kode Pembayaran : ";
		cin >> kodepembayaran;

		if (kodepembayaran == "1a2b3c")
		{
			if (saldo < 10000)
			{
				cout << "Saldo tidak mencukupi\n";
				
			}
			else
			{
				cout << "\n>> Pembayaran senilai Rp. 10.000,-";
				cout << "\n--------- Transaksi Berhasil ---------";
				saldo -= 10000;
			}
		}
		else if (kodepembayaran == "4d5e6f")
		{
			if (saldo < 20000)
			{
				cout << "Saldo tidak mencukupi\n";
				
			}
			else
			{
				cout << "\n>> Pembayaran senilai Rp. 20.000,-";
				cout << "\n--------- Transaksi Berhasil ---------";
				saldo -= 20000;
			}
		}
		else if (kodepembayaran == "7g8h9i")
		{
			if (saldo < 25000)
			{
				cout << "Saldo tidak mencukupi\n";
				
			}
			else
			{
				cout << "\n>> Pembayaran senilai Rp. 25.000,-";
				cout << "\n--------- Transaksi Berhasil ---------";
				saldo -= 25000;
			}
		}
		else
		{
			system("cls");
			cout << "---! Kode Pembayaran Salah !---\n";
			goto bahanbakar;
		}
		simpanSaldo();
	}
	
	void akun() {
		cout << "----- INFORMASI AKUN -----\n\n";
		cout << ">> Username : sihab\n";
		cout << ">> PIN      : " << gantipin << endl;
	}

	bool akunGantipin() {
		cout << "\nMasukan PIN Lama : ";
		cin >> verifikasipin;
		if (verifikasipin == gantipin)
		{
			cout << "Masukan PIN Baru : ";
			cin >> gantipin;
			cout << "\n--------- Ganti PIN Berhasil ---------";
			gantiPin();
			return true;
		}
		else
		{
			system("cls");
			cout << "---! PIN Salah !---\n";
			return false;
		}
	}
}
