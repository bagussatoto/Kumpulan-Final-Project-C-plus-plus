// Pemanggilan standar library fungsi

// Standart library
#include <iostream>
// Library untuk fungsi sleep()
#include <unistd.h>


using namespace std;

// Deklarasi Array Data User

// Nama
string nama[3] = {"Fais", "Adit", "Sopo Jarwo"};
// Username
string username[3] = {"Faisa", "Aditya", "SopoJarwo"};
// PIN
int pin[3] = {123456, 789012, 345678};
// Bank
string bank[3] = {"TRI", "TWO", "TRI"};
// Rekening
int rekening[3] = {300001, 200021, 300002};
// Saldo
int saldo[3] = {200000, 300000, 250000};

// Deklarasi variabel tipe data Int
int pin_sekarang, pin_baru, pin_konfirmasi, pin_input, user_index = -1, opsi, admin_fee = 6500;
// Deklarasi variabel tipe data String
string username_input;
// Deklarasi variabel tipe data Boolean
bool auth = true, app = true, is_login = false, is_repeat = true;

// Fungsi menghitung jumlah inputan integer
int countInt(int n)
{
    // Merubah parameter n menjadi string, kemudian di hitung per-karakternya
    return to_string(n).length();
}

// Fungsi menampilkan pesan selamat datang
void welcome()
{
    system("cls");
    cout << "===================================" << endl;
    cout << "===      Selamat Datang di      ===" << endl;
    cout << "===           ATM TRI           ===" << endl;
    cout << "===================================" << endl;
    cout << endl;
}

// Fungsi menampilkan pesan sampai jumpa
void goodbye()
{
    system("cls");
    cout << "===================================" << endl;
    cout << "==        Berhasil Logout        ==" << endl;
    cout << "==          Terimakasih          ==" << endl;
    cout << "===================================" << endl;
}

// Fungsi menampikan menu
void show_menu()
{
    system("cls");
    cout << "===================================" << endl;
    cout << "==           MAIN MENU           ==" << endl;
    cout << "===================================" << endl;
    cout << "== 1. Transfer Dana              ==" << endl;
    cout << "== 2. Tarik Tunai                ==" << endl;
    cout << "== 3. Cek Saldo                  ==" << endl;
    cout << "== 4. Ganti Pin                  ==" << endl;
    cout << "== 0. Logout                     ==" << endl;
    cout << "===================================" << endl;
    cout << endl;
    cout << "Pilih menu [0-4]" << endl;
}

// Fungsi menampilkan pesan inputan tidak diketahui
void invalid_input()
{
    system("cls");
    cout << "===================================" << endl;
    cout << "==          Input Tidak          ==" << endl;
    cout << "==            Diketahui          ==" << endl;
    cout << "===================================" << endl;
    system("pause");
}

// Fungsi login akun
void login()
{
    cout << "Silahkan masukkan username Anda" << endl;
    cout << "> ";
    cin >> username_input;
    cout << "Masukan PIN Anda" << endl;
    cout << "> ";
    cin >> pin_input;

    /* Penjelasan menghitung jumlah array
    code :
    sizeof(arr) / sizeof(arr[0])

    penjelasan :
    operasi bagi dari sizeof(arr) yang merupakan ukuran array keseluruhan dalam bytes
    dengan sizeof(arr[0]) yang merupakan ukuran elemen array di index 0 */
    for (int i = 0; i < sizeof(username) / sizeof(username[0]); i++)
    {
        if (username[i] == username_input)
        {
            user_index = i;
        }
    }

    if (user_index != -1)
    {
        if (pin[user_index] == pin_input)
        {
            cout << "Login berhasil.." << endl;
            cout << "Tunggu.." << endl;
            auth = false;
            is_login = true;
            sleep(2);
        }
        else
        {
            cout << "Akun tidak ditemukan \nSilahkan coba lagi" << endl;
            user_index = -1;
            system("pause");
        }
    }
    else
    {
        cout << "Akun tidak ditemukan \nSilahkan coba lagi" << endl;
        system("pause");
    }
}

// Fungsi logout akun
void logout()
{
    system("cls");
    cout << "Tunggu.." << endl;
    is_login = false;
    auth = true;
    is_repeat = true;
    user_index = -1;
    sleep(1);
    system("cls");
    goodbye();
    system("pause");
}

