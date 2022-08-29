#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
#include "login.h"
#include "menu.h"
#include "duitku.h"

int main() {
	Duitku::getPin();
login:
	if (!login(Duitku::gantipin)) {
		goto login;
	}

menu:
	Duitku::getSaldo();
	Menu::display();
	switch (Menu::pilih) {
	case 1: // Informasi Saldo
		Duitku::infoSaldo();
		break;
		
	case 2: // Kirim  duitku
		Duitku::transfer();
		break;

	case 3: // isi saldo
		Duitku::isiSaldo();
		break;

	case 4: // tarik saldo
		Duitku::tarikSaldo();
		break;

	case 5: // menu lainya
	menu_2:
		Menu::displayMenu2();
		switch (Menu::pilih) {
		case 1: // telekomunikasi
		telekomunikasi:

			Menu::displayMenuTelekomunikasi();
			switch (Menu::pilih) {
			case 1: //isi pulsa
				Duitku::isiPulsa();
				break;

			case 2: //isi paket data
				Duitku::isiPaketData();
				break;

			case 3: //kembali
				system("cls");
				goto menu_2;
				break;

			case 4: //keluar
				exit(1);
				break;

			default:
				cout << "\n>> Pilihan yang anda masukan salah, Pilih lagi   !!" << endl;
				system("pause");
				goto telekomunikasi;
				break;
			}
			break;

		case 2: // beli/bayar
			beli:
			Menu::displayMenuBayar();
			switch (Menu::pilih)
			{
			case 1: //internet
				Duitku::internet();
				break;
			case 2: //pendidikan
				Duitku::pendidikan();
				break;
			case 3: //listrik
				Duitku::listrik();
				break;
			case 4: //pajak
				Duitku::pajak();
				break;
			case 5: //kembali
				system("cls");
				goto menu_2;
				break;
			case 6: //keluar
				exit(1);
				break;
			default:
				cout << "\n>> Pilihan yang anda masukan salah, Pilih lagi   !!" << endl;
				system("pause");
				goto beli;
				break;
			}
			break;

		case 3: // transportasi
		transportasi:
			Menu::displayMenuTransportasi();
			switch (Menu::pilih) {
			case 1: //kapal
				Duitku::kapal();
				break;
			case 2: //parkir
				Duitku::parkir();
				break;
			case 3: //kereta
				Duitku::kereta();
				break;
			case 4: //taksi
				Duitku::taksi();
				break;
			case 5: //bis
				Duitku::bis();
				break;
			case 6: //pesawat
				Duitku::pesawat();
				break;
			case 7: //bahanbakar
				Duitku::bahanbakar();
				break;
			case 8: //kembali
				system("cls");
				goto menu_2;
				break;
			case 9: //keluar
				system("cls");
				exit(1);
				break;
			default:
				cout << "\n>> Pilihan yang anda masukan salah, Pilih lagi   !!" << endl;
				system("pause");
				goto transportasi;
				break;
			}
			break;

		case 4: // akun profil
		akunProfil:
			Menu::displayMenuAkun();
			switch (Menu::pilih)
			{
			case 1: // info akun
			infakun:
				Duitku::akun();

				cout << endl;
				cout << "Kembali? (y/n) ";
				cin >> Menu::lanjut;
				if (Menu::lanjut == 'y')
				{
					system("cls");
					goto akunProfil;
				}
				else if (Menu::lanjut == 'n')
				{
					system("cls");
					exit(1);
				}
				else
				{
					cout << "Pilih (y/n)!!";
					system("cls");
					goto infakun;
				}
				break;
			case 2: // ganti pin
			gntpin:
				cout << "\nMasukan PIN Lama : ";
				cin >> Duitku::verifikasipin;
				if (Duitku::akunGantipin()) {
				gntpin2:
					cout << endl;
					cout << "Kembali? (y/n) ";
					cin >> Menu::lanjut;
					if (Menu::lanjut == 'y')
					{
						system("cls");
						goto akunProfil;
					}
					else if (Menu::lanjut == 'n')
					{
						system("cls");
						exit(1);
					}
					else
					{
						cout << "Pilih (y/n)!!";
						goto gntpin2;
					}
				}
				else {

					system("cls");
					cout << "---! PIN Salah !---\n";
					goto gntpin;
				}
				break;
			case 3: // kembali
				system("cls");
				goto menu_2;
				break;
			case 4: // keluar
				exit(1);
				break;
			default:
				cout << "\n>> Pilihan yang anda masukan salah, Pilih lagi   !!" << endl;
				system("pause");
				goto akunProfil;
				break;
			}
			break;

		case 5: // kembali
			system("cls");
			goto menu;
			break;
		case 6: // keluar
			exit(1);
			break;
		default:
			cout << "\n>> Pilihan yang anda masukan salah, Pilih lagi   !!" << endl;
			system("pause");
			goto menu;
		}
		break;

	case 6: // keluar
		exit(1);
		break;
	default:
		cout << "\n>> Pilihan yang anda masukan salah, Pilih lagi   !!" << endl;
		system("pause");
		goto menu;
		break;
	}

transaksi_lagi:
	cout << "\n>> Sisa Saldo saat ini Rp." << Duitku::saldo << endl;
	cout << endl;
	cout << "Kembali? (y/n) ";
	cin >> Menu::lanjut;

	switch (Menu::lanjut) {
	case 'Y':
	case 'y':
		system("cls");
		goto menu;
		break;
	case 'n':
	case 'N':
		exit(1);
		break;
	default:

		cout << "Pilih (y/n)!!";
		goto transaksi_lagi;
		break;
	}

	system("pause>0");
	return 0;
}
