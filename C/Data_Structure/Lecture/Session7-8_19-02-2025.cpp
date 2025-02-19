#include <stdio.h>
#include <stdlib.h>

struct tnode{
    int value;
    struct tnode *next;
};

void insertAtFront(struct tnode **head, int value){

    struct tnode *newNode = (struct tnode *)malloc(sizeof(struct tnode));
    if(newNode == NULL){
        printf("Gagal mengalokasikan memori\n");
        return;
    }
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}

int main(){

    struct tnode *head = NULL;
    insertAtFront(&head, 10);
    insertAtFront(&head, 20);
    insertAtFront(&head, 5);








    return 0;
}