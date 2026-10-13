#ifndef VECT_H
#define VECT_H
typedef struct Vect{
    char name[50];
    int value[15];
}Vect;
char operation(Vect *a, Vect *b,char *target_name);
Vect add(Vect a, Vect b, const char *target_name);
Vect sub(Vect a, Vect b, const char *target_name);
Vect assign(Vect a);

#endif