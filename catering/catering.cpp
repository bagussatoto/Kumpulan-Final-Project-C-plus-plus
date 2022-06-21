
#include <iostream>
#include <string.h>
#include <stdlib.h>
#define max 100
using namespace std;

int head, tail, pilih;
bool ketemu = false;

void init(){
	head = 0;
	tail = -1;
}

//queue
bool isEmpty(){
	if(tail == -1){
		return true;
	} else {
		return false;
	}		
}

bool isFull(){
	if(head == max-1){
		return true;
	} else {
		return false;
	}
}

//struct
typedef struct catering
{
	char nama[100];
	char alamat[50];
	char nohp[13];
	float tglkrm;
	int total;
} catering;

catering data[1000];
int i=0;

//fungsi non void
int harga(int nasi, int ayam, int sayur, int lauk)
{
	int total;
	data[tail].total = nasi*5000+ayam*6000+sayur*3000+lauk*5000;
	return data[tail].total;
	tail++; //mengulang data input next
}

int tanggal(int tglorder){
	float tgl;
	data[tail].tglkrm=tglorder+2; //+2 waktu pengerjaan
	return data[tail].tglkrm;
	tail++;
}

void order(){
	int nasi=5000, ayam=6000, sayur=3000, lauk=5000;
	int uang, kembalian, hutang;
	float tglorder;
	int a=0, z=0, temp;
	
	if (isFull()){
		cout<<"Antrian Penuh";
	} else {
		system("color 7");
		cout<<"=========================================================================================="<<endl;
		cout<<" Nama Pelanggan \t: "; cin>>data[tail].nama;
		cout<<" Alamat\t\t\t: "; cin>>data[tail].alamat;
		cout<<" No. HP \t\t: "; cin>>data[tail].nohp;
		cout<<" Tanggal Pesan \t\t: "; cin>>tglorder;
		tanggal(tglorder);
		cout <<"==========================================================================================" << endl;
	
		cout<<"Nama Makanan				Harga[satuan]				Pesanan[satuan]"<<endl;
		cout<<"============================================================================================="<<endl;
		cout<<"\n 1. Nasi				Rp. 5.000				"; cin>>nasi;
		cout<<"\n 2. Ayam				Rp. 6.000				"; cin>>ayam;
		cout<<"\n 3. Sayur				Rp. 3.000				"; cin>>sayur;
		cout<<"\n 4. Lauk				Rp. 5.000				"; cin>>lauk;	

		system("cls");
		cout<<"------------------------ Resi Pesanan ------------------------\n";
		cout<<"==============================================================\n";
		cout<<" Nama Pelanggan		: "<<data[tail].nama<<endl;
		cout<<" Alamat			: "<<data[tail].alamat<<endl;
		cout<<" No. HP			: "<<data[tail].nohp<<endl;
		cout<<"==============================================================\n";
		cout<<" Total harga		: Rp. "<<harga(nasi,ayam,sayur,lauk);

		cout<<"\n Input Uang		: RP. "; cin>>uang;
			if(uang>harga(nasi,ayam,sayur,lauk)){
				kembalian = uang-harga(nasi,ayam,sayur,lauk);
				hutang = 0;
				cout<<"==============================================================\n";
				cout<<" Kembalian		: Rp. "<<kembalian;
			} else if (uang==harga(nasi,ayam,sayur,lauk)){
				kembalian = 0;
				hutang = 0;
				cout<<"==============================================================\n";
				cout<<" Kembalian		: Rp. "<<kembalian;
			} else {
				kembalian = 0;
				hutang = harga(nasi,ayam,sayur,lauk)-uang;
				cout<<"==============================================================\n";
				cout<<" Hutang			: Rp. "<<hutang;
			}
		cout<<"\n\n\n";
		tail++;
	}
	system("pause");
}

void hapus(){
	if(isEmpty()==false){
		int head;
		cout<<"Data Berhasil di Hapus! "<<endl;
		for(int i=head; i<tail; i++){
			data[i]=data[i+1];
		}
		tail--;
	} else {
		cout<<"Antrian Kosong"<<endl;
	}
	system("pause");
}

void dataorder(){
	if(isEmpty()==false){
		int a;
		system("color 7");
		cout<<"\t\t------------------------ DATA PESANAN CATERING ------------------------\n";
		cout<<" NO.\tNama\t\tNO HP\t\tAlamat\t\tTotal Harga\t\tTanggal Diambil\n";
		cout<<"====================================================================================================";
		cout<<endl;
		
		for(a=head; a<tail; a++){
			cout<<" "<< a+1 << "\t" << data[a].nama << "\t\t" << data[a].nohp << "\t" << data[a].alamat << "\t\t" << data[a].total << "\t\t\t" << data[a].tglkrm;
			cout<<"\n====================================================================================================";
			cout<<endl;
		}
		cout<<endl;
		cout<<"\n\n\n";
	} else {
		cout<<"Antrian Kosong"<<endl;
	}
	system("pause");
}

//searching
void cari(){
	string cari;
	cout<<"Masukkan nama yang dicari : "; cin>>cari;
	
	for(int a=head; a<tail; a++){
		if(data[a].nama == cari){
			ketemu = true;
			break;
		}
	}
		if(ketemu){
			cout<<"Nama Ditemukan Dalam Data!"<<endl;
		} else {
			cout<<"Nama Tidak Ada Dalam Data!"<<endl;
		}
		system("pause");
}

//Bubble Sort Ascending
void PengurutanTotal(){
	int j;
	int temp; //penyimpanan sementara
	
	for(i=head; i<tail; i++){
		for(j=i+1; j<tail; j++){
			if(data[i].total>data[j].total){
				temp = data[i].total;
				data[i].total = data[j].total;
				data[j].total = temp;
			}
		}
	}
	
	cout<<"-------------- DATA TELAH DIURUTKAN --------------\n";
	for(i=head; i<tail; i++){
		cout<<i+1<<". "<<data[i].total<<endl;
	}
	cout<<"--------------------------------------------------\n";
	system("pause");
}

int main(){
	int menu;
	
	cout<<"\t\t\tSELAMAT DATANG\n";
	cout<<"======================================================\n";
	awal:
	// perulangan do while
	do{
		cout<<"======================================================\n";
		cout<<" Pilihan Menu \n";
		cout<<" 1. Order Catering \n";
		cout<<" 2. Data Pesanan \n";
		cout<<" 3. Hapus Data Pesanan \n";
		cout<<" 4. Cari Data Pelanggan \n";
		cout<<" 5. Urutkan Data Total Harga \n";
		cout<<" 6. Exit \n";
		cout<<"======================================================\n";
		cout<<"Pilih Menu : "; cin>>menu;
		switch(menu) //menu switch case
		{
			case 1: system("cls");
				order(); //fungsi void yang sudah dibuat di atas
				system("cls"); //seperti fitur clear di terminal linux
				break;
			case 2: system("cls");
				dataorder();
				system("cls");
				break;
			case 3: system("cls");
				hapus();
				system("cls");
				break;
			case 4: system("cls");
				cari();
				system("cls");
				goto awal;
				break;
			case 5: system("cls");
				PengurutanTotal();
				system("cls");
				goto awal;
				break;
			case 6: exit(0);
		}
	} while(menu);
	return 0;
}
