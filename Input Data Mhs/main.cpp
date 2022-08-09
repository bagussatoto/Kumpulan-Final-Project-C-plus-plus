#include <iostream>
#include <stdlib.h>
#define max 5
using namespace std;

struct Mahasiswa
{
    string nama, nim;
    int nilai[max];
    static int ipk;
    Mahasiswa *next;
};
int Mahasiswa::ipk = 0;
Mahasiswa *headMahasiswa = NULL, *currentMahasiswa = NULL;

bool isEmpty();
void inputData();
void hapusDataByNim();
void tampilData();
void hitungIpk();

int main()
{
    int pilih;
    do
    {
        cout << "===========================" << endl;
        cout << "INPUT DATA MAHASISWA AMIKOM" << endl;
        cout << "===========================" << endl;
        cout << "1. Input Data Mahasiswa" << endl;
        cout << "2. Hapus Data Mahasiswa by NIM" << endl;
        cout << "3. Tampil Data Mahasiswa" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih [1..4]: ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
            system("cls");
            inputData();
            break;
        case 2:
            system("cls");
            hapusDataByNim();
            break;
        case 3:
            system("cls");
            tampilData();
            break;

        default:
            cout << "Pilihan Yang anda Inputkan Salah" << endl;
            break;
        }
    } while (pilih != 4);

    return 0;
}

bool isEmpty()
{
    return (headMahasiswa == NULL);
};

void inputData()
{
    Mahasiswa *mhs = NULL;
    mhs = new Mahasiswa;
    cout << "Masukkan Nama : ";
    cin >> mhs->nama;
    cout << "Masukkan NIM : ";
    cin >> mhs->nim;
    for (int i = 0; i < max; i++)
    {
        cout << "Masukkan Nilai Matkul ke- " << i + 1 << " : ";
        cin >> mhs->nilai[i];
    }

    if (isEmpty())
    {
        headMahasiswa = mhs;
    }
    else
    {
        currentMahasiswa->next = mhs;
    }
    cout << "\nData berhasil diinput" << endl;
    system("pause");
    currentMahasiswa = mhs;
    currentMahasiswa->next = NULL;
}

void hapusDataByNim()
{
    Mahasiswa *help = headMahasiswa;
    string hapus, nim;
    if (isEmpty())
    {
        cout << "\nLinked List kosong, \nPenghapusan tidak dapat dilakukan" << endl;
        system("pause");
    }
    else
    {
        Mahasiswa *prevMhs = headMahasiswa;
        cout << "\nMasukkan NIM untuk menghapus data: ";
        cin >> nim;
        while (help != NULL)
        {
            if (nim == help->nim)
            {
                prevMhs->next = help->next;
                delete help;
            }
            prevMhs = help;
            help = help->next;
        }
        cout << "Node berhasil dikosongkan" << endl;
        system("pause");
    }
}

void tampilData()
{
    Mahasiswa *fristMahasiswa = headMahasiswa;
    while (fristMahasiswa != NULL)
    {
        int temp = 0;
        cout << "\nNama : " << fristMahasiswa->nama << endl;
        cout << "Nim : " << fristMahasiswa->nim << endl;
        for (int i = 0; i < max; i++)
        {
            cout << "Nilai Matkul ke- " << i + 1 << " : " << fristMahasiswa->nilai[i] << endl;
            temp = fristMahasiswa->nilai[i] + temp;
        }
        fristMahasiswa->ipk = temp / max;
        cout << "IPK: " << fristMahasiswa->ipk;
        fristMahasiswa = fristMahasiswa->next;
    }
    cout << endl;
}
