# Pertanyaan dan Jawaban Kritis Program Sistem Manajemen Toko Buku

## 1. Penggunaan Library

**Pertanyaan:** Kenapa menggunakan `<iostream>`, `<iomanip>`, dan `<cstring>`?

**Jawaban:**

- `<iostream>` digunakan untuk operasi input/output seperti `cin` dan `cout`.
- `<iomanip>` digunakan untuk formatting output, misalnya `setw` dan `setfill` saat menampilkan tabel buku.
- `<cstring>` digunakan untuk operasi string berbasis array karakter, seperti `strcmp` dan `strstr`.

**Pertanyaan:** Apakah ada library lain yang bisa digunakan untuk pengolahan string?

**Jawaban:**

- Bisa menggunakan `<string>` dan `std::string` agar pengolahan string lebih aman dan fleksibel.

---

## 2. Definisi Struct

**Pertanyaan:** Kenapa data buku dikelompokkan dalam struct `Buku`?

**Jawaban:**

- Agar data buku (kode, judul, penulis, harga, stok) terorganisir dalam satu kesatuan dan mudah diakses.

**Pertanyaan:** Apa kelebihan menggunakan struct dibandingkan array terpisah?

**Jawaban:**

- Struct membuat data lebih terstruktur, mudah dikelola, dan mengurangi kemungkinan kesalahan akses data.

**Pertanyaan:** Kenapa tipe data judul, penulis, dan kode menggunakan array karakter (`char[]`), bukan `std::string`?

**Jawaban:**

- Untuk latihan dasar C/C++ dan membatasi ukuran input. Namun, `std::string` lebih aman dan fleksibel.

---

## 3. Variabel Global

**Pertanyaan:** Kenapa variabel `daftarBuku` dan `jumlahBuku` dideklarasikan secara global?

**Jawaban:**

- Agar bisa diakses oleh semua fungsi tanpa harus selalu mengirimkan sebagai parameter.

**Pertanyaan:** Apa dampak positif dan negatif dari penggunaan variabel global?

**Jawaban:**

- Positif: Memudahkan akses data di seluruh program.
- Negatif: Bisa menyebabkan bug jika tidak hati-hati, dan sulit dilacak jika program besar.

**Pertanyaan:** Bagaimana jika ingin menghindari variabel global?

- Bisa menggunakan parameter pada setiap fungsi atau membungkus data dan fungsi dalam class (OOP).

---

## 4. Fungsi tambahBuku

**Pertanyaan:** Kenapa fungsi `tambahBuku` menggunakan parameter pointer ke array dan pointer ke jumlah buku?

**Jawaban:**

- Agar fungsi dapat memodifikasi langsung data array buku dan jumlah buku di memori utama, bukan hanya salinan lokal.

**Pertanyaan:** Bagaimana cara kerja pengecekan kapasitas pada fungsi ini?

**Jawaban:**

- Fungsi memeriksa apakah jumlah buku sudah mencapai batas maksimum (`MAKS_BUKU`). Jika sudah penuh, data baru tidak akan ditambahkan.

**Pertanyaan:** Kenapa input judul dan penulis menggunakan `cin.ignore()` dan `getline()`?

**Jawaban:**

- `cin.ignore()` digunakan untuk membersihkan karakter newline di buffer setelah input sebelumnya, agar `getline()` bisa membaca input string dengan benar.

**Pertanyaan:** Apakah ada validasi input pada fungsi ini?

**Jawaban:**

- Belum ada validasi input. Jika pengguna memasukkan data yang tidak sesuai tipe (misal huruf pada harga), program bisa error. Validasi bisa ditambahkan untuk meningkatkan keandalan.

**Pertanyaan:** Bagaimana jika kode buku yang dimasukkan sudah ada sebelumnya?

**Jawaban:**

- Saat ini belum ada pengecekan kode buku duplikat. Sebaiknya ditambahkan agar data lebih konsisten.

**Pertanyaan:** Apa yang terjadi jika panjang input melebihi kapasitas array karakter?

**Jawaban:**

- Bisa terjadi buffer overflow. Sebaiknya tambahkan validasi panjang input agar tidak melebihi kapasitas array.

---

## 5. Fungsi tampilkanBuku

**Pertanyaan:** Kenapa fungsi `tampilkanBuku` menerima parameter array buku dan jumlah buku?

**Jawaban:**

- Agar fungsi dapat menampilkan data buku sesuai jumlah yang ada, tanpa bergantung pada variabel global.

**Pertanyaan:** Kenapa menggunakan `setw`, `setfill`, dan `left` pada output?

**Jawaban:**

- Untuk membuat tampilan tabel buku lebih rapi dan mudah dibaca di console.

**Pertanyaan:** Bagaimana jika jumlah buku 0?

**Jawaban:**

- Fungsi tetap berjalan, hanya saja tidak ada data buku yang ditampilkan di tabel.

**Pertanyaan:** Apakah ada validasi agar tampilan tetap rapi jika judul/penulis sangat panjang?

**Jawaban:**

- Saat ini belum ada pemotongan string jika melebihi lebar kolom, sehingga bisa membuat tampilan tabel berantakan. Bisa ditambahkan validasi atau pemotongan string.

**Pertanyaan:** Apakah fungsi ini bisa digunakan untuk menampilkan data buku yang sudah diurutkan?

**Jawaban:**

- Bisa, karena fungsi hanya menampilkan data sesuai urutan array yang diberikan.

---

