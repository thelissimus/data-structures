#include <stddef.h>
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

bool
insert_after(List *l, size_t i, int a)
{
	List *curr;
	for (curr = l; curr != NULL; curr = curr->tail, i--) {
		if (i == 0) {
			curr->tail = cons(a, curr->tail);
			return true;
		}
	}
	return false;
}

bool
delete_after(List *l, size_t i)
{
	if (l == NULL)
		return false;

	List *curr;
	for (curr = l; curr->tail != NULL; curr = curr->tail, i--) {
		if (i == 0) {
			free(curr->tail);
			curr->tail = curr->tail->tail;
			return true;
		}
	}
	return false;
}

void
foreach(const List *l, void (*f)(int))
{
	const List *curr;
	for (curr = l; curr != NULL; curr = curr->tail) {
		f(curr->head);
	}
}

List *
map(const List *l, int (*f)(int))
{
	List *acc;
	const List *curr;
	for (curr = l, acc = NULL; curr != NULL; curr = curr->tail) {
		acc = cons(f(curr->head), acc);
	}
	reverse(&acc);
	return acc;
}

void
rforeach(const List *l, void (*f)(int))
{
	if (l == NULL)
		return;
	f(l->head);
	rforeach(l->tail, f);
}

List *
rmap(const List *l, int (*f)(int))
{
	if (l == NULL)
		return NULL;
	return cons(f(l->head), rmap(l->tail, f));
}

int
foldr(const List *l, int (*f)(int, int), int z)
{
	if (l == NULL)
		return z;
	return f(l->head, foldr(l->tail, f, z));
}

size_t
length(const List *l)
{
	size_t acc = 0;
	const List *curr;
	for (curr = l; curr != NULL; curr = curr->tail) {
		acc++;
	}
	return acc;
}

bool
elem(const List *l, int a)
{
	const List *curr;
	for (curr = l; curr != NULL; curr = curr->tail) {
		if (curr->head == a)
			return true;
	}
	return false;
}

ssize_t
find_index(const List *l, int a)
{
	ssize_t i;
	const List *curr;
	for (i = 0, curr = l; curr != NULL; i++, curr = curr->tail) {
		if (curr->head == a)
			return i;
	}
	return -1;
}

bool
get_at(const List *l, size_t i, int *res)
{
	const List *curr;
	for (curr = l; curr != NULL; curr = curr->tail, i--) {
		if (i == 0) {
			*res = curr->head;
			return true;
		}
	}
	return false;
}
