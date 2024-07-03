#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Species {
    char class[30];
    char order[30];
    char family[30];
    char genus[30];
    char species[30];
    struct Species* next;
} Species;

void printMenu() {
    printf("\nMenu:\n");
    printf("1. Add species information\n");
    printf("2. Sort species information\n");
    printf("3. Modify species information\n");
    printf("4. Delete species information\n");
    printf("5. Print list\n");
    printf("6. Exit\n");
}

void printSpecies(Species* head) {
    Species* current = head;
    if (current == NULL) {
        printf("List is empty\n");
        return;
    }
    while (current != NULL) {
        printf("Class: %s\nOrder: %s\nFamily: %s\nGenus: %s\nSpecies: %s\n\n",current->class, current->order, current->family, current->genus, current->species);
        current = current->next;
    }
}


void addSpecies(Species** head) {
    Species* newSpecies = (Species*)malloc(sizeof(Species));
    printf("Enter class: ");
    scanf("%s", newSpecies->class);
    printf("Enter order: ");
    scanf("%s", newSpecies->order);
    printf("Enter family: ");
    scanf("%s", newSpecies->family);
    printf("Enter genus: ");
    scanf("%s", newSpecies->genus);
    printf("Enter species: ");
    scanf("%s", newSpecies->species);
    newSpecies->next = *head;
    *head = newSpecies;
}

void sort(Species* head, char criteria[15]) {
    if (head == NULL) return;
    Species* sorted = NULL;
    Species* current = head;
    Species* next = NULL;
    if(strcmp(criteria,"species")==0){
        while (current != NULL) {
            next = current->next;
            if (sorted == NULL || strcmp(current->species, sorted->species) < 0) {
                current->next = sorted;
                sorted = current;
            } else {
                Species* temp = sorted;
                while (temp->next != NULL && strcmp(temp->next->species, current->species) < 0) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }
    }
    else if(strcmp(criteria,"class")==0){
                while (current != NULL) {
            next = current->next;
            if (sorted == NULL || strcmp(current->class, sorted->class) < 0) {
                current->next = sorted;
                sorted = current;
            } else {
                Species* temp = sorted;
                while (temp->next != NULL && strcmp(temp->next->class, current->class) < 0) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }
    }
    else if(strcmp(criteria,"order")==0){
                while (current != NULL) {
            next = current->next;
            if (sorted == NULL || strcmp(current->order, sorted->order) < 0) {
                current->next = sorted;
                sorted = current;
            } else {
                Species* temp = sorted;
                while (temp->next != NULL && strcmp(temp->next->order, current->order) < 0) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }
    }

    else if(strcmp(criteria,"family")==0){
                while (current != NULL) {
            next = current->next;
            if (sorted == NULL || strcmp(current->family, sorted->family) < 0) {
                current->next = sorted;
                sorted = current;
            } else {
                Species* temp = sorted;
                while (temp->next != NULL && strcmp(temp->next->family, current->family) < 0) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }
    }

    else if(strcmp(criteria,"genus")==0){
                while (current != NULL) {
            next = current->next;
            if (sorted == NULL || strcmp(current->genus, sorted->genus) < 0) {
                current->next = sorted;
                sorted = current;
            } else {
                Species* temp = sorted;
                while (temp->next != NULL && strcmp(temp->next->genus, current->genus) < 0) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }
    }


    head = sorted;
}

void modifySpecies(Species* head, char* speciesName) {
    Species* current = head;
    while (current != NULL) {
        if (strcmp(current->species, speciesName) == 0) {
            printf("Enter new class: ");
            scanf("%s", current->class);
            printf("Enter new order: ");
            scanf("%s", current->order);
            printf("Enter new family: ");
            scanf("%s", current->family);
            printf("Enter new genus: ");
            scanf("%s", current->genus);
            printf("Enter new species: ");
            scanf("%s", current->species);
            return;
        }
        current = current->next;
    }
    printf("Species not found.\n");
}

void deleteSpecies(Species** head, char* speciesName) {
    Species* temp = *head, *prev = NULL;
    if (temp != NULL && strcmp(temp->species, speciesName) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && strcmp(temp->species, speciesName) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void freeList(Species* head) {
    Species* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


int main() {
    Species* head = NULL;
    int choice;
    char speciesName[30],criteria[15];
    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addSpecies(&head);
                break;
            case 2:
                printf("Enter criteria: ");
                scanf(" %s",criteria);
                sort(head,criteria);
                printf("Listed %s\n",criteria);
                printSpecies(head);
                break;
            case 3:
                printf("Enter species name to modify: ");
                scanf("%s", speciesName);
                modifySpecies(head, speciesName);
                printf("Species modified successfully.\n");
                break;
            case 4:
                printf("Enter species name to delete: ");
                scanf("%s", speciesName);
                deleteSpecies(&head, speciesName);
                break;
            case 5: printSpecies(head);
                break;
            case 6:
                freeList(head);
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
