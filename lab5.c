/*
 * File: Lab7.c
 * Author: Christian Montoya
 * date: 9/29/2026
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
 #include <stdbool.h>
 #include "vect.h"

int main(void) {
    // Register exit handler so valgrind reports zero leaks[cite: 8, 9, 10]
    atexit(free_all_memory);

    char line[256];
    int run = 1;

    while (run) {
        printf("minimat> ");
        if (fgets(line, sizeof(line), stdin) == NULL) break;
        
        // Remove trailing newline
        line[strcspn(line, "\r\n")] = 0;

        if (strcmp(line, "quit") == 0) {
            run = 0;
        } else if (strcmp(line, "clear") == 0) {
            clear_vectors(); // Releases dynamic memory on clear[cite: 9]
        } 
        // Handle assignments and operations here...
    }

    printf("done\n");
    return 0;
}