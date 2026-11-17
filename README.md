# Proyek-Array-C-C2583207052
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
* Proses ini diawali dengan menambahkan menu "Ayam Penyet", dengan harga sebesar Rp15.000, serta stok awal sebanyak 40, kemudian Es Lemon Tea (harga Rp10.000, stok 20), Thai Tea (harga Rp12.000, stok 23), Sate Ayam (harga Rp25.000, stok 12), hingga Sate Maranggi (harga Rp60.000, stok 10). Setelah seluruh item menu dan data stok awal tersebut selesai diinput melalui opsi tambah produk, pengguna dapat kembali melihat keseluruhan daftar produk yang telah tersimpan di dalam sistem kantin.

### 2. Transaksi Penjualan Beberapa Produk
* **Tindakan:** Melakukan transaksi pembelian lebih dari satu jenis produk (Menu 4).
* **Hasil:** Subtotal per item dan total keseluruhan dihitung secara akurat.
* <img width="1917" height="1011" alt="Screenshot 2026-11-17 210403" src="https://github.com/user-attachments/assets/3bf403aa-cef0-4425-a91c-e2c13499d54b" />
* <img width="1917" height="362" alt="Screenshot 2026-11-17 210523" src="https://github.com/user-attachments/assets/c331ed01-6828-46ec-a88a-121901e4181a" />
* Pada bagian input transaksi, pengguna memasukkan jumlah jenis produk yang ingin dibeli, yaitu sebanyak 3 jenis. Pembelian pertama (Item ke-1) memilih nomor produk 5 (Ayam Geprek) dengan jumlah beli sebanyak 2 porsi. Pembelian kedua (Item ke-2) memilih nomor produk 9 (Sate Maranggi) sebanyak 1 porsi. Pembelian ketiga (Item ke-3) memilih nomor produk 7 (Es Lemon Tea) sebanyak 5 porsi. Setelah semua item dimasukkan, sistem otomatis mencetak Struk Transaksi yang merinci rincian belanjaan—yakni Ayam Geprek (2 x Rp16.000 = Rp32.000), Sate Maranggi (1 x Rp60.000 = Rp60.000), dan Es Lemon Tea (5 x Rp10.000 = Rp50.000)—dengan total keseluruhan pembayaran sebesar Rp142.000, diakhiri dengan pesan sukses bahwa transaksi selesai dan stok produk telah berhasil diperbarui.

### 3. Pembaruan Stok & Jumlah Terjual
* **Tindakan:** Menyelesaikan transaksi pembayaran.
* **Hasil:** Stok produk berkurang otomatis dan jumlah terjual bertambah.
* <img width="1917" height="778" alt="Screenshot 2026-11-17 210545" src="https://github.com/user-attachments/assets/8b17f448-1248-48a4-9f19-109a0549f873" />
* Pengguna memilih menu 5 (Tambah Stok), lalu memasukkan nomor produk 2 (Mie Ayam) dengan jumlah tambahan stok sebanyak 8 unit. Sistem kemudian berhasil memperbarui stok Mie Ayam dari 3 unit menjadi 11 unit.

### 4. Penolakan Pembelian Melebihi Stok
* **Tindakan:** Membeli produk dengan jumlah yang melebihi stok tersedia.
* **Hasil:** Transaksi ditolak oleh sistem dan stok awal tetap aman.
* <img width="1917" height="925" alt="Screenshot 2026-11-17 210609" src="https://github.com/user-attachments/assets/698fd53c-2a77-4707-b0ca-b9d5f7709642" />
* Untuk membeli 1 jenis produk, yaitu nomor 2 (Mie Ayam) sebanyak 15 unit. Karena stok Mie Ayam yang tersedia hanya 11 unit, sistem menolak transaksi dengan pesan [ERROR] Transaksi ditolak! Stok 'Mie Ayam' tidak cukup (Tersedia: 11) sehingga transaksi dibatalkan.

### 5. Laporan Penjualan & Produk Terlaris
* **Tindakan:** Membuka menu laporan penjualan (Menu 8).
* **Hasil:** Menampilkan rincian unit terjual, total pendapatan, dan produk terlaris.
* <img width="1917" height="781" alt="Screenshot 2026-11-17 210630" src="https://github.com/user-attachments/assets/931b0ad5-8e67-49d2-9ad6-cd001602572a" />
* Untuk melihat rekapitulasi penjualan kantin. Berdasarkan laporan tersebut, tercatat produk yang laku terjual adalah Ayam Geprek (2 unit), Es Lemon Tea (5 unit), dan Sate Maranggi (1 unit), dengan total keseluruhan unit terjual sebanyak 8 unit, total pendapatan sebesar Rp142.000, serta produk terlaris yaitu Es Lemon Tea dengan 5 unit terjual.

### 6. Pengurutan Produk (Sorting)
* **Tindakan:** Mengurutkan produk berdasarkan harga termurah atau penjualan terbanyak.
* **Hasil:** Data produk tersusun rapi sesuai kriteria pengurutan.
* <img width="1917" height="830" alt="Screenshot 2026-11-17 210653" src="https://github.com/user-attachments/assets/bc0b4640-e4fb-4297-b8fb-0633fe00d7b0" />
* Pengguna memilih menu 7 (Urutkan Produk), lalu memasukkan pilihan pengurutan nomor 1 (Harga Termurah ke Termahal / Ascending). Sistem berhasil mengurutkan data dan menampilkan daftar produk secara berurutan mulai dari harga terendah (Air Mineral Rp2.500) hingga harga tertinggi (Sate Maranggi Rp60.000).

### 7. Pencarian & Cek Stok Menipis
* **Tindakan:** Mencari produk via nama dan mengecek stok di bawah 5 (Menu 6 & 9).
* **Hasil:** Menampilkan hasil pencarian yang akurat serta peringatan stok menipis.
* <img width="1917" height="550" alt="Screenshot 2026-11-17 231122" src="https://github.com/user-attachments/assets/2e86c273-da35-4998-b4fc-d37571b159f5" />
* Pengguna memilih menu 6 lalu mengetik kata kunci nama produk "Ayam Penyet". Sistem kemudian menampilkan hasil pencarian berupa detail produk Ayam Penyet dengan harga Rp15.000, stok 40, dan jumlah terjual 0.
* <img width="1917" height="446" alt="Screenshot 2026-11-17 231157" src="https://github.com/user-attachments/assets/f52d81ed-0fd3-454e-b248-20e5afb273bd" />
* Pada tangkapan layar berikutnya, pengguna memilih menu 9 untuk memeriksa produk dengan stok yang hampir habis (di bawah 5). Sistem menampilkan peringatan stok menipis dan mendeteksi produk Air Mineral yang tersisa 4 unit saja.

