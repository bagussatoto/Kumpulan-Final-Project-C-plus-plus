#include <iostream>
#include <cstdlib>
#define max 10
using namespace std;

struct mahasiswa
{
	string nama;
	string nim;
	float ipk;
	int atas;
};

void awal(mahasiswa *mhs)
{
    mhs->atas=-1;
}

int kosong(mahasiswa *mhs)
{
    if (mhs->atas==-1)
        return 1;
    else
        return 0;
}
int penuh(mahasiswa *mhs)
{
    if (mhs->atas==max-1)
        return 1;
    else    
        return 0;
}

void nama(mahasiswa *mhs)					// void input nama
{
	cout << "Inputkan Nama Mahasiswa: ";
	cin.ignore();
	getline(cin, mhs->nama);
}
void nim(mahasiswa *mhs)					// void input nim
{
	cout << "Inputkan NIM Mahasiswa: ";
	cin >> mhs->nim;
	cout << endl;
}
float calculate(float *TOT,mahasiswa *mhs) 	// void menghitung IPK
{ 	
	return mhs->ipk=*TOT/5/25;	
}
void remove(mahasiswa *mhs)					// void menghapus data terakhhir Mahasiswa	
{
    if(kosong(mhs)==0)
    {
        cout << "\nData terakhir sudah terambil";
        mhs->atas--;
    }
    else
        cout << "\nData Kosong";
}
void clear(mahasiswa *mhs)					// void menghapus semua data terakhhir Mahasiswa
{
    mhs->atas=-1;
    cout<<"\nSemua data telah hapus";
}
// deklarasi fungsi back
void back();
// deklarasi fungsi input 
void input(mahasiswa *mhs); 
// deklarasi fungsi push
void push(mahasiswa *mhs);
// deklarasi fungsi sort
void sort(mahasiswa *mhs);
// deklarasi fungsi rangking 
void ranking (mahasiswa *mhs);
// deklarasi fungsi show
void show (mahasiswa *mhs);
// deklarasi fungsi find
void find (mahasiswa *mhs);

// Main Program 
int main()
{
	mahasiswa mhs[max];
	int pil;
    awal(mhs);
    do
    {	
		// swicth case tampilan menu
		cout << "--------Program Mahasiswa--------"<<endl<<endl;
        cout << "1. Input data Mahasiswa\n2. Hapus data Mahasiswa\n3. Tampil data Mahasiswa\n4. ";
        cout << "Bersihkan semua data Mahasiswa \n5. Mengurutkan Peringkat Mahasiswa \n6. Mencari Data Mahasiswa\n7. ";
		cout << "Keluar Program Mahasiswa\n\nMasukkan pilihan :";
        cin >> pil;
        switch(pil)
        {
            case 1: 	// swicth case Input data mahasiswa
		push(mhs);
		break;
            case 2: 	// swicth case Hapus data mahasiswa
		remove(mhs);
                break;
            case 3: 	// swicth case Tampil data mahasiswa
		show (mhs);
                break;
            case 4:		// swicth case Membersihkan semua data mahasiswa
		clear(mhs);
                break;
            case 5: 	// swicth case Mengurutkan data Mahasiswa secara Descending
		sort (mhs);
		break;
	    	case 6:		// swicth case Mencari data Mahasiswa
		find (mhs);		
		break;
	   		case 7:		// swicth case Keluar dari program
		cout << "-----Terimakasih telah menggunakan program data Mahasiswa-----"; 
        }
    getchar();			// meminimalisir error jika terdapat input selain int
    cout<<endl<<endl;
    }
    while(pil!=7);
	return 0;
}
void back()
{
	cin.ignore();
	cout << "\ntekan entar untuk kembali ke menu";
	cin.get();
}
void input(mahasiswa *mhs)
{	
	// Deklarasi variabel lokal
	string matkul[5] = {"Pemrograman","Sistem Operasi","Struktur Data",
						"Bahasa Inggris","Hardware/Software"};	
	float tot[max];
	int total; 	

	// alokasi blok memori nilai 			
	float *nilai = new float[max*5];
		// Input nama dan nim
		cout<<endl;
		cout << "Mahasiswa ke-" << (mhs->atas + 1) <<endl;
		total=0;
		nama(mhs + mhs->atas);
		nim(mhs + mhs->atas);
		
		for(int j=0; j<5; j++)
		{
			// input nilai Mata Kuliah Mahasiswa
			cout << "Nilai Mata kuliah "<<matkul[j]<<": ";
			cin>>*(nilai+(mhs->atas*5+j));

			// Menjumlahkan nilkai mata kuliah mahasiswa
			total = total + nilai[(mhs->atas*5+j)];	
		}
		tot[mhs->atas]=total; 

		// menghitung ipk mahasiswa
		calculate(&tot[mhs->atas],(mhs + mhs->atas));

	// bebaskan blok memori nilai mata kuliah yang dialokasikan
	delete[] nilai;
}

void push(mahasiswa *mhs)
{	
	// jika variabel kosong sama dengan 1 atau true
    if(kosong(mhs)==1)
    {
        mhs->atas++;
        input(mhs);
        cout<<"\nData "<<(mhs + mhs->atas)->nama<<" Masuk ke stack";
    }
	// jika variabel peuh sama dengan 0 atau false
    else if (penuh(mhs)==0)
    {
        mhs->atas++;
        input(mhs);
        cout<<"\nData "<<(mhs + mhs->atas)->nama<<" Masuk ke stack"; 
    }
    else
        cout<<"Data telah penuh";
}

