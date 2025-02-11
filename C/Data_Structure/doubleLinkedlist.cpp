#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next, *prev;

} *head, *tail;

struct Node *newNode(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node) * 1);
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void pushHead(struct Node *newNode){
    if(head == NULL){
        head = tail = newNode;
    }
    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void pushTail(struct Node *newNode){
    if(head == NULL){
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void pushMid(Node *newNode){
    
    if(head == NULL){
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
int main(){






    return 0;
}