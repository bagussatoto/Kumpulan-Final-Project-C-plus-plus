#include <iostream>
#include <stdlib.h>
using namespace std;

void pilihMenu();
void truthTabel();
void menuProgram();
void hitungGaji();
void hitungPajak();
void pajakMotor();
void pajakMobil();
void pilihWarna();
int main(){
    menuProgram();
}

// All Functions

// Fungsi End Program
void endProgram(){
    system("cls");
    cout << "\tKELOMPOK 0";
    cout << "\n1. BAGUS BUDI SATOTO \t\t\t 21.11.0000 ";
    cout << "\nTerimakasih telah menggunakan program kami\n\n";
    cout << "Klik Enter untuk keluar dari program";
    cin.ignore();
    cin.get();
    exit(0);
}

// Fungsi Pilihan
void pilihMenu(){
    string jawab;
    cout << "\nIngin Menjalankan lagi? Ya atau Tidak : ";
    cin >> jawab;
    if (jawab == "Ya" || jawab == "ya"){
        truthTabel();
    } else if ( jawab == "Tidak" || "tidak"){
        menuProgram();
    }else{
        cout << "Input yang anda masukkan salah";
        cout << "Klik Enter untuk melanjutkan";
        cin.ignore();
        cin.get();
        pilihMenu();
    }
    
    
}

// Fungsi Cek Variable apakah ada yang sama atau tidak
void cekVariable(int inp, char nama[]){
    for (int  i = 0; i <= inp; i++){
        for (int j = i+1; j <= inp; j++){
            // Cek Kondisi Input Nilai Variable tidak boleh ada yg sama
            if (nama[i] == nama[j]){
                cout << "\n\t===================================\n";
                cout << "\t=============== ALERT =============\n";
                cout << "\t= Nama variable tidak boleh sama! =\n";
                cout << "\t===================================\n";
                cout << "\t===================================\n";
                cin.ignore();
                cout << "\nKlik Enter untuk kembali ke Program Truth Table";
                cin.get();
                truthTabel();
            }
        }
    }
}

// Fungsi Truth Tablel
void truthTabel(){
    system("cls");
    int inpVar;
    string pilihan;

    cout << "============================";
    cout << "\n========== PROGRAM =========";
    cout << "\n======= TRUTH TABLE ========";
    cout << "\n============================\n\n";

    cout << "Masukkan Jumlah Variable : ";
    cin >> inpVar;
    char namaVar[inpVar];

    if (inpVar <= 5){
        for (int i = 0; i < inpVar; i++){
            cout << "Masukkan nama Variable ke-"<< i+1 << " : ";
            cin >> namaVar[i];
        }
    }else{
        cout << "Mohon maaf program ini masih dalam tahap pengembangan dan belum bisa menjalankan perintah lebih dari 5\n";
        cout << "Silahkan klik Enter untuk coba lagi";
        cin.ignore();
        cin.get();
        truthTabel();
    }

    cekVariable(inpVar,namaVar);
    if (inpVar <= 0){
        cout << "Mohon maaf angka yang anda inputkan tidak valid\n";
        cout << "Silahkan klik Enter untuk coba lagi";
        cin.ignore();
        cin.get();
        truthTabel();
    } else if (inpVar == 1){
        cout<<namaVar[0] << "\t" << "!"<< namaVar[0] << "\t";
        for (int a = 0; a <= 1; a++){
            cout<<"\n\n"<< a << "\t" << !a;
        }
        pilihMenu();
    } else if (inpVar == 2){
        cout<<namaVar[0] << "\t" <<  namaVar[1] << "\t" << "!" << namaVar[0] << "\t" << "!" << namaVar[1] << "\t" << namaVar[0] << "." << namaVar[1] << "\t" << namaVar[0] << "+" << namaVar[1];
        for (int a = 0; a <= 1; a++)
        for (int b = 0; b <= 1; b++){
        cout<<"\n\n"<< a << "\t" << b << "\t" << !a << "\t" << !b << "\t" << (a && b) << "\t" << (a || b);
        }      
        pilihMenu();
    }else if (inpVar == 3){
        cout<<namaVar[0] << "\t" <<  namaVar[1] << "\t" << namaVar[2] << "\t" << "!" << namaVar[0] << "\t" << "!" << namaVar[1] << "\t" << "!" << namaVar[2] << "\t" << namaVar[0] << "." << namaVar[1] << "." << namaVar[2] << "\t" << namaVar[0] << "+" << namaVar[1] << "+" << namaVar[2];
        for (int a = 0; a <= 1; a++)
        for (int b = 0; b <= 1; b++)
        for (int c = 0; c <= 1; c++){
            cout<<"\n\n"<< a << "\t" << b << "\t" << c << "\t" << !a << "\t" << !b << "\t" << !c << "\t" << (a && b && c) << "\t" << (a || b || c);                  
        } 
        pilihMenu();
    }else if (inpVar == 4){
        cout<<namaVar[0] << "\t" <<  namaVar[1] << "\t" << namaVar[2] << "\t" << namaVar[3] << "\t" << "!" << namaVar[0] << "\t" << "!" << namaVar[1] << "\t" << "!" << namaVar[2] << "\t" << "!" << namaVar[3] << "\t" << namaVar[0] << "." << namaVar[1] << "." << namaVar[2] << "." << namaVar[3] << "\t" << namaVar[0] << "+" << namaVar[1] << "+" << namaVar[2] << "+" << namaVar[3];
        for (int a = 0; a <= 1; a++)
        for (int b = 0; b <= 1; b++)
        for (int c = 0; c <= 1; c++)
        for (int d = 0; d <= 1; d++){
            cout<<"\n\n"<< a << "\t" << b << "\t" << c << "\t" << d << "\t" << !a << "\t" << !b << "\t" << !c << "\t" << !d << "\t    " << (a && b && c && d) << "\t    " << (a || b || c || d);                  
        }
        pilihMenu();
    }else if (inpVar == 5){
        cout<<namaVar[0] << "\t" <<  namaVar[1] << "\t" << namaVar[2] << "\t" << namaVar[3] << "\t" << namaVar[4] << "\t" << "!" << namaVar[0] << "\t" << "!" << namaVar[1] << "\t" << "!" << namaVar[2] << "\t" << "!" << namaVar[3] << "\t" << "!" << namaVar[4] << "\t" << namaVar[0] << "." << namaVar[1] << "." << namaVar[2] << "." << namaVar[3] << "." << namaVar[4] << "\t" << namaVar[0] << "+" << namaVar[1] << "+" << namaVar[2] << "+" << namaVar[3] << "+" << namaVar[4];
        for (int a = 0; a <= 1; a++)
        for (int b = 0; b <= 1; b++)
        for (int c = 0; c <= 1; c++)
        for (int d = 0; d <= 1; d++)
        for (int e = 0; e <= 1; e++)
        {
            cout<<"\n\n"<< a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << !a << "\t" << !b << "\t" << !c << "\t" << !d << "\t" << !e << "\t    " << (a && b && c && d && e) << "\t\t   " << (a || b || c || d || e);                  
        }
        pilihMenu();
    }
}

