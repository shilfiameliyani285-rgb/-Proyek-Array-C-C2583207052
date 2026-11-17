# -Proyek-Array-C-C2583207052
# Proyek Array C - Sistem Monitoring Stok dan Penjualan Kantin Kampus

Repositori ini dibuat untuk memenuhi tugas proyek praktikum mata kuliah **Algoritma dan Pemrograman Lanjutan**. Program ini mengimplementasikan struktur data **array** dalam bahasa C untuk mengelola data produk, transaksi penjualan, pencarian, pengurutan, serta laporan keuangan kantin kampus.

---

## Identitas Pembuat
* **Nama Lengkap:** Shilfia Meliyani
* **NIM:** C2583207052
* **Kelas:** PTI-3A
* **Mata Kuliah:** Algoritma dan Pemrograman Lanjutan
* **Nama Proyek:** Sistem Pemantauan Stok dan Penjualan Kantin Kampus
---

## Deskripsi Singkat Proyek
Kantin kampus sebelumnya mencatat stok dan transaksi secara manual, sehingga menyulitkan pengelola dalam memantau ketersediaan barang, menghitung transaksi, dan mengetahui produk terlaris. Aplikasi berbasis *console* (terminal) ini dirancang untuk mengatasi masalah tersebut secara otomatis dengan memanfaatkan array satu dimensi dan array karakter dua dimensi. Program dapat berjalan dengan kapasitas maksimal 50 produk serta dilengkapi minimal 5 data produk awal.

---

## Daftar Fitur Program
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

## Penjelasan Penggunaan Array dalam Program
Di dalam program bahasa C ini, **array** digunakan sebagai struktur data utama penyimpanan memori selama program berjalan:
* **Array Karakter Dua Dimensi (`char nama[50][50]`):** Digunakan untuk menyimpan daftar nama produk secara baris dan kolom (string array) dengan kapasitas maksimal 50 produk.
* **Array Satu Dimensi (`int harga[50]`, `int stok[50]`, `int terjual[50]`):** Digunakan secara paralel untuk menyimpan data harga satuan, sisa stok, serta akumulasi jumlah unit yang terjual untuk masing-masing indeks produk.
* Penggunaan indeks array dikombinasikan dengan perulangan (`for`/`while`) dan percabangan (`if-else`) untuk memudahkan manipulasi data, pencarian (*searching*), pengurutan (*sorting*), serta validasi kapasitas maksimal array.

---

## Petunjuk Kompilasi dan Menjalankan Program

Pastikan komputer atau laptop kamu sudah terpasang compiler bahasa C (seperti `gcc` melalui MinGW atau GCC bawaan Linux/macOS).

### 1. Kloning atau Unduh Repositori
Buka terminal atau Command Prompt pada direktori folder tempat file proyek ini berada.

### 2. Proses Kompilasi (Compile)
Ketik perintah berikut untuk mengkompilasi file *source code* (misalnya `main.c`) menjadi file *executable*:
```bash
gcc main.c -o program_kantin
```
---

## Dokumentasi Pengujian Program (Skenario Test)

Berikut adalah bukti tangkapan layar (*screenshot*) dari skenario pengujian program yang telah divalidasi sesuai ketentuan tugas:

### 1. Tambah Produk Baru
* **Tindakan:** Memilih menu 2 dan memasukkan data produk baru.
* **Hasil:** Produk berhasil ditambahkan dan muncul di daftar produk.
* <img width="1917" height="1016" alt="Tambah Produk" src="https://github.com/user-attachments/assets/85b4b0ca-83da-4623-8034-092b302e6c98" />
* <img width="1916" height="1020" alt="Screenshot 2026-11-17 210308" src="https://github.com/user-attachments/assets/8e7f968e-56b2-4d9d-a436-d9838f39f5e4" />
* <img width="1917" height="500" alt="Screenshot 2026-11-17 210344" src="https://github.com/user-attachments/assets/4f7d922f-04a1-49f0-bdb3-e620433697df" />
* Berdasarkan program Sistem Monitoring Stok & Penjualan Kantin yang ditampilkan, pengerjaan dimulai dengan memilih menu nomor 2, yaitu "Tambah Produk". Proses ini diawali dengan menambahkan menu Ayam Penyet dengan memasukkan nama produk "Ayam Penyet", menetapkan harga sebesar Rp15.000, serta mengisi stok awal sebanyak 40, yang kemudian disusul dengan pesan sukses bahwa produk berhasil ditambahkan. Langkah serupa juga dilakukan untuk memasukkan produk-produk lainnya secara berurutan, mulai dari Es Lemon Tea (harga Rp10.000, stok 20), Thai Tea (harga Rp12.000, stok 23), Sate Ayam (harga Rp25.000, stok 12), hingga Sate Maranggi (harga Rp60.000, stok 10). Setelah seluruh item menu dan data stok awal tersebut selesai diinput melalui opsi tambah produk, pengguna dapat kembali melihat keseluruhan daftar produk yang telah tersimpan di dalam sistem kantin.


### 2. Transaksi Penjualan Beberapa Produk
* **Tindakan:** Melakukan transaksi pembelian lebih dari satu jenis produk (Menu 4)[cite: 2, 3].
* **Hasil:** Subtotal per item dan total keseluruhan dihitung secara akurat[cite: 3].
* ![Skenario 2 - Transaksi Penjualan](screenshots/transaksi.png)

### 3. Pembaruan Stok & Jumlah Terjual
* **Tindakan:** Menyelesaikan transaksi pembayaran[cite: 3].
* **Hasil:** Stok produk berkurang otomatis dan jumlah terjual bertambah[cite: 3].
* ![Skenario 3 - Pembaruan Stok](screenshots/pembaruan_stok.png)

### 4. Penolakan Pembelian Melebihi Stok
* **Tindakan:** Membeli produk dengan jumlah yang melebihi stok tersedia[cite: 3].
* **Hasil:** Transaksi ditolak oleh sistem dan stok awal tetap aman[cite: 3].
* ![Skenario 4 - Stok Tidak Cukup](screenshots/stok_tidak_cukup.png)

### 5. Laporan Penjualan & Produk Terlaris
* **Tindakan:** Membuka menu laporan penjualan (Menu 8)[cite: 2, 3].
* **Hasil:** Menampilkan rincian unit terjual, total pendapatan, dan produk terlaris[cite: 3].
* ![Skenario 5 - Laporan Penjualan](screenshots/laporan.png)

### 6. Pengurutan Produk (Sorting)
* **Tindakan:** Mengurutkan produk berdasarkan harga termurah atau penjualan terbanyak[cite: 2, 3].
* **Hasil:** Data produk tersusun rapi sesuai kriteria pengurutan[cite: 3].
* ![Skenario 6 - Pengurutan Produk](screenshots/pengurutan.png)

### 7. Pencarian & Cek Stok Menipis
* **Tindakan:** Mencari produk via nama dan mengecek stok di bawah 5 (Menu 6 & 9)[cite: 2, 3].
* **Hasil:** Menampilkan hasil pencarian yang akurat serta peringatan stok menipis[cite: 3].
* ![Skenario 7 - Pencarian dan Stok Menipis](screenshots/pencarian_stok.png)
