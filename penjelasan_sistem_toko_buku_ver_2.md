# Penjelasan Sistem Manajemen Toko Buku Versi 2 (Linked List)

Sistem Manajemen Toko Buku versi 2 ini menggunakan struktur data linked list untuk menyimpan data buku, menggantikan array pada versi sebelumnya. Dengan linked list, penambahan, penghapusan, dan pengubahan data buku menjadi lebih efisien dan fleksibel, karena tidak perlu menggeser elemen seperti pada array. Setiap data buku disimpan dalam node yang saling terhubung melalui pointer `next`, dimulai dari pointer global `head`. Program ini menyediakan fitur tambah, tampilkan, ubah, hapus, cari, dan urutkan buku melalui menu interaktif di konsol.

## Highlight dan Penjelasan Kode

### Struktur Data

```cpp
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

// Node untuk linked list
struct Node
{
  Buku data;
  Node *next;
};

Node *head = nullptr;
```

- **Library `<iostream>`**: Digunakan untuk operasi input/output seperti `cin` dan `cout`.
- **Library `<iomanip>`**: Digunakan untuk formatting tampilan, misal `setw`, `setfill`, dan `left` agar output tabel rapi.
- **Library `<cstring>`**: Menyediakan fungsi manipulasi string seperti `strcmp` dan `strstr` untuk membandingkan dan mencari string.
- **using namespace std**: Agar tidak perlu menulis `std::` di depan fungsi/fitur dari library standar C++.
- **struct Buku**: Menyimpan data satu buku, terdiri dari kode, judul, penulis, harga, dan stok.
- **struct Node**: Membungkus data buku dan pointer ke node berikutnya, membentuk rantai linked list.
- **Node \*head**: Pointer global yang menunjuk ke node pertama pada linked list. Jika `head` bernilai `nullptr`, berarti daftar buku masih kosong.

### Fungsi Tambah Buku

```cpp
void tambahBuku()
{
  Node *baru = new Node;
  cout << "\nMasukkan kode buku: ";
  cin >> baru->data.kode;
  cout << "Masukkan judul buku: ";
  cin.ignore();
  cin.getline(baru->data.judul, 50);
  cout << "Masukkan penulis: ";
  cin.getline(baru->data.penulis, 30);
  cout << "Masukkan harga: ";
  cin >> baru->data.harga;
  cout << "Masukkan stok: ";
  cin >> baru->data.stok;
  baru->next = nullptr;
  if (!head)
  {
    head = baru;
  }
  else
  {
    Node *p = head;
    while (p->next)
      p = p->next;
    p->next = baru;
  }
  cout << "\nBuku berhasil ditambahkan!\n";
}
```

Fungsi ini digunakan untuk menambah data buku baru ke dalam sistem. Prosesnya dimulai dengan membuat node baru menggunakan `new Node`, yang berarti memori dialokasikan secara dinamis sehingga jumlah data tidak terbatas selama memori komputer cukup. Data buku diinput satu per satu oleh pengguna melalui beberapa tahap:

- `cin >> baru->data.kode;` digunakan untuk input kode buku. Karena `cin` hanya membaca sampai spasi, maka setelahnya perlu `cin.ignore();` agar buffer input bersih sebelum membaca string berikutnya.
- `cin.getline(baru->data.judul, 50);` dan `cin.getline(baru->data.penulis, 30);` digunakan untuk membaca judul dan penulis yang bisa mengandung spasi. Fungsi `getline` membaca seluruh baris hingga batas karakter yang ditentukan.
- Input harga dan stok menggunakan `cin` karena berupa angka.
- Setelah data diisi, pointer `next` pada node baru di-set ke `nullptr` karena node ini akan menjadi node terakhir.
- Jika linked list masih kosong (`head == nullptr`), node baru langsung menjadi head. Jika sudah ada data, program menelusuri node sampai ke node terakhir, lalu menambahkan node baru di ujung dengan mengatur pointer `next` pada node terakhir.
- Pesan "Buku berhasil ditambahkan!" ditampilkan sebagai konfirmasi.

Dengan cara ini, penambahan data tidak memerlukan penggeseran data lain seperti pada array, dan data baru langsung terhubung di akhir daftar.

### Fungsi Tampilkan Buku

