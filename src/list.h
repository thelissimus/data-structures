#pragma once

#include <stdbool.h>
#include <sys/types.h>

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
void foreach(const List *, void (*)(int));
List *map(const List *, int (*)(int));

/* Transformations: immutable & recursive */
void rforeach(const List *, void (*)(int));
List *rmap(const List *, int (*)(int));
int fold(const List *, int (*)(int, int), int);

/* Basic functions: immutable */
size_t length(const List *);
bool elem(const List *, int);
ssize_t find_index(const List *, int);
bool get_at(const List *, size_t, int *);
