#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _book
{
    char title[100];
    unsigned int num_pages;
    float price;
} Book;

Book *create_book(const char *title, unsigned int num_pages, float price) {
    Book *book = (Book *) calloc(1, sizeof(Book));

    strcpy(book->title, title);
    book->num_pages = num_pages;
    book->price = price;

    return book;
}

void print_book(Book *name_book) {
    puts("######################");
    printf("Title: %s\n", name_book->title);
    printf("Number of pages: %d\n", name_book->num_pages);
    printf("Price: %.2f$\n\n", name_book->price);

}

int main() {

    Book *book_1 = create_book("Harry", 100, 20.50);
    Book *book_2 = create_book("Trading in the zone", 250, 25);
    print_book(book_1);
    print_book(book_2);


    return 0;
}