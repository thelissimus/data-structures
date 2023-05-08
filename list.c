#include <stdlib.h>

typedef struct List_ {
    int head;
    struct List_ *tail;
} List;

List *cons(int, List *);

int *head(List *);
List *tail(List *);

void foreach(List *, void (*)(List *));
List *map(List *, List *(*)(List *));

List *
cons(int head, List *tail)
{
    List *l = malloc(sizeof(List));
    if (l == NULL) return NULL;
    l->head = head;
    l->tail = tail;
    return l;
}

int *
head(List *l)
{
	if (l == NULL) return NULL;
	return &l->head;
}

List *
tail(List *l)
{
	if (l == NULL) return NULL;
	return l->tail;
}

void
foreach(List *l, void (*fn)(List *))
{
	List *curr, *next;
	for (curr = l; curr != NULL; curr = next) {
		next = curr->tail;
		fn(curr);
	}
}

List *
map(List *l, List *(*fn)(List *))
{
	if (l == NULL) return l;
	return cons(*head(fn(l)), map(tail(l), fn));
}
