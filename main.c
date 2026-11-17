#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUK 50
#define MAX_NAMA 50

// Data Utama menggunakan Array
char namaProduk[MAX_PRODUK][MAX_NAMA]; // Array 2D karakter untuk nama produk
int hargaProduk[MAX_PRODUK];           // Array 1D untuk harga
int stokProduk[MAX_PRODUK];            // Array 1D untuk stok
int terjualProduk[MAX_PRODUK];         // Array 1D untuk jumlah terjual

int jumlahData = 0; // Menilai jumlah produk aktif yang terdaftar

// Inisialisasi Data Awal (Minimal 5 Produk)
void inisialisasiData() {
    strcpy(namaProduk[0], "Ayam Goreng");
    hargaProduk[0] = 12000;
    stokProduk[0] = 15;
    terjualProduk[0] = 0;

    strcpy(namaProduk[1], "Mie Ayam");
    hargaProduk[1] = 10000;
    stokProduk[1] = 3; // Contoh stok < 5
    terjualProduk[1] = 0;

    strcpy(namaProduk[2], "Es Teh Manis");
    hargaProduk[2] = 3000;
    stokProduk[2] = 25;
    terjualProduk[2] = 0;

    strcpy(namaProduk[3], "Air Mineral");
    hargaProduk[3] = 2500;
    stokProduk[3] = 4; // Contoh stok < 5
    terjualProduk[3] = 0;

    strcpy(namaProduk[4], "Ayam Geprek");
    hargaProduk[4] = 16000;
    stokProduk[4] = 30;
    terjualProduk[4] = 0;

    jumlahData = 5;
}

// Helper untuk membersihkan buffer input
void bersihkanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 1. Fitur Lihat Daftar Produk
void lihatDaftarProduk() {
    printf("\n=== DAFTAR PRODUK KANTIN KAMPUS ===\n");
    if (jumlahData == 0) {
        printf("Belum ada data produk.\n");
        return;
    }
    printf("%-5s | %-25s | %-12s | %-8s | %-8s\n", "No", "Nama Produk", "Harga (Rp)", "Stok", "Terjual");
    printf("--------------------------------------------------------------------\n");
    for (int i = 0; i < jumlahData; i++) {
        printf("%-5d | %-25s | Rp%-10d | %-8d | %-8d\n",
               i + 1, namaProduk[i], hargaProduk[i], stokProduk[i], terjualProduk[i]);
    }
}

// 2. Fitur Tambah Produk Baru
void tambahProduk() {
    printf("\n=== TAMBAH PRODUK BARU ===\n");
    if (jumlahData >= MAX_PRODUK) {
        printf("[ERROR] Kapasitas penyimpanan penuh (Maksimal 50 produk)!\n");
        return;
    }

    printf("Masukkan Nama Produk: ");
    bersihkanBuffer();
    fgets(namaProduk[jumlahData], MAX_NAMA, stdin);
    namaProduk[jumlahData][strcspn(namaProduk[jumlahData], "\n")] = 0; // Hapus newline

    int harga, stok;
    do {
        printf("Masukkan Harga Produk (Rp): ");
        if (scanf("%d", &harga) != 1 || harga < 0) {
            printf("[ERROR] Harga harus berupa angka non-negatif!\n");
            bersihkanBuffer();
        } else {
            break;
        }
    } while (1);

    do {
        printf("Masukkan Stok Awal: ");
        if (scanf("%d", &stok) != 1 || stok < 0) {
            printf("[ERROR] Stok harus berupa angka non-negatif!\n");
            bersihkanBuffer();
        } else {
            break;
        }
    } while (1);

    hargaProduk[jumlahData] = harga;
    stokProduk[jumlahData] = stok;
    terjualProduk[jumlahData] = 0;
    jumlahData++;

    printf("[BERHASIL] Produk berhasil ditambahkan.\n");
}

