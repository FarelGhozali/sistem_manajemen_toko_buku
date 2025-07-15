// Sistem Manajemen Toko Buku - Console
// Library tambahan untuk formatting
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

// Struktur data buku
struct Buku
{
  char kode[10];
  char judul[50];
  char penulis[30];
  int harga;
  int stok;
};

const int MAKS_BUKU = 100;
Buku daftarBuku[MAKS_BUKU];
int jumlahBuku = 0;

// Fungsi untuk menambah data buku
// Menggunakan pointer ke array dan pointer ke jumlah buku
void tambahBuku(Buku *bukuArr, int *jml)
{
  if (*jml >= MAKS_BUKU)
  {
    cout << "\nData buku penuh!\n";
    return;
  }
  Buku *b = &bukuArr[*jml];
  cout << "\nMasukkan kode buku: ";
  cin >> b->kode;
  cout << "Masukkan judul buku: ";
  cin.ignore();
  cin.getline(b->judul, 50);
  cout << "Masukkan penulis: ";
  cin.getline(b->penulis, 30);
  cout << "Masukkan harga: ";
  cin >> b->harga;
  cout << "Masukkan stok: ";
  cin >> b->stok;
  (*jml)++;
  cout << "\nBuku berhasil ditambahkan!\n";
}

// Fungsi untuk menampilkan daftar buku
void tampilkanBuku(Buku *bukuArr, int jml)
{
  cout << "\nDaftar Buku:\n";
  cout << setfill('-') << setw(85) << "" << setfill(' ') << endl;
  cout << left
       << setw(4) << "No"
       << setw(10) << "Kode"
       << setw(25) << "Judul"
       << setw(20) << "Penulis"
       << setw(12) << "Harga"
       << setw(8) << "Stok" << endl;
  cout << setfill('-') << setw(85) << "" << setfill(' ') << endl;
  for (int i = 0; i < jml; i++)
  {
    cout << left
         << setw(4) << i + 1
         << setw(10) << bukuArr[i].kode
         << setw(25) << bukuArr[i].judul
         << setw(20) << bukuArr[i].penulis
         << setw(12) << bukuArr[i].harga
         << setw(8) << bukuArr[i].stok << endl;
  }
  cout << setfill('-') << setw(85) << "" << setfill(' ') << endl;
}

// Fungsi untuk mengubah data buku
void ubahBuku(Buku *bukuArr, int jml)
{
  char kodeCari[10];
  cout << "\nMasukkan kode buku yang ingin diubah: ";
  cin >> kodeCari;
  for (int i = 0; i < jml; i++)
  {
    if (strcmp(bukuArr[i].kode, kodeCari) == 0)
    {
      cout << "Data lama:\n";
      cout << "Judul: " << bukuArr[i].judul << "\nPenulis: " << bukuArr[i].penulis << "\nHarga: " << bukuArr[i].harga << "\nStok: " << bukuArr[i].stok << endl;
      cout << "Masukkan data baru:\n";
      cout << "Judul: ";
      cin.ignore();
      cin.getline(bukuArr[i].judul, 50);
      cout << "Penulis: ";
      cin.getline(bukuArr[i].penulis, 30);
      cout << "Harga: ";
      cin >> bukuArr[i].harga;
      cout << "Stok: ";
      cin >> bukuArr[i].stok;
      cout << "\nData buku berhasil diubah!\n";
      return;
    }
  }
  cout << "Buku dengan kode tersebut tidak ditemukan!\n";
}

// Fungsi untuk menghapus data buku
void hapusBuku(Buku *bukuArr, int *jml)
{
  char kodeCari[10];
  cout << "\nMasukkan kode buku yang ingin dihapus: ";
  cin >> kodeCari;
  for (int i = 0; i < *jml; i++)
  {
    if (strcmp(bukuArr[i].kode, kodeCari) == 0)
    {
      for (int j = i; j < *jml - 1; j++)
      {
        bukuArr[j] = bukuArr[j + 1];
      }
      (*jml)--;
      cout << "Buku berhasil dihapus!\n";
      return;
    }
  }
  cout << "Buku dengan kode tersebut tidak ditemukan!\n";
}

