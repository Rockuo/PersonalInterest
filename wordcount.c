//
// Created by rockuo on 27.4.16.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"
#include "htable.h"

#define wordLen 127


//int get_word(char *s, int max, FILE *f) {
//
//    static int errorActivated = 0;
//    if (s == NULL || f == NULL)
//        return EOF;
//
//
//    for (int i = 0; i < max + 1; i++) {
//        s[i] = '\0';
//    }
//
//    int i = 0;
//    int c = 0;
//    while (EOF != (c = fgetc(f))) {
//        if ((i + 1) > max || (i + 1) == max) {
//            if (errorActivated == 0) {
//                fprintf(stderr, "Chyba: Retezec priliz dlouhy, bude zkracen.\n");
//                errorActivated = 1;
//            }
//            if (c == ' ' || c == '\n' || c == '\t') {
//                // (s=="")=>i=0 continue
//                return 1;
//            }
//        } else {
//            if (c == ' ' || c == '\n' || c == '\t') {
//                return 1;
//            }
//            s[i] = c;
//        }
//        i++;
//    }
//
//    return EOF;
//
//}

void printIt(const char *key, unsigned value) {
    printf("%s %d \n", key, value);
    return;
}

int main() {
    htab_t *t;
    t = htab_init(32768);
    char s[wordLen + 1] = {'\0'};
    while (get_word(s, wordLen, stdin) != EOF) {
        if (strcmp(s, "") != 0)
            htab_lookup_add(t, s);

    }

    htab_foreach(t, printIt);

    htab_free(t);

    return EXIT_SUCCESS;
}

