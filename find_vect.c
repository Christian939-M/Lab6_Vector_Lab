/*
 * File: find_vect.c
 * Author: Christian Montoya
 * date: 10/13/2026
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "vect.h"
Vect findvect(const char *name) {
    VectNode *current = head;
    
    while (current != NULL) {
        if (strcmp(current->vect.name, name) == 0) {
            return current->vect; 
        }
        current = current->next;
    }
    
    Vect empty_vect;
    strcpy(empty_vect.name, "");
    for (int i = 0; i < 10; i++) {
        empty_vect.value[i] = 0;
    }
    return empty_vect;
}