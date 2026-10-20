/*
 * File: Lab7.c
 * Author: Christian Montoya
 * date: 10/13/2026
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "vect.h"
void print_help(void) {
    printf("mini-mat Vector Calculator Help:\n");
    printf("  -h                        Display this help text\n");
    printf("  var = val1, val2, ...     Create or assign a vector (up to 10 values)\n");
    printf("  var                       Display a vector's value\n");
    printf("  var1 + var2               Add two vectors\n");
    printf("  var1 - var2               Subtract two vectors\n");
    printf("  var1 . var2               Dot product\n");
    printf("  var1 x var2               Cross product\n");
    printf("  var * num  or  num * var  Scalar multiplication\n");
    printf("  clear                     Clear all stored vectors\n");
    printf("  list                      List all stored vectors\n");
    printf("  quit                      Exit the program\n");
}

int main(int argc, char *argv[]) {
    printf("Welcome to mini-mat! Type 'quit' to exit, '-h' for help info.\n");

    atexit(free_all_memory);

    char line[256];
    int run = 1;

    while (run) {
        printf("minimat> ");
        if (fgets(line, sizeof(line), stdin) == NULL) break;
        
        line[strcspn(line, "\r\n")] = 0;

        if (strlen(line) == 0) continue;

        if (strcmp(line, "quit") == 0) {
            run = 0;
        } 
        else if (strcmp(line, "-h") == 0) { 
            print_help();
        }
        else if (strcmp(line, "clear") == 0) {
            clear_vectors();
            printf("Memory cleared.\n");
        }
        else if (strncmp(line, "load ", 5) == 0) {
            load_csv(line + 5);
        } 
        else if (strncmp(line, "save ", 5) == 0) {
            save_csv(line + 5);
        } 
        else if (strchr(line, '=')) {
                if (strchr(line, '+') || strchr(line, '-') || strchr(line, '*') || strchr(line, 'x') || strchr(line, '.')) {
                char target_name[50];
                char a_name[50], b_name[50];
                float multiple;
                char op;

                if (sscanf(line, "%49s = %49s %c %f", target_name, a_name, &op, &multiple) == 4 && op == '*') {
                    Vect *a = find_or_create_vector(a_name);
                    scalar(*a, multiple, target_name);
                } 
                else if (sscanf(line, "%49s = %49s %c %49s", target_name, a_name, &op, b_name) == 4) {
                    Vect *a = find_or_create_vector(a_name);
                    Vect *b = find_or_create_vector(b_name);
                    if (op == '+') {
                        add(*a, *b, target_name);
                    } else if (op == '-') {
                        sub(*a, *b, target_name);
                    } else if (op == '*') {
                        product(*a, *b, target_name);
                    } else if (op == 'x') {
                        cross_prod(*a, *b, target_name);
                    } else {
                        printf("Error: Unknown operator '%c'\n", op);
                    }
                } else {
                    printf("Error: Invalid expression format.\n");
                }
            } 
            else {
                char name[50];
                char line_copy[256];
                strcpy(line_copy, line);

                char *eq = strchr(line_copy, '=');
                if (eq != NULL) {
                    *eq = '\0';
                    sscanf(line_copy, "%49s", name);
                    
                    Vect *v = find_or_create_vector(name);

                    char *values_ptr = strchr(line, '=') + 1;
                    int i = 0;
                    char *token = strtok(values_ptr, " \t");
                    while (token != NULL && i < 10) {
                        v->value[i] = atoi(token);
                        i++;
                        token = strtok(NULL, " \t");
                    }
                    while (i < 10) {
                        v->value[i] = 0;
                        i++;
                    }

                    printf("%s = (", v->name);
                    for(int j = 0; j < 10; j++){
                        printf("%d", v->value[j]);
                        if(j < 9) printf(",");
                    }
                    printf(")\n");
                }
            }
        } 
        else {
            Vect v = findvect(line);
            if (strlen(v.name) > 0) {
                printf("%s = (", v.name);
                for (int j = 0; j < 10; j++) {
                    printf("%d", v.value[j]);
                    if (j < 9) printf(",");
                }
                printf(")\n");
            } else {
                printf("Unknown command or vector: %s\n", line);
            }
        }
    }

    printf("done\n");
    return 0;
}