#include <stdio.h> // Untuk input/output standar seperti printf, scanf
#include <string.h> // Untuk fungsi string seperti strcpy, strlen
#include <stdlib.h> // Untuk fungsi exit atau konversi jika diperlukan

// Definisi struktur untuk menyimpan data pesanan
struct Pemesanan {
    char nama_penumpang[50];
    char rute[100];
    long harga_satuan;
    int jumlah_tiket;
    long total_bayar;
};

int main() {
    // Deklarasi variabel
    struct Pemesanan pesanan;
    char pilihan_menu_char; // Menggunakan char untuk input menu a/b/c
    int pilihan_menu_int; // Menggunakan int untuk konversi pilihan menu dari char
    char pesan_lagi; // Untuk konfirmasi pemesanan ulang

    // Loop do-while untuk memungkinkan pemesanan ulang
    do {
        // Membersihkan data pesanan sebelumnya jika ada pemesanan ulang
        memset(&pesanan, 0, sizeof(struct Pemesanan)); 

        printf("=== SISTEM PEMESANAN TIKET KBT ===\n");

        // Input Nama Penumpang (mengandung spasi)
        printf("Masukkan Nama Penumpang: ");
        // Menggunakan fgets untuk membaca string dengan spasi, aman dari buffer overflow
        fgets(pesanan.nama_penumpang, sizeof(pesanan.nama_penumpang), stdin);
        // Menghilangkan karakter newline ('\n') yang mungkin ditambahkan fgets
        pesanan.nama_penumpang[strcspn(pesanan.nama_penumpang, "\n")] = 0;

        // Menampilkan menu pilihan rute
        printf("\nPilih Rute Perjalanan:\n");
        printf("1. Medan - P. Siantar - Parapat (Rp 60.000)\n");
        printf("2. Porsea - Balige - Laguboti - Tarutung (Rp 85.000)\n");
        printf("3. Dolok Sanggul - Muara - Sipahutar - Panyabungan (Rp 100.000)\n");

        // Loop validasi untuk input menu (harus 1, 2, atau 3)
        do {
            printf("Pilih menu (1-3): ");
            // Menggunakan scanf dan kemudian getchar untuk membersihkan buffer
            // Ini untuk mencegah masalah dengan fgets berikutnya jika ada
            if (scanf(" %c", &pilihan_menu_char) != 1) {
                printf("Input tidak valid. Harap masukkan angka 1, 2, atau 3.\n");
                // Membersihkan buffer input jika terjadi kesalahan
                while (getchar() != '\n');
                pilihan_menu_int = 0; // Set ke nilai tidak valid
                continue;
            }
            // Membersihkan buffer input setelah scanf untuk char
            while (getchar() != '\n');
            
            // Konversi char ke int untuk memudahkan switch-case
            if (pilihan_menu_char >= '1' && pilihan_menu_char <= '3') {
                pilihan_menu_int = pilihan_menu_char - '0';
            } else {
                pilihan_menu_int = 0; // Menandakan input tidak valid
            }

            if (pilihan_menu_int < 1 || pilihan_menu_int > 3) {
                printf("Pilihan tidak valid. Silakan pilih 1, 2, atau 3.\n");
            }
        } while (pilihan_menu_int < 1 || pilihan_menu_int > 3);

        // Menggunakan switch-case untuk logika pemilihan rute dan harga
        switch (pilihan_menu_int) {
            case 1:
                strcpy(pesanan.rute, "Medan - P. Siantar - Parapat");
                pesanan.harga_satuan = 60000;
                break;
            case 2:
                strcpy(pesanan.rute, "Porsea - Balige - Laguboti - Tarutung");
                pesanan.harga_satuan = 85000;
                break;
            case 3:
                strcpy(pesanan.rute, "Dolok Sanggul - Muara - Sipahutar - Panyabungan");
                pesanan.harga_satuan = 100000;
                break;
            default:
                // Seharusnya tidak tercapai karena validasi sebelumnya
                printf("Terjadi kesalahan. Program berhenti.\n");
                exit(1); 
        }

        // Input jumlah tiket (bilangan bulat positif)
        do {
            printf("Masukkan Jumlah Tiket: ");
            if (scanf("%d", &pesanan.jumlah_tiket) != 1 || pesanan.jumlah_tiket <= 0) {
                printf("Jumlah tiket tidak valid. Harap masukkan bilangan bulat positif.\n");
                // Membersihkan buffer input jika terjadi kesalahan
                while (getchar() != '\n'); 
            }
             // Membersihkan buffer input setelah scanf untuk int
            while (getchar() != '\n');
        } while (pesanan.jumlah_tiket <= 0);

        // Menghitung total bayar
        pesanan.total_bayar = pesanan.harga_satuan * pesanan.jumlah_tiket;

        // Menampilkan struk sederhana
        printf("\n---------------------------------------\n");
        printf("      STRUK PEMESANAN TIKET KBT        \n");
        printf("---------------------------------------\n");
        printf("Nama Penumpang : %s\n", pesanan.nama_penumpang);
        printf("Rute           : %s\n", pesanan.rute);
        printf("Harga Satuan   : Rp %ld\n", pesanan.harga_satuan);
        printf("Jumlah Tiket   : %d\n", pesanan.jumlah_tiket);
        printf("---------------------------------------\n");
        printf("TOTAL BAYAR    : Rp %ld\n", pesanan.total_bayar);
        printf("---------------------------------------\n");

        // Konfirmasi pemesanan ulang
        do {
            printf("\nApakah ingin memesan tiket lagi? (y/n): ");
            if (scanf(" %c", &pesan_lagi) != 1) {
                 printf("Input tidak valid. Harap masukkan 'y' atau 'n'.\n");
                 while (getchar() != '\n'); // Bersihkan buffer
            }
            while (getchar() != '\n'); // Bersihkan buffer setelah membaca char
            if (pesan_lagi != 'y' && pesan_lagi != 'Y' && pesan_lagi != 'n' && pesan_lagi != 'N') {
                printf("Pilihan tidak valid. Harap masukkan 'y' atau 'n'.\n");
            }
        } while (pesan_lagi != 'y' && pesan_lagi != 'Y' && pesan_lagi != 'n' && pesan_lagi != 'N');

    } while (pesan_lagi == 'y' || pesan_lagi == 'Y'); // Melanjutkan jika user memilih 'y' atau 'Y'

    printf("Terima kasih telah menggunakan layanan KBT!\n");

    return 0; // Program berakhir dengan sukses
}
