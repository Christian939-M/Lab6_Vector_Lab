/*
 * File: vect_operation.c
 * Author: Christian Montoya
 * date: 9/29/2026
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
 #include "vect.h"

 char operation(Vect *a, Vect *b, char *target_name){
    char op;
    printf("minimat>");
    scanf("%49s = %49s %c %49s", target_name, a->name, &op, b->name);
    return op;
 }