#include <iostream>

using namespace std;

string nama, nim, user_fakul, fakul[3];
int fakultas, prodi, spp_tetap, sks, spp_vbl, totbay;

void Percabangan(int fakul_kuliah){
	//Code If ELse
	char kelas;
	if(fakul_kuliah == 1){
		user_fakul = fakul[0];
		cout<<"Kamu adalah Anggota dari "<<user_fakul<<endl;
		cout<<"Apakah Anda Memilih Kelas International. (Y/n)"<<endl;
		cin>>kelas;
		if(kelas == 'Y' || kelas == 'y' ){ // Ya untuk kelas inter
			spp_tetap = 2550000;
			spp_vbl = 180000;
		}
		else{ // tidak, default reguler
			spp_tetap = 2075000;
			spp_vbl = 140000;
		}
	}
	else if(fakul_kuliah == 2){
		user_fakul = fakul[1];
		cout<<"Kamu adalah Anggota dari "<<user_fakul<<endl;
		spp_tetap = 1475000;
		spp_vbl = 140000;
	}
	else if(fakul_kuliah == 3){
		user_fakul = fakul[2];
		cout<<"Kamu adalah Anggota dari "<<user_fakul<<endl;
		spp_tetap = 2075000;
		spp_vbl = 140000;
	}
	else{
		throw range_error("Mohon Masukkan Input yang sudah disediakan di atas.\n");
	}
}




//Fungsi Menghitung Total Bayar
int Perhitungan(int spp_ttp, int spp_variabel, int sks){
	int spp_totVbl = spp_variabel * sks;
	int tot_bay = spp_ttp + spp_totVbl;
	cout<<"Total SPP Tetap \t\t: "<<spp_ttp<<endl;
	cout<<"\tSPP Variabel \t: "<<spp_variabel<<endl;
	cout<<"\tsks \t\t: "<<sks<<endl;
	cout<<"Total SPP Variabel \t\t: "<<spp_totVbl<<endl;
	cout<<"Total Yang Harus Dibayarkan \t: "<<tot_bay<<endl;
	return tot_bay;
}

int main(){
	
	fakul[0] = "Fakultas Ilmu Komputer";
	fakul[1] = "Fakultas Ekonomi dan Sosial";
	fakul[2] = "Fakultas Sains dan Teknologi";
	
	// Code Input Nama dan Nim 
	cout<<"Masukkan NIM Anda : ";
	cin>>nim;
	cout<<"Masukkan Nama Anda : ";
	getline(cin >> ws, nama);
	
	cout<<"Silahkan Masukkan Fakultas Anda"<<endl;
	cout<<"Ketik 1 untuk Fakultas Ilmu Komputer"<<endl;
	cout<<"Ketik 2 untuk Fakultas Ekonomi dan Sosial"<<endl;
	cout<<"Ketik 3 untuk Fakultas Sains dan Teknologi"<<endl;
	cin>>fakultas;
	try
	{
		Percabangan(fakultas);
		cout<<"Masukkan SKS : ";
		cin>>sks;

		cout<<"\nAdministrasi Mahasiswa Amikom"<<endl; 
		cout<<user_fakul<<endl;
		cout<<"Nama Mahasiswa : "<<nama<<endl;
		cout << "NIM : " << nim << endl;
		Perhitungan(spp_tetap, spp_vbl, sks);
	}
	catch(const exception& e)
	{
		cerr << e.what() << '\n';
	}

	return 0;
}
