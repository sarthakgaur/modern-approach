/* Maintains a p arts database (linked list version) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define NAME_LEN 25
#define FN_LENGTH 100

struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
    struct part *next;
};

struct rw_part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
};

struct part *inventory = NULL; /* points to first part */

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(void);
void restore(void);

/*
 * main: Prompts the user to enter an operation code, then
 * calls a function to perform the requested action. Repeats
 * until the user enters the command 'q'. Prints an error message
 * if the user enters an illegal code.
 */
int main(void) {
    char code;

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n') /* skips to end of line */
            ;
        switch (code) {
            case 'i': insert();
                      break;
            case 's': search();
                      break;
            case 'u': update();
                      break;
            case 'p': print();
                      break;
            case 'd': dump();
                      break;
            case 'r': restore();
                      break;
            case 'q': return 0;
            default: printf("Illegal code\n");
        }
        printf("\n");
    }
}

/*
 * find_part: Looks up a part number in the inventory list.
 * Returns a pointer to the node containing the part number;
 * if the part number is not found, returns NULL.
 */
struct part *find_part(int number) {
    struct part *p;

    for (p = inventory;
         p != NULL && number > p->number;
         p = p->next)
        ;
    if (p != NULL && number == p->number)
        return p;
    return NULL;
}

/*
 * insert: Prompts the user for information about a new part
 * and then inserts the part into the inventory list; the list
 * remains sorted by part number. Prints an error message and
 * returns prematurely if the part already exists or space
 * could not be allocated for the part.
 */
void insert(void) {
    struct part *cur, *prev, *new_node;

    new_node = malloc(sizeof(struct part));
    if (new_node == NULL) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);

    for (cur = inventory, prev = NULL;
         cur != NULL && new_node->number > cur->number;
         prev = cur, cur = cur->next)
        ;
    if (cur != NULL && new_node->number == cur->number) {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);

    new_node->next = cur;
    if (prev == NULL)
        inventory = new_node;
    else
        prev->next = new_node;
}

/*
 * search: Prompts the user to enter a part number, then looks
 * up the part in the database. If the part exists, prints the
 * name and quantity on hand; if not, prints an error message.
 */
void search(void) {
    int number;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    } else
        printf("Part not found.\n");
}

/*
 * update: Prompts the user to enter a part number. Prints an
 * error message if the part doesn't exist; otherwise, prompts
 * the user to enter change in quantity on hand and updates the 
 * database.
 */
void update(void) {
    int number, change;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        p->on_hand += change;
    } else
        printf("Part not found.\n");
}

/*
 * print: Prints a listing of all parts in the database, showing
 * the part number, part name, and quantity on hand. Part numbers
 * will appear in ascending order.
 */
void print(void) {
    struct part *p;

    printf("Part Number   Part Name                     "
           "Quantity on Hand\n");
    for (p = inventory; p != NULL; p = p->next)
        printf("%7d        %-25s%11d\n", p->number, p->name,
                p->on_hand);
}

void restore(void) {
    struct part *cur, *prev, *new_node;
    struct rw_part tmp_part;

    char filename[FN_LENGTH + 1];
    FILE *fp;

    printf("Enter name of input file: ");
    read_line(filename, FN_LENGTH);

    fp = fopen(filename, "rb");

    if (fp == NULL) {
        fprintf(stderr, "Error: failed on open %s", filename);
        exit(EXIT_FAILURE);
    }

    while (fread(&tmp_part, sizeof(tmp_part), 1, fp) == 1) {
        new_node = malloc(sizeof(struct part));

        if (new_node == NULL) {
            printf("Database is full; can't add more parts.\n");
            return;
        }

        new_node->number = tmp_part.number;

        for (cur = inventory, prev = NULL;
             cur != NULL && new_node->number > cur->number;
             prev = cur, cur = cur->next)
            ;
        if (cur != NULL && new_node->number == cur->number) {
            printf("Part already exists.\n");
            free(new_node);
            continue;
        }

        strcpy(new_node->name, tmp_part.name);
        new_node->on_hand = tmp_part.on_hand;

        new_node->next = cur;
        if (prev == NULL)
            inventory = new_node;
        else
            prev->next = new_node;
    }

    fclose(fp);
}

void dump(void) {
    struct part *p;
    struct rw_part tmp_part;

    char filename[FN_LENGTH + 1];
    FILE *fp;

    printf("Enter name of output file: ");
    read_line(filename, FN_LENGTH);

    fp = fopen(filename, "wb");

    if (fp == NULL) {
        fprintf(stderr, "Error: failed on open %s", filename);
        exit(EXIT_FAILURE);
    }

    for (p = inventory; p != NULL; p = p->next) {
        tmp_part.number = p->number;
        strcpy(tmp_part.name, p->name);
        tmp_part.on_hand = p->on_hand;

        fwrite(&tmp_part, sizeof(tmp_part), 1, fp);
    }

    fclose(fp);
}
