#include <stdio.h>
#include <iostream>
#include <cstring>
 
int main()
    {
        char nama[80], nomor_hp[80], switchKategori[45], kategori;
        int harga, total_bayar, kembalian, berat, total;
 
        //Judul Program
        std::cout<<"================================="<<std::endl;  
        std::cout<<"\tAplikasi Berkah Laundry"<<std::endl;  
        std::cout<<"================================="<<std::endl<<std::endl;
 
        //Data Customer
        std::cout<<"\tData Customer Laundry"<<std::endl;
        std::cout<<"---------------------------------"<<std::endl;
        std::cout<<"Nama Customer   : ";std::cin>>nama;
        std::cout<<"No Handphone    : ";std::cin>>nomor_hp;
        std::cout<<"---------------------------------"<<std::endl;
 
        //Pilih Kategori
        std::cout<<"\tKategori Cucian"<<std::endl;
        std::cout<<"---------------------------------"<<std::endl;
        std::cout<<"1. Reguler (2 Hari)"<<std::endl;
        std::cout<<"2. Ekspress (1 Hari)"<<std::endl;
        std::cout<<"3. Kilat (3 Jam)"<<std::endl;
        std::cout<<"4. Promo (2 Hari - Minimal 5Kg)"<<std::endl;
        std::cout<<"---------------------------------"<<std::endl;
        std::cout<<"Pilih No Kategori [1-4]  : ";std::cin>>kategori;
       
        //Kondisi Switch Case
        switch(kategori)
            {
                case '1' :
                    strcpy(switchKategori, "Paket Reguler Cuci 2 Hari");
                    harga=10000;
                break;
                case '2' :
                    strcpy(switchKategori, "Paket Ekspress Cuci 1 Hari");
                    harga=12000;
                break;
                case '3' :
                    strcpy(switchKategori, "Paket Kilat Cuci 3 Jam");
                    harga=15000;
                break;
                case '4' :
                    strcpy(switchKategori, "Paket Cuci Promo");
                    harga=8500;
                break;
                default:
                    strcpy(switchKategori, "Nomor Kategori Yang Dimasukkan Salah");
                break;
            }
 
        std::cout<<"Berat Cucian (Kg)       : ";std::cin>>berat;  
        std::cout<<"-------------------------------------------"<<std::endl;
 
        //Result Pemesanan Jasa Laundry
        std::cout<<"\tDetail Pemesanan Berkah Laundry"<<std::endl;
        std::cout<<"-------------------------------------------"<<std::endl;
        std::cout<<"Nama Customer   : "<<nama<<std::endl;
        std::cout<<"No. Handphone   : "<<nomor_hp<<std::endl;
        std::cout<<switchKategori<<": Rp. "<<harga<<std::endl;
       
        //rumus perhitungan total
        total=harga*berat;
        std::cout<<"Total Harga     : Rp. "<<total<<std::endl;
        std::cout<<"============================================"<<std::endl;
        std::cout<<"Total Bayar     : Rp. ";std::cin>>total_bayar;
       
        //rumus perhitungan kembalian
        kembalian=total_bayar-total;
        std::cout<<"Kembalian       : Rp. "<<kembalian<<std::endl;
        std::cout<<"============================================"<<std::endl;
        std::cout<<""<<std::endl;
    }