#pragma once

typedef struct List_ {
	int head;
	struct List_ *tail;
} List;

List *cons(int, List *);
void decons(List *);

void foreach(List *, void (*)(int));
List *map(List *, int (*)(int));
void rforeach(List *, void (*)(int));
List *rmap(List *, int (*)(int));
