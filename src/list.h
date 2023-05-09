#pragma once

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

/* Transformations: immutable */
void foreach(List *, void (*)(int));
List *map(List *, int (*)(int));

/* Transformations: immutable & recursive */
void rforeach(List *, void (*)(int));
List *rmap(List *, int (*)(int));
int fold(List *, int (*)(int, int), int);

/* Basic functions: immutable */
size_t length(List *);
