#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Tipe data abstrak untuk jenis kendaraan
class Kendaraan {
public:
  virtual void print() = 0; // Fungsi virtual tanpa implementasi
  virtual int hitungBiayaPerawatan() = 0; // Fungsi virtual tanpa implementasi
};

// Kelas Motor adalah turunan dari Kendaraan
class Motor : public Kendaraan {
private:
  int biayaPerawatan;
  string merek;
  string tipe;

public:
  Motor(string merek, string tipe, int biayaPerawatan) {
    this->merek = merek;
    this->tipe = tipe;
    this->biayaPerawatan = biayaPerawatan;
  }

  void print() {
    cout << "Motor: " << merek << " " << tipe << endl;
  }

  int hitungBiayaPerawatan() {
    return biayaPerawatan;
  }
};

// Kelas Mobil adalah turunan dari Kendaraan
class Mobil : public Kendaraan {
private:
  int biayaPerawatan;
  string merek;
  string tipe;

public:
  Mobil(string merek, string tipe, int biayaPerawatan) {
    this->merek = merek;
    this->tipe = tipe;
    this->biayaPerawatan = biayaPerawatan;
  }

  void print() {
    cout << "Mobil: " << merek << " " << tipe << endl;
  }

  int hitungBiayaPerawatan() {
    return biayaPerawatan;
  }
};

// Kelas Bengkel
class Bengkel {
private:
  string nama;
  vector<Kendaraan*> daftarKendaraan; // Array of pointer ke objek Kendaraan

public:
  Bengkel(string nama) {
    this->nama = nama;
  }

  void tambahKendaraan(Kendaraan* kendaraan) {
    daftarKendaraan.push_back(kendaraan);
  }

  void printDaftarKendaraan() {
    for (int i = 0; i < daftarKendaraan.size(); i++) {
      daftarKendaraan[i]->print();
    }
  }

  int hitungTotalBiayaPerawatan() {
    int total = 0;
    for (int i = 0; i < daftarKendaraan.size(); i++) {
      total += daftarKendaraan[i]->hitungBiayaPerawatan();
    }
    return total;
}
};

int main() {
// Membuat objek bengkel
Bengkel bengkel("Bengkel ABC");

// Membuat objek motor dan mobil
Motor motor1("Yamaha", "Vixion", 100000);
Motor motor2("Honda", "CBR", 120000);
Mobil mobil1("Toyota", "Avanza", 200000);
Mobil mobil2("Honda", "Mobilio", 250000);

// Menambahkan kendaraan ke daftar kendaraan di bengkel
bengkel.tambahKendaraan(&motor1);
bengkel.tambahKendaraan(&motor2);
bengkel.tambahKendaraan(&mobil1);
bengkel.tambahKendaraan(&mobil2);

// Menampilkan daftar kendaraan yang ada di bengkel
bengkel.printDaftarKendaraan();

// Menghitung total biaya perawatan kendaraan di bengkel
cout << "Total biaya perawatan: " << bengkel.hitungTotalBiayaPerawatan() << endl;

return 0;
}