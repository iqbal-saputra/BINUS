#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;

}*head, *tail;

struct Node *newNode(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)* 1);
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void pushHead(struct Node *newNode){

    if(head == NULL){
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

void pushTail(struct Node *newNode){

    if(head == NULL){
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void pushMid(struct Node *newNode){

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
        curr->next = newNode;
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
        Node *curr = head;
        while(curr->next != tail){
            curr = curr->next;
        }
        Node *temp = tail;
        curr->next = NULL;
        tail = curr;
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
    else{
        Node *curr = head;
        while(curr->next != NULL && curr->next->data != data){
            curr = curr->next;
        }
        if(curr->next != NULL){
            Node *temp = curr->next;
            curr->next = temp->next;
            free(temp);
        }
    }
}

void popAll(){
    if(head == NULL){
        return;
    }
    else{
        free(head);
        head = tail = NULL;
    }
}

void search(int data){
    Node *curr = head;

    while( (curr != NULL) && (curr->data != data) ){
        curr = curr->next;
    }

    if(curr == NULL){
        printf("%d wasn't found in the linked list\n", data);
    }
    else {
        printf("%d was found in the linked list\n", data);
    }
}

void print(){

    Node *curr = head;

    while(curr != NULL){
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main(){

    pushMid(newNode(1));
    pushMid(newNode(5));
    pushMid(newNode(8));
    pushMid(newNode(3));
    pushMid(newNode(4));
    print();

    popHead();
    print();

    popTail();
    print();

    popMid(4);
    print();
}