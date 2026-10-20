/*
 * File: scalar.c
 * Author: Christian Montoya
 * date: 10/13/2026
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
 #include "vect.h"

 Vect* scalar(Vect a, float multiple, const char *target_name){
    Vect *returnval = find_or_create_vector(target_name);
    
    for(int i = 0; i < 10; i++){
        returnval->value[i] = a.value[i] * multiple;
    }
    printf("Values of %s are: (", returnval->name);
    for(int i = 0; i < 10; i++){
        printf("%.2d", returnval->value[i]);
        if (i < 9) printf(",");
    }
    printf(")\n");
    
    return returnval;
 }