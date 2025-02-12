#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct Address{
    char streetName[101];
    char houseNumber[101];
    char city[101];
    char province[101];
};

struct Birth{
    char place[101];
    int day;
    int month;
    int year;
};
struct Student{
    long long int nim;
    char name[101];
    struct Address address;
    struct Birth birth;
};

int main(){
    int jumlahStudent = 5;
    struct Student student[jumlahStudent];

    for(int i = 0; i < jumlahStudent; i++){
        printf("Masukan NIM mahasiswa ke-%d\t: ", i + 1);
        scanf("%lld", &student[i].nim);
        getchar();

        printf("Masukan nama mahasiswa ke-%d\t: ", i + 1);
        scanf("%[^\n]", student[i].name);
        getchar();

        printf("\nMasukan alamat mahasiswa ke-%d\n", i + 1);
        printf("Nama jalan\t: ");
        scanf("%[^\n]", student[i].address.streetName);
        getchar();

        printf("Nomor rumah\t: ");
        scanf("%[^\n]", student[i].address.houseNumber);
        getchar();

        printf("Kota\t\t: ");
        scanf("%[^\n]", student[i].address.city);
        getchar();

        printf("Provinsi\t: ");
        scanf("%[^\n]", student[i].address.province); 
        getchar();

        printf("\nMasukan tempat tanggal lahir mahasiswa ke-%d\n", i + 1);
        printf("Tempat Lahir\t: ");
        scanf("%[^\n]", student[i].birth.place);
        getchar();

        printf("Tanggal lahir[01-31]\t: ");
        scanf("%d", &student[i].birth.day);
        getchar();

        printf("Bulan lahir[01-12]\t: ");
        scanf("%d", &student[i].birth.month);
        getchar();

        printf("Tahun lahir[2000]\t: ");
        scanf("%d", &student[i].birth.year);
        printf("\n");
    }
    system("cls");
    for(int i = 0; i < jumlahStudent; i++){
        printf("\nData mahasiswa ke-%d: \n", i + 1);
        printf("NIM\t: %lld\n", student[i].nim);
        printf("Nama\t: %s\n", student[i].name);
        printf("Alamat\t: %s, %s\n\t  %s, %s\n", student[i].address.streetName, student[i].address.houseNumber, student[i].address.city, student[i].address.province);

        // printf("\tNama jalan: %s\n", student[i].address.streetName);
        // printf("\tNomor rumah: %s\n", student[i].address.houseNumber);
        // printf("\tKota: %s\n", student[i].address.city);
        // printf("\tProvinsi: %s\n", student[i].address.province);

        printf("TTL\t: %s, %d-%d-%d\n\n", student[i].birth.place, student[i].birth.day, student[i].birth.month, student[i].birth.year);
        // printf("\tTempat lahir: %s\n", student[i].birth.place);
        // printf("\tTanggal lahir: %d\n", student[i].birth.day);
        // printf("\tBulan lahir: %d\n", student[i].birth.month);
        // printf("\tTahun lahir: %d\n", student[i].birth.year);
    }

    return 0;
}