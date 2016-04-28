//
// Created by rockuo on 28.4.16.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"

void htab_remove(htab_t *t, const char *key) {

    if ((t == NULL) || (key == NULL)) {
        fprintf(stderr, "Chyba: Chybne zadana tabulka nebo klic\n");
        return;
    }

    unsigned int hash = (unsigned int) ((t->hash_fun_ptr))(key, t->htab_size);

    struct htab_listitem *listitem = t->htab_lists[hash];

    if (listitem == NULL)
        return;

    if (strcmp(listitem->key, key)) {
        t->htab_lists[hash] = listitem->next;
        free(listitem->key);
        free(listitem);
        return;
    }

    struct htab_listitem *prev = t->htab_lists[hash];


    while (listitem != NULL) {
        if (strcmp(listitem->key, key)) {
            prev->next = listitem->next;
            free(listitem->key);
            free(listitem);
            return;
        }
        prev = listitem;
        listitem = listitem->next;
    }

}