#include "linked_list.h"

int main() {
	LinkedList *L = LinkedList_create();

	LinkedList_add_first(L, 10);
	LinkedList_print(L);
	LinkedList_add_first(L, 20);
	LinkedList_print(L);
	LinkedList_add_first(L, 30);
	LinkedList_print(L);
	LinkedList_add_first(L, 40);
	LinkedList_print(L);
	LinkedList_add_first(L, 50);
	LinkedList_print(L);

	LinkedList_add_last(L, 10);
	LinkedList_print(L);
	LinkedList_add_last(L, 20);
	LinkedList_print(L);
	LinkedList_add_last(L, 30);
	LinkedList_print(L);
	LinkedList_add_last(L, 40);
	LinkedList_print(L);
	LinkedList_add_last(L, 50);
	LinkedList_print(L);
	return (0);
}