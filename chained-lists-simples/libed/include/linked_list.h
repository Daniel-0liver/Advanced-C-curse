#ifndef LINKED_LIST_H
# define LINKED_LIST_H

typedef struct _snode SNode;
typedef struct _linked_list LinkedList;

SNode *SNode_create(int val);

LinkedList *LinkedList_creat();
void *LinkedList_add_first(LinkedList *L, int val);

#endif