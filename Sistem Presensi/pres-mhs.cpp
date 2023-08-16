#include <iostream>
#include <ctime>
#include <stdio.h>

// Hanya untuk ala ala
#include "lib/menu.h"
#include "lib/color.h"
#include "lib/fort.hpp"
using namespace std;

// Struktur data untuk simpul mahasiswa
struct Mahasiswa
{
  string nim;
  string nama;
  string waktu;
  Mahasiswa *next;
};

// Fungsi untuk menyisipkan simpul di awal linked list
void sisipAwal(Mahasiswa *&head, Mahasiswa *simpulBaru)
{
  simpulBaru->next = head;
  head = simpulBaru;
}

// Fungsi untuk mencari mahasiswa berdasarkan NIM
Mahasiswa *cariMahasiswa(Mahasiswa *head, string nim)
{
  Mahasiswa *current = head;
  while (current != nullptr)
  {
    if (current->nim == nim)
    {
      return current;
    }
    current = current->next;
  }
  return nullptr;
}

// Fungsi untuk membuat simpul baru
Mahasiswa *tambahSimpulPresensi(Mahasiswa *&head)
{
  string nim, nama;
  time_t now = time(0);
  char *dt = ctime(&now); // mengeluarkan output waktu saat ini realtime
  system("cls");

  set_xy(28, 2);
  cout << "Presensi" << endl;
  set_xy(16, 3);
  cout << "================================" << endl;
  cout << "\t\tNIM \t: ";
  cin >> nim;
  cout << endl;
  cout << "\t\tNama \t: ";
  cin.ignore();
  getline(cin, nama);

  // Cek apakah NIM sudah ada
  if (cariMahasiswa(head, nim) != nullptr)
  {
    cout << "\t\tNIM " << nim << " sudah melakukan presensi." << endl;
    cout << "\t\t";
    system("pause");
    return nullptr;
  }

  Mahasiswa *newSimpul = new Mahasiswa;
  newSimpul->nim = nim;
  newSimpul->nama = nama;
  newSimpul->waktu = dt;
  newSimpul->next = nullptr;
  sisipAwal(head, newSimpul);
  cout << "\t\tPresensi NIM " << nim << " berhasil." << endl;
  cout << "\t\t";
  system("pause");
  return newSimpul;
}

// Fungsi untuk melakukan update nama berdasarkan pencarian nim
void updateNama(Mahasiswa *head, string nim)
{
  Mahasiswa *current = cariMahasiswa(head, nim);
  if (current != nullptr)
  {
    system("cls");
    cout << "\t\t\tUpdate Data" << endl;
    cout << "\t\t================================" << endl;
    cout << "\t\tNIM \t\t: " << nim << endl;
    cout << "\t\tNama Lama \t: " << current->nama << endl
         << endl;
    cout << "\t\tMasukkan Nama Baru: ";
    cin.ignore();
    getline(cin, current->nama);
    cout << "\t\tNama berhasil diperbarui" << endl;
    cout << "\t\t";
    system("pause");
  }
  else
  {
    cout << "\t\tNIM " << nim << " tidak ditemukan." << endl;
    cout << "\t\t";
    system("pause");
  }
}

// Fungsi untuk menampilkan menu
int showMenu()
{
  menu mn;
  mn.set_color(mn.PURPLE);
  system("cls");
  int opsi;

  set_xy(30, 2);
  cout << "MENU" << endl;
  set_xy(16, 3);
  cout << "================================" << endl
       << endl;
  opsi = mn.Gmenu("Tambah/Gagalkan Presensi", "Data Presensi", "Tampilkan Detail Presensi", "Menu Sorting", "Keluar");
  return opsi + 1;
}

// Fungsi untuk menampilkan sub-menu
int showSubMenu()
{
  menu mn;
  mn.set_color(mn.GREEN);
  system("cls");
  int opsi;

  set_xy(26, 2);
  cout << "HALAMAN EDITOR" << endl;
  set_xy(16, 3);
  cout << "================================" << endl
       << endl;
  opsi = mn.Gmenu("Tambah Presensi", "Gagalkan Presensi", "Perbarui Nama", "Kembali ke menu utama");
  return opsi + 1;
}

