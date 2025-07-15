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

- Membuat node baru, mengisi data, dan menambahkannya di akhir linked list.
- **new Node**: Mengalokasikan memori dinamis untuk node baru.

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

- Menelusuri seluruh node dari head dan menampilkan data buku satu per satu.

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

- Mencari node dengan kode buku tertentu, lalu mengubah datanya.
- **strcmp**: Membandingkan string kode buku.

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

- Mencari node yang ingin dihapus, mengatur pointer agar node tersebut dilewati, lalu menghapus memori node.
- **delete p**: Menghapus node dari memori.

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

- Menelusuri node untuk mencari buku berdasarkan judul atau kode.
- **strstr**: Mencari substring pada judul.

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

- Mengurutkan data buku berdasarkan judul dengan bubble sort pada linked list.
- **Bubble sort**: Menukar data antar node, bukan node-nya.

## Penjelasan Detail untuk Orang Awam

- **Node dan Linked List**: Setiap buku disimpan dalam node yang saling terhubung. Linked list memudahkan penambahan dan penghapusan data tanpa perlu menggeser seluruh data seperti pada array.
- **Pointer**: Digunakan untuk menunjuk ke node berikutnya. `head` adalah awal dari daftar buku.
- **new dan delete**: Untuk mengelola memori secara dinamis, sehingga program tidak terbatas jumlah data selama memori cukup.
- **strcmp dan strstr**: Fungsi untuk membandingkan dan mencari string, penting untuk pencarian dan pengurutan data buku.
- **Bubble sort pada linked list**: Mengurutkan data dengan menukar isi node, bukan node-nya, agar struktur linked list tetap utuh.

Dengan pendekatan ini, program lebih efisien dan mudah dikembangkan untuk data buku yang jumlahnya dinamis.
