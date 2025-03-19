#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Movie {
    char title[100];
    char genre[50];
    int duration;
    struct Movie *prev, *next;
};

// Pointer untuk main playlist
struct Movie *head_main = NULL, *tail_main = NULL;

// Pointer untuk watch later playlist
struct Movie *head_watch = NULL, *tail_watch = NULL;

// Fungsi untuk mengonversi karakter menjadi huruf kecil
char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

// Fungsi strcmp case-insensitive manual
int strcmp_case_insensitive(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        char c1 = toLower(*s1);
        char c2 = toLower(*s2);

        if (c1 != c2) return c1 - c2;
        s1++;
        s2++;
    }
    return toLower(*s1) - toLower(*s2);
}

// Fungsi Insert ke Main Playlist
void insert_main(char title[], char genre[], int duration) {
    struct Movie *newMovie = (struct Movie*) malloc(sizeof(struct Movie));
    strcpy(newMovie->title, title);
    strcpy(newMovie->genre, genre);
    newMovie->duration = duration;
    newMovie->next = newMovie->prev = NULL;

    if (head_main == NULL) {
        head_main = tail_main = newMovie;
    } else {
        tail_main->next = newMovie;
        newMovie->prev = tail_main;
        tail_main = newMovie;
    }
}

// Fungsi Insert ke Watch Later Playlist
void insert_watch_later(char title[], char genre[], int duration) {
    struct Movie *newMovie = (struct Movie*) malloc(sizeof(struct Movie));
    strcpy(newMovie->title, title);
    strcpy(newMovie->genre, genre);
    newMovie->duration = duration;
    newMovie->next = newMovie->prev = NULL;

    if (head_watch == NULL) {
        head_watch = tail_watch = newMovie;
    } else {
        tail_watch->next = newMovie;
        newMovie->prev = tail_watch;
        tail_watch = newMovie;
    }
}

// Fungsi Play (Menonton Film)
void play() {
    if (head_main == NULL) {
        printf("Main playlist is empty!\n");
        return;
    }

    struct Movie *temp = head_main;
    printf("WATCHED: %s %s %d\n", temp->title, temp->genre, temp->duration);

    head_main = head_main->next;
    if (head_main) head_main->prev = NULL;
    else tail_main = NULL;

    free(temp);
}

// Fungsi Merge (Watch Later ? Main Playlist)
void merge() {
    if (head_watch == NULL) {
        printf("Watch later playlist is empty!\n");
        return;
    }

    if (head_main == NULL) {
        head_main = head_watch;
        tail_main = tail_watch;
    } else {
        tail_main->next = head_watch;
        head_watch->prev = tail_main;
        tail_main = tail_watch;
    }

    head_watch = tail_watch = NULL;

    // Sorting menggunakan strcmp_case_insensitive()
    struct Movie *i, *j;
    for (i = head_main; i; i = i->next) {
        for (j = i->next; j; j = j->next) {
            if (strcmp_case_insensitive(i->title, j->title) > 0) {
                // Swap data
                char tempTitle[100], tempGenre[50];
                int tempDuration;

                strcpy(tempTitle, i->title);
                strcpy(tempGenre, i->genre);
                tempDuration = i->duration;

                strcpy(i->title, j->title);
                strcpy(i->genre, j->genre);
                i->duration = j->duration;

                strcpy(j->title, tempTitle);
                strcpy(j->genre, tempGenre);
                j->duration = tempDuration;
            }
        }
    }
}

// Fungsi Display Main Playlist
void display_main() {
    struct Movie *temp = head_main;
    while (temp) {
        printf("%s %s %d\n", temp->title, temp->genre, temp->duration);
        temp = temp->next;
    }
}

// Fungsi Display Watch Later Playlist
void display_watch_later() {
    struct Movie *temp = head_watch;
    while (temp) {
        printf("%s %s %d\n", temp->title, temp->genre, temp->duration);
        temp = temp->next;
    }
}

// Fungsi Stop (Menghapus Semua Data)
void stop() {
    struct Movie *temp;
    
    while (head_main) {
        temp = head_main;
        head_main = head_main->next;
        free(temp);
    }
    
    while (head_watch) {
        temp = head_watch;
        head_watch = head_watch->next;
        free(temp);
    }
}

// Fungsi utama (main)
int main() {
    char command[50], title[100], genre[50];
    int duration;
    
    while (1) {
        scanf("%s", command);
        
        if (strcmp(command, "insert_main") == 0) {
            scanf("%s %s %d", title, genre, &duration);
            insert_main(title, genre, duration);
        }
        else if (strcmp(command, "insert_watch_later") == 0) {
            scanf("%s %s %d", title, genre, &duration);
            insert_watch_later(title, genre, duration);
        }
        else if (strcmp(command, "play") == 0) {
            play();
        }
        else if (strcmp(command, "merge") == 0) {
            merge();
        }
        else if (strcmp(command, "display_main") == 0) {
            display_main();
        }
        else if (strcmp(command, "display_watch_later") == 0) {
            display_watch_later();
        }
        else if (strcmp(command, "stop") == 0) {
            stop();
            break;
        }
    }
    
    return 0;
}