// Fungsi untuk menampilkan menu sorting presensi
int showMenuSorting()
{
  menu mn;
  mn.set_color(mn.RED);
  system("cls");
  int opsi;

  set_xy(27, 2);
  cout << "MENU SORTING" << endl;
  set_xy(16, 3);
  cout << "================================" << endl
       << endl;
  opsi = mn.Gmenu("Berdasarkan NIM", "Berdasarkan Nama", "Kembali ke menu utama");
  return opsi + 1;
}

void invalidOption()
{
  menu mn;
  system("cls");

  set_xy(32, 2);
  cout << "ERROR" << endl;
  set_xy(16, 3);
  cout << "================================" << endl
       << endl;
  set_xy(16, 3);
  cout << "Pilihan tidak valid" << endl
       << endl;
  set_xy(16, 3);
  system("pause");
}

// Fungsi untuk mencetak daftar mahasiswa dan status kehadiran
void cetakPresensi(Mahasiswa *head, string nim)
{
  system("cls");
  if (head == nullptr)
  {
    cout << endl
         << endl;
    cout << "\t\tDaftar mahasiswa kosong." << endl;
    cout << "\t\t";
    system("pause");
    return;
  }

  if (nim == "0")
  {
    ft_table_t *table = ft_create_table();
    /* Set "header" untuk row pertama */
    ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);
    ft_write_ln(table, "No", "NIM", "Nama", "Waktu");
    ft_set_tbl_prop(table, FT_TPROP_LEFT_MARGIN, 16);
    int numbering = 1;

    Mahasiswa *current = head;
    set_xy(19, 2);
    cout << "Daftar Presensi Mahasiswa" << endl;
    set_xy(16, 3);
    cout << "================================" << endl
         << endl;
    while (current != nullptr)
    {
      ft_write_ln(table, to_string(numbering++).c_str(), current->nim.c_str(), current->nama.c_str(), current->waktu.c_str());
      current = current->next;
    }
    printf("%s\n", ft_to_string(table));
    ft_destroy_table(table);
  }
  else
  {
    Mahasiswa *current = cariMahasiswa(head, nim);
    if (current != nullptr)
    {
      ft_table_t *table = ft_create_table();
      /* Set "header" untuk row pertama */
      ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);
      ft_write_ln(table, "No", "NIM", "Nama", "Waktu");
      ft_set_tbl_prop(table, FT_TPROP_LEFT_MARGIN, 16);
      int numbering = 1;

      set_xy(19, 2);
      cout << "Detail Presensi Mahasiswa" << endl;
      set_xy(16, 3);
      cout << "================================" << endl
           << endl;
      ft_write_ln(table, to_string(numbering++).c_str(), current->nim.c_str(), current->nama.c_str(), current->waktu.c_str());
      printf("%s\n", ft_to_string(table));
      ft_destroy_table(table);
    }
    else
    {
      cout << "\t\tNIM : " << nim << " tidak ditemukan" << endl;
    }
  }
  cout << "\t\t";
  system("pause");
  return;
}

// Fungsi untuk menghapus kehadiran mahasiswa berdasarkan NIM
void gagalkanPresensi(Mahasiswa *&head, string nim)
{
  Mahasiswa *current = head;
  Mahasiswa *prev = nullptr;

  // Jika mahasiswa yang akan dihapus adalah head
  if (current != nullptr && current->nim == nim)
  {
    head = current->next;
    delete current;
    cout << "\t\tMahasiswa dengan NIM " << nim << " telah dihapus." << endl;
    cout << "\t\t";
    system("pause");

    // Periksa apakah linked list kosong setelah penghapusan
    if (head == nullptr)
    {
      cout << "\t\tLinked list kosong." << endl;
    }

    return;
  }

  // Cari mahasiswa yang akan dihapus
  while (current != nullptr && current->nim != nim)
  {
    prev = current;
    current = current->next;
  }

  // Jika mahasiswa ditemukan, hapus simpulnya
  if (current != nullptr)
  {
    prev->next = current->next;
    delete current;
    cout << "\t\tMahasiswa dengan NIM " << nim << " telah dihapus." << endl;
  }
  else
  {
    cout << "\t\tMahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
  }
  cout << "\t\t";
  system("pause");
}

