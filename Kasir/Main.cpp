#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

const int MAX = 40;

//Variabel

struct keteranganbarang {
    string namabarang;
    string kodebarang;
    string stringhargabarang;
    string stringstockbarang;
    int stockbarang;
    int hargabarang;   
};


keteranganbarang brg[MAX];

int pilihan;
ifstream in;
ofstream out;
int totalharga = 0;
vector<string> showkode;
vector <int> showharga;
vector <string> showbarang;

//Function Queue
bool isFull();
bool isEmpty();
void enqueue();
void dequeue();
void Reset();
void print();

//Function
void loaddata();
void menu();
void line(int);
void pembelian();
void searchharga();
void sortingbarang();
void sortbarangmurah();
void sortstockbarang();
void tambahstockbarang();
void kurangstockbarang();
void savedata();
void clear_screen();

int main(int argc, char *argv[])
{
    int choose;
    loaddata();
    while (true)
    {
        clear_screen();
        menu();
        if (pilihan == 1)
        {
            clear_screen();
            pembelian();
        }
        else if (pilihan == 2)
        {
            searchharga();
        }
        else if (pilihan == 3)
        {
            sortingbarang();
            cin.get();
        }
        else if (pilihan == 4)
        {
            tambahstockbarang();
        }
        else if (pilihan == 5)
        {
            kurangstockbarang();
        }
        else if (pilihan == 6)
        {
            savedata();
            cout << "Terima Kasih Telah menggunakan Program Kami" <<endl;
            return 0;
        }
        else {
            clear_screen();
            cout << "Pilihan yang Di masukkan Salah" <<endl;
        }
        cin.get();
    }
}

void loaddata()
{
    int x= 0;
    in.open("Data.csv",ios::in);
    while (in.peek() != EOF)
    {
        string kodebrg,namabrg,hargabrg,stockbarang;
        int harga,stock;


        getline (in,kodebrg,',');
        getline(in,namabrg,',');
        getline (in,hargabrg,',');
        getline(in,stockbarang);

        brg[x].stringhargabarang = hargabrg;
        brg[x].stringstockbarang = stockbarang;

        istringstream(hargabrg) >> harga;
        istringstream(stockbarang) >> stock;


        brg[x].kodebarang = kodebrg;
        brg[x].namabarang = namabrg;
        brg[x].hargabarang = harga;
        brg[x].stockbarang = stock;
        x++;
    }
    in.close();
}

void menu()
{
    cout << ">>> PROGRAM KASIR SEDERHANA <<<" <<endl;
    cout << "1. Pembelian" <<endl;
    cout << "2. Cek Harga" <<endl;
    cout << "3. Sorting Daftar Barang" <<endl;
    cout << "4. Tambah Stock Barang" <<endl;
    cout << "5. Kurangi Stock Barang" <<endl;
    cout << "6. Exit" <<endl;
    cout << "Masukkan Pilihan Menu : ";cin >> pilihan;
}

void line (int x)
{
    for (int y = 0;y <= x-1;y++)
    {
        cout << "-";
        if (y == x-1)
        {
            cout << endl;
        }
    }
}