// 3. Fitur Ubah Produk (Harga & Stok)
void ubahProduk() {
    lihatDaftarProduk();
    if (jumlahData == 0) return;

    int idx;
    printf("\nMasukkan Nomor Produk yang ingin diubah: ");
    if (scanf("%d", &idx) != 1 || idx < 1 || idx > jumlahData) {
        printf("[ERROR] Nomor produk tidak ditemukan/tidak valid!\n");
        bersihkanBuffer();
        return;
    }

    idx--; // Penyesuaian ke indeks array (0-based)

    int hargaBaru, stokBaru;
    do {
        printf("Masukkan Harga Baru untuk '%s' (Rp): ", namaProduk[idx]);
        if (scanf("%d", &hargaBaru) != 1 || hargaBaru < 0) {
            printf("[ERROR] Harga harus bernilai non-negatif!\n");
            bersihkanBuffer();
        } else {
            break;
        }
    } while (1);

    do {
        printf("Masukkan Stok Baru untuk '%s': ", namaProduk[idx]);
        if (scanf("%d", &stokBaru) != 1 || stokBaru < 0) {
            printf("[ERROR] Stok harus bernilai non-negatif!\n");
            bersihkanBuffer();
        } else {
            break;
        }
    } while (1);

    hargaProduk[idx] = hargaBaru;
    stokProduk[idx] = stokBaru;
    printf("[BERHASIL] Data produk '%s' berhasil diperbarui!\n", namaProduk[idx]);
}

// 4. Fitur Transaksi Penjualan Multi-Item
void transaksiPenjualan() {
    lihatDaftarProduk();
    if (jumlahData == 0) return;

    int jumlahItem;
    printf("\n=== TRANSAKSI PENJUALAN ===\n");
    printf("Berapa jenis produk yang ingin dibeli? ");
    if (scanf("%d", &jumlahItem) != 1 || jumlahItem <= 0) {
        printf("[ERROR] Jumlah jenis produk harus lebih dari 0!\n");
        bersihkanBuffer();
        return;
    }

    int itemBeli[50];
    int qtyBeli[50];
    int validCount = 0;
    long totalBayar = 0;

    for (int i = 0; i < jumlahItem; i++) {
        int noProd, qty;
        printf("\nItem ke-%d:\n", i + 1);
        printf("  Nomor Produk: ");
        if (scanf("%d", &noProd) != 1 || noProd < 1 || noProd > jumlahData) {
            printf("  [ERROR] Nomor produk tidak ditemukan! Item ini dilewati.\n");
            bersihkanBuffer();
            continue;
        }
        printf("  Jumlah Beli: ");
        if (scanf("%d", &qty) != 1 || qty <= 0) {
            printf("  [ERROR] Jumlah pembelian harus bernilai positif (> 0)! Item ini dilewati.\n");
            bersihkanBuffer();
            continue;
        }

        int idx = noProd - 1;
        if (qty > stokProduk[idx]) {
            printf("  [ERROR] Transaksi ditolak! Stok '%s' tidak cukup (Tersedia: %d).\n", namaProduk[idx], stokProduk[idx]);
            continue;
        }

        itemBeli[validCount] = idx;
        qtyBeli[validCount] = qty;
        validCount++;
    }

    if (validCount == 0) {
        printf("\n[BATAL] Tidak ada item valid yang diproses dalam transaksi ini.\n");
        return;
    }

    // Struk Pembayaran & Update Stok
    printf("\n================ STRUK TRANSAKSI ================\n");
    for (int i = 0; i < validCount; i++) {
        int idx = itemBeli[i];
        int qty = qtyBeli[i];
        long subtotal = (long)hargaProduk[idx] * qty;
        totalBayar += subtotal;

        // Pembaruan Stok dan Terjual
        stokProduk[idx] -= qty;
        terjualProduk[idx] += qty;

        printf("%d. %-20s x %-3d @ Rp%-8d = Rp%ld\n",
               i + 1, namaProduk[idx], qty, hargaProduk[idx], subtotal);
    }
    printf("-------------------------------------------------\n");
    printf("TOTAL PEMBAYARAN: Rp%ld\n", totalBayar);
    printf("=================================================\n");
    printf("[BERHASIL] Transaksi selesai, stok berhasil diperbarui.\n");
}

