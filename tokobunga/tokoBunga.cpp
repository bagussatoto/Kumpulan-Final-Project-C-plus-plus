#include <iostream>
#include <windows.h>
#include <ctime>
#define MAX 100
using namespace std;

int i;
time_t now = time(0);
char* dt = ctime(&now);

struct Menu {
	string bunga[5]={"Mawar", "Melati", "Matahari", "Gerbera", "Anggrek"} ;
	int hargaBunga[5]={15000, 4000, 20000, 5000, 5000};
} mn;

struct Sort {
	int tukar;
	int n=5;
} srt;

struct Record {
	int bunga[MAX];
	int jumlah[MAX];
	string nama[MAX];
	int depan;
	int belakang;
} rcd;


//Sorting start
void sortingMenu() {
	for (int i = 0; i < srt.n-1; i++) {
        srt.tukar = i;
        string temp;
        for(int j = i+1; j < srt.n; j++){
            if(mn.bunga[j] < mn.bunga[srt.tukar]){
                srt.tukar = j;
            }
        }   

        temp = mn.bunga[srt.tukar];
        mn.bunga[srt.tukar] = mn.bunga[i];
        mn.bunga[i] = temp;
        
    }

    for(int i = 0; i < srt.n; i++){
    	if(mn.bunga[i]=="Matahari") {
    		cout << i+1<<". "<<mn.bunga[i] << "\t\t : "<<mn.hargaBunga[i]<<endl;
    		continue;
		}
        cout << i+1<<". "<< mn.bunga[i] << "\t\t : "<<mn.hargaBunga[i]<<endl;
    }
}
//Sorting end

//Queue start
struct Queue {
	int depan;
	int belakang;
	int bunga[MAX];
	int jumlah[MAX];
} queue;

struct Customer {
	string nama[MAX];
	int nomer=1;
	int antrian[MAX];
}cstm;

bool isEmpty() {
	return(queue.belakang==-1);
}

bool isFull() {
	return(queue.belakang>=(MAX-1) );
}

void inisialisasi() {
	queue.depan = queue.belakang = -1;
	rcd.depan = rcd.belakang = -1;
}

//Nota start
void nota(int i) {
	int harga;
	int bayar;
	cout<<"\n\n\n\n\t\t\tNota Pemesanan Bunga"<<endl;
		cout<<" ======================================================================";
		cout<<"\n\t\tNo Antrian      : "<<cstm.antrian[i];
		cout<<"\n\t\tNama Pemesan    : "<<cstm.nama[i];
		if(queue.bunga[i]==1) {
			cout<<"\n\t\tBunga       	: Anggrek";   
			harga=15000;
		} else if(queue.bunga[i]==2) {
			cout<<"\n\t\tBunga       	: Gerbera";   
			harga=4000;
		} else if(queue.bunga[i]==3) {
			cout<<"\n\t\tBunga       	: Matahari";   
			harga=20000;
		} else if(queue.bunga[i]==4) {
			cout<<"\n\t\tBunga       	: Mawar";   
			harga=5000;
		} else if(queue.bunga[i]==5) {
			cout<<"\n\t\tBunga       	: Melati";   
			harga=5000;
		}
		
		cout<<"\n\t\tJumlah          : "<<queue.jumlah[i];
		
        cout<<"\n\t\tTanggal Pesan   : "<<dt;
        cout<<" ======================================================================";
        
        
        cout<<"\n\n\t\tBiaya Total      : Rp. "<<queue.jumlah[i]*harga;
        cout<<"\n\t\tBayar            : Rp. ";cin>>bayar;
        cout<<"\n\t\tKembali          : Rp. "<<bayar-(queue.jumlah[i]*harga);


        cout<<"\n ======================================================================";
               
        cout<<"\n\n\t\tTerima Kasih Telah Membeli Bunga\n\n";
}
//Nota end

void enqueue(int bunga, int jumlah, string nama) {
	if(isFull()) {
		cout<<"Antrian sudah penuh!!!\n";
	} else {
		queue.depan = 0;
		queue.belakang++;
		queue.bunga[queue.belakang]=bunga;
		queue.jumlah[queue.belakang]=jumlah;
		cstm.nama[queue.belakang]=nama;
		cstm.antrian[queue.belakang]=cstm.nomer++;
		
		rcd.depan = 0;
		rcd.belakang++;
		rcd.bunga[rcd.belakang]=bunga;
		rcd.jumlah[rcd.belakang]=jumlah;
		rcd.nama[rcd.belakang]=nama;
		
		system("cls"); 
		nota(queue.belakang);
	}
	
}

void dequeue() {
	cout<<"Antrian "<<cstm.antrian[queue.depan]<<" atas nama "<<cstm.nama[queue.depan]<<" sudah dihapus"<<endl<<endl;
	
	for(int i=queue.depan; i<=queue.belakang; i++) {
		queue.bunga[i]=queue.bunga[i+1];
		queue.jumlah[i]=queue.jumlah[i+1];
		cstm.nama[i]=cstm.nama[i+1];
		cstm.antrian[i]=cstm.antrian[i+1];
	}
	queue.belakang--;
}

