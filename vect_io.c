#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vect.h"

void load_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename); 
        return;
    }
    
    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\r\n")] = 0;
        
        if (strlen(line) == 0) continue; 
        
        char name[50];
        char *token = strtok(line, ",");
        if (token != NULL) {
            strcpy(name, token);
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

void save_csv(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not create file '%s'\n", filename);
        return;
    }
    
    VectNode *current = head;
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