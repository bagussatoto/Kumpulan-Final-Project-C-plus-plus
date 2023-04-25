#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "buyer_data.cpp"

using namespace std;
char oke;
int subMenu, chsCat;
bool menuCon; 
bool pilihMenu = true;


    void pilihItem(){
            int i = ID1;

            for (int j = 0; j < 10; j++)
            {   
                if (menuMakan[i][j] == "em" || hargaMakan[i][j] == 0) // JIKA SISA ARRAY KOSONG
                {   
                    cout << " ";
                } else{ // JIKA ARRAY TIDAK KOSONG
                    cout << "\t\t " << j+1 << ". " << menuMakan[i][j];
                    for (int k = 0; k < space; k++)
                    {
                        cout << " ";
                    }
                    cout << "  ||  Rp. "; dot(&hargaMakan[i][j]); cout << endl;
                    }
            }

            cout << "\t\t=========================================" << endl;
            cout << "\t\tPilih: "; cin >> ID2;
            ID2-=1;
            enQueue(buyer);
            cout << "\t\tApakah ingin menambah pesanan? y/n : "; cin >> oke;
            if (oke == 'y'|| oke == 'Y'){
                ordering = true;
            } else {
                ordering = false;
                antrian++;
            }
    }
    
    

    void headerResto(){
        cout << "\t\t=====================================" << endl;
        cout << "\t\t||       RESTORAN PUNYA RASA       ||" << endl;
        cout << "\t\t=====================================" << endl;
    }
    void headerFood(){
        system("CLS");
        cout << "\t\t=========================================" << endl;
        cout << "\t\t||               MAKANAN               ||" << endl;
        cout << "\t\t=========================================" << endl;
    }

    void headerDrink(){
        system("CLS");
        cout << "\t\t=========================================" << endl;
        cout << "\t\t||               MINUMAN               ||" << endl;
        cout << "\t\t=========================================" << endl;
    }
    void mainMenu(){
        if (antrian == -1)
        {
            antrian = 0;
        }
        
        cout << "\t\t||=================================||" << endl;
        cout << "\t\t||   1. Pesan Makanan              ||" << endl;
        cout << "\t\t||   2. Tampil Data  (" << antrian << ")           ||" << endl;
        cout << "\t\t||   3. Dequeue                    ||" << endl;
        cout << "\t\t||   4. Exit                       ||" << endl;
        cout << "\t\t=====================================" << endl;
        cout << "\t\t     pilih : "; cin >> subMenu;
        
    }


    void category(){
        system("CLS");
        cout << "\t\t=====================================" << endl;
        cout << "\t\t||      MENU RESTO PUNYA RASA      ||" << endl;
        cout << "\t\t||       PILIH KATEGORI MENU       ||" << endl;
        cout << "\t\t||=================================||" << endl;
        cout << "\t\t||   1. Makanan                    ||" << endl;
        cout << "\t\t||   2. Minuman                    ||" << endl;
        cout << "\t\t=====================================" << endl;
        cout << "\t\t||    pilih : "; cin >> chsCat;

        if (chsCat == 2)
        {
            ID1 = 4;
        } 
    }

    void foodMenu(){
        system("CLS");
        headerFood();
        cout << "\t\t||   1. Ayam                           ||" << endl;
        cout << "\t\t||   2. Cumi                           ||" << endl;
        cout << "\t\t||   3. Udang                          ||" << endl;
        cout << "\t\t||   4. Sapi                           ||" << endl;
        cout << "\t\t=========================================" << endl;
        cout << "\t\t||   pilih : "; cin >> ID1; ID1 -= 1;
    }
    
    void detailFood(){
        system("CLS");
        headerFood(); // LAYOUT HEADER 
        pilihItem();
    cout << "\n\t\tKlik tombol apa saja...";
    getch();
    system("cls");
    // pilihMenu();
}

    void detailDrink()
    {
    system("CLS");
    headerDrink();
    pilihItem();
    cout << "\n\t\tKlik tombol apa saja...";
    getch();
    system("cls");
    }

    int main(){
        system("cls");
        do
        {   
            amogus();
            cout << "\n";
            headerResto();
            mainMenu();
            switch (subMenu)
            {
            case 1:
                do
                {
                    category();
                    if (chsCat == 1)
                    {
                        headerFood();
                        foodMenu();
                        detailFood();
                    } else if (chsCat == 2)
                    {
                        headerDrink();
                        detailDrink();
                    }
                    sortDescending(buyer);
                }while (ordering);
                tail++;
                break;
            case 2:
                system("cls");
                displayData(buyer);
                getch();
                system("cls");
                break;
            case 3:
                cout << "\t\t\n\nData sudah dihapus";
                deQueue(buyer);
                getch();
                system("cls");
                break;
            case 4:
                system("CLS");
                amogusExit();
                getch();
                system("CLS");
                pilihMenu = false;
                break;
            default:
                cout << "Invalid input, please try again";
                break;
            }
        } while (pilihMenu);
    }
