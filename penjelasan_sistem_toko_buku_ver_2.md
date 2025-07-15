# Penjelasan Sistem Manajemen Toko Buku Versi 2 (Linked List)

Sistem Manajemen Toko Buku versi 2 ini menggunakan struktur data linked list untuk menyimpan data buku, menggantikan array pada versi sebelumnya. Dengan linked list, penambahan, penghapusan, dan pengubahan data buku menjadi lebih efisien dan fleksibel, karena tidak perlu menggeser elemen seperti pada array. Setiap data buku disimpan dalam node yang saling terhubung melalui pointer `next`, dimulai dari pointer global `head`. Program ini menyediakan fitur tambah, tampilkan, ubah, hapus, cari, dan urutkan buku melalui menu interaktif di konsol.

## Highlight dan Penjelasan Kode

### Struktur Data

```cpp
struct Buku {
  char kode[10];
  char judul[50];
  char penulis[30];
  int harga;
  int stok;
};

struct Node {
  Buku data;
  Node *next;
};
Node *head = nullptr;
```

- **Buku**: Menyimpan informasi satu buku.
- **Node**: Membungkus data buku dan pointer ke node berikutnya.
- **head**: Pointer ke node pertama (awal linked list).

### Fungsi Tambah Buku

```cpp
void tambahBuku() {
  Node *baru = new Node;
  // ...input data buku...
  baru->next = nullptr;
  if (!head) head = baru;
  else {
    Node *p = head;
    while (p->next) p = p->next;
    p->next = baru;
  }
}
```

Fungsi ini digunakan untuk menambah data buku baru ke dalam sistem. Prosesnya dimulai dengan membuat node baru menggunakan `new Node`, yang berarti memori dialokasikan secara dinamis sehingga jumlah data tidak terbatas selama memori komputer cukup. Data buku diinput satu per satu oleh pengguna, lalu node baru dihubungkan ke akhir daftar (linked list). Jika daftar masih kosong (`head` masih `nullptr`), node baru langsung menjadi head. Jika sudah ada data, program akan menelusuri node sampai ke node terakhir, lalu menambahkan node baru di ujung. Dengan cara ini, penambahan data tidak memerlukan penggeseran data lain seperti pada array.

### Fungsi Tampilkan Buku

```cpp
void tampilkanBuku() {
  int no = 1;
  Node *p = head;
  while (p) {
    // ...cetak data buku...
    p = p->next;
  }
}
```

Fungsi ini bertugas menampilkan seluruh data buku yang tersimpan di sistem. Program akan mulai dari node pertama (`head`) dan menelusuri satu per satu node hingga akhir (sampai `p` menjadi `nullptr`). Setiap data buku dicetak ke layar dengan format yang rapi menggunakan fungsi-fungsi formatting seperti `setw` dan `left`. Penomoran dilakukan dengan variabel `no` yang bertambah setiap kali data buku ditampilkan. Dengan linked list, penelusuran data dilakukan dengan mengikuti pointer `next` dari satu node ke node berikutnya.

### Fungsi Ubah Buku

```cpp
void ubahBuku() {
  char kodeCari[10];
  Node *p = head;
  while (p) {
    if (strcmp(p->data.kode, kodeCari) == 0) {
      // ...ubah data buku...
      return;
    }
    p = p->next;
  }
}
```

Fungsi ini digunakan untuk mengubah data buku yang sudah ada. Pengguna diminta memasukkan kode buku yang ingin diubah. Program kemudian menelusuri seluruh node dari head, membandingkan kode buku pada setiap node dengan kode yang dicari menggunakan fungsi `strcmp`. Jika ditemukan, data lama ditampilkan dan pengguna diminta memasukkan data baru untuk menggantikan data lama. Proses pengubahan hanya mengubah isi data pada node yang ditemukan, tanpa mengubah struktur linked list. Jika kode buku tidak ditemukan, program akan menampilkan pesan bahwa data tidak ditemukan.

