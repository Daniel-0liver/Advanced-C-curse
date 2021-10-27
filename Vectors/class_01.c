#include <stdio.h>

int main() {
    int v[5] = {0, 1, 2, 3, 4};

    for (int i = 0; i < 5; i++)
    {
        printf("&v[%d] = %p, v[%d] = %d\n", i, &v[i], i, v[i]);
    }

    //Show that I can call one memory position that I don't allocate, and don't return error.
    printf("&v[6] = %p, v[6] = %d\n\n", &v[5], v[5]);
    printf("&v[7] = %p, v[7] = %d\n\n", &v[6], v[6]);
    
    return 0;
}