#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;

void push(int value){
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop(){
    if(top == NULL){
        printf("Stack underflow\n");
    }
    else {
        struct Node *temp = top;
        printf("Menghapus %d dari stack\n", temp->data);
        top = top->next;
        free(temp);
    }
}

void peek(){
    if(top == NULL){
        printf("Stack underflow\n");
    }
    else {
        printf("Elemen teratas: %d\n", top->data);
    }
}

void display(){
    if(top == NULL){
        printf("Stack kosong\n");
        return;
    }
    else {
        struct Node *temp = top;
        printf("Stack: \n");

        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    peek();

    display();

    pop();

    display();

    return 0;
}
