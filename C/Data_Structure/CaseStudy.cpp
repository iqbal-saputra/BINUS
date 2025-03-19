#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

struct Node{
    char name[MAX];
    char number[MAX];
    Node *left;
    Node *right;
};

Node *createNode(char *name, char *number){
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->number, number);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *node, char *name, char *number){
    if(node == NULL){
        return createNode(name, number);
    }else{
        Node *current = node;
        while(true){
            if(strcmp(name, current->name) < 0){
                if(current->left == NULL){
                    current->left = createNode(name, number);
                    break;
                } else{
                    current = current->left;
                }
            } else{
                if(current->right == NULL){
                    current->right = createNode(name, number);
                    break;
                }else{
                    current = current->right;
                }
            }
        }
    }
    return node;
}

Node *searchName(Node *node, char *name){
    while(node != NULL){
        if(strcmp(node->name, name) == 0){
            return node;
        }else if(strcmp(node->name,name) < 0){
            node = node->right;
        }else{
            node = node->left;
        }
    }
    return NULL;
}

Node *deleteName(Node *node, char *name){
    if (node == NULL){
        return NULL;
    }

    if(strcmp(node->name, name) < 0){
        node->right = deleteName(node->right, name);
    } else if(strcmp(node->name, name) > 0){
        node->left = deleteName(node->left, name);
    } else{
        if(node->left == NULL && node->right == NULL){
            free(node);
            return NULL;
        } else if(node->left == NULL || node->right == NULL){
            Node *temp = (node->left == NULL) ? node->right : node->left;
            free(node);
            return temp;
        } else{
            Node *temp = node->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            strcpy(temp->name, node->name);
            node->right = deleteName(node->right, temp->name);
        }
    }
    return node;
}

void inOrderDisplay(Node *node){
    if(node != NULL){
        inOrderDisplay(node->left);
        printf("%s %s\n", node->name, node->number);
        inOrderDisplay(node->right);
    }
}

void mainMenu(){
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Delete\n");
    printf("4. Display\n");
    printf("5. Exit\n");

}

int main(){
    Node *root = NULL;
    do{
        mainMenu();
        int choice;
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                char name[MAX];
                char number[MAX];
                printf("Name: ");
                scanf("%s", name);
                printf("Number: ");
                scanf("%s", number);
                root = insertNode(root, name, number);
                break;
            }
            case 2:{
                char name[MAX];
                printf("Name: ");
                scanf("%s", name);
                Node *temp = searchName(root, name);
                if(temp != NULL){
                    puts("Data Found.");
                    printf("%s %s\n", temp->name, temp->number);
                }else{
                    printf("Data not found\n");
                }
                break;
            }
            case 3:{
                char name[MAX];
                printf("Name: ");
                scanf("%s", name);
                root = deleteName(root, name);
                puts("Data deleted.");
                break;
            }
            case 4:{
                inOrderDisplay(root);
                break;
            }
            case 5:{
                exit(0);
                break;
            }
            
            default:{
                printf("Invalid choice\n");
                break;
            }
        }
    } while(true);
    

    return 0;
}