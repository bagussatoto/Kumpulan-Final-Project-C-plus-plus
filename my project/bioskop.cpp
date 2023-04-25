#include <iostream>
#include <string>

using namespace std;

const int MAX_JUMLAH_PELANGGAN = 100; // jumlah maksimum pelanggan yang dapat ditangani

// Kelas Pelanggan untuk menyimpan informasi tentang pelanggan
class Pelanggan {
private:
string nama;
string alamat;
string nomor_telepon;

public:
Pelanggan(string nama, string alamat, string nomor_telepon) {
this->nama = nama;#include<iostream>
using namespace std;
main()

 {

 int pilihan,angka;
 kembali:
  do
 {
     cout<<" ====================================================";cout<<endl;
     cout<<" \t     Program Bioskop XXI Jakarta ";cout<<endl;
     cout<<" ====================================================";cout<<endl; cout<<endl;

     cout<<"\t Bioskop XXI Jakarta";cout<<endl;
     cout<<"\t JL.Kemayoran Jakarta";cout<<endl;
     cout<<endl;
     cout<<" ===================================================="<<endl;
     cout<<"\t   DAFTAR MENU ";cout<<endl;
     cout<<"\t---------------------------------"<<endl;
     cout<<"\t| 1. Pembelian Tiket            |"<<endl;
     cout<<"\t| 2. Cek Sisa Kursi             |"<<endl;
     cout<<"\t| 3. Laporan Penjualan Tiket    |"<<endl;
     cout<<"\t| 4. Keluar   |"<<endl;
     cout<<"\t---------------------------------"<<endl;
     cout<<" ===================================================="<<endl;
     cout<<endl;
     cout<<" Masukan Pilihan Anda (1-4) : ";cin>>pilihan;
     cout<<endl;
  
     switch (pilihan)
   {
    case 1:
     mulai:
     int jenisTKT,jumlahTKT,totalTKT;
     char* jenisTXT;
     char ulang,belanjaKmbl;
  
       cout<<" ===================================================="<<endl;
       cout<<"\t   Pembelian Tiket ";cout<<endl;
       cout<<" ===================================================="<<endl;
    
       cout<<" Keterangan"<<endl;
       cout<<" 1. Tiket Dewasa  : Rp. 35.000"<<endl;
       cout<<" 2. Tiket Anak-anak  : Rp. 20.000"<<endl;
       cout<<" ===================================================="<<endl;
       cout<<" Input Pembelian Tiket"<<endl;
       cout<<" Jenis Tiket (1-2)  : "; cin>>jenisTKT;
       cout<<" Jumlah Tiket   : "; cin>>jumlahTKT;cout<<endl;
       cout<<" ===================================================="<<endl;
     if (jenisTKT==1)
     {
      totalTKT=jumlahTKT*35000;
      jenisTXT="Dewasa";
     }
     else if (jenisTKT==2)
     {
      totalTKT=jumlahTKT*20000;
      jenisTXT="Anak-anak";
     }
     else
     {
      cout<<" Angka Yang Anda Input Salah";
      cout<<endl;
      goto mulai;
     }
  
       cout<<" Jenis Tiket   : "<<jenisTXT<<endl;
       cout<<" Jumlah Tiket   : "<<jumlahTKT<<"\n";
       cout<<" ----------------------------------------------------"<<endl;
       cout<<" Total Bayar   : Rp. "<<totalTKT<<endl;
       cout<<endl;
       break;
    
    
     case 2:
      int KursiTerisi[2],kursiKSONG[2];
       cout<<" ===================================================="<<endl;
       cout<<"\t   Cek Sisa Kursi ";cout<<endl;
       cout<<" ===================================================="<<endl;
       cout<<" Keterangan"<<endl;
       cout<<" Jumlah Kursi Di Bioskop SerbaBebas sebangak 50 Kursi"<<endl;
       cout<<" ===================================================="<<endl;
       cout<<" Input Jumlah Kursi Yang Ingin Dipesan"<<endl;
        angka=0;
      do
  
     {
  
      cout<<" Jumlah Pemesanan Kursi  : ";
       cin>>KursiTerisi[angka];
       angka++;
  
     }
  
     while (angka<1);
      for (angka=0;angka<1;angka++)
       kursiKSONG[angka]=50-KursiTerisi[angka];
    
      cout<<" ===================================================="<<endl;
       for (angka=0;angka<1;angka++)
    
      {
    
       cout<<" Sisa Kursi   : "<<kursiKSONG[angka];cout<<endl;
       cout<<" ===================================================="<<endl;
       cout<<endl;
      } 
        break;
  
   case 3:
    int tiketAnak[2],tiketDewasa[2],total[2];
     cout<<" ===================================================="<<endl;
     cout<<"\t   Input Laporan Penjualan Tiket ";cout<<endl;
     cout<<" ===================================================="<<endl;
     for (angka=0;angka<2;angka++)
    {
     cout<<" Input Data Penjualan "<<angka+1<<endl;
      cout<<" Anak-anak   : "; cin>>tiketAnak[angka];
      cout<<" Dewasa    : "; cin>>tiketDewasa[angka];
      cout<<endl;
    }
    for (angka=0;angka<2;angka++)
      total[angka]=tiketAnak[angka]+tiketDewasa[angka];
      cout<<" ===================================================="<<endl;
      cout<<"\t   Input Laporan Penjualan Tiket ";cout<<endl;
      cout<<" ===================================================="<<endl;
      cout<<" |Tiket  |  Anak-anak  |  Dewasa  |  Total Penjualan|"<<endl;
      cout<<" ----------------------------------------------------"<<endl;
     for (angka=0;angka<2;angka++)
    {
     cout<<" |  "<<angka+1<<"  "<<tiketAnak[angka]<<"          "<<tiketDewasa[angka];
      cout<<"  "<<total[angka]<<"           |"<<endl;
  
     }
      break;
   }
 }
 while (pilihan!=4);

 }
this->alamat = alamat;
this->nomor_telepon = nomor_telepon;
}

// Getter dan setter untuk atribut nama
string getNama() {
return nama;
}
void setNama(string nama) {
this->nama = nama;
}

// Getter dan setter untuk atribut alamat
string getAlamat() {
return alamat;
}
void setAlamat(string alamat) {
this->alamat = alamat;
}

// Getter dan setter untuk atribut nomor_telepon
string getNomorTelepon() {
return nomor_telepon;
}
void setNomorTelepon(string nomor_telepon) {
this->nomor_telepon = nomor_telepon;
}
};

