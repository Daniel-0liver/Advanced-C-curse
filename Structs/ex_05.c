#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _book {
    char title[100];
    float price;
    int num_pages;
}Book;

Book *create_book(char *title, float price, int num_pages) {
    Book *book = (Book*) calloc(1, sizeof(Book));

    strcpy(book->title, title);
    book->price = price;
    book->num_pages = num_pages;

    return book;
}

int main() {
    
    Book book1 = {.title = "Harry Potter", 30.0, 250};
    Book *book2 = create_book("The secret of Cacilds", 10.0, 100);

    printf("Title1 = %s\n", book1.title);
    // printf("Title1 = %s\n", book1->title);
    printf("Title1 = %s\n", &book1.title);
    // printf("Title1 = %s\n", (&book1).title);
    // printf("Title2 = %s\n", book2.title);
    printf("Title2 = %s\n", book2->title);
    // printf("Title2 = %s\n", *book2.title);
    printf("Title2 = %s\n", (*book2).title);
    printf("Title2 = %s\n", book2[0].title);

    return 0;

}