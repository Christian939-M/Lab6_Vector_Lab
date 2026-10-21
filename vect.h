#ifndef VECT_H
#define VECT_H

#define MAX_VECTORS 10
#define NAME_LEN 32

typedef struct {
    char name[NAME_LEN];
    int value[10];
} vect;

vect add_vect(vect a, vect b);
vect sub_vect(vect a, vect b);
vect scalar_mult(vect v, double scalar);
double dot_prod(vect a, vect b);
vect cross_prod(vect a, vect b);

void init_storage(void);
int add_to_storage(vect v);
vect* find_vect(const char* name);
void clear_storage(void);
void list_storage(void);

#endif