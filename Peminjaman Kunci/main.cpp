#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <unistd.h>

using namespace std;

void clear_screen() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}


string verifiedusr,verifiedpass,fulldatakunci[10],pilihanlogin;

int pilihan;

string namakunci[10] = {"Gedung A1","Gedung B1","Gedung C1","Gedung D1","Gedung E1","Gedung A2","Gedung B2","Gedung C2","Gedung D2","Gedung E2"};
string namapeminjam[10] = {"-","-","-","-","-","-","-","-","-","-"};
string tanggalpinjam[10] = {"-","-","-","-","-","-","-","-","-","-"};

string username = "Admin";
string password = "User";

//Get Real Time
time_t now = time(0);
char* waktu = ctime(&now);

int main(int argc, char const *argv[])
{
    awal:
    cout << "Program Peminjaman Kunci Sederhana" <<endl;
    cout << "Menu : "<<endl;
    cout << "1.Login" <<endl;
    cout << "2.Buat Akun" <<endl;
    cout << "3.Keluar" <<endl;
    cout << "Masukkan Angka Opsi Pilihan : ";cin >> pilihan;
    clear_screen();
    if (pilihan == 1)
    {
        login:
        cout << "=====LOGIN====="<<endl;
        cout << "Masukkan Username Anda :";getline(cin >> ws,verifiedusr);
        cout << "Masukkan Password Anda : ";getline(cin,verifiedpass);
        if (username == verifiedusr && password == verifiedpass)
        {
            clear_screen();
            cout << "Anda Berhasil Login!!!" <<endl;
            goto menu;
        }
        else{
            clear_screen();
            cout << "Username Atau Password Salah,Harap Masukkan Kembali Password Anda"<<endl;
            goto login;
        }
    }
    else if (pilihan == 2)
    {
        cout << "=====BUAT AKUN=====" <<endl;
        cout << "Masukkan Nama Username : ";getline(cin >> ws,username);
        cout << "Masukkan Nama Password : ";getline(cin,password);
        clear_screen();
        cout << "Akun Anda Berhasil Di Buat "<<endl;
        cout << "Apakah Anda Ingin login (Ya/Tidak) : ";cin>>pilihanlogin;
        if (pilihanlogin == "YA" || pilihanlogin == "Ya" || pilihanlogin == "yA" || pilihanlogin == "ya")
        {
            clear_screen();
            goto login;
        }
        else {
            clear_screen();
            cout << "Anda Di Arahkan Ke Menu!" <<endl;
            goto awal;
        }
    }
    else {
        keluar:
        clear_screen();
        cout << "Terima Kasih Telah Menggunakan Program Kami" <<endl;
        goto end;
    }
    int pilihanmenu,pilihankunci;
    menu:
    cout << "=====MENU PROGRAM PEMINJAMAN KUNCI=====" <<endl;
    cout << "1.Peminjaman Kunci"<<endl;
    cout << "2.Pengembalian Kunci"<<endl;
    cout << "3.Data Peminjaman Kunci"<<endl;
    cout << "4.Keluar"<<endl;
    cout << "Masukkan Angka Pilihan Dari Menu : ";cin >> pilihanmenu;
    if (pilihanmenu == 1)
    {
        cout << "==========MENU PEMINJAMAN KUNCI==========" <<endl;
        cout << "Daftar Kunci : "<<endl;
        int y = 1;
        for (int x=0;x < 10;++x)
        {
            cout << y << "." << namakunci[x] <<endl;
            y++; 
        }
        cout << "Masukkan Angka Pilihan Kunci : ";cin >>pilihankunci;
        pilihankunci = pilihankunci-1;
        if (namapeminjam[pilihankunci] != "-"){
            clear_screen();
            cout << "Maaf,Kunci " <<namakunci[pilihankunci] << " telah di pinjam oleh " <<namapeminjam[pilihankunci] << " pada tanggal " << tanggalpinjam[pilihankunci] <<endl;
            sleep(5);
            goto menu;
        }
        cout << "Masukkan Nama Peminjam Kunci : ";getline(cin >> ws,namapeminjam[pilihankunci]);
        tanggalpinjam[pilihankunci] = waktu;
        fulldatakunci[pilihankunci] = namakunci[pilihankunci] + " " + namapeminjam[pilihankunci] + " " + tanggalpinjam[pilihankunci];
        clear_screen();
        cout << "Data Telah Berhasil Di Tambahkan" <<endl;
        cout <<"Harap Tunggu ...." <<endl;
        sleep(2);
        clear_screen();
        goto menu;
    }
    else if (pilihanmenu == 2)
    {
        clear_screen();
        int pilihanbalik;
        int z=1,x=0;
        for (int x=0;x<10;x++)
        {
            if(namapeminjam[x] != "-")
            {
                goto daftar;
            }
        }
        if(namapeminjam[9] == "-")
            {
                cout << "BELUM ADA KUNCI YANG TERPINJAM" <<endl;
                sleep(3);
                goto menu;
            }
        int lacak[10];
        daftar:
        cout << "Daftar Kunci Yang Sedang Di Pinjam : "<<endl;
        for (int x = 0;x < 41;++x)
            {
                cout << "-";
                if (x == 40)
                {
                    cout << endl;
                }
            }
        
        while (x<10)
        {
            if(x == 0)
            {
                cout << "|" << setw(2) << "NO" << "|" << setw(15) << "Nama Kunci" << "|" << setw(20) << "Nama Peminjam" << "|" <<endl;
                for (int x = 0;x <= 40;++x)
                {
                cout << "-";
                if (x == 40)
                    {
                        cout << endl;
                    }
                }
            }
            if (namapeminjam[x] != "-")
            {
                cout << "|" <<setw(2) << z << "|" << setw(15) << namakunci[x] << "|" << setw(20) << namapeminjam[x] << "|" <<endl;
            }
            else {
                cout << "|" <<setw(2) << z << "|" << setw(15) << namakunci[x] << "|" << setw(20) << "Belum Di Pinjam" << "|" <<endl;
            }
        z++;
        x++;
        }
        for (int x = 0;x <= 40;++x)
            {
                cout << "-";
                if (x == 40)
                {
                    cout << endl;
                }
            }
        cout << "Masukkan Pilihan Nomer Kunci yang Ingin Di Kembalikan : ";cin >> pilihanbalik;
        pilihanbalik = pilihanbalik-1;
        if(namapeminjam[pilihanbalik] != "-")
        {
            clear_screen;
            cout << "Kunci Berhasil Di Kebalikan " <<endl;
            cout << "Please Wait";
            namapeminjam[pilihanbalik] = "-";tanggalpinjam[pilihanbalik] = "-";
            sleep(2);
            clear_screen();
            goto menu;
        }
        else {
            clear_screen();
            cout << "Kunci Belum Di Pinjam "<<endl;
            sleep(2);
            clear_screen();
            goto menu;
        }
    }
    else if (pilihanmenu == 3)
    {
        int f=1,h=0;
        string keputusan;
        cout << "Data Peminjaman Kunci" <<endl;
        for (int x = 0;x < 78;++x)
            {
                cout << "-";
                if (x == 77)
                {
                    cout << endl;
                }
            }
        while (h<10)
        {
            if(h == 0)
            {
                cout << "|" << setw(2) << "NO" << "|" << setw(15) << "Nama Kunci" << "|" << setw(20) << "Nama Peminjam" << "|" << setw(30) << "Tanggal Peminjaman Kunci"  <<endl;
                for (int x = 0;x < 78;++x)
                {
                cout << "-";
                if (x == 77)
                    {
                        cout << endl;
                    }
                }
            }
            cout << "|" <<setw(2) << f << "|" << setw(15) << namakunci[h] << "|" << setw(20) << namapeminjam[h] << "|" << tanggalpinjam[h] << endl;
        f++;
        h++;
        }
        for (int x = 0;x < 78;++x)
                {
                cout << "-";
                if (x == 77)
                    {
                        cout << endl;
                    }
                }
    cout << "Apakah Anda Ingin Kembali Ke Menu (Ya/Tidak) :";cin >> keputusan;
    if (keputusan == "YA" || keputusan == "Ya" || keputusan == "yA" || keputusan == "ya")
    {
        clear_screen();
        goto menu;
    }
    else {
        clear_screen();
        cout << "Anda Akan Kembali Ke Halaman Login " <<endl;
        cout << "Please wait...."<<endl;
        sleep(4);
        goto awal;
    }
    }
    else {
        goto keluar;
    }
    end:
    return 0;
}
