#include <iostream>   // Library untuk input/output standar (cout, cin)
#include <iomanip>    // Library untuk manipulasi format output (setw, setfill)
#include <cstring>    // Library untuk operasi string C (strcmp, strstr, dll)
using namespace std; // Agar bisa menggunakan fungsi-fungsi standar C++ tanpa menulis 'std::'

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

Node *head = nullptr; // Pointer ke node pertama (head) dari linked list

// Fungsi untuk menambah data buku baru ke dalam linked list
void tambahBuku()
{
  Node *baru = new Node; // Membuat node baru
  cout << "\nMasukkan kode buku: ";
  cin >> baru->data.kode;
  cout << "Masukkan judul buku: ";
  cin.ignore();
  cin.getline(baru->data.judul, 50); // Input judul buku
  cout << "Masukkan penulis: ";
  cin.getline(baru->data.penulis, 30); // Input penulis
  cout << "Masukkan harga: ";
  cin >> baru->data.harga; // Input harga
  cout << "Masukkan stok: ";
  cin >> baru->data.stok; // Input stok
  baru->next = nullptr; // Node baru belum terhubung ke node lain
  if (!head)
  {
    head = baru; // Jika list kosong, node baru jadi head
  }
  else
  {
    Node *p = head;
    while (p->next)
      p = p->next; // Cari node terakhir
    p->next = baru; // Tambahkan node baru di akhir
  }
  cout << "\nBuku berhasil ditambahkan!\n"; // Konfirmasi
}

// Fungsi untuk menampilkan daftar buku yang ada di linked list
void tampilkanBuku()
{
  cout << "\nDaftar Buku:\n";
  // Membuat header tabel
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
  // Menampilkan data setiap buku
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

// Fungsi untuk mengubah data buku berdasarkan kode
void ubahBuku()
{
  char kodeCari[10];
  cout << "\nMasukkan kode buku yang ingin diubah: ";
  cin >> kodeCari;
  Node *p = head;
  // Mencari buku dengan kode yang sesuai
  while (p)
  {
    if (strcmp(p->data.kode, kodeCari) == 0)
    {
      // Menampilkan data lama
      cout << "Data lama:\n";
      cout << "Judul: " << p->data.judul << "\nPenulis: " << p->data.penulis << "\nHarga: " << p->data.harga << "\nStok: " << p->data.stok << endl;
      // Input data baru
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
  // Jika kode tidak ditemukan
  cout << "Buku dengan kode tersebut tidak ditemukan!\n";
}

// Fungsi untuk menghapus data buku berdasarkan kode
void hapusBuku()
{
  char kodeCari[10];
  cout << "\nMasukkan kode buku yang ingin dihapus: ";
  cin >> kodeCari;
  Node *p = head, *prev = nullptr;
  // Mencari node yang akan dihapus
  while (p)
  {
    if (strcmp(p->data.kode, kodeCari) == 0)
    {
      // Jika node yang dihapus adalah head
      if (prev == nullptr)
      {
        head = p->next;
      }
      else
      {
        prev->next = p->next;
      }
      delete p; // Hapus node dari memori
      cout << "Buku berhasil dihapus!\n";
      return;
    }
    prev = p;
    p = p->next;
  }
  // Jika kode tidak ditemukan
  cout << "Buku dengan kode tersebut tidak ditemukan!\n";
}

// Fungsi pencarian buku berdasarkan judul atau kode
void cariBuku()
{
  int mode;
  cout << "\nCari berdasarkan:\n1. Judul\n2. Kode\nPilih: ";
  cin >> mode;
  cin.ignore();
  if (mode == 1)
  {
    // Pencarian berdasarkan judul
    char judulCari[50];
    cout << "Masukkan judul buku: ";
    cin.getline(judulCari, 50);
    bool ditemukan = false;
    Node *p = head;
    while (p)
    {
      // Jika judul mengandung kata kunci
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
    // Pencarian berdasarkan kode
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
    // Jika pilihan mode tidak valid
    cout << "Pilihan tidak valid!\n";
  }
}

// Fungsi pengurutan buku berdasarkan judul (bubble sort manual)
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
      // Jika urutan judul salah, tukar data
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

// Fungsi pengurutan buku berdasarkan harga (bubble sort manual)
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
      // Jika harga buku lebih besar dari berikutnya, tukar data
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


int main()
{
  int pilihan;
  do
  {
    // Menampilkan menu utama
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
  } while (pilihan != 0); // Loop sampai user memilih keluar
  return 0;
}