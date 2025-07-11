# Penjelasan Fungsi pada sistem_toko_buku.cpp

Berikut adalah penjelasan teknis dan detail setiap fungsi yang terdapat pada file `sistem_toko_buku.cpp`, termasuk penjelasan penggunaan pointer, variabel biasa, dan alasan pemilihan teknik/programming:

## 1. tambahBuku

- Parameter: `Buku *bukuArr` (pointer ke array buku), `int *jml` (pointer ke jumlah buku).
- Alasan:
  - Array digunakan agar data buku dapat disimpan secara berurutan dan mudah diakses dengan indeks.
  - Pointer dipakai agar fungsi dapat mengubah data asli di array dan jumlah buku secara langsung (bukan salinan).
  - Fungsi ini memudahkan penambahan data tanpa harus mengembalikan nilai, cukup mengubah data lewat pointer.
- Proses:
  - Mengecek apakah `*jml >= MAKS_BUKU` (batas maksimal array).
  - Membuat pointer `Buku *b = &bukuArr[*jml];` untuk menunjuk ke elemen array berikutnya.
  - Input data ke anggota struct melalui pointer `b` (misal: `b->kode`, `b->judul`).
  - Setelah data diisi, nilai `*jml` ditambah satu (`(*jml)++`).

## 2. tampilkanBuku

- Parameter: `Buku *bukuArr` (pointer ke array buku), `int jml` (jumlah buku, variabel biasa).
- Alasan:
  - Array memudahkan penelusuran data secara berurutan.
  - Tidak perlu pointer ke jumlah buku karena hanya membaca data, bukan mengubah.
  - Fungsi ini memisahkan logika tampilan dari logika data, sehingga kode lebih rapi.
- Proses:
  - Menampilkan header tabel dengan manipulasi output.
  - Loop dari `i = 0` sampai `i < jml`, akses data dengan `bukuArr[i]`.

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
