#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _snode
{
	int				val;
	struct _snode	*next;
} SNode;

typedef struct _linked_list 
{
	SNode	*begin;
	SNode	*end;
	size_t	size;
} LinkedList;

SNode *SNode_create(int val) {
	SNode *snode = (SNode *) calloc(1, sizeof(SNode));
	snode->val = val;
	snode->next = NULL;

	return snode;
}

LinkedList *LinkedList_create() {
	LinkedList *L = (LinkedList *) calloc(1, sizeof(LinkedList));
	L->begin = NULL;
	L->end = NULL;
	L->size = 0;
	return (L);
}

void LinkedList_destroy(LinkedList **L_ref) {
	LinkedList *L = *L_ref;
	
	SNode *p = L->begin;
	SNode *aux = NULL;
	while (p){
		aux = p;
		p = p->next;
		free(aux);
	}
	free(L);

	*L_ref = NULL;
}

bool LinkedList_is_empty(const LinkedList *L) {
	return (L->size == 0);
}

void LinkedList_add_first(LinkedList *L, int val) {
	SNode *p = SNode_create(val);
	p->next = L->begin;
	
	if (LinkedList_is_empty(L))
		L->end = p;
	
	L->begin = p;
	L->size++;
}

void LinkedList_add_last_slow(LinkedList *L, int val) {
	SNode	*q = SNode_create(val);

	if (LinkedList_is_empty(L))
		L->begin = q;
	else
	{
		SNode *p = L->begin;
		while (p->next)
		{
			p = p->next;
		}
		p->next = q;
	}
	L->size++;
}

void LinkedList_add_last(LinkedList *L, int val) {
	SNode *p = SNode_create(val);

	if (LinkedList_is_empty(L)) {
		L->begin = p;
		L->end = p;
	}
	else
	{
		L->end->next = p;
		L->end = L->end->next;
	}
	L->size++;
}

void LinkedList_print(const LinkedList *L) {
	SNode *p = L->begin;

	printf("L -> ");
	while (p)
	{
		printf("%d -> ", p->val);
		p = p->next;
	}
	puts("NULL");
	if (L->end)
		printf("L -> end = %d\n", L->end->val);
	else
		printf("L -> end = NULL\n");
	printf("Size: %lu\n\n", L->size);
}

void LinkedList_remove(LinkedList *L, int val) {
	if (!LinkedList_is_empty(L))
	{
		if (L->begin->val == val)
		{
			SNode *pos = L->begin;
			if (L->end == L->begin)
				L->end = NULL;
			L->begin = L->begin->next;
			free(pos);
			L->size--;
		}
		else
		{
			SNode *pos = L->begin->next;
			SNode *prev = L->begin;
			while (pos && pos->val != val)
			{
				pos = pos->next;
				prev = prev->next;
			}
			if (pos)
			{
				prev->next = pos->next;
				if (!pos->next)
					L->end = prev;
				free(pos);
				L->size--;
			}	
		}
	}
}

size_t	LinkedList_size_slow(const LinkedList *L) {
	size_t size = 0;
	SNode *p = L->begin;
	while (p) {
		size++;
		p = p->next;
	}
	// The same but using for
	// for (SNode *p = L->begin; p; p = p->next)
	// 	size++;
	return (size);
}

size_t	LinkedList_size(const LinkedList *L) {
	return L->size;
}

int	LinkedList_first_val(const LinkedList *L) {
	if (LinkedList_is_empty(L))
		return 0;
	return L->begin->val;
}

int	LinkedList_last_val(const LinkedList *L) {
	if (LinkedList_is_empty(L))
		return 0;
	return L->end->val;
}

int	LinkedList_get_val(const LinkedList *L, int index) {
	if (LinkedList_is_empty(L) || index > (int)L->size)
		return 0;
	int count = 1;
	SNode *p = L->begin;
	while (count < index)
	{
		p = p->next;
		count++;
	}
	return p->val;
}