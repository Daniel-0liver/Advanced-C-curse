#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _book
{
    char title[100];
    unsigned int num_pages;
    float price;
} Book;

typedef struct _vectorBook
{
    Book **vec;
    unsigned int num_elements;
} VectorBook;


Book *create_book(const char *title, unsigned int num_pages, float price) {
    Book *book = (Book *) calloc(1, sizeof(Book));

    strcpy(book->title, title);
    book->num_pages = num_pages;
    book->price = price;

    return book;
}

VectorBook **create_vector_book(unsigned int size) {
    VectorBook **vec = (VectorBook **) calloc(size, sizeof(Book *));
    return vec;
} 

void print_book(const Book *name_book) {
    puts("######################");
    printf("Title: %s\n", name_book->title);
    printf("Number of pages: %d\n", name_book->num_pages);
    printf("Price: %.2f$\n\n", name_book->price);

}

void print_all_vector(const Book **vec, unsigned int size) {
    for (int i = 0; i < size; i++)
    {
        print_book(vec[i]);
    }
}

Book *copy_book(const Book *book) {
    return create_book(book->title, book->num_pages, book->price);
}

void destroy_book(Book **ref_book) {
    free(*ref_book);
    *ref_book = NULL;
}

void destroy_vector_book(Book **vec, unsigned int size) {
    Book *aux = *vec;
    for (int i = 0; i < size; i++)
    {
        destroy_book(&aux[i]);
    }
    free(vec);
    *vec = NULL;
}

bool is_the_same_title(const Book *book_1, const Book *book_2) {
    if (strcmp(book_1->title, book_2->title) == 0)
    {
        return true;
    } else
    {
        return false;
    }
    
}

int main() {

    Book **vec = create_vector_book(3);

    vec[0] = create_book("Harry", 100, 20.50);
    vec[1] = create_book("Trading in the zone", 250, 25);
    vec[2] = create_book("The man who counted", 250, 6);

    print_all_vector(vec, 3);

    destroy_vector_book(&vec, 3);

    printf("Is null? %d\n", vec == NULL);
    
    // printf("\n%d\n", book_1 == NULL);
    // printf("\n%d\n", book_2 == NULL);

    return 0;
}