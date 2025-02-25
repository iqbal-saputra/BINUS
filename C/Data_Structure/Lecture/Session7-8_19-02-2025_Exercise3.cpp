#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
    int value;
    struct tnode *next;
    struct tnode *prev;
} Node;

Node *head = NULL;
Node *tail = NULL;

void insertHead(int x) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Gagal mengalokasikan memori!\n");
        return;
    }
    node->value = x;
    node->prev = NULL;
    node->next = head;

    if (head != NULL) {
        head->prev = node;
    }
    head = node;

    if (tail == NULL) {
        tail = node;
    }
}

void insertTail(int x) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Gagal mengalokasikan memori!\n");
        return;
    }
    node->value = x;
    node->next = NULL;
    node->prev = tail;

    if (tail != NULL) {
        tail->next = node;
    }
    tail = node;

    if (head == NULL) {
        head = node;
    }
}

void insertAfter(int key, int x) {
    Node *current = head;
    while (current != NULL && current->value != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node dengan nilai %d tidak ditemukan!\n", key);
        return;
    }

    Node *node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Gagal mengalokasikan memori!\n");
        return;
    }
    node->value = x;
    node->next = current->next;
    node->prev = current;

    if (current->next != NULL) {
        current->next->prev = node;
    } else {
        tail = node;
    }
    current->next = node;
}

void deleteNode(int data){

    if(head == tail){
        head = tail = NULL;
        free(head);
    }
    else if(head->value == data){
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
    else if(tail->value == data){
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
    else {
        Node *current = head;
        while(current != NULL && current->value != data){
            current = current->next;
        }
        if(current->next != NULL){ 
            Node *temp = current;
            current->prev->next = temp->next;
            temp->next->prev = current->prev;
            free(temp);
        }

    }
}

void displayForward() {
    Node *current = head;
    printf("Forward: ");
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    insertTail(10);
    insertTail(24);
    insertTail(17);

    printf("Setelah insert tail:\n");
    displayForward();

    insertHead(5);
    printf("Setelah insert head (5):\n");
    displayForward();

    insertAfter(24, 15);
    printf("Setelah insert di tengah (setelah 24):\n");
    displayForward();

    deleteNode(10);
    printf("Setelah delete node (10):\n");
    displayForward();

    return 0;
}
