/*
Autor : Bagus Budi Satoto
		Informatika
		Universitas Amikom Yogyakarta
*/

#include <iostream> // Untuk menampilan perintah cin, cout, endl
#include <conio.h> //library yg berisi Untuk menampilkan perintah getch
#include <stdio.h> //digunakan untuk perintah gets()

using namespace std;

void line(){
	cout<<"\n -------------------------------------------------------------------------- \n";
}

int m,i,j,z;

int y,v,pin;

struct x{
	char nama[100];
	int nim;
}x[100];

	char jb[100][100];
	int b[100];
	int c[100];


int main(){

	// initialize variabel //

	int tp,tk;
	char user[50];
	int kb[pin];
	char stats;
	int q,pass;
	int denda;
	int kb1;
	
	// ------------ Login ------------- // 
	atas:
	line();
	cout<<" Selamat Datang di Aplikasi Peminjaman Buku Perpustakaan";
	line();
	cout<<"\n Silahkan login terlebih dahulu ";
	cout<<"\n\n Username : ";
	gets(user);	//-- untuk menginput lebih dari satu kata (menggunakan spasi), dapat di gunakan perintah gets() --//
	
	cout<<"\n PIN : ";cin>>pass;
	if(pass == 1234){  
		line(); 
		cout<<"\n User Berhasil Login\n";
		cout<<endl;
		cout<<" Tekan Enter untuk melanjutkan...";
		getch();
		system("cls");

	}else{
		cout<< "\n Password Salah\n";
		cout<<endl;
		system("cls");
		goto atas;
	}
	
	// ------------ Menu -------------- //
	
	menu:
	line();
	cout<<"\t\t\t  Pilihan Menu Peminjaman";
	line();

	cout<<"\n1. Input Data Buku \n";
	cout<<"2. Daftar Buku \n";
	cout<<"3. Pendaftaran Anggota \n";
	cout<<"4. Data Anggota \n";
	cout<<"5. Peminjaman Buku \n";
	cout<<"6. Pengembalian Buku \n";
	cout<<"7. Rekap Buku \n";
	cout<<"8. Keluar\n";
	cout<<"\n Masukkan Pilihan Anda : ";cin>>m;
	system("cls");
	switch(m){

		case 1 :	// ---------------- INPUT DATA BUKU ---------------- //
		line();
		cout<<"\t\t  INPUT DATA BUKU";
		line();
		cout<<" Jumlah buku yang akan diinputkan : ";cin>>j;
		line();
		
		for(i=0;i<j;i++){
			cout<<"\n Buku Ke - "<<i+1;
			cout<<"\n\n Kode Buku : ";cin>>b[i];
			cout<<"\n Judul Buku : ";cin>>jb[i];	
			cout<<"\n Jumlah Buku yang serupa : ";cin>>c[i]; 
		}
		goto menu;
		break;

		case 2 :	// ---------------- DAFTAR BUKU ---------------- //
		
		cout<<"\t";line();
		cout<<"\t\t ------------- Daftar Buku ---------------";
		cout<<"\t";line();
		cout<<":\t Kode buku \t|\t Judul buku \t|\t Jumlah buku \t |";
		line();
		for(i=0;i<j;i++){
			cout<<": \t  "<<b[i]<< "\t\t|\t "<<jb[i]<<"\t\t|\t\t"<<c[i]<<"\t |"<<endl;
		}
		line();
		cout<<endl;
		goto menu;
		break;


		case 3 :	// ----------- Pendaftaran Anggota (PA) -------------- //
		pa:
		line();
		cout<<"\t\t ----------- Pendaftaran Anggota -------------";
		line();
		cout<<"\n Jumlah Pendaftar : ";cin>>y;

		for(z=1; z<=y; z++){
			cout<<"\n Anggota Ke - "<<z;
			cout<<"\n\n NIM : ";cin>>x[z].nim;
			cout<<"\n Nama : ";cin>>x[z].nama;
		}
		system("cls");
		goto menu;
		break;

		case 4 :	// ----------- Data nama anggota ----------------- //
		line();
		cout<<"\t\t ------------- Data Anggota -------------";
		line();
		cout<<" No :\t NIM \t\t|\t\t Nama \t\t\t|";
		line();
		for(z=1; z<=y; z++){
			cout<<" "<<z<<"  : \t"<<x[z].nim<<"\t\t| "<<x[z].nama<<"\t\t|\t"<<endl;
		}
		line();
		goto menu;
		break;

		case 5 :	// --------------- Peminjaman Buku ----------------- //
		pb:
		line();
		cout<<"\n NIM : ";cin>>v;
		line();
		bool bo;
		bo=false;

		for(z=1; z<=y; z++){
			if(v == x[z].nim){
				bo=true;
				cout<<" Nama : "<<x[z].nama;
			}
			if(bo == false){
				cout<<"\n NIM TIDAK DITEMUKAN \n";
				cout<<"\n Kembali... \n";
				getch();
				system("cls");
				goto pb;
			}
		}
		line();
		cout<<" Jumlah buku yang dipinjam = ";cin>>pin;


		for(q=1;q<=pin;q++){
			line();
			cout<<"\n Masukkan Kode Buku : ";cin>>kb[q];
			line();
			for(i=0;i<j;i++){
				if(kb[q] == b[i]){
					cout<<" Judul Buku = "<<jb[i];
					c[i] = c[i]-1;
				}
			}						
		}
		line();
		cout<<" Tanggal Pinjam : ";cin>>tp;
		goto menu;
		break;

		case 6 :	// --------------- Pengembalian Buku ---------------//
		pb2:
		line();
		cout<<"NIM : ";cin>>v;
		line();
		bo=false;
		for(z=1; z<=y; z++){
			if(v == x[z].nim){
				cout<<"Nama : "<<x[z].nama;
				bo=true;
			}
			if(bo == false){
				cout<<"\n NIM TIDAK DITEMUKAN \n";
				cout<<"\n Kembali... \n";
				getch();
				system("cls");
				goto pb2;
			}	
		}
		line();
		cout<<"\n Jumlah Buku yang dipinjam = "<<pin;
		line();

		for(q=1;q<=pin;q++){
			line();
			cout<<"\n Kode Buku = "<<kb[q];
			for(i=0;i<j;i++){
				if(kb[q] == b[i]){
					cout<<" Judul Buku = "<<jb[i];
					c[i] = c[i]+1;
				}
			}
			line();
		}
		line();
		cout<<"\n Tanggal Pinjam : "<<tp;
		cout<<"\n Tanggal Kembali : ";cin>>tk; 
		if((tk-tp)>=7)
		{	
			denda=(((tk-tp)-7)*500);
		}else{
			denda=0;
		}
		line();
		cout<<"\n Denda : "<<denda<<" Rupiah";
		line();
		cout<<" Lunas (y/n) : ";cin>>stats;
		if(stats == 'y'||stats == 'Y'){
			system("cls");
			denda=0;
			kb1=0;
			goto menu;
		}else{
			kb1=1;
			goto menu;			
		}
		break;

		case 7 :	// ------------------- Rekap buku ------------------ //
		re :
		line();
		cout<<" NIM : ";cin>>v;
		line();
		bo=false;

		for(z=1; z<=y; z++){
			if(v == x[z].nim){
				cout<<" Nama : "<<x[z].nama;
				bo=true;
			}
			if(bo == false){
				cout<<"\n NIM TIDAK DITEMUKAN \n";
				cout<<"\n Kembali... \n";
				getch();
				system("cls");
				goto re;
			}
		}
		line();
		if(kb1 == 0){
			cout<<"\n Anda tidak meminjam buku ";
			line();
			system("pause");
		}else{
			for(q=1;q<=pin;q++){
				line();		
				cout<<"\n Kode Buku = "<<kb[q];
				for(i=0;i<j;i++){
					if(kb[q] == b[i]){
						cout<<"\n Judul Buku = "<<jb[i];
						c[i] = c[i]+1;
					}
				}
				line();		
			}
			
			line();
			cout<<"\n Tanggal Pinjam : "<<tp;
			cout<<"\n Tanggal Saat ini : ";cin>>tk; 
			if((tk-tp)>=7)
			{
				denda=(((tk-tp)-7)*500);
			}else{
				denda=0;
			}
			line();
			cout<<" Denda = "<<denda;
			line();
		}
		getch();		
		system("cls");
		goto menu;
		break;
		
		default :	// -------------------- end --------------------- //
		end:
		cout<<"\n Terima kasih telah menggunakan aplikasi ini";

		cout<<"\n \n Press any key to continue ... \n\n\n\n";
		break;
	}
	getch();
	return 0;
}