// 5. Fitur Tambah Stok Produk
void tambahStok() {
    lihatDaftarProduk();
    if (jumlahData == 0) return;

    int idx, tambahan;
    printf("\nMasukkan Nomor Produk yang ingin ditambah stoknya: ");
    if (scanf("%d", &idx) != 1 || idx < 1 || idx > jumlahData) {
        printf("[ERROR] Nomor produk tidak ditemukan!\n");
        bersihkanBuffer();
        return;
    }

    idx--;
    printf("Masukkan Jumlah Tambahan Stok: ");
    if (scanf("%d", &tambahan) != 1 || tambahan <= 0) {
        printf("[ERROR] Jumlah stok tambahan harus bernilai positif!\n");
        bersihkanBuffer();
        return;
    }

    stokProduk[idx] += tambahan;
    printf("[BERHASIL] Stok '%s' bertambah menjadi %d unit.\n", namaProduk[idx], stokProduk[idx]);
}

// 6. Fitur Pencarian Produk Berdasarkan Nama
void cariProduk() {
    char cari[MAX_NAMA];
    printf("\n=== CARI PRODUK ===\n");
    printf("Masukkan kata kunci nama produk: ");
    bersihkanBuffer();
    fgets(cari, MAX_NAMA, stdin);
    cari[strcspn(cari, "\n")] = 0;

    printf("\nHasil Pencarian:\n");
    printf("%-5s | %-25s | %-12s | %-8s | %-8s\n", "No", "Nama Produk", "Harga (Rp)", "Stok", "Terjual");
    printf("--------------------------------------------------------------------\n");

    int ketemu = 0;
    for (int i = 0; i < jumlahData; i++) {
        // Case-insensitive / Partial match sederhana
        if (strstr(namaProduk[i], cari) != NULL) {
            printf("%-5d | %-25s | Rp%-10d | %-8d | %-8d\n",
                   i + 1, namaProduk[i], hargaProduk[i], stokProduk[i], terjualProduk[i]);
            ketemu++;
        }
    }

    if (ketemu == 0) {
        printf("Produk dengan nama '%s' tidak ditemukan.\n", cari);
    }
}

// 7. Fitur Pengurutan Produk (Sorting)
void urutkanProduk() {
    if (jumlahData <= 1) {
        printf("Data belum cukup untuk diurutkan.\n");
        return;
    }

    int pilihan;
    printf("\n=== URUTKAN PRODUK ===\n");
    printf("1. Harga Termurah ke Termahal (Ascending)\n");
    printf("2. Penjualan Terbanyak ke Tersedikit (Descending)\n");
    printf("Pilih jenis pengurutan: ");
    if (scanf("%d", &pilihan) != 1 || (pilihan != 1 && pilihan != 2)) {
        printf("[ERROR] Pilihan pengurutan tidak valid!\n");
        bersihkanBuffer();
        return;
    }

    // Algoritma Bubble Sort
    for (int i = 0; i < jumlahData - 1; i++) {
        for (int j = 0; j < jumlahData - i - 1; j++) {
            int tukar = 0;
            if (pilihan == 1) {
                if (hargaProduk[j] > hargaProduk[j + 1]) tukar = 1;
            } else if (pilihan == 2) {
                if (terjualProduk[j] < terjualProduk[j + 1]) tukar = 1;
            }

            if (tukar) {
                // Tukar nama
                char tempNama[MAX_NAMA];
                strcpy(tempNama, namaProduk[j]);
                strcpy(namaProduk[j], namaProduk[j + 1]);
                strcpy(namaProduk[j + 1], tempNama);

                // Tukar harga
                int tempHarga = hargaProduk[j];
                hargaProduk[j] = hargaProduk[j + 1];
                hargaProduk[j + 1] = tempHarga;

                // Tukar stok
                int tempStok = stokProduk[j];
                stokProduk[j] = stokProduk[j + 1];
                stokProduk[j + 1] = tempStok;

                // Tukar terjual
                int tempTerjual = terjualProduk[j];
                terjualProduk[j] = terjualProduk[j + 1];
                terjualProduk[j + 1] = tempTerjual;
            }
        }
    }

    printf("[BERHASIL] Data berhasil diurutkan!\n");
    lihatDaftarProduk();
}

