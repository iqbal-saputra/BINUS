#include <stdio.h>
#include <stdlib.h>

int main(){

    int *ptr;
    int n = 5;


    // Alokasi memori secara dinamis
    ptr = (int*)malloc(n * sizeof(int));

    if(ptr == NULL){
        printf("Alokasi memori gagal/tidak cukup\n");
        return 1;
    }

    // Mengisi nilai dalam array
    for(int i = 0; i < n; i++){
        ptr[i] = (i + 1) * 10;
    }

    printf("Array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", ptr[i]);
    }
    printf("\n");
    free(ptr);


    return 0;
}