void menuProgram(){
    int a;
    system("cls");
    cout << "=====================================";
    cout << "\n=============== PROJECT =============";
    cout << "\n============= KELOMPOK 0 ============\n";
    cout << "\n1. Truth Tabel";
    cout << "\n2. Hitung Pajak";
    cout << "\n3. Hitung Gaji Karyawan";
	cout << "\n4. Pilih Warna Program";
    cout << "\n5. Exit\n";
    cout << "\n=====================================";
    cout << "\n=====================================\n";
    cout << "\nPilih Program yang ingin dijalankan : ";
    cin >> a;
    if (a == 1){
        truthTabel();
    } else if (a == 2){
        hitungPajak();
    }else if (a == 3){
        hitungGaji();
    }else if (a == 4){
		pilihWarna();
	}else if (a == 5){
        endProgram();
    }else{
        cout << "Input yang anda masukkan salah!!";
        cout << "\nKlik enter untuk kembali ke menu";
        cin.ignore();
        cin.get();
        menuProgram();
    }
}
// Fungsi Hitung Pajak
void hitungPajak(){
    float nilaiJualMotor,nilaiJualMobil,presentasePajak = 0,kepemilikan = 0.02,sumbanganWajibDanaMotor = 32000 , sumbanganWajibDanaMobil = 100000;
    int bobot,tanganKe,hasilDenda,hasil;
    const float tambah = 0.005 ;
    string pilihDenda,pilih;

        // menu:
        system("cls");
        cout << "___________________________\n";
        cout << "PENGHITUNG PAJAK KENDARAAN\n";
        cout << "___________________________\n";
        cout << "1. Motor\n";
        cout << "2. Mobil\n";
        cout << "3. Back To Main Menu\n";
        cout << "4. Exit\n";
        cout << "___________________________\n";
        cout << "Silahkan pilih Kendaraan untuk dibayar pajak = ";
        cin >> pilih;
    system("cls");
    if (pilih == "1"){
        pajakMotor();
    }else if( pilih == "2"){
            pajakMobil();
    }else if(pilih == "3"){
        cin.ignore();
        menuProgram();
    }else if(pilih == "4"){
        cin.ignore();
        endProgram();
    }else if (pilih != "4" && pilih != "3" && pilih != "2" && pilih != "1") {
        cin.ignore();
        cout << "Mohon Maaf Input yang anda masukkan salah, klik enter untuk kemabli ke menu";
        cin.get();
        system("cls");
        hitungPajak();
    }
}
// Pajak Motor
void pajakMotor(){
    float nilaiJualMotor,presentasePajak = 0,kepemilikan = 0.02,sumbanganWajibDanaMotor = 32000 ;
    int bobot,tanganKe,hasilDenda,hasil;
    const float tambah = 0.005 ;
    string pilihDenda;

        system("cls");
        cout << "------------------------------------------------------------------------------\n";
        cout << "\t\t\tRINCIAN PEMBAYARAN PAJAK\n";
        cout << "------------------------------------------------------------------------------\n";
        cout << "Harga Jual Motor(Tanpa titik)\t = Rp. ";
        cin >> nilaiJualMotor;
            cout << "Bobot (1)\t\t\t = ";
            cin >> bobot ;
            cout << "Kepemilikan tangan ke\t\t = ";
            cin >> tanganKe;
            cout << "Apakah ada Denda?\n";
            cout << "Pilih 'Ya' atau 'Tidak'\t\t = ";
            cin >> pilihDenda;
            cout << "------------------------------------------------------------------------------\n";
            
            if ( tanganKe == 1){
                presentasePajak += kepemilikan ;
            } else{
                for (int i = 2; i <= tanganKe; i++){
                    kepemilikan += tambah ;
                }
            }
            presentasePajak = kepemilikan;
            hasil = (nilaiJualMotor * bobot) * presentasePajak ;
        
        if (pilihDenda == "ya" || pilihDenda == "Ya"){
            int bulan;
            cout << "Keterlambatan berapa bulan\t = ";
            cin >> bulan;
            cout << "------------------------------------------------------------------------------\n";
            hasilDenda = (hasil * 25/100 * bulan / 12) + sumbanganWajibDanaMotor;
            cout << "Total Pajak Motor\t\t = Rp. " << hasilDenda + hasil << "\n";
            cout << "------------------------------------------------------------------------------\n";
            cin.ignore();
            cout << "\nSilahkan Klik enter untuk kembali ke menu";
            cin.get();
            hitungPajak();
        } else if (pilihDenda == "tidak" || pilihDenda == "Tidak"){
            cout << "Total Pajak Motor\t\t = Rp. " << hasil << "\n"; ;
            cout << "------------------------------------------------------------------------------\n";
            cin.ignore();
            cout << "\nSilahkan Klik enter untuk kembali ke menu";
            cin.get();
            hitungPajak();
        }else {
            cin.ignore();
            cout << "Mohon Maaf Input yang anda masukkan tidak valid! Klik enter untuk reset";
            cin.get();
            pajakMotor();
        }
}
// Pajak Mobil
void pajakMobil(){
    float nilaiJualMobil,presentasePajak = 0,kepemilikan = 0.02, sumbanganWajibDanaMobil = 100000;
    int bobot,tanganKe,hasilDenda,hasil;
    const float tambah = 0.005 ;
    string pilihDenda;

            system("cls");
            cout << "------------------------------------------------------------------------------\n";
            cout << "\t\t\tRINCIAN PEMBAYARAN PAJAK\n";
            cout << "------------------------------------------------------------------------------\n";
            cout << "Harga Jual Mobil(Tanpa titik)\t = Rp. ";
            cin >> nilaiJualMobil;
            cout << "Bobot (1)\t\t\t = ";
            cin >> bobot ;
            cout << "Kepemilikan tangan ke\t\t = ";
            cin >> tanganKe;
            cout << "Apakah ada Denda?\n";
            cout << "Pilih 'Ya' atau 'Tidak'\t\t = ";
            cin >> pilihDenda;
            cout << "------------------------------------------------------------------------------\n";


                if ( tanganKe == 1){
                    presentasePajak += kepemilikan ;
                } else{
                    for (int i = 2; i <= tanganKe; i++){
                        kepemilikan += tambah ;
                    }
                }

                presentasePajak = kepemilikan;
                hasil = (nilaiJualMobil * bobot) * presentasePajak ;
    
            if (pilihDenda == "ya" || pilihDenda == "Ya"){
                int bulan;
                cout << "Keterlambatan berapa bulan\t = ";
                cin >> bulan;
                cout << "------------------------------------------------------------------------------\n";
                hasilDenda = (hasil * 25/100 * bulan / 12) + sumbanganWajibDanaMobil;
                cout << "Total Pajak Mobil\t\t = Rp. " << hasilDenda + hasil << "\n";
                cout << "------------------------------------------------------------------------------\n";
                cin.ignore();
                cout << "\nSilahkan Klik enter untuk kembali ke menu";
                cin.get();
                hitungPajak();

            } else if (pilihDenda == "tidak" || pilihDenda == "Tidak"){
                cout << "Total Pajak Mobil\t\t = Rp. " << hasil << "\n";
                cout << "------------------------------------------------------------------------------\n";
                cin.ignore();
                cout << "\nSilahkan Klik enter untuk kembali ke menu";
                cin.get();
                hitungPajak();
            }else{
                cin.ignore();
                cout << "Mohon Maaf Input yang anda masukkan tidak valid! Klik enter untuk reset";
                cin.get();
                pajakMobil();
            }
}
// Fungsi Hitung Gaji
void hitungGaji(){
    string nama,lembur,jawab;
    int masuk,libur,jmLmbr,gLmbr;
    int gaji,total;
       
    system("cls");
    cout << "Mohon untuk menginputkan gaji harian terlebih dahulu! Klik enter untuk lanjut";
    cin.ignore();
    cin.get();

    system("cls");
    cout << "Gaji Harian(Tanpa titik) = Rp. " ;
    cin >> gaji;
    menuKaryawan:
    cout << "Masukkan Nama Karyawan = ";
    cin.ignore();
    getline(cin,nama);
    cout << "Jumlah Hari Masuk = ";
    cin >> masuk;
    cout << "Jumlah Hari Libur = ";
    cin >> libur;
    cout << "Apakah ada Lembur?";
    cout << "Ya atau Tidak = ";
    cin >> lembur;
    if (lembur == "ya" || lembur == "Ya"){
        cout << "Gaji Lembur per-Jam = Rp. ";
        cin >> gLmbr;
        cout << "Jumlah Jam kerja lembur = ";
        cin >> jmLmbr;
        total = gaji * (masuk - libur);
        total += jmLmbr * gLmbr;
        cout << nama << " Menerima Gaji sebesar = Rp. " << total ;

        cout << "\n\nInput Lagi? Ya atau Tidak = " ;
        cin >> jawab;
        if (jawab == "Ya" || jawab == "ya"){
            goto menuKaryawan;
        } else{
            menuProgram();
        }
        
    } else{
        total = gaji * (masuk - libur);
        cout << nama << " Menerima Gaji sebesar = Rp. " << total ;
        cout << "\n\nInput Lagi? Ya atau Tidak = " ;
        cin >> jawab;
        if (jawab == "Ya" || jawab == "ya"){
            goto menuKaryawan;
        } else{
            menuProgram();
        }
    }
}

