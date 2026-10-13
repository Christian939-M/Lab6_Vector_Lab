#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vect2.h"

// Head pointer for our dynamic linked list of vectors
static VectNode *head = NULL;

// Find an existing vector by name, or create a new one if it doesn't exist
Vect* find_or_create_vector(const char *name) {
    VectNode *current = head;
    
    // Search existing vectors
    while (current != NULL) {
        if (strcmp(current->vect.name, name) == 0) {
            return &(current->vect);
        }
        current = current->next;
    }
    
    // If not found, allocate a new node on the heap
    VectNode *newNode = malloc(sizeof(VectNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    
    strcpy(newNode->vect.name, name);
    // Initialize values to 0
    for (int i = 0; i < 10; i++) {
        newNode->vect.value[i] = 0;
    }
    
    // Insert at the front of the linked list
    newNode->next = head;
    head = newNode;
    
    return &(newNode->vect);
}
void clear_vectors(void) {
    VectNode *current = head;
    while (current != NULL) {
        VectNode *next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

void free_all_memory(void) {
    clear_vectors();
}