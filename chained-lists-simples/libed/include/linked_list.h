#ifndef LINKED_LIST_H
# define LINKED_LIST_H

#include <stdbool.h>
#include <stdio.h>

typedef struct _snode SNode;
typedef struct _linked_list LinkedList;

SNode *SNode_create(int val);

// Creat a list with calloc.
LinkedList *LinkedList_create();

// Destroy all list
void LinkedList_destroy(LinkedList **L_ref);

// Verify is the list is empty.
bool LinkedList_is_empty(const LinkedList *L);

// Add the element val in the begin of the list.
void LinkedList_add_first(LinkedList *L, int val);

// Add the element val in the final of the list slow way.
void LinkedList_add_last_slow(LinkedList *L, int val);

// Add the element val in the final of the list fast way.
void LinkedList_add_last(LinkedList *L, int val);

// Print all the list
void LinkedList_print(const LinkedList *L);

// Remove the first element if it is equal val.
void LinkedList_remove(LinkedList *L, int val);

// Show the size of the List
size_t	LinkedList_size_slow(const LinkedList *L);

size_t	LinkedList_size(const LinkedList *L);

int	LinkedList_first_val(const LinkedList *L);

int	LinkedList_last_val(const LinkedList *L);

int	LinkedList_get_val(const LinkedList *L, int index);

#endif