// Fungsi pencarian buku berdasarkan judul atau kode
void cariBuku(Buku *bukuArr, int jml)
{
  int mode;
  cout << "\nCari berdasarkan:\n1. Judul\n2. Kode\nPilih: ";
  cin >> mode;
  cin.ignore();
  if (mode == 1)
  {
    char judulCari[50];
    cout << "Masukkan judul buku: ";
    cin.getline(judulCari, 50);
    bool ditemukan = false;
    for (int i = 0; i < jml; i++)
    {
      if (strstr(bukuArr[i].judul, judulCari))
      {
        cout << "Kode: " << bukuArr[i].kode << ", Judul: " << bukuArr[i].judul << ", Penulis: " << bukuArr[i].penulis << ", Harga: " << bukuArr[i].harga << ", Stok: " << bukuArr[i].stok << endl;
        ditemukan = true;
      }
    }
    if (!ditemukan)
      cout << "Buku tidak ditemukan!\n";
  }
  else if (mode == 2)
  {
    char kodeCari[10];
    cout << "Masukkan kode buku: ";
    cin.getline(kodeCari, 10);
    bool ditemukan = false;
    for (int i = 0; i < jml; i++)
    {
      if (strcmp(bukuArr[i].kode, kodeCari) == 0)
      {
        cout << "Kode: " << bukuArr[i].kode << ", Judul: " << bukuArr[i].judul << ", Penulis: " << bukuArr[i].penulis << ", Harga: " << bukuArr[i].harga << ", Stok: " << bukuArr[i].stok << endl;
        ditemukan = true;
      }
    }
    if (!ditemukan)
      cout << "Buku tidak ditemukan!\n";
  }
  else
  {
    cout << "Pilihan tidak valid!\n";
  }
}

// Fungsi pengurutan buku berdasarkan judul (bubble sort manual)
void urutkanBukuJudul(Buku *bukuArr, int jml, bool ascending)
{
  for (int i = 0; i < jml - 1; i++)
  {
    for (int j = 0; j < jml - i - 1; j++)
    {
      int cmp = strcmp(bukuArr[j].judul, bukuArr[j + 1].judul);
      if ((ascending && cmp > 0) || (!ascending && cmp < 0))
      {
        Buku temp = bukuArr[j];
        bukuArr[j] = bukuArr[j + 1];
        bukuArr[j + 1] = temp;
      }
    }
  }
  cout << "Daftar buku berhasil diurutkan berdasarkan judul!\n";
}

// Fungsi pengurutan buku berdasarkan harga (bubble sort manual)
void urutkanBukuHarga(Buku *bukuArr, int jml, bool ascending)
{
  for (int i = 0; i < jml - 1; i++)
  {
    for (int j = 0; j < jml - i - 1; j++)
    {
      if ((ascending && bukuArr[j].harga > bukuArr[j + 1].harga) || (!ascending && bukuArr[j].harga < bukuArr[j + 1].harga))
      {
        Buku temp = bukuArr[j];
        bukuArr[j] = bukuArr[j + 1];
        bukuArr[j + 1] = temp;
      }
    }
  }
  cout << "Daftar buku berhasil diurutkan berdasarkan harga!\n";
}

int main()
{
  int pilihan;
  do
  {
    cout << "\n=== Sistem Manajemen Toko Buku ===\n";
    cout << "1. Tambah Buku\n";
    cout << "2. Tampilkan Daftar Buku\n";
    cout << "3. Ubah Data Buku\n";
    cout << "4. Hapus Buku\n";
    cout << "5. Cari Buku\n";
    cout << "6. Urutkan Buku (Judul)\n";
    cout << "7. Urutkan Buku (Harga)\n";
    cout << "0. Keluar\n";
    cout << "Pilih menu: ";
    cin >> pilihan;
    switch (pilihan)
    {
    case 1:
      tambahBuku(daftarBuku, &jumlahBuku);
      break;
    case 2:
      tampilkanBuku(daftarBuku, jumlahBuku);
      break;
    case 3:
      ubahBuku(daftarBuku, jumlahBuku);
      break;
    case 4:
      hapusBuku(daftarBuku, &jumlahBuku);
      break;
    case 5:
      cariBuku(daftarBuku, jumlahBuku);
      break;
    case 6:
    {
      int urut;
      cout << "\nUrutkan Judul:\n1. A-Z\n2. Z-A\nPilih: ";
      cin >> urut;
      bool ascending = (urut == 1);
      urutkanBukuJudul(daftarBuku, jumlahBuku, ascending);
      tampilkanBuku(daftarBuku, jumlahBuku);
      break;
    }
    case 7:
    {
      int urut;
      cout << "\nUrutkan Harga:\n1. Terkecil-Terbesar\n2. Terbesar-Terkecil\nPilih: ";
      cin >> urut;
      bool ascending = (urut == 1);
      urutkanBukuHarga(daftarBuku, jumlahBuku, ascending);
      tampilkanBuku(daftarBuku, jumlahBuku);
      break;
    }
    case 0:
      cout << "Terima kasih!\n";
      break;
    default:
      cout << "Menu tidak valid!\n";
    }
  } while (pilihan != 0);
  return 0;
}