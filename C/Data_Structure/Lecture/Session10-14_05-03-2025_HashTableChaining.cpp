#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TABLE_SIZE 26

struct Node{
    char name[50];
    struct Node *next, *prev;
};

struct Node *head[TABLE_SIZE] = {NULL};
struct Node *tail[TABLE_SIZE] = {NULL};

struct Node* createNode(char name[]){
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = newNode->prev = NULL;
    return newNode;
}

int hashing(char key){
    int index = key - 'A';
    return index;
}

void pushHead(char name[], int index){
    struct Node *newNode = createNode(name);
    if(head[index] == NULL){
        head[index] = tail[index] = newNode;
    } else {
        newNode->next = head[index];
        head[index]->prev = newNode;
        head[index] = newNode;
    }
}

void pushTail(char name[], int index){
    struct Node *newNode = createNode(name);
    if(head[index] == NULL){
        head[index] = tail[index] = newNode;
    } else {
        newNode->prev = tail[index];
        tail[index]->next = newNode;
        tail[index] = newNode;
    }
}

void pushMid(char name[], int index){

    if(head[index] == NULL){
        head[index] = tail[index] = createNode(name);
    }
    else if(strcmp(name, head[index]->name) < 0){
        pushHead(name, index);
    }
    else if(strcmp(name, tail[index]->name) >= 0){
        pushTail(name, index);
    }
    else{
        struct Node *curr = head[index];
        while(curr != NULL && strcmp(name, curr->name) >= 0){
            curr = curr->next;
        }
        if(curr == NULL){
            return;
        }
        struct Node *newNode = createNode(name);
        newNode->next = curr;
        newNode->prev = curr->prev;
        curr->prev = newNode;
        curr->prev->next = newNode;
    }
}

void insert(char name[]){
    int index = hashing(name[0]);
    pushMid(name, index);
}

struct Node* search(char name[]){
    int index = hashing(name[0]);
    struct Node *curr = head[index];
    while(curr != NULL && strcmp(curr->name, name) != 0){
        curr = curr->next;
    }
    return curr;
}

void printAll(){

    int i;
    for(i=0;i<TABLE_SIZE;i++){
        printf("%d. ", i+1);
        struct Node *curr = head[i];
        while(curr){
            printf("%s <-> ", curr->name);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

int main(){

    insert("Ari");
    insert("Budi");
    insert("Caca");
    insert("Dodi");
    insert("Asep");
    insert("Burhan");
    insert("Cahya");
    insert("Dewi");
    insert("Euis");
    insert("Fajar");
    insert("Gina");
    insert("Hani");
    insert("Iwan");
    insert("Joko");
    insert("Kiki");
    insert("Lala");
    insert("Mama");
    insert("Nana");
    insert("Omar");
    insert("Papa");
    insert("Qiqi");
    insert("Rara");
    insert("Sasa");
    insert("Tuti");
    insert("Umar");
    insert("Vivi");
    insert("Wawa");
    insert("Xena");
    insert("Yaya");
    insert("Zizi");
    printAll();
    search("Ari");
    search("Budi");

    printf("\n");
    struct Node *temp = search("Ari");
    if(temp == NULL){
        printf("Data not found\n");
    } else {
        printf("%s", temp->name);
        strcpy(temp->name, "bagas");
    }
    printAll();
    
    return 0;
}