void pembelian()
{
    bool flagg = true;
    salah:
    line(44);
    cout << "|" << setw(5) << "Kode" << "|" << setw(20) << "Nama Barang" << "|" << setw(15) << "Harga Barang" << "|" <<endl;
    line(44);
    for (int x = 0;x < showkode.size(); ++x)
    {
        cout << "|" << setw(5) << showkode[x] << "|" << setw(20) << showbarang[x] << "|" << setw(15) << showharga[x] << "|" <<endl;
    }
    menu:
    string kode;
    cout << "|";
    getline(cin >> ws,kode);
    if (kode == ":q")
    {
        goto close;
    }
    clear_screen();
    
    for (int y = 0; y < MAX; ++y)
    {
        if (brg[y].kodebarang == kode && brg[y].stockbarang == 0)
        {
            flagg = false;
            clear_screen();
            goto salah;
        }
        else if (brg[y].kodebarang == kode)
        {
            flagg = true;
            line(44);
            cout << "|" << setw(5) << "Kode" << "|" << setw(20) << "Nama Barang" << "|" << setw(15) << "Harga Barang" << "|" <<endl;
            line(44);
            for (int x = 0;x < showkode.size(); ++x)
            {
                cout << "|" << setw(5) << showkode[x] << "|" << setw(20) << showbarang[x] << "|" << setw(15) << showharga[x] << "|" <<endl;
            }
            string barang;
            string kodebrg;
            int harga;
            brg[y].stockbarang--;
            totalharga = totalharga + brg[y].hargabarang;
            kodebrg = brg[y].kodebarang;
            barang = brg[y].namabarang;
            harga = brg[y].hargabarang;
            showkode.push_back(kodebrg);
            showbarang.push_back(barang);
            showharga.push_back(harga);
            cout << "|" << setw(5) << brg[y].kodebarang << "|" << setw(20) << brg[y].namabarang << "|" << setw(15) << brg[y].hargabarang << "|" <<endl;
            goto menu;
        }
        if (y == MAX-1)
        {
            flagg = false;
            clear_screen();
           goto salah;
        }
    }
    close:
    clear_screen();
    line(44);
    cout << "|" << setw(5) << "Kode" << "|" << setw(20) << "Nama Barang" << "|" << setw(15) << "Harga Barang" << "|" <<endl;
    line(44);
    for (int x = 0;x < showharga.size();x++)
    {
        cout << "|" << setw(5) << showkode[x] << "|" << setw(20) << showbarang[x] << "|" << setw(15) << showharga[x] << "|" <<endl;
    }
    line(44);
    cout << "|" << "TOTAL HARGA TRANSAKSI : " << setw(18) << totalharga << "|" <<endl;
    line(44);
    
    int bayarbayar;
    gagalbayar:
    cout << "Masukkan Nominal Uang : ";cin >> bayarbayar;
    if (bayarbayar >= totalharga)
    {
        clear_screen();
        line(44);
        cout << "|" << setw(5) << "Kode" << "|" << setw(20) << "Nama Barang" << "|" << setw(15) << "Harga Barang" << "|" <<endl;
        line(44);
        for (int x = 0;x < showharga.size();x++)
        {
            cout << "|" << setw(5) << showkode[x] << "|" << setw(20) << showbarang[x] << "|" << setw(15) << showharga[x] << "|" <<endl;
        }
        line(44);
        cout << "|" << "TOTAL HARGA TRANSAKSI : " << setw(18) << totalharga << "|" <<endl;
        line(44);
        cout << "|" << "Cash : " << setw(35) << bayarbayar << "|" <<endl;
        line(44);
        cout << "|" << "Kembalian : " << setw(30)  << bayarbayar-totalharga << "|" <<endl;
        line(44);
        cout << endl;
        cout << "Terima Kasih Telah Berbelanja" <<endl;
        cout << "Press Enter To Continue....." <<endl;
        cin.get();
    }
    else {
        cout << "Jumlah Uang Yang Di Bayarkan Kurang!" <<endl;
        goto gagalbayar;
    }

    showkode.clear();
    showharga.clear();
    showbarang.clear();
    totalharga = 0;
}

void searchharga()
{
    string inputsearch;
    bool flag = false;
    cout << "Masukkan Kode Barang/Harga/Stock yang Ingin Di Cari : ";cin >> inputsearch;
    for (int x = 0;x < MAX-1;x++)
    {
        if (brg[x].kodebarang == inputsearch || brg[x].stringhargabarang == inputsearch || brg[x].stringstockbarang == inputsearch)
        {
            cout << endl;
            cout << "Kode Barang : " << brg[x].kodebarang << endl;
            cout << "Nama Barang : " << brg[x].namabarang <<endl;
            cout << "Harga Barang : " << brg[x].hargabarang <<endl;
            cout << "Stock Barang : " << brg[x].stockbarang <<endl;
            flag = true;
        }
        if (x == MAX-2 && flag == false)
        {
            cout << endl;
            cout << "Kode Atau Harga Barang Yang Di Cari Tidak Di Tersedia" <<endl <<endl;
        }
    }
    cout << "Press Enter To Continue....." <<endl;
    cin.get();
}

