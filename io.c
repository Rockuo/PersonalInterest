//
// Created by rockuo on 28.4.16.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

int get_word(char *s, int max, FILE *f) {

    static int errorActivated = 0;
    if (s == NULL || f == NULL)
        return EOF;


    for (int i = 0; i < max + 1; i++) {
        s[i] = '\0';
    }

    int i = 0;
    int c = 0;
    while (EOF != (c = fgetc(f))) {
        if ((i + 1) > max || (i + 1) == max) {
            if (errorActivated == 0) {
                fprintf(stderr, "Chyba: Retezec priliz dlouhy, bude zkracen.\n");
                errorActivated = 1;
            }
            if (c == ' ' || c == '\n' || c == '\t') {
                // (s=="")=>i=0 continue
                return 1;
            }
        } else {
            if (c == ' ' || c == '\n' || c == '\t') {
                return 1;
            }
            s[i] = c;
        }
        i++;
    }

    return EOF;

}