void pilihWarna(){
	int pWarna;
	string jawab;
	
	pilwarna :
	system("cls");
	cout << "==========================================="    << endl;
	cout << "           Pilih Warna Teks Anda           "    << endl;
	cout << "==========================================="    << endl;
	cout << "0. Hitam   6. Kuning        12. Ungu Muda"  	 << endl;
	cout << "1. Biru    7. Putih         13. Kuning Muda" 	 << endl;
	cout << "2. Hijau   8. Abu-abu       14. Biru & putih"	 << endl;
	cout << "3. Aqua    9. Biru Muda     15. Aqua & Hitam"	 << endl;
	cout << "4. Merah   10. Hijau Muda   16. Putih Terang & Aqua"	  << endl;
	cout << "5. Ungu    11. Merah Terang 17. Back To Main Menu"       << endl;
	cout << "Masukan Pilihan Anda : ";
	cin  >> pWarna;
	
	switch(pWarna){
		case 0 :
		system("color 0");
		break;
		
		case 1 :
		system("color 1");
		break;
		
		case 2 :
		system("color 2");
		break;
		
		case 3 :
		system("color 3");
		break;
		
		case 4 :
		system("color 4");
		break;
		
		case 5 :
		system("color 5");
		break;
		
		case 6 :
		system("color 6");
		break;
		
		case 7 :
		system("color 7");
		break;
		
		case 8 :
		system("color 8");
		break;
		
		case 9 :
		system("color 9");
		break;
		
		case 10 :
		system("color A");
		break;
		
		case 11 :
		system("color C");
		break;
		
		case 12 :
		system("color D");
		break;
		
		case 13 :
		system("color E");
		break;
		
		case 14 :
		system("color 17");
		break;
		
		case 15 :
		system("color 30");
		break;
		
		case 16 :
		system("color F3");
		break;
		
		case 17 :
		cin.ignore();
		menuProgram();
		
		default :
		cin.ignore();
		cout << "Mohon Maaf Opsi Yang Anda Masukan Tidak Ada" << endl;
		cout << "Silahkan Tekan Enter Untuk Coba Lagi";
		cin.get();
		goto pilwarna;
	}
	
	cout << "\nIngin Mengganti warna lagi? Ya atau Tidak : ";
	cin >> jawab;
	if(jawab == "Ya" || jawab == "ya"){
		goto pilwarna;
	}else{
		menuProgram();
	}
	
}
