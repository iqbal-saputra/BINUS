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


int main(){







}