// Fungsi konfirmasi transaksi lagi
int repeat()
{
    char ulangi;

    system("cls");
    cout << "===================================" << endl;
    cout << "==  Apakah Anda ingin melakukan  ==" << endl;
    cout << "==      transaksi lainnya?       ==" << endl;
    cout << "===================================" << endl;
    cout << "[y/n]" << endl;
    cout << "> ";
    cin >> ulangi;
    if (ulangi != 'y')
    {
        is_repeat = false;
        logout();
        return false;
    }
    else
    {
        return true;
    }
}

int confirm_menu()
{
    char confirm;
    cout << "Apakah Anda ingin melanjutkan? (y/n)" << endl;
    cout << "> ";
    cin >> confirm;
    return confirm;
}

// Fungsi cek saldo
void check_balance()
{
    system("cls");
    cout << "===================================" << endl;
    cout << "==           CEK SALDO           ==" << endl;
    cout << "===================================" << endl;
    cout << "==                       " << endl;
    cout << "== Sisa Saldo Anda : Rp. " << saldo[user_index] << endl;
    cout << "===================================" << endl;
    system("pause");
    repeat();
}

// Fungsi tarik tunai
void withdraw()
{
    // Deklarasi variabel untuk fungsi tarik tunai
    int tarik, nominal;
    bool withdraw = true;

    while (withdraw)
    {
    pilihkelipatan:
        system("cls");
        cout << "===================================" << endl;
        cout << "==          TARIK TUNAI          ==" << endl;
        cout << "===================================" << endl;

        char confirm = confirm_menu();

        if (confirm == 'n')
        {
            break;
        } else if (confirm == 'y')
        {
            // kosong karena tidak melakukan apapun
        }else
        {
            invalid_input();
            break;
        }

        cout << "Sisa saldo Anda Rp. " << saldo[user_index] << endl;
        cout << "Pilih kelipatan nominal yang diinginkan" << endl;
        cout << "== 1. Rp. 50.000" << endl;
        cout << "== 2. Rp. 100.000" << endl;
        cout << "Pilih [1-2]" << endl;
        cout << "> ";
        cin >> nominal;

        if (nominal == 1)
        {
            goto jmltarik50;
        }
        else if (nominal == 2)
        {
            goto jmltarik100;
        }
        else
        {
            goto pilihkelipatan;
        }

    jmltarik100:
        cout << "masukan nominal yang ingin Anda tarik berkelipatan Rp. 100.000" << endl;
        cout << "(Tanpa titik) > Rp. ";
        cin >> tarik;

        if (tarik < 100000 || tarik > 5000000)
        {
            system("cls");
            cout << " !! Nominal minimal Rp. 100.000 dan maksimal Rp. 5.000.000 !!";
            cout << endl;
            cout << endl;
            goto jmltarik100;
        }
        else if (tarik % 100000 != 0)
        {
            system("cls");
            cout << " !! Nominal harus kelipatan Rp. 100.000 !!";
            cout << endl;
            cout << endl;
            goto jmltarik100;
        }
        else if (saldo[user_index] < tarik)
        {
            system("cls");
            cout << "Saldo Anda tidak cukup. Saldo Anda saat ini adalah : Rp. " << saldo[user_index] << endl;
            cout << endl;
            cout << endl;
            goto jmltarik100;
        }
        else
        {
            system("cls");
            cout << "Saldo = Rp. " << saldo[user_index] << " - Rp. " << tarik << endl;
            saldo[user_index] -= tarik;
            cout << "Tarik tunai sukses. Sisa saldo Anda adalah : Rp. " << saldo[user_index] << endl;
            withdraw = false;
        }

    jmltarik50:
        cout << "Masukan nominal yang ingin Anda tarik berkelipatan Rp. 50.000" << endl;
        cout << "(Tanpa titik) > Rp. ";
        cin >> tarik;

        if (tarik < 50000 || tarik > 5000000)
        {
            system("cls");
            cout << " !! Nominal minimal Rp. 50.000 dan maksimal Rp. 5.000.000 !!";
            cout << endl;
            cout << endl;
            goto jmltarik50;
        }
        else if (tarik % 50000 != 0)
        {
            system("cls");
            cout << " !! Nominal harus kelipatan Rp. 50.000!!";
            cout << endl;
            cout << endl;
            goto jmltarik50;
        }
        else if (saldo[user_index] < tarik)
        {
            system("cls");
            cout << "Saldo Anda tidak cukup. Saldo anda saat ini adalah : Rp. " << saldo[user_index] << endl;
            cout << endl;
            cout << endl;
            goto jmltarik50;
        }
        else
        {
            system("cls");
            cout << "Saldo = Rp. " << saldo[user_index] << " - Rp. " << tarik << endl;
            saldo[user_index] -= tarik;
            cout << "Tarik tunai sukses. Sisa saldo Anda : Rp. " << saldo[user_index] << endl;
            withdraw = false;
        }
        system("pause");
    }
    repeat();
}

