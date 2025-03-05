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

int hashing(char name[]){
    char firstLetter = name[0];
    if(firstLetter >= 'A' && firstLetter <= 'Z'){
        return firstLetter - 'A';
    } else {
        return firstLetter - 'a';
    }
}

void insertData(char name[], int score){
    struct Student *newNode = createNode(name, score);

    int key = hashing(name);
    int keyTemp = key + 1;

    if(hashTable[key] == NULL){
        hashTable[key] = newNode;
    } else {
       while(true){
        if(keyTemp == key){
            printf("Hash Table is full\n");
            return;
        }
        
        if(hashTable[keyTemp] == NULL){
            hashTable[keyTemp] = newNode;
            return;
        }
        else{
            keyTemp = (keyTemp + 1) % SIZE;
        }
       }
    }

}

void deleteData(char target[]){
    int key = hashing(target);
    int keyTemp = key + 1;

    if(hashTable[key] != NULL){
        if(strcmp(hashTable[key]->name,target) == 0){
            free(hashTable[key]);
            hashTable[key] = NULL;
            return;
        } 
    } 
    while(1){
        if(keyTemp == key){
            printf("data doesn't exist!\n");
            return;
        }
        if(hashTable[keyTemp] != NULL){
            if(strcmp(hashTable[keyTemp]->name,target) == 0){
                free(hashTable[keyTemp]);
                hashTable[keyTemp] = NULL;
                return;
            }
            keyTemp = (keyTemp + 1) % SIZE;
        }
    }
}

void printAllData(){
    for(int i = 0; i < SIZE; i++){
        if(hashTable[i] != NULL){
            printf("%d(%c) -> name : %s, score : %d\n", i, i + 'A', hashTable[i]->name, hashTable[i]->score);
        }
        else{
            printf("%d(%c) -> NULL\n", i, i + 'A');
        }
    }
}


int main(){

    // printf("%d\n", SIZE);
    insertData("Ari", 100);
    // insertData("Euis", 90);
    insertData("Budi", 50);
    // insertData("Dodi", 80);
    insertData("Caca", 75);
    printAllData();
    deleteData("Budi");
    printAllData();
    return 0;
}