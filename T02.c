#include <stdio.h>

int main() {
    int n, kode;
    int total = 0;

    printf("Masukkan jumlah total data (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Input tidak valid.\n");
        return 1;
    }

    int nilai[n];

    printf("Masukkan deret nilai (pisahkan dengan spasi): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nilai[i]);
    }

    printf("Masukkan kode kelompok (1 untuk ganjil, 2 untuk genap): ");
    scanf("%d", &kode);
sd,jf;zx
    for (int i = 0; i < n; i++) {
       
        if (kode == 1 && i % 2 == 0) {
            total += nilai[i];
        } 
        
        else if (kode == 2 && i % 2 != 0) {
            total += nilai[i];
        }
    }

   
    if (kode == 1 || kode == 2) {
        printf("Total nilai untuk kelompok %d adalah: %d\n", kode, total);
    } else {
        printf("Kode kelompok tidak dikenali. Silakan masukkan 1 atau 2.\n");
    }

    return 0;
}