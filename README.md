# -Proyek-Array-C-C2583207052
# Proyek Array C - Sistem Monitoring Stok dan Penjualan Kantin Kampus

Repositori ini dibuat untuk memenuhi tugas proyek praktikum mata kuliah **Algoritma dan Pemrograman Lanjutan**. Program ini mengimplementasikan struktur data **array** dalam bahasa C untuk mengelola data produk, transaksi penjualan, pencarian, pengurutan, serta laporan keuangan kantin kampus.

---

## 📌 Identitas Pembuat
* **Nama Lengkap:** Shilfia Meliyani
* **NIM:** C2583207052
* **Kelas:** PTI-3A
* **Mata Kuliah:** Algoritma dan Pemrograman Lanjutan
* **Nama Proyek:** Sistem Pemantauan Stok dan Penjualan Kantin Kampus
---

## 📝 Deskripsi Singkat Proyek
Kantin kampus sebelumnya mencatat stok dan transaksi secara manual, sehingga menyulitkan pengelola dalam memantau ketersediaan barang, menghitung transaksi, dan mengetahui produk terlaris. Aplikasi berbasis *console* (terminal) ini dirancang untuk mengatasi masalah tersebut secara otomatis dengan memanfaatkan array satu dimensi dan array karakter dua dimensi. Program dapat berjalan dengan kapasitas maksimal 50 produk serta dilengkapi minimal 5 data produk awal.

---

## ⚙️ Daftar Fitur Program
Menu utama yang tersedia di dalam aplikasi ini meliputi:
1. **Lihat Daftar Produk:** Menampilkan informasi nama, harga, dan stok seluruh produk.
2. **Tambah Produk:** Menambahkan produk baru ke dalam sistem.
3. **Ubah Produk:** Memperbarui harga atau stok produk yang sudah ada.
4. **Transaksi Penjualan:** Memproses pembelian beberapa jenis produk dalam satu transaksi sekaligus, memeriksa ketersediaan stok, menghitung subtotal/total, serta memperbarui stok dan jumlah produk terjual.
5. **Tambah Stok:** Menambahkan stok produk dan memantau produk dengan sisa stok kurang dari 5.
6. **Cari Produk:** Mencari informasi produk berdasarkan nama.
7. **Urutkan Produk:** Menyusun daftar produk berdasarkan harga termurah atau jumlah terjual terbanyak.
8. **Laporan Penjualan:** Menampilkan jumlah unit terjual per produk, total pendapatan, dan produk paling laris (*best seller*).
9. **Cek Stok Menipis:** Memperingatkan pengelola jika ada produk dengan stok $< 5$.
0. **Keluar:** Menutup program.

---

## 💻 Penjelasan Penggunaan Array dalam Program
Di dalam program bahasa C ini, **array** digunakan sebagai struktur data utama penyimpanan memori selama program berjalan:
* **Array Karakter Dua Dimensi (`char nama[50][50]`):** Digunakan untuk menyimpan daftar nama produk secara baris dan kolom (string array) dengan kapasitas maksimal 50 produk.
* **Array Satu Dimensi (`int harga[50]`, `int stok[50]`, `int terjual[50]`):** Digunakan secara paralel untuk menyimpan data harga satuan, sisa stok, serta akumulasi jumlah unit yang terjual untuk masing-masing indeks produk.
* Penggunaan indeks array dikombinasikan dengan perulangan (`for`/`while`) dan percabangan (`if-else`) untuk memudahkan manipulasi data, pencarian (*searching*), pengurutan (*sorting*), serta validasi kapasitas maksimal array.

---

## 🚀 Petunjuk Kompilasi dan Menjalankan Program

Pastikan komputer atau laptop kamu sudah terpasang compiler bahasa C (seperti `gcc` melalui MinGW atau GCC bawaan Linux/macOS).

### 1. Kloning atau Unduh Repositori
Buka terminal atau Command Prompt pada direktori folder tempat file proyek ini berada.

### 2. Proses Kompilasi (Compile)
Ketik perintah berikut untuk mengkompilasi file *source code* (misalnya `main.c`) menjadi file *executable*:
```bash
 gcc main.c -o program_kantin


1. Tambah Produk
<img width="1916" height="1020" alt="Screenshot 2026-11-17 210308" src="https://github.com/user-attachments/assets/44d2aeb3-02ce-4b44-bb2f-5f34449746ea" />



