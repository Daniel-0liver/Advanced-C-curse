#include <stdio.h>

int sum_and_sub(int a, int b,int *sub) {
    int sum = a + b;
    *sub = a - b;

    return sum;
}

int main() {
    int a = 10;
    int b = 20;
    int sub;

    int sum = sum_and_sub(a, b, &sub);

    printf("The sum of %d and %d is %d\n", a, b, sum);
    printf("The sub of %d and %d is %d\n", a, b, sub);

    return 0;
}