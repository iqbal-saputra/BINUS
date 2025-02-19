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
void insertAtEnd(struct tnode **head, int value){
    struct tnode *newNode = (struct tnode*)malloc(sizeof(struct tnode));
    if(newNode == NULL){
        printf("Gagal mengalokasikan memori\n");
        return;
    }
    newNode->value = value;
    newNode->next = NULL; // Karena akan diletakkan di akhir, maka next akan NULL

    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct tnode *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
}
void insertAfter(struct tnode *prevNode, int value){
    if(prevNode == NULL){
        printf("Node sebelumnya tidak boleh NULL\n");
        return;
    }
    struct tnode *newNode = (struct tnode*)malloc(sizeof(struct tnode));
    if(newNode == NULL){
        printf("Gagal mengalokasikan memori\n");
        return;
    }
    newNode->value = value;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}
void deleteNode(struct tnode **head, int x){

    if(*head == NULL){
        printf("List kosong, tidak ada yang bisa dihapus\n");
        return;
    }
    struct tnode *curr = *head;
    if((*head)->value == x){
        *head = (*head)->next;
        free(curr);
        return;
    }

    while(curr->next != NULL && curr->next->value != x){
        curr = curr->next;
    }

    if(curr->next == NULL){
        printf("Node dengan nilai %d tidak ditemukan\n", x);
        return;
    }

    struct tnode *del = curr->next; // Node yang akan dihapus
    curr->next = del->next; // Hubungan node sebelumnya dengan node setelah node yang dihapus
    free(del); // Bebaskan memori

}
void printList(struct tnode *head){
    struct tnode *temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->value);
        temp = temp->next;
    }

    printf("NULL\n");
}
int main(){

    struct tnode *head = NULL;
    insertAtFront(&head, 10);
    insertAtFront(&head, 20);
    insertAtFront(&head, 5);
    printf("Linked setelah insert didepan\n");
    printList(head);

    // Menyisipkan node setelah node kedua
    insertAfter(head->next, 15);
    printf("Linked setelah insert ditengah (setelah 20)\n");
    printList(head);

    deleteNode(&head, 5);
    printf("Setelah delete di depan (head 5)\n");
    printList(head);

    deleteNode(&head, 10);
    printf("Setelah delete 10\n"); 
    printList(head);

    deleteNode(&head, 100);

    return 0;
}