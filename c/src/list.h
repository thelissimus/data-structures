#pragma once

#include <sys/types.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct List_ {
	int head;
	struct List_ *tail;
} List;

/* Constructors */
List *cons(int, List *);
void decons(List *);

/* Transformations: mutable */
void reverse(List **);
bool insert_after(List *, size_t, int);
bool delete_after(List *, size_t);

/* Transformations: immutable */
List *map(const List *, int (*)(int));

/* Transformations: immutable & recursive */
List *rmap(const List *, int (*)(int));
int foldr(const List *, int (*)(int, int), int);

/* Traversing: immutable */
void foreach(const List *, void (*)(int));

/* Traversing: immutable & recursive */
void rforeach(const List *, void (*)(int));

/* Accessors: immutable */
size_t length(const List *);
bool elem(const List *, int);
ssize_t find_index(const List *, int);
bool get_at(const List *, size_t, int *);
