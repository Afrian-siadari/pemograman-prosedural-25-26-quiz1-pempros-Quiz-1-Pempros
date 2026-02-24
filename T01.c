#include <stdio.h>
#include <string.h>

// Struktur data untuk menyimpan informasi menu
typedef struct {
    char kode[5];
    char nama[50];
    long harga;
} Menu;

int main() {
    Menu daftar_menu[] = {
        {"NGS", "Nasi Goreng Spesial", 15000},
        {"AP",  "Ayam Penyet", 20000},
        {"SA",  "Sate Ayam (10 Tusuk)", 25000},
        {"BU",  "Bakso Urat", 18000},
        {"MAP", "Mie Ayam Pangsit", 15000},
        {"GG",  "Gado-Gado", 15000},
        {"SAM", "Soto Ayam", 17000},
        {"RD",  "Rendang Daging", 25000},
        {"IB",  "Ikan Bakar", 35000},
        {"NUK", "Nasi Uduk Komplit", 20000}
    };
    int jumlah_menu = 10;
    
    char input_kode[10];
    int porsi_butet;
    long total_belanja = 0;
    
    printf("=== SISTEM KASIR MAK ROBY ===\n");
    printf("Masukkan pesanan (Ketik 'END' untuk selesai):\n\n");
    
    //  menerima input pesanan
    while (1) {
        // Jika gagal membaca input, keluar dari loop
        if (scanf("%s", input_kode) != 1) break; 
        
        if (strcmp(input_kode, "END") == 0) {
            break;
        }
        
        porsi_butet = 1; 
        
        scanf("%d", &porsi_butet);
        
        // Cari menu berdasarkan kode
        int ditemukan = 0;
        for (int i = 0; i < jumlah_menu; i++) {
            if (strcmp(daftar_menu[i].kode, input_kode) == 0) {
                // Hitung porsi berdasarkan rasio berat badan (Ucok 100kg, Butet 50kg -> 2:1)
                int porsi_ucok = porsi_butet * 2;
                int total_porsi = porsi_butet + porsi_ucok;
                
                // Tambahkan ke total belanja
                long subtotal = total_porsi * daftar_menu[i].harga;
                total_belanja += subtotal;
                
                ditemukan = 1;
                break;
            }
        }
        
        if (!ditemukan) {
            printf("Kode '%s' tidak valid!\n", input_kode);
        }
    }
    
    // Menentukan kupon dan diskon berdasarkan total belanja
    int diskon = 0;
    char kupon[20] = "Tidak Ada";
    
    if (total_belanja >= 500000) {
        diskon = 25;
        strcpy(kupon, "Kupon Hitam");
    } else if (total_belanja >= 400000) {
        diskon = 20;
        strcpy(kupon, "Kupon Hijau");
    } else if (total_belanja >= 300000) {
        diskon = 15;
        strcpy(kupon, "Kupon Merah");
    } else if (total_belanja >= 200000) {
        diskon = 10;
        strcpy(kupon, "Kupon Kuning");
    } else if (total_belanja >= 100000) {
        diskon = 5;
        strcpy(kupon, "Kupon Biru");
    }
    
    // Kalkulasi akhir
    long potongan_harga = (total_belanja * diskon) / 100;
    long total_bayar = total_belanja - potongan_harga;
    
    printf("\n==============================\n");
    printf("Total Belanja  : Rp %ld\n", total_belanja);
    printf("Kupon Didapat  : %s (%d%%)\n", kupon, diskon);
    printf("Potongan Harga : Rp %ld\n", potongan_harga);
    printf("------------------------------\n");
    printf("TOTAL BAYAR    : Rp %ld\n", total_bayar);
    printf("==============================\n");
    
    return 0;
}