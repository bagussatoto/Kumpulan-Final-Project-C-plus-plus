#include <iostream>
#include <iomanip>
#include <string.h>
#include <conio.h>
using namespace std;

class LOGIN
{
  public:
    string username;
    string password;
    bool Login()
    {
      system("cls");
      char ch;
      int loop = 1;
      initiateLogin:
      bool isLogin;
      cout << "========LOGIN=========" << endl;
      cout << "username: "; cin >> username;
      cout << "password: "; ch = getch();
      while(ch != 1 && loop <=6)
      {
        password.push_back(ch);
        cout << '*';
        ch = getch();
        loop++;
      }
      cout << "======================" << endl;
      (username == "123456" && password == "123456") ? isLogin = true: isLogin = false;
      return isLogin;
    }
};

class Data{
    public:
      int NIM[70];
      string nama[70];
      int nim;

      void SetNIM()
      {
        nim = 4040;
        for(int i = 0; i < 33; i++)
        {
          NIM[i] = nim;
          nim++;
        }
        NIM[33] = 4073;
        NIM[34] = 4074;
        
        for(int i = 35; i < 65; i++)
        {
          NIM[i] = nim;
          nim++;
        }
      }

      void SetNama()
      {
        nama[0] = "Dimas Pramudya Nagara";
        nama[1] = "Selma Setia Monika";
        nama[2] = "Ari Valdy Pratama Arsyad";
        nama[3] = "Dimas Ardhito";
        nama[4] = "Ekhsan Nur Qolis";
        nama[5] = "Fadhil Asyraf Rafli Amir";
        nama[6] = "Muhammad Satri Chusnun Kitaro";
        nama[7] = "Yahya Hamid";
        nama[8] = "Rachmat Surandito";
        nama[9] = "Muhmmad Hanif Ismail";
        nama[10] = "Muhammad Rangga Pangestu";
        nama[11] = "Muhammad Jawahir Al Faqih";
        nama[12] = "Tegar Rifai";
        nama[13] = "Aldyansa";
        nama[14] = "Mohammad Daffa My Honest Anugerah";
        nama[15] = "Muhammad Albab Ridho Pratama";
        nama[16] = "Arya Manunggal Putra";
        nama[17] = "Kholan Susuri";
        nama[18] = "Rahmatika Yusttiani";
        nama[19] = "Muhammad Maulid Sam Endra";
        nama[20] = "Evi Zulffa Rahmah";
        nama[21] = "Widi Widana Pandu Sumarya";
        nama[22] = "Jihan Rabbani";
        nama[23] = "Siti Wahyuni";
        nama[24] = "Quiin Latifah Akmatin Lubis";
        nama[25] = "Dicky Priambudi Nur Prasetyo";
        nama[26] = "Maulana Izzra Satriyo Wicaksono";
        nama[27] = "Ray Bagus Al Arief";
        nama[28] = "Novelino Arya Pratama";
        nama[29] = "Rizki Gunawan";
        nama[30] = "Andreas Andrian";
        nama[31] = "Bagus Budi Satoto";
        nama[32] = "Rastra Ardiansyah Pora";
        nama[33] = "Kalwabed Rizki";
        nama[34] = "Saddam Akbari Hasibuan";
        nama[35] = "Dimas Aji Nalagati";
        nama[36] = "Andrian Pradana";
        nama[37] = "Fikri Oktafian";
        nama[38] = "Zahwa Putri Chairunnisa";
        nama[39] = "Shera Alice Ayutri";
        nama[40] = "Hizkiana Ruli Oktaseli";
        nama[41] = "Indra Wahyu Hermawan";
        nama[42] = "Ndaru Windra Sayidina";
        nama[43] = "Ditar Rozano";
        nama[44] = "Antonia Vania Viyani";
        nama[45] = "I Wayan BAyu Arya Wiguna";
        nama[46] = "Achmad Fadillah Pernata";
        nama[47] = "Fajar Rizki Yunanto";
        nama[48] = "Dwi Anas Al Fajrin";
        nama[49] = "Muhammad Daffa' Sidiq";
        nama[50] = "Muhammad nasyrullah eddy";
        nama[51] = "Rani saputri";
        nama[52] = "Muhamad Rosyid";
        nama[53] = "Fadli Setia Winata";
        nama[54] = "Firresa Alif Nurahman";
        nama[55] = "Ariza Akmal Syahida";
        nama[56] = "Ahita Hanazah Fitraih";
        nama[57] = "Mambaul Hisam";
        nama[58] = "Deska Danu Permadi";
        nama[59] = "I Nyoman Karma Dharma Nalendra W";
        nama[60] = "Tegar Tri Putrawan";
        nama[61] = "Faiq Akmal Fadjar";
        nama[62] = "Brigita Julia Chadra";
        nama[63] = "Alfi Yanuar";
        nama[64] = "Zekky Islahudin";
      }
};

