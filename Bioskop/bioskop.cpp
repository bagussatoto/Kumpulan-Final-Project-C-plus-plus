#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>


using namespace std;

void setcolor(unsigned short color)
{
	HANDLE vatrick = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(vatrick, color);
}

void cursorposition(short x, short y)
{
	HANDLE vatrick = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(vatrick, { x, y });
}

int main()
{
	setcolor(14);
	cout << "==============================================================" << endl;
	cout << "||                  BIOSKUO INDONESIA                        ||" << endl;
	cout << "==============================================================" << endl;
	cout << endl << endl;

	// daftar film
	setcolor(6);
	cout << "==============================================================" << endl;
	cout << "|                        DAFTAR FILM                         |" << endl;
	cout << "|       +--------------------------------------------+       |" << endl;
	cout << "|       |    1. Captain Marvel                       |       |" << endl;
	cout << "|       |    2. Avengers Endgame                     |       |" << endl;
	cout << "|       |    3. The Maze Runner                      |       |" << endl;
	cout << "|       |    4. Thor Ragnarok                        |       |" << endl;
	cout << "|       |    5. Iron Man                             |       |" << endl;
	cout << "|       |    6. Guardians Of The Galaxy              |       |" << endl;
	cout << "|       +--------------------------------------------+       |" << endl;
	cout << "==============================================================" << endl;


	int PilihanFilm, HariTiket, JumlahTiket;
	int TiketBioskop = 30;
	int x = 30.000;
	int y = 40.000;
	string Film1 = "Captain Marvel", Film2 = "Avengers Endgame", Film3 = "The Maze Runner", Film4 = "Thor Ragnarok", Film5 = "Iron Man", Film6 = "Guardians Of The Galaxy";


	// inputan
	setcolor(9);
	cout << " MASUKAN PILIHAN ANDA < 1-5 >   :";
	cin >> PilihanFilm;
	
	if (PilihanFilm == 1) {
		cout << "  Film Yang Akan DITONTON YAITU : " << Film1 << endl;
	}
	else if (PilihanFilm == 2) {
		cout << "  Film Yang Akan DITONTON YAITU : " << Film2 << endl;
	}
	else if (PilihanFilm == 3) {
		cout << "  Film Yang Akan DITONTON YAITU : " << Film3 << endl;
	}
	else if (PilihanFilm == 4) {
		cout << "  Film Yang Akan DITONTON YAITU : " << Film4 << endl;
	}
	else if (PilihanFilm == 5) {
		cout << "  Film Yang Akan DITONTON YAITU : " << Film5 << endl;
	}
	else if (PilihanFilm == 6) {
		cout << "  Film Yang Akan DITONTON YAITU : " << Film6 << endl;
	}
	
	if (PilihanFilm == 0) {
		cout << "PILIHAN FILM TIDAK TERSEDIA, SILAHKAN PILIH ANGKA YANG SESUAI!!!" << endl;
	}

	// perulangan

	for (int i = 0; i < 100; i++)
	{
		if (PilihanFilm <= 6) {
			break;
		}

		else {
			setcolor(11);
			cout << "==============================================================" << endl;
			setcolor(5);
			cout << "PILIHAN FILM TIDAK TERSEDIA, SILAHKAN PILIH ANGKA YANG SESUAI!!!" << endl;
		}

		setcolor(11);
		cout << "  MASUKAN PILIHAN ANDA < 1-5 >      :";
		cin >> PilihanFilm;
		if (PilihanFilm == 1) {
			cout << "  Film Yang Akan DITONTON YAITU : " << Film1 << endl;
		}
		else if (PilihanFilm == 2) {
			cout << "  Film Yang Akan DITONTON YAITU : " << Film2 << endl;
		}
		else if (PilihanFilm == 3) {
			cout << "  Film Yang Akan DITONTON YAITU : " << Film3 << endl;
		}
		else if (PilihanFilm == 4) {
			cout << "  Film Yang Akan DITONTON YAITU : " << Film4 << endl;
		}
		else if (PilihanFilm == 5) {
			cout << "  Film Yang Akan DITONTON YAITU : " << Film5 << endl;
		}
	}


	//output
	setcolor(11);
	cout << "==============================================================" << endl;
	cout << "                        PEMBELIAN TIKET                       " << endl;
	cout << "==============================================================" << endl;
	cout << "Keterangan Harga Tiket               :" << endl;
	cout << "1. Tiket Hari Senin-Jum'at           : Rp. 30.000" << endl;
	cout << "2. Tiket Hari Sabtu-Minggu           : Rp. 40.000" << endl;
	cout << "==============================================================" << endl;
	cout << "PEMBELIAN TIKET" << endl;
	cout << "Jenis Tiket < 1-2 >                  :";
	cin >> HariTiket;
	cout << "Jumlah Tiket Yang Di Pesan           :";
	cin >> JumlahTiket;

	setcolor(11);
	cout << "==============================================================" << endl;


	// pengkondisian


	for (int i = 0; i < 100; i++)
	{
		if (HariTiket <= 2 && JumlahTiket <= 30)
		{
			break;
		}
		else if (HariTiket > 2) {
			setcolor(5);
			cout << "JENIS TIKET YANG ANDA PILIH TIDAK TERSEDIA. MOHON ULANGI LAGI!!!" << endl;
		}
		else if (JumlahTiket > 30) {
			setcolor(13);
			cout << "==============================================================" << endl;
			setcolor(5);
			cout << "!! TIKET TIDAK MENCUKUPI SILAHKAN ULANGI !!" << endl;
		}
		setcolor(14);
		cout << "PEMBELIAN TIKET" << endl;
		cout << "Jenis Tiket < 1-2 >                  :";
		cin >> HariTiket;
		cout << "Jumlah Tiket Yang Di Pesan           :";
		cin >> JumlahTiket;
	}

	if (HariTiket == 1)
	{
		cout << "Jenis Tiket                          :Hari Senin-Jum'at" << endl;
	}
	else if (HariTiket == 2)
	{
		cout << "Jenis Tiket                          :Hari Sabtu-Minggu" << endl;
	}

	cout << "TIKET SISA                           :" << TiketBioskop - JumlahTiket << endl;
	cout << "Jumlah Tiket Yang Di Pesan           :" << JumlahTiket << endl;
	cout << "==============================================================" << endl;
	cout << "JUMLAH PEMBAYARAN                    : Rp.";
	if (HariTiket == 1)
	{
		cout << JumlahTiket * x << ".000" << endl;
	}

	else if (HariTiket == 2)
	{
		cout << JumlahTiket * y << ".000" << endl;
	}
	else {
		cout << "!! PEMBAYARAN TIDAK VALID !!" << endl;
	}

	cout << "==============================================================" << endl;
	cout << endl << endl;


	system("pause");

	return 0;
	
}