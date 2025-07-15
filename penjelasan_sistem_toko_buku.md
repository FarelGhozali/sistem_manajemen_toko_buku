# Penjelasan Sistem Manajemen Toko Buku Versi 1 (Array)

Sistem Manajemen Toko Buku versi 1 menggunakan array statis untuk menyimpan data buku. Setiap data buku disimpan dalam elemen array bertipe `Buku`, dan jumlah maksimal data ditentukan oleh konstanta `MAKS_BUKU`. Program menyediakan fitur tambah, tampilkan, ubah, hapus, cari, dan urutkan buku melalui menu interaktif di konsol.

## Highlight dan Penjelasan Kode

### Struktur Data

```cpp
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

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
```

- **Array `daftarBuku`**: Menyimpan data buku secara berurutan, dengan kapasitas maksimal 100 buku.
- **Variabel `jumlahBuku`**: Menyimpan jumlah data buku yang sudah diinput.
- **Struct Buku**: Menyimpan data satu buku, terdiri dari kode, judul, penulis, harga, dan stok.

### Fungsi Tambah Buku

```cpp
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
```

Fungsi ini digunakan untuk menambah data buku baru ke dalam array. Prosesnya dimulai dengan mengecek apakah array sudah penuh. Jika belum, data buku diinput satu per satu oleh pengguna dan disimpan pada elemen array berikutnya. Pointer digunakan agar perubahan pada jumlah buku dan data array langsung mempengaruhi variabel global.

### Fungsi Tampilkan Buku

```cpp
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
```

Fungsi ini digunakan untuk menampilkan seluruh data buku yang tersimpan di array dalam bentuk tabel yang rapi. Penomoran otomatis dilakukan dengan variabel `i`, dan data buku dicetak sesuai urutan dan format kolom.

### Fungsi Ubah Buku

```cpp
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
```

Fungsi ini digunakan untuk mengubah data buku yang sudah ada di array. Pencarian dilakukan dengan membandingkan kode buku, dan jika ditemukan, data lama ditampilkan lalu diubah dengan data baru yang diinput pengguna.

### Fungsi Hapus Buku

```cpp
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
```

Fungsi ini digunakan untuk menghapus data buku dari array. Jika data ditemukan, elemen array setelahnya digeser ke depan agar tidak ada celah kosong, dan jumlah data dikurangi satu.

### Fungsi Cari Buku

```cpp
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
```

Fungsi ini digunakan untuk mencari data buku berdasarkan judul atau kode. Pencarian judul menggunakan fungsi `strstr` untuk substring, sedangkan pencarian kode menggunakan `strcmp` untuk kecocokan persis.

### Fungsi Urutkan Buku Berdasarkan Judul

```cpp
void urutkanBukuJudul(Buku *bukuArr, int jml)
{
  for (int i = 0; i < jml - 1; i++)
  {
    for (int j = 0; j < jml - i - 1; j++)
    {
      if (strcmp(bukuArr[j].judul, bukuArr[j + 1].judul) > 0)
      {
        Buku temp = bukuArr[j];
        bukuArr[j] = bukuArr[j + 1];
        bukuArr[j + 1] = temp;
      }
    }
  }
  cout << "Daftar buku berhasil diurutkan berdasarkan judul!\n";
}
```

Fungsi ini digunakan untuk mengurutkan data buku berdasarkan judul secara alfabetis menggunakan algoritma bubble sort pada array. Penukaran dilakukan pada isi data array, bukan pointer.

### Fungsi Urutkan Buku Berdasarkan Harga

```cpp
void urutkanBukuHarga(Buku *bukuArr, int jml)
{
  for (int i = 0; i < jml - 1; i++)
  {
    for (int j = 0; j < jml - i - 1; j++)
    {
      if (bukuArr[j].harga > bukuArr[j + 1].harga)
      {
        Buku temp = bukuArr[j];
        bukuArr[j] = bukuArr[j + 1];
        bukuArr[j + 1] = temp;
      }
    }
  }
  cout << "Daftar buku berhasil diurutkan berdasarkan harga!\n";
}
```

Fungsi ini digunakan untuk mengurutkan data buku berdasarkan harga dari yang termurah ke yang termahal menggunakan algoritma bubble sort pada array. Penukaran dilakukan pada isi data array, bukan pointer.

### Fungsi Utama Program

```cpp
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
      urutkanBukuJudul(daftarBuku, jumlahBuku);
      break;
    case 7:
      urutkanBukuHarga(daftarBuku, jumlahBuku);
      break;
    case 0:
      cout << "Terima kasih!\n";
      break;
    default:
      cout << "Menu tidak valid!\n";
    }
  } while (pilihan != 0);
  return 0;
}
```

Fungsi `main` adalah titik awal eksekusi program dan berfungsi sebagai pengendali utama alur aplikasi. Menu interaktif memungkinkan pengguna memilih fitur, dan setiap pilihan memanggil fungsi yang sesuai.

## Penjelasan Konsep dan Fitur

- **Array statis**: Data buku disimpan dalam array dengan kapasitas tetap, cocok untuk data yang jumlahnya tidak terlalu besar.
- **Pointer**: Digunakan pada parameter fungsi agar perubahan pada data array dan jumlah buku langsung mempengaruhi variabel global.
- **Struct Buku**: Menyimpan data satu buku secara terstruktur.
- **Bubble sort pada array**: Mengurutkan data dengan menukar isi array, bukan pointer.
- **Manipulasi data langsung**: Perubahan data dilakukan langsung pada array melalui pointer, sehingga perubahan bersifat global dan konsisten.

