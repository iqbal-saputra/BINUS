#include <stdio.h>

#define MAX 5

int stack[MAX], top = -1;

void push(int value){
    if(top == MAX - 1){
        printf("Stack overflow, tidak bisa menambahkan %d\n", value);
    }
    else {
        top++; // geser TOP ke atas
        stack[top] = value;
        printf("Menambahkan %d ke dalam stack\n", value);
    }
}

void display(){
    if(top == -1){
        printf("Stack kosong\n");
    }
    else {
        printf("Stack: \n");

        for(int i = top; i >= 0; i--){
            printf("%d ", stack[i]);
            printf("\n");
        }
    }
}

int main(){

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    display();

    return 0;
}