void sortingbarang()
{
    int pilihannn;
    cout << "Menu Sorting Daftar Barang  " <<endl;
    cout << "Menu Sorting : " <<endl;
    cout << "1.Harga " <<endl;
    cout << "2.Stock" <<endl;
    replay:
    cout << "Masukkan Pilihan : ";cin >> pilihannn;

    if (pilihannn == 1)
    {
        sortbarangmurah();
        line(60);
        cout << "|" << setw(5) << "Kode" << "|" << setw(20) << "Nama Barang" << "|" << setw(15) << "Harga Barang" << "|" << setw(15) << "Stock Barang" << "|" <<endl;
        line(60);
        for (int x=0;x < MAX;x++)
        {
            cout << "|" << setw(5) << brg[x].kodebarang << "|" << setw(20) << brg[x].namabarang << "|" << setw(15) << brg[x].hargabarang << "|" << setw(15) << brg[x].stockbarang << "|" <<endl;
        }
        line(60);
    }
    else if (pilihannn == 2)
    {
        sortstockbarang();
        line(60);
        cout << "|" << setw(5) << "Kode" << "|" << setw(20) << "Nama Barang" << "|" << setw(15) << "Harga Barang" << "|" << setw(15) << "Stock Barang" << "|" <<endl;
        line(60);
        for (int x=0;x < MAX;x++)
        {
            cout << "|" << setw(5) << brg[x].kodebarang << "|" << setw(20) << brg[x].namabarang << "|" << setw(15) << brg[x].hargabarang << "|" << setw(15) << brg[x].stockbarang << "|" <<endl;
        }
        line(60);
    }
    else {
        cout << "Menu Yang Di Pilih Salah,Harap Masukkan kembali" <<endl;
        goto replay;
    }
    cout << "Press Enter To Continue...." <<endl;

}

void sortbarangmurah() {
    
  for (int step = 0; step < (MAX-1); ++step) {
      
    int swapped = 0;
    
    for (int i = 0; i < (MAX-step-1); ++i) {
        
      if (brg[i].hargabarang > brg[i + 1].hargabarang) {

        int temp = brg[i].hargabarang;
        brg[i].hargabarang = brg[i + 1].hargabarang;
        brg[i + 1].hargabarang = temp;
        
        string tempbrg = brg[i].namabarang;
        brg[i].namabarang = brg[i + 1].namabarang;
        brg[i + 1].namabarang = tempbrg;

        string tempkode = brg[i].kodebarang;
        brg[i].kodebarang = brg[i + 1].kodebarang;
        brg[i + 1].kodebarang = tempkode;

        string tempstrharga = brg[i].stringhargabarang;
        brg[i].stringhargabarang = brg[i + 1].stringhargabarang;
        brg[i + 1].stringhargabarang = tempstrharga;

        int stockbrg = brg[i].stockbarang;
        brg[i].stockbarang = brg[i + 1].stockbarang;
        brg[i + 1].stockbarang = stockbrg;
        swapped = 1;
      }
    }
    if (swapped == 0)
      break;
  }
}