// 8. Fitur Laporan Penjualan
void laporanPenjualan() {
    printf("\n=== LAPORAN PENJUALAN KANTIN ===\n");
    if (jumlahData == 0) {
        printf("Belum ada data produk.\n");
        return;
    }

    long totalUnitTerjual = 0;
    long totalPendapatan = 0;
    int maxTerjual = -1;
    int idxTerlaris = -1;

    printf("%-5s | %-25s | %-10s | %-12s | %-12s\n", "No", "Nama Produk", "Terjual", "Harga Unit", "Subtotal");
    printf("----------------------------------------------------------------------\n");

    for (int i = 0; i < jumlahData; i++) {
        long subtotal = (long)terjualProduk[i] * hargaProduk[i];
        totalUnitTerjual += terjualProduk[i];
        totalPendapatan += subtotal;

        printf("%-5d | %-25s | %-10d | Rp%-10d | Rp%-10ld\n",
               i + 1, namaProduk[i], terjualProduk[i], hargaProduk[i], subtotal);

        if (terjualProduk[i] > maxTerjual) {
            maxTerjual = terjualProduk[i];
            idxTerlaris = i;
        }
    }

    printf("----------------------------------------------------------------------\n");
    printf("Total Unit Terjual  : %ld unit\n", totalUnitTerjual);
    printf("Total Pendapatan    : Rp%ld\n", totalPendapatan);
    if (idxTerlaris != -1 && maxTerjual > 0) {
        printf("Produk Terlaris     : %s (%d unit terjual)\n", namaProduk[idxTerlaris], maxTerjual);
    } else {
        printf("Produk Terlaris     : Belum ada produk terjual\n");
    }
    printf("======================================================================\n");
}

// 9. Fitur Cek Stok Menipis (< 5)
void cekStokMenipis() {
    printf("\n=== PERINGATAN STOK MENIPIS (< 5) ===\n");
    int adaStokMenipis = 0;

    printf("%-5s | %-25s | %-8s\n", "No", "Nama Produk", "Sisa Stok");
    printf("-------------------------------------------\n");

    for (int i = 0; i < jumlahData; i++) {
        if (stokProduk[i] < 5) {
            printf("%-5d | %-25s | %-8d\n", i + 1, namaProduk[i], stokProduk[i]);
            adaStokMenipis = 1;
        }
    }

    if (!adaStokMenipis) {
        printf("Semua produk memiliki stok cukup (>= 5).\n");
    }
    printf("-------------------------------------------\n");
}

// Main Function (Menu Utama)
int main() {
    inisialisasiData();
    int pilihan;

    do {
        printf("\n=== SISTEM MONITORING STOK & PENJUALAN KANTIN ===\n");
        printf("1. Lihat Daftar Produk\n");
        printf("2. Tambah Produk\n");
        printf("3. Ubah Produk\n");
        printf("4. Transaksi Penjualan\n");
        printf("5. Tambah Stok\n");
        printf("6. Cari Produk\n");
        printf("7. Urutkan Produk\n");
        printf("8. Laporan Penjualan\n");
        printf("9. Cek Stok Menipis\n");
        printf("0. Keluar\n");
        printf("Pilih menu [0-9]: ");

        if (scanf("%d", &pilihan) != 1) {
            printf("[ERROR] Input harus berupa angka pilihan menu!\n");
            bersihkanBuffer();
            continue;
        }

        switch (pilihan) {
            case 1: lihatDaftarProduk(); break;
            case 2: tambahProduk(); break;
            case 3: ubahProduk(); break;
            case 4: transaksiPenjualan(); break;
            case 5: tambahStok(); break;
            case 6: cariProduk(); break;
            case 7: urutkanProduk(); break;
            case 8: laporanPenjualan(); break;
            case 9: cekStokMenipis(); break;
            case 0: printf("\nTerima kasih telah menggunakan sistem kantin!\n"); break;
            default: printf("[ERROR] Pilihan menu tidak tersedia (Pilih 0-9)!\n"); break;
        }
    } while (pilihan != 0);

    return 0;
}



