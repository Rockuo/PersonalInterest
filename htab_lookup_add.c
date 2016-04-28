//
// Created by rockuo on 28.4.16.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"

struct htab_listitem *htab_lookup_add(htab_t *t, const char *key) {

    if ((t == NULL) || (key == NULL)) {
        fprintf(stderr, "Chyba: Chybne zadana tabulka nebo klic\n");
        return NULL;
    }

    unsigned int hash = (unsigned int) ((t->hash_fun_ptr))(key, t->htab_size);

    if ((t->htab_lists)[hash] == NULL) {
        struct htab_listitem *new_listitem = (struct htab_listitem *) malloc(sizeof(struct htab_listitem));
        new_listitem->key = (char *) malloc(strlen(key) + 1);
        strcpy(new_listitem->key, key);
        new_listitem->data = 1;
        new_listitem->next = NULL;

        (t->htab_lists)[hash] = new_listitem;
        return new_listitem;
    }

    struct htab_listitem *now = (t->htab_lists)[hash];
    while (1) {
        if (strcmp(now->key, key) == 0) {
            (t->n)++;
            (now->data)++;
            return now;
        } else if (now->next == NULL) {
            struct htab_listitem *new_listitem = (struct htab_listitem *) malloc(sizeof(struct htab_listitem));
            new_listitem->key = (char *) malloc(strlen(key) + 1);
            strcpy(new_listitem->key, key);
            new_listitem->data = 1;
            new_listitem->next = NULL;

            now->next = new_listitem;
            return new_listitem;
        } else {
            now = now->next;
        }

    }

}

