#include <stdio.h.>

int main(){
    int x = 20;
    int *px = &x;

    *px = 10;

    printf("Nilai dari x: %d\n", x);
    printf("Alamat memori dari x: %p\n", &x);

    printf("Alamat yang ditunjuk px: %p\n", px);
    printf("Nilai yang ditunjuk px: %d \n", *px);


    return 0;
}