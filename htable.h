//
// Created by rockuo on 28.4.16.
//

#ifndef IJCDU02_HTABLE_H
#define IJCDU02_HTABLE_H

struct htab_listitem {
    char *key;
    unsigned data;
    struct htab_listitem *next;
};

typedef struct {
    int htab_size;

    unsigned int  (*hash_fun_ptr)(const char *, unsigned);

    int n;
    struct htab_listitem *htab_lists[];
} htab_t;


htab_t *htab_init(int htab_size);

htab_t *htab_init2(int htab_size, unsigned int  (*hash_fun_ptr)(const char *, unsigned));

struct htab_listitem *htab_lookup_add(htab_t *t, const char *key);

void htab_foreach(htab_t *t, void (*function)(const char *, unsigned));

void htab_remove(htab_t *t, const char *key);

void htab_clear(htab_t *t);

void htab_free(htab_t *t);

unsigned int hash_function(const char *str, unsigned htab_size);


#endif //IJCDU02_HTABLE_H