Data mhs;
void mainMenu();
void cekMhs();
void cari();
int logout();
void linetopbot();
void linemid();

int main()
{
    LOGIN lgn;
    initiate:
    if(lgn.Login()){
        mainMenu();
    }else{
        system("cls");
        cout << "something wrong" << endl;
        goto initiate;
    }
}

void linetopbot()
{
  for(int i = 0; i < 49; i++)
  {
    cout << "=";
  }
  cout << endl;
}

void linemid()
{
  for(int i = 0; i < 49; i++)
  {
    cout << "-";
  }
  cout << endl;
}

void mainMenu(){
    system("cls");
    mhs.SetNIM();
    mhs.SetNama();
    int choice;
    cout << "=======================" << endl;
    cout << "== 21 INFORMATIKA 04 ==" << endl;
    cout << "=======================" << endl;
    cout << "1.Cek Daftar Mahasiswa" << endl;
    cout << "2.Cari Mahasiswa" << endl;
    cout << "3.Logout" << endl;
    cout << "=======================" << endl;
    cout << "pilihan: "; cin >> choice;
    switch(choice){
        case 1:
            cekMhs();
            break;
        case 2:
            cari();
            break;
        case 3:
           logout();
            break;
        default:
        mainMenu();
        break;
    }
}

void cekMhs(){
    system("cls");
    char b;
    linetopbot();
    cout << setiosflags(ios::left) << setw(11) << "     NIM"; cout << " | ";
    cout << setiosflags(ios::left) << setw(25) << "\t\t    Nama"; cout << " | " << endl;
    for(int i = 0; i < 65; i++)
    {
      linemid();
      cout << setiosflags(ios::left) << " 21.11." << setw(4) << mhs.NIM[i]; cout << " | ";
      cout << setiosflags(ios::left) << setw(33) << mhs.nama[i]; cout << " | " << endl;
    }
    linetopbot();
    cout << endl;
    cout << "\nTekan B untuk Kembali" << endl;
    cin >> b;
    if(b == 'b' || b == 'B'){
        mainMenu();
    }
}

void cari(){
    char b, validation;
    int nim;
    cari:
    system("cls");
    cout << "===========================" << endl;
    cout << "4 Digit NIM terakhir : ";
    cin >> nim;
    cout << "[y] yes [c] cancel : ";
    cin >> validation;
    if(validation == 'y' || validation == 'Y'){
      cout << endl;
      linetopbot();
      cout << setiosflags(ios::left) << setw(11) << "     NIM"; cout << " | ";
      cout << setiosflags(ios::left) << setw(25) << "\t\t    Nama"; cout << " | " << endl;
      linemid();

      int awal = 0, akhir = 65, tengah;

      while(awal <= akhir)
      {
        tengah = (awal + akhir)/2;
        if(nim > mhs.NIM[tengah])
        {
          awal = tengah + 1;
        }else if(nim < mhs.NIM[tengah])
        {
          akhir = tengah - 1;
        }else{
          awal = akhir + 1;
        }
      }

      if(nim == mhs.NIM[tengah])
      {
        cout << setiosflags(ios::left) << " 21.11." << setw(4) << mhs.NIM[tengah]; cout << " | ";
        cout << setiosflags(ios::left) << setw(33) << mhs.nama[tengah]; cout << " | " << endl;
        linetopbot();
      }else{
        cout << "Data Tidak Ditemukan";
      }

    }else if(validation == 'c' || validation == 'C'){
        goto cari;
    }
    cout << "\nTekan B untuk kembali" << endl;
    cin >> b;
    if(b == 'b' || b == 'B'){
        mainMenu();
    }
}

int logout(){
    system("cls");
    return 0;
}
