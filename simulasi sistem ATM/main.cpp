#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iomanip>
#include <fstream>
#include <stdio.h>


using namespace std;

int tabungan;
int temp;
int pin;
int transfer;
int norek;
int angka,penarikan, ttabungan= 10000000;
char pilihan;
bool status;
//baca file txt
ifstream inFile;

//	TAMPILAN AWAL
int main ()
{
    cout << "________________________________________\n" << endl;
    cout << "           SELAMAT DATANG                 " << endl;
    cout << "           BANK     BURJO                 " << endl;
    cout << "________________________________________\n" << endl;

    cout <<"Tutup jari dan layar anda demi keamanan dan kenyamanan bersama" << endl;
    cout << "Silahkan masukan PIN anda : ";
    cin >> pin;
    system ("cls");
menu :
    system("color C0");
    cout << "___________________________________" << endl;
    cout << "|          Menu utama             |" << endl;
    cout << "|______(Pecahan 100.000)__________|" << endl;
    cout << "|=================================|" << endl;
    cout << "|1. -> Informasi saldo            |" << endl;
    cout << "|2. -> Penarikan tunai            |" << endl;
    cout << "|3. -> Transfer                   |" << endl;
    cout << "|_________________________________|" << endl;
    cout << " Masukan pilihan anda : ";
    cin >> angka;
    switch ( angka )
    {
    case 1 :
        system("color B0");
        system("cls");
        cout << "====( INFORMASI SALDO )=======" << endl;
        cout << endl << "Saldo anda sekarang " << ttabungan << endl;

        cout << "Apakah anda ingin transaksi lain (y/t)? ";
        cin >> pilihan;

        if (pilihan == 'y')
        {
            system ("cls");
            goto menu;
        }
        else if (pilihan == 't')
        {
            system ("cls");
            cout << "Silahkan ambil kartu anda";

        }
        break;

    case 2 :

tarik :
        system("color F0");
        system("cls");
        cout << "==========( TARIKAN TUNAI )========== " << endl;
        cout << endl << "Masukan jumlah yang ingin anda tarik :";
        cin >> penarikan;
        system ("cls");
        printf ("Transaksi anda sedang diproses\n");
        printf ("Mohon tunggu....");
        system ("cls");

        if (penarikan <= 100000)
        {
            cout << "Penarikan harus kelipatan 100.000...." << endl;
            cout << "Apakah anda ingin transaksi lain (y/t)? : ";
            char a;
            cin >> a;
            if (a == 'y')
            {
                system ("cls");
                goto tarik;
            }
            else if (a == 't')
            {
                system ("cls");
                cout << "Silahkan ambil kartu anda dan kembali ke menu utama";
                goto menu;
            }
        }
        else if (penarikan > ttabungan)
        {

            cout << "Maaf saldo anda tidak cukup..." << endl;
            penarikan > ttabungan;
            char a;
            cout << "Apakah anda ingin transaksi lain (y/t)? : ";
            cin >> a;
            if (a == 'y')
            {
                system ("cls");
                goto menu;
            }
            else if (a == 't')
            {
                system ("cls");
                cout << "Silahkan ambil kartu anda";
            }
        }
        else
        {
            ttabungan -= penarikan;
            cout << "Transaksi anda sukses..." << endl;

        }
        cout << "Apakah anda ingin transaksi lain (y/t)? : ";
        cin >> pilihan;

        if (pilihan == 'y')
        {
            system ("cls");
            goto menu;
        }
        else if (pilihan == 't')
        {
            system ("cls");
            cout << "Silahkan ambil kartu anda";
        }
        break;

    case 3 :
tf :
        system("color A0");
        system("cls");
        cout << "============( TRANSFER )=============" << endl;

        cout << endl << endl << "1. -> lanjutkan" << endl;
        cout << endl << "2. -> Daftar kode bank" << endl;
        cout << endl;
        cout << "Masukan pilihan anda : ";
        cin >> angka;
        if (angka == 1)
        {
            system("cls");
            cout << endl << "Masukan no. bank dan no. rekening yang anda tuju :" << endl;
            cin >> norek;
            cout<<endl;
            cout << "Masukan jumlah yang ingin anda transfer : RP. ";
            cin >> transfer;
            system ("cls");
            cout << endl << "Jumlah yang akan anda transfer RP."<<transfer<<endl;
            system ("cls");
            printf ("Mohon tunggu....");
            system ("cls");
            if (transfer > ttabungan)
            {
                cout << "Maaf saldo anda tidak cukup" << endl;
                penarikan > ttabungan;
            }
            else
            {
                printf ("Transaksi anda sukses");
                ttabungan -= transfer;
                system ("cls");
            }
        }
        else if (angka == 2)
        {
            system ("cls");
            cout<< "1. BNI "<<setw(14)<< "009\n";
            cout<< "2. Mandiri "<<setw(11)<<"008\n";
            cout<< "3. BCA "<<setw(14)<< "014\n";
            cout<< "4. BRI "<<setw(14)<< "002\n";
            cout<< "5. Muamalat"<<setw(10)<< "147\n";
            cout<< "6. Kalbar"<<setw(12)<< "123\n";
            cout<< "7. Kaltim"<<setw(12)<< "124\n";
            cout<< "8. DKI"<<setw(15)<< "111\n";
            cout<< "9. BTN"<<setw(15)<< "200\n";
            cout<< "10.CIMB Niaga"<<setw(8)<< "022\n";
            cout << "Tekan sembarang angka untuk kembali : ";
            cin >> angka;
            goto tf;
        }
        cout << "Apakah anda ingin transaksi lain (y/t)? ";
        cin >> pilihan;
        if (pilihan == 'y')
        {
            system ("cls");
            goto menu;
        }
        else if (pilihan == 't')
        {
            system ("cls");
            cout << "Silahkan ambil kartu anda";
        }
    }
}
