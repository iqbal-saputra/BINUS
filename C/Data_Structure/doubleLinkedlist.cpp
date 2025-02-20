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
    else if(head->data > newNode->data){
        pushHead(newNode);
    }
    else if(tail->data < newNode->data){
        pushTail(newNode);
    }
    else {
        Node *curr = head;
        while( (curr->next != NULL) && (curr->next->data < newNode->data) ){
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next->prev = newNode;
        curr->next = newNode; // pointer hanya bisa menunjuk satu arah
        newNode->prev = curr;
    }
}

void popHead(){

    if(head == NULL){
        return;
    }
    else if(head == tail){
        free(head);
        head = tail = NULL;
    }
    else {
        Node *temp = head;

        head = head->next;
        head->prev = NULL;
        free(temp);
    }
}

void popTail(){

    if(head == NULL){
        return;
    }
    else if(head == tail){
        free(head);
        head = tail = NULL;
    }
    else {
        Node *temp = tail;

        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
}

void popMid(int data){
    if(head == NULL){
        return;
    }
    else if(head->data == data){
        popHead();
    }
    else if(tail->data == data){
        popTail();
    }
}
int main(){






    return 0;
}