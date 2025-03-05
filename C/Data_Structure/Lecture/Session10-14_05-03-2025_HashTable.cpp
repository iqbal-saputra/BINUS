#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26

struct Student {
    char name[100]; // bakal jadi key
    int score; // bakal jadi value
} *hashTable[SIZE] = {NULL};

struct Student *createNode(char name[], int score){
    struct Student *newNode = (struct Student*) malloc(sizeof(struct Student));
    strcpy(newNode->name, name);
    newNode->score = score;
    return newNode;
}

int main(){

    printf("%d\n", SIZE);

    return 0;
}