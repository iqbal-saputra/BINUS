#include <stdio.h>
#include <stdlib.h>

struct tnode{
    int value;
    struct tnode *next;
    struct tnode *prev;
} *head, *tail;

void insertAtFront(int value){
    struct tnode *newNode = (struct tnode *)malloc(sizeof(struct tnode));
    if(newNode == NULL){
        printf("Gagal mengalokasikan memori\n");
        return;
    }
    newNode->value = value;
    newNode->next = head;
    newNode->prev = NULL;
    if(head != NULL){
        head->prev = newNode;
    }
    head = newNode;
    if(tail == NULL){
        tail = head;
    }
}

void insertAfter(int key, int x){
    struct tnode *curr = head;
    while(curr != NULL && curr->value != key){
        curr = curr->next;
    }
    if(curr == NULL){
        printf("Node tidak ditemukan\n");
        return;
    }
    struct tnode *newNode = (struct tnode *)malloc(sizeof(struct tnode));
    if(newNode == NULL){
        printf("Gagal mengalokasikan memori\n");
        return;
    }
    newNode->value = x;
    newNode->next = curr->next;
    newNode->prev = curr;
    if(curr->next != NULL){
        curr->next->prev = newNode;
    }
    curr->next = newNode;
}

void insertHead(int value){
    struct tnode *newNode = (struct tnode *)malloc(sizeof(struct tnode));
    if(newNode == NULL){
        printf("Gagal mengalokasikan memori\n");
        return;
    }
    newNode->value = value;
    newNode->next = head;
    newNode->prev = NULL;
    if(head != NULL){
        head->prev = newNode;
    }
    head = newNode;
    if(tail == NULL){
        tail = head;
    }
}
void insertTail(int value){
    struct tnode *newNode = (struct tnode *)malloc(sizeof(struct tnode));
    if(newNode == NULL){
        printf("Gagal mengalokasikan memori\n");
        return;
    }
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = tail;
    if(tail != NULL){
        tail->next = newNode;
    }
    tail = newNode;
    if(head == NULL){
        head = tail;

    }
}

void displayForward(){
    struct tnode *curr = head;
    while(curr != NULL){
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

int main(){

    insertTail(10);
    insertTail(24);
    insertTail(17);
    printf("Setelah insert tail:\n");
    displayForward();

    insertHead(5);
    printf("Setelah insert head:\n"); 
    displayForward();


    return 0;
}