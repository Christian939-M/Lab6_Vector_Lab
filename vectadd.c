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

 Vect add(Vect a, Vect b, const char *target_name){
   Vect returnval;
   strcpy(returnval.name, target_name);
   for(int i = 0; i<10; i++){
      returnval.value[i] = a.value[i] + b.value[i];
   }
   printf("Values of %s are: (",returnval.name);
   for(int i = 0; i<10; i++){
      printf("%d", returnval.value[i]);
      if (i < 9) printf(",");
   }
   printf(")\n");
   return returnval;
 }