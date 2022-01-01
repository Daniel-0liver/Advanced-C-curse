#include "linked_list.h"

int main() {
	LinkedList *L = LinkedList_create();

    LinkedList_add_last(L, 10);
    LinkedList_add_last(L, 2);
    LinkedList_add_last(L, 4);
    LinkedList_add_last(L, 5);
    LinkedList_add_last(L, 7);
    LinkedList_print(L);

	printf("Size of the list is: %ld", LinkedList_size(L));

	LinkedList_destroy(&L);
	return (0);
}