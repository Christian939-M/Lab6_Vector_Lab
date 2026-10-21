/*
 * Filename: lab5.c
 * Author: Christian Montoya
 * Date: 10/15/2026
 * Description: make
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    if (argc > 1 && strcmp(argv[1], "-h") == 0) {
        print_help();
        return 0;
    }

    init_storage();
    char line[256];

    printf("Welcome to mini-mat! Type 'quit' to exit, '-h' for help info.\n");

    while (1) {
        printf("minimats> ");
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }

        line[strcspn(line, "\r\n")] = 0;
        if (strlen(line) == 0) continue;
        if (strcmp(line, "quit") == 0) break;
        if (strcmp(line, "-h") ==0) {print_help(); continue;}
        if (strcmp(line, "clear") == 0) { clear_storage(); continue; }
        if (strcmp(line, "list") == 0) { list_storage(); continue; }

        char dest[NAME_LEN];
        char rest[200];


        if (sscanf(line, "%s = %199[^\n]", dest, rest) == 2) {
            

            char v1_name[NAME_LEN], op_str[10], v2_name[NAME_LEN];
            double scalar_val;

            if (sscanf(rest, "%s %s %s", v1_name, op_str, v2_name) == 3 && 
                (strcmp(op_str, "+") == 0 || strcmp(op_str, "-") == 0 || strcmp(op_str, "x") == 0 || strcmp(op_str, ".") == 0)) {
                
                vect* v1 = find_vect(v1_name);
                vect* v2 = find_vect(v2_name);
                
                if (!v1 || !v2) {
                    printf("Error: One or both vectors do not exist.\n");
                    continue;
                }

                vect res;
                if (strcmp(op_str, "+") == 0) res = add_vect(*v1, *v2);
                else if (strcmp(op_str, "-") == 0) res = sub_vect(*v1, *v2);
                else if (strcmp(op_str, "x") == 0) res = cross_prod(*v1, *v2);
                else if (strcmp(op_str, ".") == 0) {
                    double dot = dot_prod(*v1, *v2);
                    printf("%s = %.2f\n", dest, dot);
                    continue;
                }
                
                strcpy(res.name, dest);
                add_to_storage(res);
                printf("%s =", res.name);
                for (int i = 0; i < 10; i++) printf(" %d", res.value[i]);
                printf("\n");
                continue;
            }

            if (sscanf(rest, "%s * %lf", v1_name, &scalar_val) == 2 || sscanf(rest, "%lf * %s", &scalar_val, v1_name) == 2) {
                vect* v = find_vect(v1_name);
                if (!v) {
                    printf("Error: Vector '%s' does not exist.\n", v1_name);
                    continue;
                }
                vect res = scalar_mult(*v, scalar_val);
                strcpy(res.name, dest);
                add_to_storage(res);
                printf("%s =", res.name);
                for (int i = 0; i < 10; i++) printf(" %d", res.value[i]);
                printf("\n");
                continue;
            }

  
            vect new_v;
            strcpy(new_v.name, dest);
            for (int i = 0; i < 10; i++) new_v.value[i] = 0;

            int vals[10];
            int count = 0;
            char rest_copy[200];
            strcpy(rest_copy, rest);
            char *token = strtok(rest_copy, ", ");
            while (token != NULL && count < 10) {
                vals[count++] = atoi(token);
                token = strtok(NULL, ", ");
            }

            if (count > 0) {
                for (int i = 0; i < count; i++) {
                    new_v.value[i] = vals[i];
                }
                if (add_to_storage(new_v) != 0) {
                    printf("Error: Storage full (max 10 vectors).\n");
                } else {
                    printf("%s =", new_v.name);
                    for (int i = 0; i < 10; i++) printf(" %d", new_v.value[i]);
                    printf("\n");
                }
                continue;
            }
        }


        char v1_name[NAME_LEN], op_str[10], v2_name[NAME_LEN];
        double scalar_val;

        if (sscanf(line, "%s %s %s", v1_name, op_str, v2_name) == 3) {
            vect* v1 = find_vect(v1_name);
            vect* v2 = find_vect(v2_name);

            if (!v1 || !v2) {
                printf("Error: One or both vectors do not exist.\n");
                continue;
            }

            if (strcmp(op_str, "+") == 0) {
                vect res = add_vect(*v1, *v2);
                printf("ans =");
                for (int i = 0; i < 10; i++) printf(" %d", res.value[i]);
                printf("\n");
            } else if (strcmp(op_str, "-") == 0) {
                vect res = sub_vect(*v1, *v2);
                printf("ans =");
                for (int i = 0; i < 10; i++) printf(" %d", res.value[i]);
                printf("\n");
            } else if (strcmp(op_str, ".") == 0) {
                double dot = dot_prod(*v1, *v2);
                printf("ans = %.2f\n", dot);
            } else if (strcmp(op_str, "x") == 0) {
                vect res = cross_prod(*v1, *v2);
                printf("ans =");
                for (int i = 0; i < 10; i++) printf(" %d", res.value[i]);
                printf("\n");
            } else {
                printf("Error: Invalid operator.\n");
            }
            continue;
        }
        if (sscanf(line, "%s * %lf", v1_name, &scalar_val) == 2 || sscanf(line, "%lf * %s", &scalar_val, v1_name) == 2) {
            vect* v = find_vect(v1_name);
            if (!v) {
                printf("Error: Vector '%s' does not exist.\n", v1_name);
                continue;
            }
            vect res = scalar_mult(*v, scalar_val);
            printf("ans =");
            for (int i = 0; i < 10; i++) printf(" %d", res.value[i]);
            printf("\n");
            continue;
        }
        char single_name[NAME_LEN];
        if (sscanf(line, "%s", single_name) == 1) {
            vect* v = find_vect(single_name);
            if (v != NULL) {
                printf("%s =", v->name);
                for (int i = 0; i < 10; i++) printf(" %d", v->value[i]);
                printf("\n");
            } else {
                printf("Error: Vector '%s' not found.\n", single_name);
            }
            continue;
        }

        printf("Error: Unknown command or expression.\n");
    }

    return 0;
}