```cpp
void tampilkanBuku()
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
  int no = 1;
  Node *p = head;
  while (p)
  {
    cout << left
         << setw(4) << no++
         << setw(10) << p->data.kode
         << setw(25) << p->data.judul
         << setw(20) << p->data.penulis
         << setw(12) << p->data.harga
         << setw(8) << p->data.stok << endl;
    p = p->next;
  }
  cout << setfill('-') << setw(85) << "" << setfill(' ') << endl;
}
```

Fungsi ini digunakan untuk menampilkan seluruh data buku yang tersimpan di sistem dalam bentuk tabel yang rapi. Berikut penjelasan detail setiap bagian:

- Baris judul dan garis pembatas dibuat menggunakan `setfill('-')` dan `setw(85)` agar tampilan tabel konsisten dan mudah dibaca.
- `left` digunakan agar data rata kiri di setiap kolom.
- `setw` menentukan lebar kolom, sehingga data buku tidak saling bertabrakan dan tetap rapi.
- Penomoran otomatis dilakukan dengan variabel `no` yang bertambah setiap kali data buku ditampilkan.
- Penelusuran data dilakukan dengan pointer `p` yang dimulai dari `head` dan bergerak ke node berikutnya (`p = p->next`) hingga seluruh data ditampilkan.
- Setiap data buku (kode, judul, penulis, harga, stok) dicetak sesuai urutan dan format kolom.
- Setelah semua data ditampilkan, garis pembatas akhir dicetak agar tabel terlihat jelas.

Dengan cara ini, seluruh data buku dapat dilihat dengan mudah dan terstruktur, meskipun jumlah data bertambah banyak.

### Fungsi Ubah Buku

```cpp
void ubahBuku()
{
  char kodeCari[10];
  cout << "\nMasukkan kode buku yang ingin diubah: ";
  cin >> kodeCari;
  Node *p = head;
  while (p)
  {
    if (strcmp(p->data.kode, kodeCari) == 0)
    {
      cout << "Data lama:\n";
      cout << "Judul: " << p->data.judul << "\nPenulis: " << p->data.penulis << "\nHarga: " << p->data.harga << "\nStok: " << p->data.stok << endl;
      cout << "Masukkan data baru:\n";
      cout << "Judul: ";
      cin.ignore();
      cin.getline(p->data.judul, 50);
      cout << "Penulis: ";
      cin.getline(p->data.penulis, 30);
      cout << "Harga: ";
      cin >> p->data.harga;
      cout << "Stok: ";
      cin >> p->data.stok;
      cout << "\nData buku berhasil diubah!\n";
      return;
    }
    p = p->next;
  }
  cout << "Buku dengan kode tersebut tidak ditemukan!\n";
}
```

Fungsi ini digunakan untuk mengubah data buku yang sudah ada. Berikut penjelasan detail setiap langkahnya:

- Pengguna diminta memasukkan kode buku yang ingin diubah. Kode ini akan digunakan sebagai kunci pencarian.
- Program menelusuri seluruh node dari head menggunakan pointer `p`. Pada setiap node, kode buku dibandingkan dengan kode yang dicari menggunakan fungsi `strcmp`. Fungsi ini membandingkan dua string dan mengembalikan 0 jika sama.
- Jika ditemukan, data lama buku ditampilkan agar pengguna bisa melihat informasi sebelum diubah.
- Pengguna diminta memasukkan data baru untuk judul, penulis, harga, dan stok. Untuk input judul dan penulis, digunakan `cin.ignore()` agar buffer input bersih, lalu `cin.getline()` untuk membaca string yang bisa mengandung spasi.
- Data baru langsung menggantikan data lama pada node yang ditemukan. Tidak ada perubahan pada struktur linked list, hanya isi data yang diupdate.
- Setelah data diubah, program menampilkan pesan konfirmasi.
- Jika kode buku tidak ditemukan setelah seluruh node ditelusuri, program menampilkan pesan bahwa data tidak ditemukan.

Dengan cara ini, proses pengubahan data menjadi mudah dan langsung pada node yang sesuai tanpa perlu memindahkan data lain.

### Fungsi Hapus Buku

