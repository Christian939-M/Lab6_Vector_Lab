/*
 * Filename: vect.c
 * Author: Christian Montoya
 * Date: 10/15/2026
 */
#include <stdio.h>
#include <string.h>
#include "vect.h"

Vect* cross_prod(Vect a, Vect b, const char *target_name) {
    Vect *returnval = find_or_create_vector(target_name);
    if (returnval == NULL) return NULL;

    for (int i = 0; i < 10; i++) {
        returnval->value[i] = 0;
    }
    
    returnval->value[0] = (a.value[1] * b.value[2]) - (a.value[2] * b.value[1]);
    returnval->value[1] = (a.value[2] * b.value[0]) - (a.value[0] * b.value[2]);
    returnval->value[2] = (a.value[0] * b.value[1]) - (a.value[1] * b.value[0]);
    
    return returnval;
}