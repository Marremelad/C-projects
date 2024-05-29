#include <stdio.h>
#include <cs50.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("%i\n%i\n", x, y);
    swap(&x, &y);
    printf("%i\n%i\n", x, y);
}

void swap(int *a, int *b)
{
    int buffer = *a;
    *a = *b;
    *b = buffer;
}