// Fungsi ganti pin
void change_pin()
{
    bool ganti_pin = true;

    while (ganti_pin)
    {
        system("cls");
        cout << "===================================" << endl;
        cout << "==        Menu Ganti PIN         ==" << endl;
        cout << "===================================" << endl;

        char confirm = confirm_menu();

        if (confirm == 'n')
        {
            break;
        } else if (confirm == 'y')
        {
            // kosong karena tidak melakukan apapun
        }else
        {
            invalid_input();
            break;
        }

        cout << "Masukkan PIN saat ini" << endl;
        cout << "> ";
        cin >> pin_sekarang;
        cout << "Masukkan PIN baru" << endl;
        cout << "> ";
        cin >> pin_baru;
        cout << "Konfirmasi PIN baru" << endl;
        cout << "> ";
        cin >> pin_konfirmasi;

        if (pin_sekarang == pin[user_index])
        {
            if (countInt(pin_baru) < 6 || countInt(pin_konfirmasi) < 6)
            {
                cout << "Maaf PIN minimal 6 kombinasi angka" << endl;
            }
            else if (countInt(pin_baru) > 6 || countInt(pin_konfirmasi) > 6)
            {
                cout << "Maaf PIN maksimal 6 kombinasi angka" << endl;
            }
            else if (pin_baru == pin_konfirmasi)
            {
                pin[user_index] = pin_baru;
                cout << "PIN telah diubah" << endl;
                ganti_pin = false;
            }
            else
            {
                cout << "Maaf PIN baru tidak sama dengan PIN konfirmasi";
                cout << endl;
            }
        }
        else
        {
            cout << "Maaf PIN Anda salah, silahkan masukkan ulang PIN";
            cout << endl;
        }

        system("pause");
    }
    repeat();
}

// Fungsi resi transfer
void show_resi(int user_target_index, int nominal)
{
    int total;
    // tanggal / waktu sekarang berdasarkan sistem saat ini
    time_t now = time(0);

    // ubah sekarang menjadi bentuk string
    char *dt = ctime(&now);

    // ubah sekarang (now) menjadi tm struct untuk UTC
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);

    system("cls");
    cout << "=======================================" << endl;
    cout << "===             ATM TRI             ===" << endl;
    cout << "===          RESI TRANSFER          ===" << endl;
    cout << "\t" << dt << endl;
    cout << "===                                 ===" << endl;
    cout << "=======================================" << endl;
    cout << "== Bank Penerima \t: " << bank[user_target_index] << endl;
    cout << "== Nama Penerima \t: " << nama[user_target_index] << endl;
    cout << "== Rekening Tujuan \t: " << rekening[user_target_index] << endl;
    cout << "== Nominal Transfer \t: Rp. " << nominal << endl;
    if (bank[user_target_index] != "TRI")
    {
        total = nominal + admin_fee;
        cout << "== Biaya transfer antar Bank \t: Rp. " << admin_fee << endl;
        cout << "== Total biaya \t\t: Rp. " << total << endl;
    }
    else
    {
        total = nominal;
        cout << "== Biaya transfer \t: Rp. 0 " << endl;
        cout << "== Total biaya \t\t: Rp. " << nominal << endl;
    }
    cout << "=======================================" << endl;
    cout << "===          TERIMA KASIH           ===" << endl;
    cout << "===   TELAH MENGGUNAKAN BANK KAMI   ===" << endl;
    cout << "=======================================" << endl;
    cout << endl;
}