### Fungsi Hapus Buku

```cpp
void hapusBuku() {
  char kodeCari[10];
  Node *p = head, *prev = nullptr;
  while (p) {
    if (strcmp(p->data.kode, kodeCari) == 0) {
      if (prev == nullptr) head = p->next;
      else prev->next = p->next;
      delete p;
      return;
    }
    prev = p;
    p = p->next;
  }
}
```

Fungsi ini digunakan untuk menghapus data buku dari sistem. Pengguna memasukkan kode buku yang ingin dihapus, lalu program menelusuri node satu per satu. Jika node yang dicari adalah node pertama (`prev == nullptr`), maka head dipindahkan ke node berikutnya. Jika node berada di tengah atau akhir, pointer node sebelumnya (`prev`) diatur agar langsung menunjuk ke node setelah node yang dihapus. Setelah pointer diatur, node yang dihapus dibebaskan dari memori dengan `delete p`. Dengan linked list, penghapusan data menjadi sangat efisien karena tidak perlu menggeser data lain.

### Fungsi Cari Buku

```cpp
void cariBuku() {
  // ...pilihan cari judul/kode...
  Node *p = head;
  while (p) {
    // ...cek judul/kode...
    p = p->next;
  }
}
```

Fungsi ini memungkinkan pengguna mencari data buku berdasarkan judul atau kode. Setelah memilih mode pencarian, program akan menelusuri seluruh node dari head. Jika pencarian berdasarkan judul, program menggunakan fungsi `strstr` untuk mencari substring judul yang diinput pengguna pada setiap node. Jika pencarian berdasarkan kode, program menggunakan `strcmp` untuk membandingkan kode buku. Jika ditemukan, data buku akan ditampilkan. Jika tidak ditemukan, program akan memberi tahu pengguna. Fungsi ini sangat berguna untuk menemukan data dengan cepat tanpa harus menelusuri seluruh daftar secara manual.

### Fungsi Urutkan Buku

```cpp
void urutkanBukuJudul() {
  // Bubble sort manual pada linked list
  do {
    swapped = false;
    Node *p = head;
    while (p->next) {
      if (strcmp(p->data.judul, p->next->data.judul) > 0) {
        Buku temp = p->data;
        p->data = p->next->data;
        p->next->data = temp;
        swapped = true;
      }
      p = p->next;
    }
  } while (swapped);
}
```

Fungsi ini digunakan untuk mengurutkan data buku berdasarkan judul secara alfabetis menggunakan algoritma bubble sort pada linked list. Prosesnya adalah dengan menelusuri node satu per satu dan membandingkan judul buku pada node saat ini dengan node berikutnya menggunakan `strcmp`. Jika urutan salah, data pada kedua node ditukar. Proses ini diulang terus hingga tidak ada lagi data yang perlu ditukar (data sudah terurut). Penukaran dilakukan pada isi data node, bukan node-nya, agar struktur linked list tetap utuh. Dengan pengurutan ini, tampilan daftar buku menjadi lebih rapi dan memudahkan pencarian manual.

## Penjelasan Detail untuk Orang Awam

- **Node dan Linked List**: Setiap buku disimpan dalam node yang saling terhubung. Linked list memudahkan penambahan dan penghapusan data tanpa perlu menggeser seluruh data seperti pada array.
- **Pointer**: Digunakan untuk menunjuk ke node berikutnya. `head` adalah awal dari daftar buku.
- **new dan delete**: Untuk mengelola memori secara dinamis, sehingga program tidak terbatas jumlah data selama memori cukup.
- **strcmp dan strstr**: Fungsi untuk membandingkan dan mencari string, penting untuk pencarian dan pengurutan data buku.
- **Bubble sort pada linked list**: Mengurutkan data dengan menukar isi node, bukan node-nya, agar struktur linked list tetap utuh.

Dengan pendekatan ini, program lebih efisien dan mudah dikembangkan untuk data buku yang jumlahnya dinamis.
