//
// Created by rockuo on 28.4.16.
//


#include <stdio.h>
#include <stdlib.h>
#include "htable.h"


htab_t *htab_init2(int htab_size, unsigned int  (*hash_fun_ptr)(const char *, unsigned)) {

    if (htab_size <= 0) {
        fprintf(stderr, "Chyba: Priliz mala velikost tabulky\n");
        return NULL;
    }

    htab_t *t = (htab_t *) malloc(sizeof(htab_t) + htab_size * sizeof(struct htab_listitem *));

    if (t == NULL)
        return NULL;

    t->htab_size = htab_size;
    t->hash_fun_ptr = hash_fun_ptr;
    t->n = 0;

    for (int i = 0; i < htab_size; i++)
        t->htab_lists[i] = NULL;

    return t;
}