void sortstockbarang() {
    
  for (int step = 0; step < (MAX-1); ++step) {
      
    int swapped = 0;
    
    for (int i = 0; i < (MAX-step-1); ++i) {
        
      if (brg[i].stockbarang > brg[i + 1].stockbarang) {

        int temp = brg[i].hargabarang;
        brg[i].hargabarang = brg[i + 1].hargabarang;
        brg[i + 1].hargabarang = temp;
        
        string tempbrg = brg[i].namabarang;
        brg[i].namabarang = brg[i + 1].namabarang;
        brg[i + 1].namabarang = tempbrg;

        string tempkode = brg[i].kodebarang;
        brg[i].kodebarang = brg[i + 1].kodebarang;
        brg[i + 1].kodebarang = tempkode;

        string tempstrharga = brg[i].stringhargabarang;
        brg[i].stringhargabarang = brg[i + 1].stringhargabarang;
        brg[i + 1].stringhargabarang = tempstrharga;

        int stockbrg = brg[i].stockbarang;
        brg[i].stockbarang = brg[i + 1].stockbarang;
        brg[i + 1].stockbarang = stockbrg;
        swapped = 1;
      }
    }
    if (swapped == 0)
      break;
  }
}

void savedata()
{
    system ("rm Data.csv");
    system("call > Data.csv");
    out.open("Data.csv",ios::in);
    for (int x = 0;x < MAX;x++)
    {
        out << brg[x].kodebarang << "," << brg[x].namabarang << "," << brg[x].hargabarang << "," << brg[x].stockbarang << "\n";
        
    }
    out.close();
}

void tambahstockbarang()
{
    bool tanda = false;
    string inputkode;
    cout << "Menu Penambahan Stock" <<endl;
    line(60);
    cout << "|" << setw(5) << "Kode" << "|" << setw(20) << "Nama Barang" << "|" << setw(15) << "Harga Barang" << "|" << setw(15) << "Stock Barang" << "|" <<endl;
    line(60);
    for (int x=0;x < MAX;x++)
    {
        cout << "|" << setw(5) << brg[x].kodebarang << "|" << setw(20) << brg[x].namabarang << "|" << setw(15) << brg[x].hargabarang << "|" << setw(15) << brg[x].stockbarang << "|" <<endl;
    }
    line(60);
    cout << "Masukkan Kode Barang Yang Ingin Di Tambah Stock : ";cin >> inputkode;
    for (int x = 0;x < MAX;x++)
    {
        if (inputkode == brg[x].kodebarang)
        {
            int tambahstock;
            cout << "Masukkan Jumlah Stock Barang " << brg[x].namabarang << " : ";cin >> tambahstock;
            brg[x].stockbarang = brg[x].stockbarang + tambahstock;
            cout << "Data Stock Berhasil Di Tambahkan" <<endl;
            cin.get();
            tanda = true;
        }
        if (x == MAX-1 && tanda == false)
        {
            cout << "Data Kode Barang Tidak Tersedia" <<endl;
            cin.get();
        }
    }
}

void kurangstockbarang()
{
    bool tanda = false;
    string inputkode;
    cout << "Menu Penambahan Stock" <<endl;
    line(60);
    cout << "|" << setw(5) << "Kode" << "|" << setw(20) << "Nama Barang" << "|" << setw(15) << "Harga Barang" << "|" << setw(15) << "Stock Barang" << "|" <<endl;
    line(60);
    for (int x=0;x < MAX;x++)
    {
        cout << "|" << setw(5) << brg[x].kodebarang << "|" << setw(20) << brg[x].namabarang << "|" << setw(15) << brg[x].hargabarang << "|" << setw(15) << brg[x].stockbarang << "|" <<endl;
    }
    line(60);
    cout << "Masukkan Kode Barang Yang Ingin Di Tambah Stock : ";cin >> inputkode;
    for (int x = 0;x < MAX;x++)
    {
        if (inputkode == brg[x].kodebarang)
        {
            int tambahstock;
            cout << "Masukkan Jumlah Kurang Stock Barang  " << brg[x].namabarang << " : ";cin >> tambahstock;
            brg[x].stockbarang = brg[x].stockbarang - tambahstock;
            cout << "Data Stock Berhasil Di Kurangi" <<endl;
            cin.get();
            tanda = true;
        }
        if (x == MAX-1 && tanda == false)
        {
            cout << "Data Kode Barang Tidak Tersedia" <<endl;
            cin.get();
        }
    }
}



void clear_screen()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
