#ifndef VECT_H
#define VECT_H

typedef struct Vect {
    char name[50];
    int value[10];
} Vect;

// Linked list node for dynamic storage
typedef struct VectNode {
    Vect vect;
    struct VectNode *next;
} VectNode;

void load_csv(const char *filename);
void save_csv(const char *filename);
// Function declarations
Vect assign(Vect a);
Vect add(Vect a, Vect b, const char *target_name);
Vect sub(Vect a, Vect b, const char *target_name);
char operation(char *target_name, Vect **a, Vect **b);

// Linked list management functions
Vect* find_or_create_vector(const char *name);
void clear_vectors(void);
void free_all_memory(void);

#endif