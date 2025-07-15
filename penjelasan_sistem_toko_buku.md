# Penjelasan Sistem Manajemen Toko Buku Versi 1 (Array)

Sistem Manajemen Toko Buku versi 1 menggunakan array statis untuk menyimpan data buku. Setiap data buku disimpan dalam elemen array bertipe `Buku`, dan jumlah maksimal data ditentukan oleh konstanta `MAKS_BUKU`. Program menyediakan fitur tambah, tampilkan, ubah, hapus, cari, dan urutkan buku melalui menu interaktif di konsol.

## Highlight dan Penjelasan Kode

### Library yang Digunakan

```cpp
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
```

- **`#include <iostream>`**: Library standar C++ untuk operasi input/output seperti `cin` (input dari keyboard) dan `cout` (output ke layar). Digunakan di seluruh bagian program untuk interaksi dengan pengguna.
- **`#include <iomanip>`**: Library untuk manipulasi format output, seperti `setw` (lebar kolom), `setfill` (karakter pengisi), dan `left` (rata kiri). Sangat berguna untuk membuat tampilan tabel data buku yang rapi dan mudah dibaca.
- **`#include <cstring>`**: Library untuk operasi string berbasis karakter, seperti `strcmp` (membandingkan dua string), `strstr` (mencari substring dalam string), dan `cin.getline` (membaca string dengan spasi). Library ini penting untuk pencarian, pengurutan, dan input data buku yang berupa teks.
- **`using namespace std;`**: Agar tidak perlu menulis `std::` di depan fungsi-fungsi dari library standar, sehingga kode lebih ringkas dan mudah dibaca.

### Struktur Data

