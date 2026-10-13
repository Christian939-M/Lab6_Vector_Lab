/*
 * File: vectassignval.c
 * Author: Christian Montoya
 * date: 9/29/2026
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
 #include "vect.h"

 Vect assign(Vect a){
    Vect returnval;
    int values;
    int count = 0;
    printf("minimat>");
    scanf("%49s = ", returnval.name);
    for(int i = 0; i<10; i++){
        if(scanf("%d", &values) != 1){
            break;
        }
      returnval.value[i] = values;
      count++;
    }
    printf("%s = (", returnval.name);
    for(int i = 0; i <count; i++){
        printf("%d", returnval.value[i]);
        if (i < count-1) printf(","); 
    }
    printf(")\n");
    return returnval;
 }