void clear() {
	queue.depan = queue.belakang = -1;
	cout<<"Antrian sudah dikosongkan"<<endl<<endl;
}

void print() {
	int no=1;
	if(isEmpty()) {
		cout<<"Antrian masih kosong!!!\n";
	} else {
		cout<<"Isi pesanan : \n";
		for(int i=queue.depan; i<=queue.belakang; i++) {
			if(queue.bunga[i]==1) {
				cout<<cstm.antrian[i]<<". "<<cstm.nama[i]<<" : Anggrek sejumlah "<<queue.jumlah[i];
			} else if(queue.bunga[i]==2) {
				cout<<cstm.antrian[i]<<". "<<cstm.nama[i]<<" : Gerbera  sejumlah "<<queue.jumlah[i];
			} else if(queue.bunga[i]==3) {
				cout<<cstm.antrian[i]<<". "<<cstm.nama[i]<<" : Matahari sejumlah "<<queue.jumlah[i];
			} else if(queue.bunga[i]==4) {
				cout<<cstm.antrian[i]<<". "<<cstm.nama[i]<<" : Mawar sejumlah "<<queue.jumlah[i];
			} else if(queue.bunga[i]==5) {
				cout<<cstm.antrian[i]<<". "<<cstm.nama[i]<<" : Melati sejumlah "<<queue.jumlah[i];
			}
			cout<<endl;
		}
		cout<<endl<<endl;
		
	}
}
//Queue end

//Search start
void searchBunga() {
	bool found{false};
	int key, total=0, no=1;
	cout << "\nMasukan bunga yang ingin dicari : ";
	cin >> key;
	
	for (int i=rcd.depan; i<=rcd.belakang; i++)
	{
		if (rcd.bunga[i] == key)
		{
			if(rcd.bunga[i]==1) {
				cout<<no<<". "<<rcd.nama[i]<<" : Anggrek sejumlah "<<rcd.jumlah[i];
			} else if(rcd.bunga[i]==2) {
				cout<<no<<". "<<rcd.nama[i]<<" : Gerbera  sejumlah "<<rcd.jumlah[i];
			} else if(rcd.bunga[i]==3) {
				cout<<no<<". "<<rcd.nama[i]<<" : Matahari sejumlah "<<rcd.jumlah[i];
			} else if(rcd.bunga[i]==4) {
				cout<<no<<". "<<rcd.nama[i]<<" : Mawar sejumlah "<<rcd.jumlah[i];
			} else if(rcd.bunga[i]==5) {
				cout<<no<<". "<<rcd.nama[i]<<" : Melati sejumlah "<<rcd.jumlah[i];
			}
			cout<<endl;
			found=true;
			total+=rcd.jumlah[i];
			no++;
			continue;
		}
	}
	
	if(found==false) {
		cout<<"Data yang Anda cari tidak ditemukan!";
	}
	
	cout<<"\n\nTotal bunga yang dicari ada : "<<total<<endl<<endl;

}
//Search end


int main(){
	inisialisasi();
	int pilihan;
	int bunga;
	int jumlah;
	string nama;
	
	main:
	system("cls"); 
	cout<<"\n\n=========================================================\n\n";
	cout<<"\t\t\tTOKO BUNGA RENI!\n";
	cout<<"=========================================================\n\n";
	
	cout<<"1. Menu Bunga\n";
	cout<<"2. Pesan Bunga\n";
	cout<<"3. Hapus Antrian\n";
	cout<<"4. List Antrian\n";
	cout<<"5. Cari Penjualan Bunga\n";
	cout<<"6. Keluar";
	
	cout<<endl<<endl;
	
	cout<<"Pilih nomor: ";
	cin>>pilihan;
	
	if(pilihan==1) {
		sortingMenu();
		
        system("pause");
    	goto main;
	} else if(pilihan==2) {
		sortingMenu();
		cout<<"Nama pemesan : ";
		cin>>nama;
		cout<<"Masukkan nomor pilihan bunga : ";
		cin>>bunga;
		cout<<"Jumlah bunga : ";
		cin>>jumlah;
		enqueue(bunga, jumlah, nama);
		
        system("pause");
    	goto main;
	} else if(pilihan==3) {
		dequeue();
		
        system("pause");
    	goto main;
	} else if(pilihan==4) {
		print();
		
        system("pause");
    	goto main;
	} else if(pilihan==5) {
		sortingMenu();
		searchBunga();
		
		system("pause");
    	goto main;
	}else if(pilihan==6) {
		cout<<"Terima Kasih!\n\n";
		system("cls");
	}
	
	return 0;
}
