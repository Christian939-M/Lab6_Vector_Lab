#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vect.h"

// Load vectors from a CSV file into dynamic memory
void load_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename); // Gracefully handles missing/mistyped files[cite: 7]
        return;
    }
    
    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Handle both '\n' and '\r\n' line endings
        line[strcspn(line, "\r\n")] = 0;
        
        // Skip empty lines at the end or middle of the file[cite: 8]
        if (strlen(line) == 0) continue; 
        
        char name[50];
        char *token = strtok(line, ",");
        if (token != NULL) {
            strcpy(name, token);
            // Use our dynamic lookup to create or update the vector
            Vect *v = find_or_create_vector(name);
            
            int i = 0;
            while ((token = strtok(NULL, ",")) != NULL && i < 10) {
                v->value[i] = atoi(token);
                i++;
            }
        }
    }
    
    fclose(file);
    printf("Loaded vectors from %s successfully.\n", filename);
}

// Save all current vectors in memory to a CSV file (overwriting if it exists)[cite: 7]
void save_csv(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not create file '%s'\n", filename);
        return;
    }
    
    // Traverse the dynamic linked list and write each vector
    VectNode *current = head; // Assuming 'head' is accessible globally or passed in
    while (current != NULL) {
        fprintf(file, "%s", current->vect.name);
        for (int i = 0; i < 10; i++) {
            fprintf(file, ",%d", current->vect.value[i]);
        }
        fprintf(file, "\n");
        current = current->next;
    }
    
    fclose(file);
    printf("Saved vectors to %s successfully.\n", filename);
}