// Fungsi untuk menukar dua simpul Mahasiswa pada linked list
void tukarMahasiswa(Mahasiswa *a, Mahasiswa *b)
{
  // Menyimpan data sementara
  string tempNIM = a->nim;
  string tempNama = a->nama;
  string tempWaktu = a->waktu;

  // Merubah value data A dengan data B
  a->nim = b->nim;
  a->nama = b->nama;
  a->waktu = b->waktu;

  // Memasukkan data A yang sebelumnya disimpan di variable temp ke value data B
  b->nim = tempNIM;
  b->nama = tempNama;
  b->waktu = tempWaktu;
}

// Fungsi untuk melakukan sorting data presensi berdasarkan NIM dengan algoritma Bubble Sort
void sortNIM(Mahasiswa *head)
{
  if (head == nullptr || head->next == nullptr)
    return;

  bool swapped;
  Mahasiswa *current;
  Mahasiswa *last = nullptr;

  do
  {
    swapped = false;
    current = head;

    while (current->next != last)
    {
      if (current->nim > current->next->nim)
      {
        tukarMahasiswa(current, current->next);
        swapped = true;
      }
      current = current->next;
    }
    last = current;
  } while (swapped);
  set_xy(24, 2);
  cout << "Berhasil Sorting" << endl;
  set_xy(16, 3);
  system("pause");
}

// Fungsi untuk melakukan sorting data presensi berdasarkan nama dengan algoritma Selection Sort
void sortNama(Mahasiswa *head)
{
  if (head == nullptr || head->next == nullptr)
    return;

  Mahasiswa *current = head;

  while (current != nullptr)
  {
    Mahasiswa *minNode = current;
    Mahasiswa *temp = current->next;

    while (temp != nullptr)
    {
      if (temp->nama < minNode->nama)
        minNode = temp;
      temp = temp->next;
    }

    tukarMahasiswa(current, minNode);
    current = current->next;
  }
  set_xy(24, 2);
  cout << "Berhasil Sorting" << endl;
  set_xy(16, 3);
  system("pause");
}

int main()
{
  // Deklarasi variable yang akan digunakan
  bool loopMenu = true, loopSubMenu, loopSorting;
  string searchNim;

  // Inisialisasi linked list awal
  Mahasiswa *head = nullptr;

  // Melakukan perulangan menu
  while (loopMenu)
  {
    // Menampilkan menu
    switch (showMenu())
    {

    case 1:

      loopSubMenu = true;
      while (loopSubMenu)
      {

        switch (showSubMenu())
        {

        case 1:
          tambahSimpulPresensi(head);
          break;

        case 2:
          system("cls");
          set_xy(24, 2);
          cout << "Gagalkan Presensi" << endl;
          set_xy(16, 3);
          cout << "================================" << endl;
          cout << "\t\tMasukkan NIM yang ingin digagalkan: ";
          cin >> searchNim;
          gagalkanPresensi(head, searchNim);
          break;

        case 3:
          system("cls");
          set_xy(24, 2);
          cout << "Update Data" << endl;
          set_xy(16, 3);
          cout << "================================" << endl;
          cout << "\t\tMasukkan NIM nama yang ingin diperbarui: ";
          cin >> searchNim;
          updateNama(head, searchNim);
          break;

        case 4:
          loopSubMenu = false;
          break;

        default:
          invalidOption();
          continue;
        }
      }
      break;

    case 2:
      cetakPresensi(head, "0");
      break;

    case 3:
      system("cls");
      set_xy(19, 2);
      cout << "Cari Detail Mahasiswa" << endl;
      set_xy(16, 3);
      cout << "================================" << endl;
      cout << "\t\tMasukkan NIM yang ingin dicari: ";
      cin >> searchNim;
      cetakPresensi(head, searchNim);
      break;

    case 4:
      loopSorting = true;
      while (loopSorting)
      {
        switch (showMenuSorting())
        {

        case 1:
          sortNIM(head);
          cetakPresensi(head, "0");
          break;

        case 2:
          sortNama(head);
          cetakPresensi(head, "0");
          break;

        case 3:
          loopSorting = false;
          break;

        default:
          invalidOption();
          continue;
        }
      }
      break;

    case 5:
      system("cls");
      loopMenu = false;
      cout << "\t\tPembelajaran selesai!" << endl;
      cout << "\t\tSampai jumpa!" << endl;
      break;

    default:
      invalidOption();
      continue;
      break;
    }
  }

  return 0;
}