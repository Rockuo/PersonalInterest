//
// Created by rockuo on 28.4.16.
//

#include <stdio.h>
#include <stdlib.h>
#include "htable.h"


void htab_foreach(htab_t *t, void (*function)(const char *, unsigned)) {
    if (t == NULL) {
        fprintf(stderr, "Chybna: spatne zadana tabulka\n");
        return;
    }

    struct htab_listitem *listItem;

    for (int i = 0; i < t->htab_size; i++) {
        if (t->htab_lists[i] == NULL)
            continue;

        listItem = t->htab_lists[i];

        function(listItem->key, listItem->data);

        while ((listItem = listItem->next) != NULL) {
            function(listItem->key, listItem->data);
        }

    }

}