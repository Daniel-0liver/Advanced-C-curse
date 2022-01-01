#include "linked_list.h"

int main() {
	LinkedList *L = LinkedList_create();

    LinkedList_add_last(L, 10);
    LinkedList_add_last(L, 2);
    LinkedList_add_last(L, 4);
    LinkedList_add_last(L, 5);
    LinkedList_add_last(L, 7);
    LinkedList_print(L);

	printf("First val: %d\n", LinkedList_first_val(L));
	printf("Last val: %d\n", LinkedList_last_val(L));
	printf("Get val: %d\n", LinkedList_get_val(L, 6));

	LinkedList_destroy(&L);
	return (0);
}