#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node{
	
	int data;
	char nama[101];
	struct Node *next, *prev;
	
}*head, *tail;

struct Node *newNode(int data, char nama[101]){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	
	temp->data = data;
	strcpy(temp->nama, nama);
	
	temp->next = temp->prev = NULL;
	
	return temp;
}

void pushHead(struct Node *newNode){
	
	if(head == NULL){
		head = tail = newNode;
	}
	else {
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

void pushMid(struct Node *newNode){

	if(head == NULL){
		head = tail = newNode;
	}
	else if(strcmp(head->nama, newNode->nama) > 0){
		pushHead(newNode);
	}
	else if(strcmp(tail->nama, newNode->nama) < 0){
		pushTail(newNode);
	}
	else{
		struct Node *curr = head;
		while( (curr->next != NULL) && strcmp(curr->next->nama, newNode->nama) < 0 ){
			curr = curr->next;
		}
		newNode->next = curr->next;
		if(curr->next != NULL){
			curr->next->prev = newNode;
		}
		curr->next = newNode;
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
		struct Node *temp = head;
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
	else{
		struct Node *temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		free(temp);
	}
	
}

void popMid( char nama[101]){
	
	if(head == NULL){
		return;
	}
	else if(strcmp(head->nama, nama) == 0){
		popHead();
	}
	else if(strcmp(tail->nama, nama) == 0){
		popTail();
	}
	else {
		struct Node *curr = head;
		while( (curr->next != NULL) && strcmp(curr->next->nama, nama) != 0){
			curr = curr->next;
		}
		
		if(curr->next != NULL){
			struct Node *temp = curr->next;
			curr->next = temp->next;
			
			if(temp->next != NULL){
				temp->next->prev = curr;
			}
			
			free(temp);
		}
		
	}
}

void search(char nama[101]){
	
	struct Node *curr = head;
	
	while((curr != NULL) && strcmp(curr->nama,nama) != 0){
		curr = curr->next;
	}
	
	if(curr == NULL){
		printf("%s wasn't found in the linked list!\n", nama);
	}
	else {
		printf("%s was found in the linked list\n", nama);
	}
	
}

void print(){
	
	struct Node *curr = head;
	while(curr != NULL){
		printf("%s <-> ", curr->nama);
		curr = curr->next;
		
	}
	printf("NULL\n");
}
int main(){
	
	head = tail = NULL;
	pushMid(newNode(1,"Alice"));
    pushMid(newNode(2,"Bob"));
    pushMid(newNode(3,"Charlie"));
    pushMid(newNode(4,"David"));
    pushMid(newNode(5,"Eve"));
    pushMid(newNode(6,"Frank"));
    pushMid(newNode(7,"Grace"));
    pushMid(newNode(8,"Hannah"));
    pushMid(newNode(9,"Isaac"));
    print();
    
    printf("\nAfter deleting Alice:\n");
    popMid("Alice");
    print();
    
    printf("\nSearching for Bob:\n");
    search("Bob");

    printf("\nSearching for Alice:\n");
    search("Alice");
    
	return 0;
}