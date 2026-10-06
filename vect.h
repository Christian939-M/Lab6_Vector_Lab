#ifndef VECT_H
#define VECT_H
typedef struct Vect{
    char name[8];
    int value[10];
}Vect;
Vect add(Vect a, Vect b);

#endif