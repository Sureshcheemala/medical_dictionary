#include <stdio.h>
#include <string.h>

#define MAX_TERMS 100
#define TERM_LEN 50
#define DEF_LEN 200

typedef struct {
    char term[TERM_LEN];
    char definition[DEF_LEN];
} MedicalTerm;

MedicalTerm dictionary[MAX_TERMS];
int termCount = 0;

void addTerm() {
    if (termCount >= MAX_TERMS) {
        printf("Dictionary is full.\n");
        return;
    }
    printf("Enter term: ");
    scanf(" %[^\n]", dictionary[termCount].term);
    printf("Enter definition: ");
    scanf(" %[^\n]", dictionary[termCount].definition);
    termCount++;
    printf("Term added successfully.\n");
}

void viewTerms() {
    printf("\n--- Medical Terms ---\n");
    for (int i = 0; i < termCount; i++) {
        printf("%d. %s: %s\n", i + 1, dictionary[i].term, dictionary[i].definition);
    }
}

void searchTerm() {
    char search[TERM_LEN];
    printf("Enter term to search: ");
    scanf(" %[^\n]", search);
    for (int i = 0; i < termCount; i++) {
        if (strcmp(dictionary[i].term, search) == 0) {
            printf("Found: %s - %s\n", dictionary[i].term, dictionary[i].definition);
            return;
        }
    }
    printf("Term not found.\n");
}

void deleteTerm() {
    char deleteName[TERM_LEN];
    printf("Enter term to delete: ");
    scanf(" %[^\n]", deleteName);
    for (int i = 0; i < termCount; i++) {
        if (strcmp(dictionary[i].term, deleteName) == 0) {
            for (int j = i; j < termCount - 1; j++) {
                dictionary[j] = dictionary[j + 1];
            }
            termCount--;
            printf("Term deleted successfully.\n");
            return;
        }
    }
    printf("Term not found.\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Medical Dictionary ---\n");
        printf("1. Add Term\n");
        printf("2. View Terms\n");
        printf("3. Search Term\n");
        printf("4. Delete Term\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addTerm(); break;
            case 2: viewTerms(); break;
            case 3: searchTerm(); break;
            case 4: deleteTerm(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
