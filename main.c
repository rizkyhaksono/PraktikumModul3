#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main () {

    int menu, jumlahMenu, i, totalAkhir = 0, uang;

    char teks = 'p';
    char jawab;

    // Untuk struk kembalian
    int totalUang, kembali;

    back:
    printf("||\t   SELAMAT DATANG  \t||\n");
    printf("||\t   DI WARUNG ALAS  \t||\n\n");

    printf("No.\tNama Menu\tHarga\n\n");
    printf("1.\tRawon \t\tRp. 15.000\n2.\tSoto \t\tRp. 10.000\n3.\tNasi Pecel \tRp.  8.000\n4.\tEs Teh \t \tRp.  2.500\n5.\tEs Jeruk \tRp.  3.000\n");


    while (teks == 'p') {
        printf("\n\nMasukkan Berapa Menu : ");
        scanf("%d", &jumlahMenu);

        for (i = 1; i <= jumlahMenu; i++){
            printf("\nMasukkan Menu Ke-%d : ", i);
            scanf("%d", &menu);

            if (menu == 1) {
                totalAkhir = totalAkhir + totalHarga ("Rawon", 15000);
            }else if (menu == 2) {
                totalAkhir = totalAkhir + totalHarga ("Soto", 10000);
            }else if (menu == 3) {
                totalAkhir = totalAkhir + totalHarga ("Nasi Pecel", 8000);
            }else if (menu == 4) {
                totalAkhir = totalAkhir + totalHarga ("Es Teh", 2500);
            }else if (menu == 5) {
                totalAkhir = totalAkhir + totalHarga ("Es Jeruk", 3000);
            }else{
                printf("\n||\t Menu Tidak Ada! \t||\n");
                goto back;
            }
        }

        printf("\nGrand Total\t: Rp. %d\n", totalAkhir);

        uang:
		printf("Tunai\t\t: Rp. ");
		scanf("%d", &uang);

        totalUang = uang;
        kembali = uang - totalAkhir;

        if (uang >= totalAkhir) {
            printf("Kembali\t\t: Rp. %d\n", uang - totalAkhir);
            goto confirm;
        }else{
            printf("\n-----------------------------");
			printf("\nMaaf, Uang Anda Kurang!\n");
            printf("-----------------------------\n\n");
			goto uang;
        }
        
    }

    confirm:
    printf("\nIngin membeli lagi? (y/n) : ");
    scanf("%s", &jawab);

    switch (tolower(jawab)) {
    case 'y':
    case 'Y':
        system("cls");
        goto back;
        break;
    case 'n':
    case 'N':
        system("cls");

        printf("\n||\t  TERIMA KASIH TELAH BERBELANJA! \t||");
        printf("\n||\t\t  INI STRUK ANDA \t\t||\n");
        printf("||\t\t\t\t\t\t||");

        printf("\n||\t  Grand Total\t: Rp. %d\t\t||", totalAkhir);
        printf("\n||\t  Tunai\t\t: Rp. %d\t\t||", totalUang);
        printf("\n||\t  Kembali\t: Rp. %d\t\t||", kembali);

        printf("\n||\t\t\t\t\t\t||");
        printf("\n||\t  LAYANAN KONSUMEN WARUNG ALAS \t\t||");
        printf("\n||\t  SMS 081 2345 6789 CALL 1500 280 \t||");
        printf("\n||\t  EMAIL: warungalas@gmail.com  \t\t||");
        printf("\n||\t  Jalan Raya Apel Manis, Malang \t||\n\n");

        break;
    default:
        printf("\n||\t ANDA SALAH KETIK! \t||\n");
        goto confirm;
    }
    
    return 0;
}

int totalHarga (char namaMenu[], int hargaMenu) {
	int totalMenu, jumlah;

    printf("\n-----------------------------");
	printf("\nAnda Memilih Menu : %s\n", namaMenu);
	printf("-----------------------------\n");

	printf("\nMasukan Jumlah Menu : ");
	scanf("%d", &jumlah);

	totalMenu = hargaMenu * jumlah;
	printf("Quantity : %d %s\n", jumlah, namaMenu);
	
    printf("\n-----------------------------\n");
	printf("Total Harga : Rp. %d\n", totalMenu);
	printf("-----------------------------\n");

	return totalMenu;
}