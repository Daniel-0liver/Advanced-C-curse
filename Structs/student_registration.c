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

typedef struct _student
{
    char name[100];
    unsigned int age;
    Book *fav_book;
} Student;



Book *create_book(const char *title, unsigned int num_pages, float price) {
    Book *book = (Book *) calloc(1, sizeof(Book));

    strcpy(book->title, title);
    book->num_pages = num_pages;
    book->price = price;

    return book;
}

void print_book(const Book *name_book) {
    puts("######################");
    printf("Title: %s\n", name_book->title);
    printf("Number of pages: %d\n", name_book->num_pages);
    printf("Price: %.2f$\n\n", name_book->price);

}

Book *copy_book(const Book *book) {
    return create_book(book->title, book->num_pages, book->price);
}

Student *create_student(const char *name, unsigned int age, const Book *fav_book) {
    Student *student = (Student *) calloc(1, sizeof(Student));

    strcpy(student->name, name);
    student->age = age;
    student->fav_book = copy_book(fav_book);

    return student;
}

void destroy_student(Student **student_ref) {
    Student *student = *student_ref;
    destroy_book(&student->fav_book);
    free(student);
    student_ref = NULL;
}

void print_student(const Student *student) {
    printf("Student name: %s\n", student->name);
    printf("Student age: %d\n", student->age);
    print_book(student->fav_book);
}

void destroy_book(Book **ref_book) {
    free(*ref_book);
    *ref_book = NULL;
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

    Book *book_1 = create_book("Harry", 100, 20.50);
    Book *book_2 = create_book("Trading in the zone", 250, 25);

    Student *student_1 = create_student("Daniel", 27, book_2);
    
    print_book(book_1);
    print_book(book_2);

    print_student(student_1);


    // Is the same book?
    if (student_1->fav_book == book_2)
    {
        puts("TRUE");
    } else
    {
        puts("FALSE");
    }
    
    // Is the same name?
    puts("\nAre the same names");
    if (is_the_same_title(student_1->fav_book, book_2))
    {
        puts("TRUE");
    } else
    {
        puts("FALSE");
    }
    
    
    destroy_book(&book_1);
    destroy_book(&book_2);

    print_student(student_1);

    destroy_student(&student_1);

    // printf("\n%d\n", book_1 == NULL);
    // printf("\n%d\n", book_2 == NULL);


    return 0;
}