// Kelas Laundry untuk mengelola pelanggan-pelanggan yang memiliki cucian yang harus dicuci
class Laundry {
private:
Pelanggan pelanggans[MAX_JUMLAH_PELANGGAN]; // array untuk menyimpan pelanggan-pelanggan yang memiliki cucian yang harus dicuci
int jumlah_pelanggan; // jumlah pelanggan yang memiliki cucian yang harus dicuci

public:
Laundry() {
jumlah_pelanggan = 0;
}

// Fungsi untuk menambahkan pelanggan baru ke laundry
void tambahPelanggan(Pelanggan pelanggan) {
if (jumlah_pelanggan < MAX_JUMLAH_PELANGGAN) {
pelanggans[jumlah_pelanggan] = pelanggan;
jumlah_pelanggan++;
} else {
throw "Jumlah pelanggan sudah mencapai batas maksimum"; // exception jika jumlah pelanggan sudah mencapai batas maksimum
}
}
// Fungsi untuk mencetak daftar pelanggan yang memiliki cucian yang harus dicuci
void cetakDaftarPelanggan() {
cout << "Daftar pelanggan yang memiliki cucian yang harus dicuci:" << endl;
for (int i = 0; i < jumlah_pelanggan; i++) {
cout << i + 1 << ". " << pelanggans[i].getNama() << " (" << pelanggans[i].getAlamat() << ", " << pelanggans[i].getNomorTelepon() << ")" << endl;
}
}