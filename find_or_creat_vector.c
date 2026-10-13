/*
 * File: find_or_create_vector.c
 * Author: Christian Montoya
 * date: 10/13/2026
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vect.h"

VectNode *head = NULL;

Vect* find_or_create_vector(const char *name) {
    VectNode *current = head;

    while (current != NULL) {
        if (strcmp(current->vect.name, name) == 0) {
            return &(current->vect);
        }
        current = current->next;
    }
    
    VectNode *newNode = malloc(sizeof(VectNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    
    strcpy(newNode->vect.name, name);
    for (int i = 0; i < 10; i++) {
        newNode->vect.value[i] = 0;
    }
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