// Fungsi transfer saldo
void transfer()
{
    int rekening_target, nominal, total, user_target_index = -1;
    bool transfer = true;
    char konfirmasi;

    while (transfer)
    {
        system("cls");
        cout << "===================================" << endl;
        cout << "==         TRANSFER DANA         ==" << endl;
        cout << "===================================" << endl;

        char confirm = confirm_menu();

        if (confirm == 'n')
        {
            break;
        } else if (confirm == 'y')
        {
            // kosong karena tidak melakukan apapun
        }else
        {
            invalid_input();
            break;
        }

        cout << "Masukan rekening tujuan" << endl;
        cout << "> ";
        cin >> rekening_target;

        for (int i = 0; i < sizeof(rekening) / sizeof(rekening[0]); i++)
        {
            if (rekening_target == rekening[i])
            {
                user_target_index = i;
            }
        }

        cout << "Masukan nominal transfer" << endl;
        cout << "> Rp. ";
        cin >> nominal;

        cout << "Tunggu..." << endl;
        sleep(1);

        if (user_target_index == user_index)
        {
            cout << "Anda tidak bisa transfer ke rekening Anda sendiri" << endl;
            user_target_index = -1;
        }
        else if (user_target_index != -1)
        {
            system("cls");
            cout << "================================================" << endl;
            cout << "==                 Periksa Data               ==" << endl;
            cout << "================================================" << endl;
            cout << "== Bank Penerima \t\t: " << bank[user_target_index] << endl;
            cout << "== Nama Penerima \t\t: " << nama[user_target_index] << endl;
            cout << "== Rekening Tujuan \t\t: " << rekening[user_target_index] << endl;
            cout << "== Nominal Transfer \t\t: Rp. " << nominal << endl;
            if (bank[user_target_index] != "TRI")
            {
                total = nominal + admin_fee;
                cout << "== Biaya transfer antar Bank \t: Rp. " << admin_fee << endl;
                cout << "== Total biaya \t\t\t: Rp. " << total << endl;
            }
            else
            {
                total = nominal;
                cout << "== Biaya transfer \t\t: Rp. 0 " << endl;
                cout << "== Total biaya \t\t\t: Rp. " << nominal << endl;
            }
            cout << "================================================" << endl;
            cout << "Apakah Anda ingin melanjutkan? [y/n]: ";
            cin >> konfirmasi;
            if (konfirmasi == 'y')
            {
                if (total > saldo[user_index])
                {
                    cout << endl
                         << "Saldo Anda tidak mencukupi" << endl;
                    user_target_index = -1;
                }
                else
                {
                    cout << "Tunggu..." << endl;
                    saldo[user_index] -= total;
                    saldo[user_target_index] += total;
                    sleep(1);
                    cout << endl;
                    cout << "Transfer Berhasil" << endl;
                    cout << "Mencetak Resi..." << endl;
                    sleep(2);
                    transfer = false;
                    show_resi(user_target_index, nominal);
                }
            }
            else
            {
                system("cls");
                cout << endl
                     << "Transaksi berhasil dibatalkan" << endl;
                user_target_index = -1;
                transfer = false;
            }
        }
        else
        {
            cout << "Rekening tujuan tidak ditemukan" << endl;
        }

        system("pause");
    }
    repeat();
}

int main()
{
    // Apabila app = true, maka aplikasi akan terus berjalan
    while (app)
    {
        // Perulangan untuk login
        while (auth)
        {
            welcome();
            login();
        }

        while (is_login && is_repeat)
        {
            show_menu();
            cout << "> ";
            cin >> opsi;

            switch (opsi)
            {
            case 0:
                // Pemanggilan fungsi logout
                logout();
                break;
            case 1:
                // Pemanggilan fungsi transfer
                transfer();
                break;
            case 2:
                // Pemanggilan fungsi tarik tunai
                withdraw();
                break;
            case 3:
                // Pemangilan fungsi cek saldo
                check_balance();
                break;
            case 4:
                // Pemanggilan fungsi ganti pin
                change_pin();
                break;
            default:
                // Pemanggilan fungsi apabila input salah
                invalid_input();
                break;
            }
        }
    }
}