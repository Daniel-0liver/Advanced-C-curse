#include <stdio.h>
#include <stdlib.h>

int main() {

    // Static vector allocation (Stack memory)
    int vs[5] = {0, 10, 20, 30, 40};

    puts("### STATIC VECTOR ###");
    printf("&vs = %p vs = %p\n", &vs, vs);

    for (int i = 0; i < 5; i++)
    {
        printf("&vs[%d] = %p, vs[%d] = %d\n", i, &vs[i], i, vs[i]);
    }

    puts("\n");

    // Dinamyc vector allocation using malloc (Heap memory)
    // There're trash at the memory allocated
    int *vh_mal = (int *) malloc(5 * sizeof(int));

    puts("### DINAMYC VECTOR WHITH MALLOC ###");
    printf("&vh_mal = %p vh_mal = %p\n", &vh_mal, vh_mal);

    for (int i = 0; i < 5; i++)
    {
        printf("&vh_mal[%d] = %p, vh_mal[%d] = %d\n", i, &vh_mal[i], i, vh_mal[i]);
    }

    puts("\n");

    // Dinamyc vector allocation using calloc (Heap memory)
    // Thare're no trash at the memory allocated
    int *vh_cal = (int *) calloc(5, sizeof(int));

    puts("### DINAMYC VECTOR WHITH CALLOC ###");
    printf("&vh_cal = %p vh_cal = %p\n", &vh_cal, vh_cal);

    for (int i = 0; i < 5; i++)
    {
        printf("&vh_cal[%d] = %p, vh_cal[%d] = %d\n", i, &vh_cal[i], i, vh_cal[i]);
    }

    puts("\n");


    return 0;
}