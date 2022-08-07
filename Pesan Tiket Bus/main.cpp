//pengarah compiler
#include <conio.h>

#include <cstdio>

#include <iostream>

#include <string.h>

#include <cstdlib>

using namespace std;

static int p = 0;

class a

//deklarasi
{

  char bus_no[5], sopir[10], jam_keberangkatan[5], jam_tiba[5], asal_kota[10], kota_tujuan[10], kursi[8][4][10];

public:

  void pendataan();

  void pemesanan();

  void kekosongan();

  void cek_data();

  void ketersediaan();

  void posisi(int i);

}

bus[10];

void vline(char ch)
//deklarasi
{

  for (int i=80;i>0;i--)

  cout<<ch;

}
//deklarasi
void a::pendataan()
// definisi dalam opsi "Pendataan"
{

  cout<<"Masukan nomor bus: ";

  cin>>bus[p].bus_no;

  cout<<"\nMasukan nama pengemudi: ";

  cin>>bus[p].sopir;

  cout<<"\nJam Keberangkatan: ";

  cin>>bus[p].jam_keberangkatan;

  cout<<"\nJam Tiba: ";

  cin>>bus[p].jam_tiba;

  cout<<"\n Kota Asal: \t\t\t";

  cin>>bus[p].asal_kota;

  cout<<"\nKota Tujuan: \t\t\t";

  cin>>bus[p].kota_tujuan;

  bus[p].kekosongan();

  p++;

}

void a::pemesanan()
// definisi dalam opsi "Pemesanan"
{

  int kursi;

  char nomor[5];

  top:

  cout<<"Bus nomor: ";

  cin>>nomor;

  int n;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].bus_no, nomor)==0)

    break;

  }

  while(n<=p)

  {

    cout<<"\nNomor Kursi: ";

    cin>>kursi;

    if(kursi>32)

    {

      cout<<"\nHanya tersedia 32 kursi di bus ini!.";

    }

    else

    {

    if (strcmp(bus[n].kursi[kursi/4][(kursi%4)-1], "kosong")==0)

      {

        cout<<"Masukan nama anda: ";

        cin>>bus[n].kursi[kursi/4][(kursi%4)-1];

        break;

      }

    else

      cout<<"Kursi dengan nomor tesebut tidak tersedia\n";

      }

      }

    if(n>p)

    {

      cout<<"Masukan nomor bus dengan benar.\n";

      goto top;

    }

  }

// definisi dan deklarsi dalam menunjukan kursi kosong
void a::kekosongan()

{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(bus[p].kursi[i][j], "kosong");

    }

  }

}

void a::cek_data()
// definisi dalam opsi "cek data"
{

  int n;

  char nomor[5];

  cout<<"Masukan nomor Bus: ";

  cin>>nomor;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].bus_no, nomor)==0)

    break;

  }

while(n<=p)

{

  vline('*');

  cout<<"\nBus nomor: \t"<<bus[n].bus_no

  <<"\nNama Pengemudi: \t"<<bus[n].sopir<<"\t\tJam Keberangkatan: \t"

  <<bus[n].jam_keberangkatan<<"\tJam Tiba:"<<bus[n].jam_tiba

  <<"\nAsal Kota: \t\t"<<bus[n].asal_kota<<"\t\tKota Tujuan: \t\t"<<

  bus[n].kota_tujuan<<"\n";

  vline('*');

  bus[0].posisi(n);

  int a=1;

  for (int i=0; i<8; i++)

  {

    for(int j=0;j<4;j++)

    {

      a++;

      if(strcmp(bus[n].kursi[i][j],"kosong")!=0)

      cout<<"\nKursi nomor : "<<(a-1)<<" telah dipesan oleh: "<<bus[n].kursi[i][j]<<".";

    }

  }

  break;

  }

  if(n>p)

    cout<<"Masukan nomor bus dengan benar: ";

}

void a::posisi(int l)
// definisi dan deklarasi dalam mengambil nomor kursi
{

  int s=0;p=0;

  for (int i =0; i<8;i++)

  {

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

      s++;

      if(strcmp(bus[l].kursi[i][j], "kosong")==0)

        {

          cout.width(5);

          cout.fill(' ');

          cout<<s<<".";

          cout.width(10);

          cout.fill(' ');

          cout<<bus[l].kursi[i][j];

          p++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<bus[l].kursi[i][j];

        }

      }

    }

  cout<<"\n\nTerdapat "<<p<<" kursi yang tersedia di bus nomor: "<<bus[l].bus_no;

  }

void a::ketersediaan()
// definisi dalam opsi "ketersediaan"
{


  for(int n=0;n<p;n++)

  {

    vline('*');

    cout<<"\nBus nomor: \t"<<bus[n].bus_no<<"\nNama Pengemudi: \t"<<bus[n].sopir

    <<"\t\tjam keberangkatan: \t"<<bus[n].jam_keberangkatan<<"\tJam Tiba: \t"

    <<bus[n].jam_tiba<<"\nAsal Kota: \t\t"<<bus[n].asal_kota<<"\t\tKota Tujuan: \t\t\t"

    <<bus[n].kota_tujuan<<"\n";

    vline('*');
    
	cout<<"\n";

    vline('_');
    
    cout<<"\n";

  }

}

int main()
// deklarasi dan definisi awalan program
{

system("cls");

int w;

while(1)

{
  cout<<"\n\n\n\n\n";
  
  vline('_');
    
  cout<<"\n\t\t\tAPLIKASI PEMESANAN TIKET BUS";	

  cout<<"\n\t\t\tTERMINAL SELURUH INDONESIA";
  
  cout<<"\n";
  
  vline('_');
  
  cout<<"\n\n\n\n\n";

  cout<<"\t\t\t1.Pemesanan\n\t\t\t"

  <<"2.Cek Data\n\t\t\t"

  <<"3.Ketersediaan Bus\n\t\t\t"

  <<"4.Pendataan Bus\n\t\t\t"

  <<"5.Keluar";

  cout<<"\n\t\t\tMasukan angka pilihan anda:-> ";

  cin>>w;

  switch(w)

  {

    case 1: bus[0].pemesanan();

      break;

    case 2:  bus[p].cek_data();

      break;

    case 3:  bus[0].ketersediaan();

      break;

    case 4:  bus[p].pendataan();
 
      break;

    case 5:  exit(0);

  }

}

return 0;

}
