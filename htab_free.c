//
// Created by rockuo on 28.4.16.
//

#include <stdio.h>
#include <stdlib.h>
#include "htable.h"

void htab_free(htab_t *t) {
    if (t == NULL) {
        fprintf(stderr, "Chyba: Chybne tadana tabulka nebo klic\n");
        return;
    }


    htab_clear(t);
    free(t);
}