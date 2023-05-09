#include <stdlib.h>

#include "list.h"

List *
cons(int head, List *tail)
{
	List *l = malloc(sizeof(List));
	if (l == NULL)
		return NULL;
	l->head = head;
	l->tail = tail;
	return l;
}

void
decons(List *l)
{
	List *curr, *next;
	for (curr = l; curr != NULL; curr = next) {
		next = curr->tail;
		free(curr);
	}
}

void
foreach(List *l, void (*fn)(int))
{
	List *curr;
	for (curr = l; curr != NULL; curr = curr->tail) {
		fn(curr->head);
	}
}

List *
map(List *l, int (*fn)(int))
{
	List *curr, *acc;
	for (curr = l, acc = NULL; curr != NULL; curr = curr->tail) {
		acc = cons(fn(curr->head), acc);
	}
	return acc;
}

void
rforeach(List *l, void (*fn)(int))
{
	if (l == NULL)
		return;
	fn(l->head);
	rforeach(l->tail, fn);
}

List *
rmap(List *l, int (*fn)(int))
{
	if (l == NULL)
		return NULL;
	return cons(fn(l->head), rmap(l->tail, fn));
}
