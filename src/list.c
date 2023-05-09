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
reverse(List **l)
{
	List *prev, *curr, *next;
	for (prev = NULL, curr = *l, next = NULL; curr != NULL; curr = next) {
		next = curr->tail;
		curr->tail = prev;
		prev = curr;
	}
	*l = prev;
}

void
foreach(List *l, void (*f)(int))
{
	List *curr;
	for (curr = l; curr != NULL; curr = curr->tail) {
		f(curr->head);
	}
}

List *
map(List *l, int (*f)(int))
{
	List *curr, *acc;
	for (curr = l, acc = NULL; curr != NULL; curr = curr->tail) {
		acc = cons(f(curr->head), acc);
	}
	reverse(&acc);
	return acc;
}

void
rforeach(List *l, void (*f)(int))
{
	if (l == NULL)
		return;
	f(l->head);
	rforeach(l->tail, f);
}

List *
rmap(List *l, int (*f)(int))
{
	if (l == NULL)
		return NULL;
	return cons(f(l->head), rmap(l->tail, f));
}

int
fold(List *l, int (*f)(int, int), int z)
{
	if (l == NULL)
		return z;
	return f(l->head, fold(l->tail, f, z));
}

size_t
length(List *l)
{
	size_t acc = 0;
	List *curr;
	for (curr = l; curr != NULL; curr = curr->tail) {
		acc++;
	}
	return acc;
}
