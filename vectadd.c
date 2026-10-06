/*
 * File: vectadd.c
 * Author: Christian Montoya
 * date: 9/29/2026
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
 #include "vect.h"

 Vect add(Vect a, Vect b){
    Vect returnval;
    int values;
    printf("Assign at least 10 values for a: ");

   for(int i = 0; i<5; i++){
      scanf("%d", &values);
      a.value[i] = values;
    }

    printf("Assign at least 10 values for b: ");
   for(int i = 0; i<5; i++){
      scanf("%d ", &values);
      b.value[i] = values;
    }
    for(int i = 0; i<5; i++){
        returnval.value[i] = a.value[i] + b.value[i];
    }
   printf("Values are: (");
   for(int i = 0; i<5; i++){
      printf("%d,", returnval.value[i]);
    }
    printf(")");
    return returnval;
 }