```cpp
void hapusBuku()
{
  char kodeCari[10];
  cout << "\nMasukkan kode buku yang ingin dihapus: ";
  cin >> kodeCari;
  Node *p = head, *prev = nullptr;
  while (p)
  {
    if (strcmp(p->data.kode, kodeCari) == 0)
    {
      if (prev == nullptr)
      {
        head = p->next;
      }
      else
      {
        prev->next = p->next;
      }
      delete p;
      cout << "Buku berhasil dihapus!\n";
      return;
    }
    prev = p;
    p = p->next;
  }
  cout << "Buku dengan kode tersebut tidak ditemukan!\n";
}
```

Fungsi ini digunakan untuk menghapus data buku dari sistem. Berikut penjelasan detail setiap langkahnya:

- Pengguna memasukkan kode buku yang ingin dihapus. Kode ini digunakan sebagai kunci pencarian.
- Program menelusuri seluruh node dari head menggunakan pointer `p` dan pointer sebelumnya `prev`.
- Pada setiap node, kode buku dibandingkan dengan kode yang dicari menggunakan fungsi `strcmp`. Jika sama, node tersebut akan dihapus.
- Jika node yang ditemukan adalah node pertama (`prev == nullptr`), maka head dipindahkan ke node berikutnya (`head = p->next`).
- Jika node berada di tengah atau akhir, pointer node sebelumnya (`prev->next`) diatur agar langsung menunjuk ke node setelah node yang dihapus (`prev->next = p->next`).
- Node yang dihapus dibebaskan dari memori dengan `delete p` agar tidak terjadi memory leak.
- Setelah penghapusan, program menampilkan pesan konfirmasi.
- Jika kode buku tidak ditemukan setelah seluruh node ditelusuri, program menampilkan pesan bahwa data tidak ditemukan.

Dengan cara ini, penghapusan data pada linked list menjadi efisien dan tidak memerlukan penggeseran data lain seperti pada array. Pointer diatur agar rantai linked list tetap utuh setelah node dihapus.

### Fungsi Cari Buku

