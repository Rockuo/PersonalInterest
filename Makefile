
HTABLE_FILES=hash_function.c htab_clear.c  htab_foreach.c htab_free.c htab_init.c htab_init2.c htab_lookup_add.c htab_remove.c


C-FLAGS=-std=c99 -Wall -Wextra -pedantic

all : tail tail2 libhtable.a wordcount cl

tail : tail.c
	gcc $(C-FLAGS) -o tail tail.c

tail2 : tail2.cpp
	g++ -std=c++11 -pedantic -Wall -o tail2 tail2.cpp

libhtable.a: $(HTABLE_FILES)
	gcc -c $(C-FLAGS) $(HTABLE_FILES)
	ar -rcs  libhtable.a $(HTABLE_FILES)
	ranlib libhtable.a

wordcount: wordcount.c libhtable.a
	gcc -std=c99 -pedantic -Wall  wordcount.c io.c  libhtable.a -o $@

cl:
	rm -f *.o core *.out