void sort(mahasiswa *mhs)
{
	// Deklarasi Variabel loka
	string tempnama, tempnim;
	float sort;
	int jika;
	// tujuan dari label goto balik
	balik:
	cout<<endl;
	cout<<"Metode sorting"<<endl;
	cout<<"1. Bubble Sort\n2. Insertion sort\n3. selection Sort"<<endl<<endl;
	cout<<"Inputkan Metode yang ingin digunakan dari 1-3: ";
	cin>>jika;
	if(jika==1)
	{	
		// Bubble Sort
		for(int i=0;i<=mhs->atas;i++){
			for(int j=0;j<=mhs->atas;j++){
				if((mhs + j)->ipk < (mhs+j+1)->ipk){
					tempnama = (mhs + j)->nama;					// Proses selection Sort Nama
                	(mhs + j)->nama = (mhs + j + 1)->nama;		
                	(mhs + j + 1)->nama = tempnama;

					tempnim = (mhs + j)->nim;					// Proses selection Sort NIM
                	(mhs + j)->nim = (mhs + j + 1)->nim;
                	(mhs + j + 1)->nim = tempnim;

					sort = (mhs + j)->ipk;						// Proses selection Sort IPK
                	(mhs + j)->ipk = (mhs + j + 1)->ipk;
                	(mhs + j + 1)->ipk = sort;
				}
			}
		}
	cout<<"\nData sudah disortir menggunakan metode bubble sort";
	}else if(jika==2)
	{
		// Insertion Sort
	
		int loot;
		for(int i=0; i<=mhs->atas; i++){
		sort = (mhs + i)->ipk;
		tempnim = (mhs + i)->nim;
		tempnama = (mhs + i)->nama;
		loot = i-1;
		while((mhs + loot)->ipk < sort && loot>=0)
		{
			(mhs + loot + 1)->ipk = (mhs + loot)->ipk; 	// Proses selection Sort IPK
			(mhs + loot + 1)->nim = (mhs + loot)->nim; 	// Proses selection Sort NIM
			(mhs + loot + 1)->nama = (mhs + loot)->nama;// Proses selection Sort Nama
			loot--;	
		}
		(mhs + loot + 1)->ipk = sort;
		(mhs + loot + 1)->nim = tempnim;
		(mhs + loot + 1)->nama = tempnama;	
		}	
	cout<<"\nData sudah disortir menggunakan metode Insertion Sort";
	}else if(jika==3)
	{
	// Selection sort
	int maks;
	for(int i=0; i<=mhs->atas; i++)
	{	
		maks = i;
		for(int j=i+1; j<=mhs->atas; j++){
		if( (mhs + maks)->ipk < (mhs + j)->ipk)
		maks=j;
		}
			if((mhs + i)->ipk != (mhs + maks)->ipk)
		{
			tempnama = (mhs + i)->nama;				// Proses selection Sort Nama
            (mhs + i)->nama = (mhs + maks)->nama;
            (mhs + maks)->nama = tempnama;

			tempnim = (mhs + i)->nim;				// Proses selection Sort NIM
            (mhs + i)->nim = (mhs + maks)->nim;		
            (mhs + maks)->nim = tempnim;

			sort = (mhs + i)->ipk;					// Proses selection Sort IPK
            (mhs + i)->ipk = (mhs + maks)->ipk;
            (mhs + maks)->ipk = sort;
		}			
	}	
	cout<<"\nData sudah disortir menggunakan metode Selection sort";			
	}else{
	cout<<"Input yang anda masukan tidak sesuai, silahkan di input ulang"<<endl;
	//  pernyataan untuk melompat ke tujuan goto balik
	goto balik;
	}
}

void show (mahasiswa *mhs)
{
	if(kosong(mhs)==0)
	{
	// Menampilkan data nama mahasiswa
	cout <<"\nDaftar data Mahasiswa"<< endl;
	cout <<"-----------------------"<< endl;		
		for (int i=0;i<=mhs->atas;i++){
		cout <<(i+1)<<". "<<(mhs + i)->nama<<endl;			
		}
	cout <<"\n-----------------------"<< endl;
	back();
	}
	else
	{
		cout << "\nData kosong";
	}
        
}

void find (mahasiswa *mhs)
{	
	if(kosong(mhs)==0)
	{
		// Mencari data mahasiswa dengan Sequential Search
		string cari, posisinama,posisinim;
		float posisiipk;	
		cout<<"\nMasukan nama Mahasiswa yang ingin dicari: ";
		cin>>cari;
		int ketemu=0;
		for(int i=0; i<=mhs->atas; i++){
			if((mhs + i)->nama == cari)
			{
				ketemu = 1;
				posisinama = (mhs + i)->nama;
				posisinim = (mhs + i)->nim;
				posisiipk = (mhs + i)->ipk;
				i = mhs->atas;
			}
		}
		if(ketemu == 0)
		{
		cout<<"Data Mahasiswa tidak ditemukan";
		}
		else
		{
		// Menampilkan nama,nim,ipk yang dicari
		cout<<"\nMenampilkan data Mahasiswa yang dicari"<<endl<<endl;
		cout <<"Nama Mahasiswa: "<< posisinama<<endl;
		cout << "NIM: "<<posisinim<<endl;	
    	cout<<"IPK : "<<posisiipk<<endl<<endl;
		back();
		}
	}
	else
	{
		cout << "\nTumpukan kosong";
	}
}
