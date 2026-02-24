#include <stdio.h>
#include <string.h>

struct Pakaian {
    char jenis_pakaian[50];
    int jumlah_pakaian;
    char note[100];
};

int main() {
    struct Pakaian listLaundry[100]; 
    int index = 0;
    int jumlah_seluruh_barang = 0;
    char lanjut;

    printf("=================================\n");
    printf("      SISTEM PENDATAAN LAUNDRY   \n");
    printf("=================================\n\n");
    do {
        printf("--- Masukkan Data ke-%d ---\n", index + 1);
        
        printf("Jenis Pakaian  : ");
        scanf(" %[^\n]", listLaundry[index].jenis_pakaian); 
        
        printf("Jumlah Pakaian : ");
        scanf("%d", &listLaundry[index].jumlah_pakaian);
        
        printf("Note / Catatan : ");
        scanf(" %[^\n]", listLaundry[index].note);
        jumlah_seluruh_barang += listLaundry[index].jumlah_pakaian;
        index++;
        
        printf("\nTambah pakaian lain? (y/n): ");
        scanf(" %c", &lanjut);
        printf("\n");
        
    } while ((lanjut == 'y' || lanjut == 'Y') && index < 100);

    printf("\n========================================================================\n");
    printf("                          REKAP DAFTAR LAUNDRY                          \n");
    printf("========================================================================\n");
    printf("========================================================================\n");
    
    printf("%-3s | %-20s | %-10s | %-25s\n", "No", "Jenis Pakaian", "Jumlah", "Note");
    printf("------------------------------------------------------------------------\n");
    
    for (int i = 0; i < index; i++) {
        printf("%-3d | %-20s | %-10d | %-25s\n", 
               i + 1, 
               listLaundry[i].jenis_pakaian, 
               listLaundry[i].jumlah_pakaian, 
               listLaundry[i].note);
    }
    
    printf("------------------------------------------------------------------------\n");
    printf("TOTAL KESELURUHAN BARANG : %d pcs\n", jumlah_seluruh_barang);
    printf("========================================================================\n");

    return 0;
}