#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _snode
{
	int					val;
	struct _snode	*next;
} SNode;

typedef struct _linked_list 
{
	SNode	*begin;
	SNode	*end;
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
	return ((L->begin == NULL && L->end == NULL));
}

void LinkedList_add_first(LinkedList *L, int val) {
	SNode *p = SNode_create(val);
	if (LinkedList_is_empty(L))
	{
		L->end = p;
		L->begin = p;
	}
	else
	{
		p->next = L->begin;
		L->begin = p;
	}
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
		printf("L -> end = %d\n\n", L->end->val);
	else
		printf("L -> end = NULL\n");
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
			}	
		}		
	}
}

size_t	LinkedList_size(const LinkedList *L) {
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