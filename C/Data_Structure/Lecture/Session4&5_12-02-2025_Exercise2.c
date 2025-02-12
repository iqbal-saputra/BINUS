#include <stdio.h>
#include <stdlib.h>

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
    int nim;
    char name[101];
    struct Address address;
    struct Birth birth;
};

int main(){
    int jumlahStudent = 2;
    struct Student student[jumlahStudent];

    for(int i = 0; i < 5; i++){
        printf("Masukan NIM mahasiswa ke-%d: ", i + 1);
        scanf("%d", &student[i].nim);
        printf("Masukan nama mahasiswa ke-%d: ", i + 1);
        scanf("%[^\n]", student[i].name);
        printf("Masukan alamat mahasiswa ke-%d: \n", i + 1);
        printf("Nama jalan: ");
        scanf("%[^\n]", student[i].address.streetName);
        printf("Nomor rumah: ");
        scanf("%[^\n]", student[i].address.houseNumber);
        printf("Kota: ");
        scanf("%[^\n]", student[i].address.city);
        printf("Provinsi: ");
        scanf("%[^\n]", student[i].address.province); 
        printf("Masukan tempat tanggal lahir mahasiswa ke-%d: ", i + 1);
        printf("Tempat Lahir: ");
        scanf("%[^\n]", student[i].birth.place);
        printf("Tanggal lahir[01-31]: ");
        scanf("%d", &student[i].birth.day);
        printf("Bulan lahir[01-12]: ");
        scanf("%d", &student[i].birth.month);
        printf("Tahun lahir[2000]: ");
    }

    printf("Data mahasiswa: \n");
    for(int i = 0; i < jumlahStudent; i++){
        printf("NIM: %d\n", student[i].nim);
        printf("Nama: %s\n", student[i].name);
        printf("Alamat: \n");
        printf("Nama jalan: %s\n", student[i].address.streetName);
        printf("Nomor rumah: %s\n", student[i].address.houseNumber);
        printf("Kota: %s\n", student[i].address.city);
        printf("Provinsi: %s\n", student[i].address.province);
        printf("Tempat tanggal lahir: \n");
        printf("Tempat lahir: %s\n", student[i].birth.place);
        printf("Tanggal lahir: %d\n", student[i].birth.day);
        printf("Bulan lahir: %d\n", student[i].birth.month);
        printf("Tahun lahir: %d\n", student[i].birth.year);
    }

    return 0;
}