```cpp
void cariBuku()
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
    Node *p = head;
    while (p)
    {
      if (strstr(p->data.judul, judulCari))
      {
        cout << "Kode: " << p->data.kode << ", Judul: " << p->data.judul << ", Penulis: " << p->data.penulis << ", Harga: " << p->data.harga << ", Stok: " << p->data.stok << endl;
        ditemukan = true;
      }
      p = p->next;
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
    Node *p = head;
    while (p)
    {
      if (strcmp(p->data.kode, kodeCari) == 0)
      {
        cout << "Kode: " << p->data.kode << ", Judul: " << p->data.judul << ", Penulis: " << p->data.penulis << ", Harga: " << p->data.harga << ", Stok: " << p->data.stok << endl;
        ditemukan = true;
      }
      p = p->next;
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
- Untuk pencarian judul, pengguna memasukkan kata kunci judul. Program menelusuri seluruh node dan menggunakan fungsi `strstr` untuk mencari substring pada judul buku. Jika ditemukan, data buku ditampilkan. Fungsi `strstr` berguna untuk pencarian sebagian kata, bukan harus persis sama.
- Untuk pencarian kode, pengguna memasukkan kode buku. Program menelusuri seluruh node dan menggunakan fungsi `strcmp` untuk membandingkan kode buku secara persis. Jika ditemukan, data buku ditampilkan.
- Pada kedua mode, variabel `ditemukan` digunakan untuk menandai apakah ada data yang cocok. Jika tidak ditemukan, program menampilkan pesan "Buku tidak ditemukan!".
- Input menggunakan `cin.ignore()` dan `cin.getline()` agar pembacaan string berjalan lancar dan tidak terganggu sisa input sebelumnya.
- Jika mode pencarian tidak valid, program menampilkan pesan "Pilihan tidak valid!".

Dengan cara ini, pencarian data buku menjadi fleksibel dan mudah, baik berdasarkan judul (sebagian kata) maupun kode (persis sama).

### Fungsi Urutkan Buku

```cpp
void urutkanBukuJudul()
{
  // Bubble sort manual pada linked list
  if (!head || !head->next)
  {
    cout << "Daftar buku berhasil diurutkan berdasarkan judul!\n";
    return;
  }
  bool swapped;
  do
  {
    swapped = false;
    Node *p = head;
    while (p->next)
    {
      if (strcmp(p->data.judul, p->next->data.judul) > 0)
      {
        Buku temp = p->data;
        p->data = p->next->data;
        p->next->data = temp;
        swapped = true;
      }
      p = p->next;
    }
  } while (swapped);
  cout << "Daftar buku berhasil diurutkan berdasarkan judul!\n";
}
```

Fungsi ini digunakan untuk mengurutkan data buku berdasarkan judul secara alfabetis menggunakan algoritma bubble sort pada linked list. Berikut penjelasan detail setiap langkahnya:

- Algoritma bubble sort bekerja dengan membandingkan dua node yang bersebelahan, yaitu judul buku pada node saat ini dan node berikutnya menggunakan fungsi `strcmp`. Jika urutan judul salah (lebih besar secara alfabet), data pada kedua node ditukar.
- Penukaran dilakukan pada isi data node (`Buku temp = p->data; ...`) bukan pada node-nya, sehingga struktur linked list tetap utuh dan tidak perlu mengubah pointer.
- Proses ini diulang terus (loop do-while) hingga tidak ada lagi data yang perlu ditukar, artinya seluruh data sudah terurut.
- Fungsi ini efisien untuk jumlah data yang tidak terlalu besar dan sangat mudah diimplementasikan pada linked list karena penukaran hanya pada data, bukan node.
- Jika hanya ada satu node atau tidak ada data (`head == nullptr` atau `head->next == nullptr`), pengurutan langsung selesai.
- Setelah proses selesai, program menampilkan pesan konfirmasi.

Dengan cara ini, tampilan daftar buku menjadi lebih rapi dan memudahkan pencarian manual berdasarkan urutan judul.

### Fungsi Urutkan Buku Berdasarkan Harga

```cpp
void urutkanBukuHarga()
{
  // Bubble sort manual pada linked list
  if (!head || !head->next)
  {
    cout << "Daftar buku berhasil diurutkan berdasarkan harga!\n";
    return;
  }
  bool swapped;
  do
  {
    swapped = false;
    Node *p = head;
    while (p->next)
    {
      if (p->data.harga > p->next->data.harga)
      {
        Buku temp = p->data;
        p->data = p->next->data;
        p->next->data = temp;
        swapped = true;
      }
      p = p->next;
    }
  } while (swapped);
  cout << "Daftar buku berhasil diurutkan berdasarkan harga!\n";
}
```

Fungsi ini digunakan untuk mengurutkan data buku berdasarkan harga dari yang termurah ke yang termahal menggunakan algoritma bubble sort pada linked list. Berikut penjelasan detail setiap langkahnya:

- Algoritma bubble sort bekerja dengan membandingkan dua node yang bersebelahan, yaitu harga buku pada node saat ini dan node berikutnya. Jika harga pada node saat ini lebih besar, data pada kedua node ditukar.
- Penukaran dilakukan pada isi data node (`Buku temp = p->data; ...`) bukan pada node-nya, sehingga struktur linked list tetap utuh dan tidak perlu mengubah pointer.
- Proses ini diulang terus (loop do-while) hingga tidak ada lagi data yang perlu ditukar, artinya seluruh data sudah terurut dari harga terendah ke tertinggi.
- Jika hanya ada satu node atau tidak ada data (`head == nullptr` atau `head->next == nullptr`), pengurutan langsung selesai.
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
      tambahBuku();
      break;
    case 2:
      tampilkanBuku();
      break;
    case 3:
      ubahBuku();
      break;
    case 4:
      hapusBuku();
      break;
    case 5:
      cariBuku();
      break;
    case 6:
      urutkanBukuJudul();
      break;
    case 7:
      urutkanBukuHarga();
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

## Penjelasan Konsep dan Fitur

- **Node dan Linked List**: Setiap buku disimpan dalam node yang saling terhubung. Linked list memudahkan penambahan dan penghapusan data tanpa perlu menggeser seluruh data seperti pada array.
- **Pointer**: Digunakan untuk menunjuk ke node berikutnya. `head` adalah awal dari daftar buku.
- **new dan delete**: Untuk mengelola memori secara dinamis, sehingga program tidak terbatas jumlah data selama memori cukup.
- **strcmp dan strstr**: Fungsi untuk membandingkan dan mencari string, penting untuk pencarian dan pengurutan data buku.
- **Bubble sort pada linked list**: Mengurutkan data dengan menukar isi node, bukan node-nya, agar struktur linked list tetap utuh.

Dengan pendekatan ini, program lebih efisien dan mudah dikembangkan untuk data buku yang jumlahnya dinamis.
