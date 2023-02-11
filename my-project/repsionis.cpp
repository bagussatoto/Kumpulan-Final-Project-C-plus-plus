#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
using namespace std;
main ()
{
  char resepsionis[30], customer[30], alamat[50];
  int kamar, no_kamar, harga_kamar, ranjang;
  int total, lama, um, kurang;
  float diskon;
  string jwb, id_customer, id_resepsionis, jk, hp, checkin, checkout, fixkam;
awal:
  cout <<
    "\n\t\t             ========================================================";
  cout <<
    "\n\t\t           ==============================================================";
  cout <<
    "\n\t\t        ====================================================================";
  cout <<
    "\n\t\t      =========================================================================";
  cout <<
    "\n\t\t   ==============================================================================";
  cout <<
    "\n\t\t                   SELAMAT DATANG DI HOTEL PUYER BINTANG TUJUH                  ";
  cout <<
    "\n\n\t\t               JL. Kita Masih Panjang, no 69 telp private number              ";
  cout <<
    "\n\t\t                 Legok Hangseur, Lembur Kita, Sok tanya mbah googel             ";
  cout <<
    "\n\t\t=================================================================================";
  cout <<
    "\n\t\t=================================================================================";

  cout << "\n\n\n\n\t\tSilahkan Isi Form Berikut ini";
  cout <<
    "\n\t\t=================================================================================";
  cout << endl;
  cout << "\t\tNama Resepsionis Yang Melayani : ";
  gets (resepsionis);
  cout << "\t\tID Resepsionis                 : ";
  cin >> id_resepsionis;
  cout << "\t\tNama Pemesan                   : ";
  cin >> customer;
  cout << "\t\tID Pemesan                     : ";
  cin >> id_customer;
  cout << "\t\tJenis Kelamin [L/P]            : ";
  cin >> jk;
  cout << "\t\tNomor Telepon/HP               : ";
  cin >> hp;
  cout << "\t\tAlamat                         : ";
  cin >> alamat;
  cout <<
    "\t\t=================================================================================";

  cout << "\n\n\t\tSilahkan Pilih Tipe Kamar Yang Anda Inginkan";
  cout <<
    "\n\t\t=================================================================================";
  cout << "\n\t\t1. Standart";
  cout << "\n\t\t2. Premium";
  cout << "\n\t\t3. Deluxe";
  cout << "\n\t\t4. Suite";
  cout << "\n\t\t5. Presidential";
  cout <<
    "\n\t\t=================================================================================";
  cout << "\n\t\tMasukan Pilihan : ";
  cin >> kamar;

  cout << "\n\n\t\tSilahkan Pilih Tipe Bed Yang Anda Inginkan";
  cout <<
    "\n\t\t=================================================================================";
  cout << "\n\t\t1. Single";
  cout << "\n\t\t2. Double";
  cout <<
    "\n\t\t=================================================================================";
  cout << "\n\t\tMasukan Pilihan : ";
  cin >> ranjang;
  cout << endl;

  if (kamar == 1 && ranjang == 1)
    {
      cout << "\n\t\tAnda Memilih Kamar Tipe Standart Dengan Ranjang Single";
      fixkam = "Standart Dengan Single Bed";
      harga_kamar = 200000;
    }
  else if (kamar == 1 && ranjang == 2)
    {
      cout << "\n\t\tAnda Memilih Kamar Tipe Standart Dengan Ranjang Double";
      fixkam = "Standart Dengan Double Bed";
      harga_kamar = 250000;
    }
  else if (kamar == 2 && ranjang == 1)
    {
      cout << "\n\t\tAnda Memilih Kamar Tipe Premium Dengan Ranjang single";
      fixkam = "Premium Dengan Single Bed";
      harga_kamar = 400000;
    }
  else if (kamar == 2 && ranjang == 2)
    {
      cout << "\n\t\tAnda Memilih Kamar Tipe Premium Dengan Ranjang Double";
      fixkam = "Premium Dengan Double Bed";
      harga_kamar = 450000;
    }
  else if (kamar == 3 && ranjang == 1)
    {
      cout << "\n\t\tAnda Memilih Kamar Tipe Deluxe Dengan Ranjang single";
      fixkam = "Deluxe Dengan Single Bed";
      harga_kamar = 800000;
    }
  else if (kamar == 3 && ranjang == 2)
    {
      cout << "\n\t\tAnda Memilih Kamar Tipe Deluxe Dengan Ranjang Double";
      fixkam = "Deluxe Dengan Double Bed";
      harga_kamar = 900000;
    }
  else if (kamar == 4 && ranjang == 1)
    {
      cout << "\n\t\tAnda Memilih Kamar Tipe Suite Dengan Ranjang single";
      fixkam = "Suite Dengan Single Bed";
      harga_kamar = 1500000;
    }
  else if (kamar == 4 && ranjang == 2)
    {
      cout << "\n\t\tAnda Memilih Kamar Tipe Suite Dengan Ranjang Double";
      fixkam = "Suite Dengan Double Bed";
      harga_kamar = 1800000;
    }
  else if (kamar == 5 && ranjang == 1)
    {
      cout <<
	"\n\t\tAnda Memilih Kamar Tipe Presidential Dengan Ranjang single";
      fixkam = "Presidential Dengan Single Bed";
      harga_kamar = 2500000;
    }
  else if (kamar == 5 && ranjang == 2)
    {
      cout <<
	"\n\t\tAnda Memilih Kamar Tipe Presidential Dengan Ranjang Double";
      fixkam = "Presidential Dengan Double Bed";
      harga_kamar = 4000000;
    }
  else
    {
      cout << "\n\t\tMaaf Pilihan Anda Tidak Tersedia";
      cout << "\n\t\tUntuk Keamanan Silahkan Isi Data Dari Awal";
      cout << "\n\t\tApakah Anda Ingin Memulai Lagi ? [Y/N]";
      cin >> jwb;
      if (jwb == "Y" || "y")
	{
	  goto awal;
	}
      else
	{
	  cout << "\n\n\t\tTerima Kasih";
	}
    }
  cout << "\n\n\n\t\tSilahkan Mengisi Form Berikut";
  cout <<
    "\n\t\t=================================================================================";
  cout << "\n\t\tPilih No. Kamar [1-100]     : ";
  cin >> no_kamar;
  cout << "\n\t\tMenginap Lebih Dari 5 Hari diskon 2% perhari";
  cout << "\n\t\tLama Menginap               : ";
  cin >> lama;

  if (lama >= 5)
    {
      diskon = 0.2;
    }
  else
    {
      diskon = 0;
    }
  cout << "\n\t\tTanggal Check In [DDMMYY]   : ";
  cin >> checkin;
  cout << "\n\t\tTanggal Check Out [DDMMYY]  : ";
  cin >> checkout;
  cout <<
    "\t\t=================================================================================";

  cout << "\n\n\n\n\t\tData Pemesanan Kamar" << endl;
  cout <<
    "\t\t=================================================================================";
  cout << "\n\t\tNama Resepsionis : " << resepsionis;
  cout << "\n\t\tID Resepsionis   : " << id_resepsionis;
  cout << "\n\t\tNama Pemesan     : " << customer;
  cout << "\n\t\tID Pemesan       : " << id_customer;
  cout << "\n\t\tAlamat           : " << alamat;
  cout << "\n\t\tNo Telp/HP       : " << hp;
  cout << "\n\t\tTipe Kamar       : " << fixkam;
  cout << "\n\t\tNo. Kamar        : ";
  if (no_kamar >= 1 && no_kamar <= 100)
    {
      cout << no_kamar;
    }
  else
    {
      cout << "\n\t\tMaaf Nomer Kamar Belum Tersedia";
      cout << "\n\t\tSilahkan Hubungi Resepsionis Untuk Pergantian Nomer";
    }
  cout << "\n\t\tLama Menginap    : " << lama << " Hari";
  cout << "\n\t\tTanggal Check in : " << checkin;
  cout << "\n\t\tTanggal Check out: " << checkout;
  cout << "\n\t\tHarga Perhari    : Rp. " << harga_kamar;
  cout << "\n\t\tHarga Kamar Total: Rp. " << lama * harga_kamar;
  cout << "\n\t\tDiskon           : Rp. " << diskon * harga_kamar << endl;
  total = harga_kamar * lama - (diskon * harga_kamar);
  cout <<
    "\t\t=================================================================================";
  cout << "\n\n\t\tBiaya Total      : Rp. " << total;
  cout << "\n\t\tUang Muka        : Rp. ";
  cin >> um;
  kurang = total - um;
  if (total >= um)
    {
      cout << "\n\t\tKekurangan       : Rp. " << kurang;
    }
  else
    {
      cout << "\n\t\tKembali          : Rp. " << kurang * (-1);
    }
  cout <<
    "\n\t\t=================================================================================";

  cout << "\n\n\t\tTerima Kasih Telah Memilih Hotel PUYER BINTANG TUJUH";
  cout << "\n\t\tSebagai Tempat Peristirahatan Anda";
  cout << endl;
  cout << "\n\n\t\tApakah Anda Ingin Memesan Kamar Lagi ? [Y/N]";
  cin >> jwb;
  if (jwb == "Y" || jwb == "y")
    {
      goto awal;
    }
  else
    {
      cout << "\n\n\t\tTerima Kasih Atas Kunjungannya";
    }
  getch ();
}
