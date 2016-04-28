//
// Created by rockuo on 28.4.16.
//

#include <stdio.h>
#include <stdlib.h>
#include "htable.h"

void htab_clear(htab_t *t) {
    if (t == NULL) {
        fprintf(stderr, "Chyba: Chybne tadana tabulka nebo klic\n");
        return;
    }

    struct htab_listitem *listitem;
    for (int i = 0; i < t->htab_size; i++) {
        listitem = t->htab_lists[i];

        while (t->htab_lists[i] != NULL) {
            t->htab_lists[i] = listitem->next;
            free(listitem->key);
            free(listitem);
        }

    }
}
