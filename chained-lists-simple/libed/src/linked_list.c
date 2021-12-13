#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _snode
{
	int					val;
	struct _snode	*next;
} SNode;

typedef struct _linked_list 
{
	SNode	*begin;
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

	return (L);
}

void *LinkedList_add_first(LinkedList *L, int val) {
	SNode *p = SNode_create(val);
	p->next = L->begin;
	L->begin = p;
}
