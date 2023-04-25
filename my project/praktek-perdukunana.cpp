#include <iostream>
#include <string>
#include <array>

using namespace std;

const int MAX_SPELLS = 10; // konstanta untuk maksimum jumlah sihir

// Fungsi untuk menampilkan daftar sihir yang tersedia
void displaySpells(array<string, MAX_SPELLS> spells)
{
    for (int i = 0; i < spells.size(); i++)
    {
        cout << i + 1 << ". " << spells[i] << endl;
    }
}

// Fungsi untuk mengacak urutan sihir
void shuffleSpells(array<string, MAX_SPELLS> &spells)
{
    for (int i = 0; i < spells.size(); i++)
    {
        // mengacak urutan sihir dengan menukar posisi sihir dengan sihir lain secara acak
        int j = rand() % spells.size();
        string temp = spells[i];
        spells[i] = spells[j];
        spells[j] = temp;
    }
}

// Fungsi untuk menyihir
void castSpell(array<string, MAX_SPELLS> spells)
{
    cout << "Pilih sihir yang ingin digunakan (1-" << MAX_SPELLS << "): ";
    int spellIndex;
    cin >> spellIndex;

    // Validasi input
    while (spellIndex < 1 || spellIndex > MAX_SPELLS)
    {
        cout << "Sihir tidak tersedia. Silakan pilih sihir yang tersedia (1-" << MAX_SPELLS << "): ";
        cin >> spellIndex;
    }

    // Menampilkan efek sihir
    cout << "Memulai sihir " << spells[spellIndex - 1] << "..." << endl;
    cout << "Efek sihir: ";
    if (spells[spellIndex - 1] == "petir")
    {
        cout << "memanggil petir dari langit!" << endl;
    }
    else if (spells[spellIndex - 1] == "apipo")
    {
        cout << "memanggil api dari bumi!" << endl;
    }
    else if (spells[spellIndex - 1] == "tsunami")
    {
        cout << "memanggil tsunami dari laut!" << endl;
    }
    else if (spells[spellIndex - 1] == "gempur")
    {
        cout << "menyerang musuh dengan kekuatan yang luar biasa!" << endl;
    }
    else if (spells[spellIndex - 1] == "pemulihan")
    {
        cout << "memulihkan kesehatan dan kekuatan pengguna sihir!" << endl;
    }
    else
    {
        cout << "tidak diketahui" << endl;
    }
}

int main()
{
    // Inisialisasi daftar sihir
    array<string, MAX_SPELLS> spells = {"petir", "apipo", "tsunami", "gempur", "pemulihan", "eskalasi", "anugerah", "pelindung", "berkat", "kekebalan"};

    // Menampilkan daftar sihir yang tersedia
    cout << "Daftar sihir yang tersedia: " << endl;
    displaySpells(spells);

    // Menanyakan kepada pengguna apakah ingin mengacak daftar sihir
    cout << "Apakah Anda ingin mengacak daftar sihir? (y/n) ";
    char shuffleChoice;
    cin >> shuffleChoice;

    // Mengacak daftar sihir jika pengguna memilih untuk mengacak
    if (shuffleChoice == 'y' || shuffleChoice == 'Y')
    {
        shuffleSpells(spells);
        cout << "Daftar sihir teracak: " << endl;
        displaySpells(spells);
    }

    // Menanyakan kepada pengguna apakah ingin menyihir
    cout << "Apakah Anda ingin menyihir? (y/n) ";
    char castChoice;
    cin >> castChoice;

    // Menjalankan sihir jika pengguna memilih untuk menyihir
    if (castChoice == 'y' || castChoice == 'Y')
    {
        castSpell(spells);
    }

    return 0;
}