```cpp
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

Bagian ini mendefinisikan struktur data utama yang digunakan dalam program:

- **Array `daftarBuku`**: Merupakan array statis bertipe `Buku` yang digunakan untuk menyimpan seluruh data buku secara berurutan. Kapasitas maksimal ditentukan oleh `MAKS_BUKU` (100), sehingga program cocok untuk data berukuran kecil hingga sedang. Penggunaan array memudahkan akses data dengan indeks, namun jika data dihapus, elemen setelahnya harus digeser agar tidak ada celah kosong.
- **Variabel `jumlahBuku`**: Menyimpan jumlah data buku yang sudah diinput. Variabel ini digunakan untuk menentukan posisi penambahan data baru dan batas penelusuran data saat menampilkan, mengubah, atau menghapus buku.
- **Struct Buku**: Merupakan struktur yang mendefinisikan satu data buku, terdiri dari beberapa field:
  - `kode[10]`: Menyimpan kode unik buku, digunakan sebagai kunci pencarian dan identifikasi.
  - `judul[50]`: Menyimpan judul buku, dapat berisi spasi dan karakter panjang.
  - `penulis[30]`: Menyimpan nama penulis buku.
  - `harga`: Menyimpan harga buku dalam satuan integer.
  - `stok`: Menyimpan jumlah stok buku yang tersedia.

Penggunaan array dan struct ini membuat pengelolaan data menjadi terstruktur dan mudah diakses, namun kapasitasnya tetap terbatas oleh ukuran array. Untuk data yang sangat besar atau dinamis, struktur lain seperti linked list lebih disarankan.

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

Fungsi ini digunakan untuk menambah data buku baru ke dalam array. Berikut penjelasan detail setiap langkahnya:

- Program pertama-tama mengecek apakah jumlah data sudah mencapai batas maksimal array (`MAKS_BUKU`). Jika sudah penuh, proses penambahan dibatalkan dan pesan ditampilkan.
- Jika masih ada ruang, pointer `Buku *b = &bukuArr[*jml];` digunakan untuk menunjuk ke elemen array berikutnya yang akan diisi data baru. Penggunaan pointer di sini memungkinkan pengisian data langsung ke lokasi array yang dituju.
- Input data dilakukan satu per satu: kode, judul, penulis, harga, dan stok. Untuk judul dan penulis, digunakan `cin.ignore()` dan `cin.getline()` agar pembacaan string berjalan lancar dan tidak terganggu sisa input sebelumnya.
- Setelah semua data diisi, nilai jumlah buku (`*jml`) ditambah satu agar data berikutnya masuk ke indeks array selanjutnya.
- Pesan "Buku berhasil ditambahkan!" ditampilkan sebagai konfirmasi.

Dengan cara ini, penambahan data buku menjadi efisien dan langsung pada array, tanpa perlu menggeser data lain. Penggunaan pointer pada parameter fungsi memastikan perubahan pada array dan jumlah buku bersifat global.

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

Fungsi ini digunakan untuk menampilkan seluruh data buku yang tersimpan di array dalam bentuk tabel yang rapi. Berikut penjelasan detail setiap bagian:

- Header tabel dan garis pembatas dibuat menggunakan manipulasi output (`setfill`, `setw`, dan `left`) agar tampilan konsisten dan mudah dibaca.
- Penomoran otomatis dilakukan dengan variabel `i` yang bertambah setiap kali data buku ditampilkan.
- Penelusuran data dilakukan dengan loop dari indeks 0 hingga jumlah data (`jml`). Setiap data buku (kode, judul, penulis, harga, stok) dicetak sesuai urutan dan format kolom.
- Setelah semua data ditampilkan, garis pembatas akhir dicetak agar tabel terlihat jelas.

Dengan cara ini, seluruh data buku dapat dilihat dengan mudah dan terstruktur, meskipun jumlah data bertambah banyak.

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

Fungsi ini digunakan untuk mengubah data buku yang sudah ada di array. Berikut penjelasan detail setiap langkahnya:

- Pengguna diminta memasukkan kode buku yang ingin diubah. Kode ini digunakan sebagai kunci pencarian.
- Program menelusuri seluruh elemen array dari indeks 0 hingga jumlah data (`jml`). Pada setiap elemen, kode buku dibandingkan dengan kode yang dicari menggunakan fungsi `strcmp`.
- Jika ditemukan, data lama buku ditampilkan agar pengguna bisa melihat informasi sebelum diubah.
- Pengguna diminta memasukkan data baru untuk judul, penulis, harga, dan stok. Untuk input judul dan penulis, digunakan `cin.ignore()` agar buffer input bersih, lalu `cin.getline()` untuk membaca string yang bisa mengandung spasi.
- Data baru langsung menggantikan data lama pada elemen array yang ditemukan. Tidak ada perubahan pada struktur array, hanya isi data yang diupdate.
- Setelah data diubah, program menampilkan pesan konfirmasi.
- Jika kode buku tidak ditemukan setelah seluruh array ditelusuri, program menampilkan pesan bahwa data tidak ditemukan.

Dengan cara ini, proses pengubahan data menjadi mudah dan langsung pada elemen array yang sesuai tanpa perlu memindahkan data lain.

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

Fungsi ini digunakan untuk menghapus data buku dari array. Berikut penjelasan detail setiap langkahnya:

- Pengguna memasukkan kode buku yang ingin dihapus. Kode ini digunakan sebagai kunci pencarian.
- Program menelusuri seluruh elemen array dari indeks 0 hingga jumlah data (`*jml`). Pada setiap elemen, kode buku dibandingkan dengan kode yang dicari menggunakan fungsi `strcmp`.
- Jika data ditemukan, seluruh elemen array setelahnya digeser ke depan (`bukuArr[j] = bukuArr[j + 1]`) agar tidak ada celah kosong.
- Jumlah data dikurangi satu (`(*jml)--`) agar data berikutnya masuk ke indeks array yang benar.
- Setelah penghapusan, program menampilkan pesan konfirmasi.
- Jika kode buku tidak ditemukan setelah seluruh array ditelusuri, program menampilkan pesan bahwa data tidak ditemukan.

Dengan cara ini, penghapusan data pada array menjadi efisien dan tidak memerlukan struktur data tambahan. Pointer pada parameter memastikan perubahan jumlah data bersifat global.

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

Fungsi ini digunakan untuk mencari data buku berdasarkan judul atau kode. Berikut penjelasan detail setiap langkahnya:

- Pengguna memilih mode pencarian: 1 untuk judul, 2 untuk kode.
- Untuk pencarian judul, pengguna memasukkan kata kunci judul. Program menelusuri seluruh array dan menggunakan fungsi `strstr` untuk mencari substring pada judul buku. Jika ditemukan, data buku ditampilkan. Fungsi `strstr` berguna untuk pencarian sebagian kata, bukan harus persis sama.
- Untuk pencarian kode, pengguna memasukkan kode buku. Program menelusuri seluruh array dan menggunakan fungsi `strcmp` untuk membandingkan kode buku secara persis. Jika ditemukan, data buku ditampilkan.
- Pada kedua mode, variabel `ditemukan` digunakan untuk menandai apakah ada data yang cocok. Jika tidak ditemukan, program menampilkan pesan "Buku tidak ditemukan!".
- Input menggunakan `cin.ignore()` dan `cin.getline()` agar pembacaan string berjalan lancar dan tidak terganggu sisa input sebelumnya.
- Jika mode pencarian tidak valid, program menampilkan pesan "Pilihan tidak valid!".

Dengan cara ini, pencarian data buku menjadi fleksibel dan mudah, baik berdasarkan judul (sebagian kata) maupun kode (persis sama).

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

Fungsi ini digunakan untuk mengurutkan data buku berdasarkan judul secara alfabetis menggunakan algoritma bubble sort pada array. Berikut penjelasan detail setiap langkahnya:

- Algoritma bubble sort bekerja dengan membandingkan dua elemen array yang bersebelahan, yaitu judul buku pada indeks saat ini dan indeks berikutnya menggunakan fungsi `strcmp`. Jika urutan judul salah (lebih besar secara alfabet), data pada kedua elemen ditukar.
- Penukaran dilakukan pada isi data array (`Buku temp = bukuArr[j]; ...`) bukan pada pointer, sehingga struktur array tetap utuh dan tidak perlu mengubah referensi.
- Proses ini diulang terus (dua loop bersarang) hingga tidak ada lagi data yang perlu ditukar, artinya seluruh data sudah terurut.
- Setelah proses selesai, program menampilkan pesan konfirmasi.

Dengan cara ini, tampilan daftar buku menjadi lebih rapi dan memudahkan pencarian manual berdasarkan urutan judul.

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

Fungsi ini digunakan untuk mengurutkan data buku berdasarkan harga dari yang termurah ke yang termahal menggunakan algoritma bubble sort pada array. Berikut penjelasan detail setiap langkahnya:

- Algoritma bubble sort bekerja dengan membandingkan dua elemen array yang bersebelahan, yaitu harga buku pada indeks saat ini dan indeks berikutnya. Jika harga pada indeks saat ini lebih besar, data pada kedua elemen ditukar.
- Penukaran dilakukan pada isi data array (`Buku temp = bukuArr[j]; ...`) bukan pada pointer, sehingga struktur array tetap utuh dan tidak perlu mengubah referensi.
- Proses ini diulang terus (dua loop bersarang) hingga tidak ada lagi data yang perlu ditukar, artinya seluruh data sudah terurut dari harga terendah ke tertinggi.
- Setelah proses selesai, program menampilkan pesan konfirmasi.

Dengan pengurutan ini, pengguna dapat dengan mudah melihat daftar buku dari harga terendah hingga tertinggi, sehingga memudahkan pencarian manual atau analisis harga buku di toko.

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

Fungsi `main` adalah titik awal eksekusi program dan berfungsi sebagai pengendali utama alur aplikasi. Berikut penjelasan detail setiap bagian:

- Program menampilkan menu interaktif di konsol, memungkinkan pengguna memilih fitur yang diinginkan dengan memasukkan angka sesuai menu.
- Variabel `pilihan` digunakan untuk menyimpan input menu dari pengguna.
- Struktur `do-while` memastikan menu akan terus ditampilkan dan program berjalan hingga pengguna memilih opsi keluar (`pilihan == 0`).
- Setiap pilihan menu di-handle menggunakan struktur `switch-case`, sehingga setiap angka menu akan memanggil fungsi yang sesuai:
  - 1: Menambah data buku baru
  - 2: Menampilkan daftar buku
  - 3: Mengubah data buku
  - 4: Menghapus data buku
  - 5: Mencari data buku
  - 6: Mengurutkan buku berdasarkan judul
  - 7: Mengurutkan buku berdasarkan harga
  - 0: Keluar dari program
- Jika input menu tidak valid, program menampilkan pesan "Menu tidak valid!" dan kembali ke menu utama.
- Setelah memilih keluar, program menampilkan pesan "Terima kasih!" sebagai penutup.

Dengan struktur ini, seluruh fitur manajemen toko buku dapat diakses dengan mudah dan terintegrasi dalam satu alur program utama, sehingga pengguna dapat melakukan berbagai operasi secara interaktif dan berulang tanpa perlu menjalankan ulang program.
