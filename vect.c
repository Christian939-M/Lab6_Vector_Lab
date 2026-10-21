/*
 * Filename: vect.c
 * Author: Christian Montoya
 * Date: 10/15/2026
 */
#include <stdio.h>
#include <string.h>
#include "vect.h"

static vect storage[MAX_VECTORS];

void init_storage(void) {
    for (int i = 0; i < MAX_VECTORS; i++) {
        storage[i].name[0] = '\0';
        for (int j = 0; j < 10; j++) {
            storage[i].value[j] = 0;
        }
    }
}

vect add_vect(vect a, vect b) {
    vect result;
    result.name[0] = '\0';
    for (int i = 0; i < 10; i++) {
        result.value[i] = a.value[i] + b.value[i];
    }
    return result;
}

vect sub_vect(vect a, vect b) {
    vect result;
    result.name[0] = '\0';
    for (int i = 0; i < 10; i++) {
        result.value[i] = a.value[i] - b.value[i];
    }
    return result;
}

vect scalar_mult(vect v, double scalar) {
    vect result;
    result.name[0] = '\0';
    for (int i = 0; i < 10; i++) {
        result.value[i] = (int)(v.value[i] * scalar);
    }
    return result;
}

double dot_prod(vect a, vect b) {
    double sum = 0.0;
    for (int i = 0; i < 10; i++) {
        sum += (double)(a.value[i] * b.value[i]);
    }
    return sum;
}

vect cross_prod(vect a, vect b) {
    vect result;
    result.name[0] = '\0';
    for (int i = 0; i < 10; i++) {
        result.value[i] = 0;
    }
    result.value[0] = (a.value[1] * b.value[2]) - (a.value[2] * b.value[1]);
    result.value[1] = (a.value[2] * b.value[0]) - (a.value[0] * b.value[2]);
    result.value[2] = (a.value[0] * b.value[1]) - (a.value[1] * b.value[0]);
    return result;
}

int add_to_storage(vect new_v) {
    for (int i = 0; i < MAX_VECTORS; i++) {
        if (storage[i].name[0] != '\0' && strcmp(storage[i].name, new_v.name) == 0) {
            storage[i] = new_v;
            return 0;
        }
    }
    for (int i = 0; i < MAX_VECTORS; i++) {
        if (storage[i].name[0] == '\0') {
            storage[i] = new_v;
            return 0;
        }
    }
    return -1;
}

vect* find_vect(const char* name) {
    for (int i = 0; i < MAX_VECTORS; i++) {
        if (storage[i].name[0] != '\0' && strcmp(storage[i].name, name) == 0) {
            return &storage[i];
        }
    }
    return NULL;
}

void clear_storage(void) {
    init_storage();
}

void list_storage(void) {
    int found = 0;
    for (int i = 0; i < MAX_VECTORS; i++) {
        if (storage[i].name[0] != '\0') {
            printf("%s =", storage[i].name);
            for (int j = 0; j < 10; j++) {
                printf(" %d", storage[i].value[j]);
            }
            printf("\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No vectors stored.\n");
    }
}