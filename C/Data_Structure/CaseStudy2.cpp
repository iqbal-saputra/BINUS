#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node{
	char judul[100];
	int priority;
	struct Node *next;
	struct Node *prev;
}Node;

typedef struct Watch{
	char judul2[100];
	int priority2;
	struct Watch *next;
	struct Watch *prev;
}Watch;

Watch *newNode2 = NULL;
Watch *head2 = NULL;  // Initialize to NULL
Watch *tail2 = NULL;  // Initialize to NULL
Watch *cur2;
Watch *temp2;
Watch *del2;

Node *newNode = NULL;
Node *head = NULL;    // Initialize to NULL
Node *tail = NULL;    // Initialize to NULL
Node *cur;
Node *temp;
Node *del;

void insert_main(char judul[100],int priority)
{
	newNode = (Node *)malloc(sizeof(Node));
	newNode -> next = NULL;
	newNode -> prev = NULL;
	strcpy(newNode -> judul,judul);
	newNode -> priority = priority;
	
	cur = head;
	while(cur != NULL)
	{
		if(cur -> priority == priority)
		{
			puts("Sudah ada priority serupa tolong masukkan judul dengan priority yang berbeda");
			free(newNode);  // Free the allocated memory before returning
			return;
		}
		cur = cur -> next;	
	}
	
	if(head == NULL)
	{
		head = tail = newNode;
	}
	else if(priority < head -> priority)
	{
		newNode -> next = head;
		newNode -> prev = NULL;
		head -> prev = newNode;
		head = newNode;
	}
	else if(priority > tail -> priority)
	{
		newNode -> next = NULL;
		newNode -> prev = tail;
		tail -> next = newNode;
		tail = newNode;
	}
	else
	{
		temp = head;
		while(temp -> next != NULL && temp -> next -> priority < priority)
		{
			temp = temp -> next;
		}
		newNode -> next = temp -> next;
		newNode -> prev = temp;
        if (temp -> next != NULL) {
		    temp -> next -> prev = newNode;
        }
		temp -> next = newNode;
	}
	
}

void insert_watch_later(char judul2[100],int priority2)
{
	newNode2 = (Watch *)malloc(sizeof(Watch));
	newNode2 -> next = NULL;
	newNode2 -> prev = NULL;
	strcpy(newNode2 -> judul2,judul2);
	newNode2 -> priority2 = priority2;
	
	cur2 = head2;
	while(cur2 != NULL)
	{
		if(cur2 -> priority2 == priority2)
		{
			puts("Sudah ada priority serupa tolong masukkan judul dengan priority yang berbeda");
			free(newNode2);  // Free allocated memory
			return;  // Add a return here to prevent further execution
		}
		cur2 = cur2 -> next;
	}
	
	if(head2 == NULL)
	{
		head2 = tail2 = newNode2;
	}
	else if(priority2 < head2 -> priority2)
	{
		newNode2 -> next = head2;
		newNode2 -> prev = NULL;
		head2 -> prev = newNode2;
		head2 = newNode2;
	}
	else if(priority2 > tail2 -> priority2)
	{
		newNode2 -> next = NULL;
		newNode2 -> prev = tail2;
		tail2 -> next = newNode2;
		tail2 = newNode2;
	}
	else
	{
		temp2 = head2;
		while(temp2 -> next != NULL && temp2 -> next -> priority2 < priority2)
		{
			temp2 = temp2 -> next;
		}
		newNode2 -> next = temp2 -> next;
		newNode2-> prev = temp2;
        if (temp2 -> next != NULL) {
		    temp2 -> next -> prev = newNode2;
        }
		temp2 -> next = newNode2;
	}	
}

void merge()
{
	if (head2 == NULL) {
		puts("Watch Later list is empty, nothing to merge");
		return;
	}

	cur2 = head2;
	while(cur2 != NULL)
	{
		// Store current node data before moving to next
		char temp_judul[100];
		int temp_priority = cur2->priority2;
		strcpy(temp_judul, cur2->judul2);
		
		// Move to next node before inserting
		cur2 = cur2 -> next;
		
		// Insert the stored data
		insert_main(temp_judul, temp_priority);
	}
	
	// Clear the watch later list
	cur2 = head2;
	while(cur2 != NULL)
	{
		del2 = cur2;
		cur2 = cur2->next;
		free(del2);
	}
	head2 = tail2 = NULL;
	
	puts("Lists merged successfully");
}

void display_main()
{
	if(head == NULL)
	{
		puts("Main list is empty");
		return;
	}
	
	puts("MAIN LIST:");
	cur = head;
	while(cur != NULL)
	{
		printf("Title: %s, Priority: %d\n", cur->judul, cur->priority);
		cur = cur -> next;
	}
}

void display_watch_later()
{
	if(head2 == NULL)
	{
		puts("Watch Later list is empty");
		return;
	}
	
	puts("WATCH LATER LIST:");
	cur2 = head2;
	while(cur2 != NULL)
	{
		printf("Title: %s, Priority: %d\n", cur2->judul2, cur2->priority2);
		cur2 = cur2 -> next;
	}
}

void play()
{
	if(head == NULL)
	{
		puts("Main list is empty, nothing to play");
		return;
	}
	
	printf("WATCHED: %s (Priority: %d)\n", head->judul, head->priority);
	
	del = head;
	if (head == tail) {
		// Last item in the list
		head = tail = NULL;
	} else {
		head = head->next;
		if (head != NULL) {
			head->prev = NULL;
		}
	}
	
	free(del);  // Use free() instead of delete
}

int main() {
    char choice[100];
    char judul[100];
    int priority;

    while (1) {
        printf("Masukkan perintah: ");
        scanf("%s", choice);
        getchar();

        if (strcmp(choice, "insert_main") == 0 || strcmp(choice, "insert_watch_later") == 0) {
            printf("Masukkan judul: ");
            scanf("%[^\n]", judul);
            getchar();
            printf("Masukkan priority: ");
            scanf("%d", &priority);
            getchar();
        }

        puts("");

        if (strcmp(choice, "insert_main") == 0) {
            insert_main(judul, priority);
        } else if (strcmp(choice, "insert_watch_later") == 0) {
            insert_watch_later(judul, priority);
        } else if (strcmp(choice, "play") == 0) {
            play();
        } else if (strcmp(choice, "merge") == 0) {
            merge();
        } else if (strcmp(choice, "display_main") == 0) {
            display_main();
        } else if (strcmp(choice, "display_watch_later") == 0) {
            display_watch_later();
        } else if (strcmp(choice, "stop") == 0) {
            break;
        } else {
            puts("input lu gajelas");
        }
    }

    // Free any remaining memory before exiting
    cur = head;
    while(cur != NULL) {
        del = cur;
        cur = cur->next;
        free(del);
    }
    
    cur2 = head2;
    while(cur2 != NULL) {
        del2 = cur2;
        cur2 = cur2->next;
        free(del2);
    }

    return 0;
}