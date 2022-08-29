//Preprosesor
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct STACK
{
    int data[5];
    int top;
};
STACK tumpukan;

//deklarasi fungsi operasi stack
void inisialisasi();
int IsEmpty();
int IsFull();

void push(int data);

void pop();

//fungsi main program
int main()
{
    system("cls");
    int pilih, input, i, jumlah;

    inisialisasi();
    do
    {
        cout << "PRE-ORDER TOKO ROTI MAS BAGUS" << endl;
        cout << "Silahkan pilih perintah di bawah ini untuk mengatur antrian pelanggan" << endl;
        cout << "------------------------------" << endl;
        cout << "1. Menambahkan Pesanan" << endl;
        cout << "2. Membatalkan Pesanan terakhir" << endl;
        cout << "3. Melihat urutan Pesanan Pelanggan" << endl;
        cout << "4. Menghapus semua pesanan" << endl;
        cout << "5. Mencari Antrian" << endl;
        cout << endl;
        cout << "Pilih Perintah : ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
        {
            if (IsFull() == 1)
            {
                cout << "Tumpukanan penuh !";
            }
            else
            {
                cout << "Masukkan Kode Pelanggan : ";
                cin >> input;
                cout << "Masukkan jumlah roti yang diinginkan : ";
                cin >> jumlah;
                cout << "Kode Rasa Roti" << endl;
                cout << "1. Stroberi" << endl;
                cout << "2. Vanila" << endl;
                cout << "3. Coklat" << endl;
                cout << "4. Mokaccino" << endl;
                cout << "\nMasukkan rasa roti berdasarkan kode rasa diatas\n";
                for (int i = 0; i < jumlah; i++)
                {
                    cout << "roti ke-" << i + 1 << " : ";
                    cin >> tumpukan.data[i];
                }

                int j, k, tmp;
                for (j = 0; j < jumlah; j++)
                {
                    for (k = j + 1; k < jumlah; k++)
                    {
                        if (tumpukan.data[j] > tumpukan.data[k])
                        {
                            tmp = tumpukan.data[j];
                            tumpukan.data[j] = tumpukan.data[k];
                            tumpukan.data[k] = tmp;
                        }
                    }
                }

                cout << "\nPelanggan telah memesan :\n";
                for (int i = 0; i < jumlah; i++)
                {
                    cout << "Roti ke-" << i + 1 << ": " << tumpukan.data[i] << "\n";
                }
                //BATAS//

                //BATAS//
                push(input);
            }

            cout << endl;
            getch();
            break;
        }
        case 2:
        {
            if (IsEmpty() == 1)
            {
                cout << "Tumpukanan Kosong !";
            }
            else
            {
                cout << "Data yang akan di Pop = " << tumpukan.data[tumpukan.top] << endl;
                pop();
            }
            cout << endl;
            getch();
            break;
        }
        case 3:
        {
            if (IsEmpty() == 1)
            {
                cout << "Tumpukanan Kosong !" << endl;
            }
            else
            {
                cout << "Data : " << endl;
                for (i = 0; i <= tumpukan.top; i++)
                {
                    cout << tumpukan.data[i] << " ";
                }
            }
            cout << endl;
            getch();
            break;
        }
        case 4:
        {
            inisialisasi();
            cout << "Tumpukanan Kosong !" << endl;
            cout << endl;
            getch();
            break;
        }
        case 5:
        {
                int cari, tanda;
                cout << "\nMasukkan kode antrian yang ingin dicari = ";
                cin >> cari;

                for (int i = 1; i < input; i++)
                {
                    if (cari == tumpukan.data[i])
                        cout << "Roti terdapat pada urutan ke-" << i + 1 << endl;
                }
        }
        default:
        {
            cout << "Tidak ada dalam pilih" << endl;
        }
        }
        }
        while (pilih >= 1 && pilih <= 4)
            ;
        getch();
    }

    //fungsi inisialisasi stack = kosong
    void inisialisasi()
    {
        tumpukan.top = -1;
    }

    //fungsi mengecheck apakah stack kosong
    int IsEmpty()
    {
        if (tumpukan.top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    //fungsi mengecheck apakah stack penuh
    int IsFull()
    {
        if (tumpukan.top == 5 - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    //fungsi untuk menyisipkan data ke stack
    void push(int data)
    {
        tumpukan.top++;
        tumpukan.data[tumpukan.top] = data;
    }

    //fungsi untuk mengeluarkan data dari stack
    void pop()
    {
        tumpukan.top = tumpukan.top - 1;
        if (tumpukan.top < 0)
        {
            tumpukan.top = -1;
        }
    }