Dengan pendekatan ini, program sederhana, efisien untuk data terbatas, dan mudah dikembangkan untuk fitur-fitur dasar manajemen toko buku.

## 3. ubahBuku

- Parameter: `Buku *bukuArr` (pointer ke array buku), `int jml` (jumlah buku, variabel biasa).
- Alasan:
  - Pointer ke array agar data buku bisa diubah langsung.
  - Jumlah buku tidak perlu pointer karena tidak berubah.
  - Fungsi ini memudahkan modifikasi data tanpa harus mengembalikan array baru.
- Proses:
  - Input kode buku ke variabel lokal `kodeCari`.
  - Loop dari `i = 0` sampai `i < jml`, membandingkan `bukuArr[i].kode` dengan `kodeCari` menggunakan `strcmp`.
  - Jika ditemukan, akses dan ubah data langsung pada `bukuArr[i]`.
  - Input data baru ke anggota struct menggunakan pointer ke elemen array.

## 4. hapusBuku

- Parameter: `Buku *bukuArr` (pointer ke array buku), `int *jml` (pointer ke jumlah buku).
- Alasan:
  - Pointer ke array dan jumlah buku agar data bisa dihapus dan jumlahnya bisa dikurangi langsung.
  - Pergeseran array digunakan agar tidak ada celah kosong setelah data dihapus.
  - Fungsi ini efisien untuk array statis, meski untuk data besar lebih baik pakai struktur dinamis.
- Proses:
  - Input kode buku ke variabel lokal `kodeCari`.
  - Loop dari `i = 0` sampai `i < *jml`, membandingkan `bukuArr[i].kode` dengan `kodeCari`.
  - Jika ditemukan, lakukan pergeseran array: `bukuArr[j] = bukuArr[j + 1]` untuk setiap elemen setelahnya.
  - Jumlah buku dikurangi satu dengan `(*jml)--`.
  - Jika tidak ditemukan, tampilkan pesan gagal.

## 5. cariBuku

- Parameter: `Buku *bukuArr` (pointer ke array buku), `int jml` (jumlah buku, variabel biasa).
- Alasan:
  - Pointer ke array agar data bisa diakses langsung.
  - Jumlah buku cukup variabel biasa karena hanya membaca.
  - Fungsi ini memudahkan pencarian data dengan dua mode (judul/kode) tanpa harus membuat fungsi terpisah.
- Proses:
  - Input mode pencarian ke variabel lokal `mode`.
  - Jika mode judul: input ke `judulCari`, loop dan cek dengan `strstr(bukuArr[i].judul, judulCari)`, tampilkan data buku yang cocok.
  - Jika mode kode: input ke `kodeCari`, loop dan cek dengan `strcmp(bukuArr[i].kode, kodeCari)`, tampilkan data buku yang cocok.
  - Jika tidak ditemukan, tampilkan pesan gagal.
  - Jika mode tidak valid, tampilkan pesan error.

## 6. urutkanBukuJudul

- Parameter: `Buku *bukuArr` (pointer ke array buku), `int jml` (jumlah buku, variabel biasa).
- Alasan:
  - Pointer ke array agar data bisa diurutkan langsung.
  - Bubble sort dipilih karena mudah diimplementasikan untuk data kecil.
  - Pengurutan manual memberi kontrol penuh pada logika sorting.
- Proses:
  - Bubble sort manual: dua loop bersarang, membandingkan `bukuArr[j].judul` dan `bukuArr[j+1].judul` dengan `strcmp`.
  - Penukaran data dilakukan dengan variabel sementara bertipe `Buku` (bukan pointer).
  - Setelah selesai, tampilkan pesan sukses.

## 7. urutkanBukuHarga

- Parameter: `Buku *bukuArr` (pointer ke array buku), `int jml` (jumlah buku, variabel biasa).
- Alasan:
  - Pointer ke array agar data bisa diurutkan langsung.
  - Bubble sort dipilih karena mudah dan cukup untuk data sedikit.
  - Pengurutan manual memudahkan modifikasi logika jika dibutuhkan.
- Proses:
  - Bubble sort manual: dua loop bersarang, membandingkan `bukuArr[j].harga` dan `bukuArr[j+1].harga`.
  - Penukaran data dilakukan dengan variabel sementara bertipe `Buku` (bukan pointer).
  - Setelah selesai, tampilkan pesan sukses.

## 8. main

- Semua variabel di fungsi ini adalah variabel biasa, tidak ada pointer.
- Alasan:
  - Fungsi utama hanya mengatur alur program dan memanggil fungsi lain.
  - Variabel global dan pointer digunakan di fungsi lain agar data tetap konsisten.
- Proses:
  - Loop `do-while` untuk menampilkan menu dan menerima input.
  - Memanggil fungsi dengan parameter yang sesuai (pointer atau variabel biasa).
  - Fungsi yang mengubah data (tambah, hapus) menggunakan pointer ke jumlah buku agar perubahan langsung ke variabel global.

---

Ringkasan:

- Array digunakan karena data buku bersifat statis dan jumlahnya terbatas, sehingga mudah diakses dan diurutkan.
- Pointer digunakan agar fungsi dapat memodifikasi data asli di array dan jumlah buku tanpa harus mengembalikan nilai.
- Variabel biasa digunakan untuk data yang hanya dibaca, agar lebih sederhana dan efisien.
- Fungsi dipisah agar kode modular, mudah dibaca, dan setiap fitur dapat dikembangkan atau diuji secara terpisah.
- Algoritma bubble sort dipilih karena sederhana dan cukup untuk data sedikit, meski kurang efisien untuk data besar.
- Manipulasi data dilakukan langsung pada array melalui pointer, sehingga perubahan bersifat global dan konsisten.
