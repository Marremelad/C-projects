#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do

    {
        h = get_int("Height of ramp please\n");
    }

    while (h < 1 || h > 8);

    int n = 1;
    int k = h - 1;

    for (int i = 0; i < h; i++)
    {

        for (int d = 0; d < k; d++)
        {
            printf(" ");
        }
        k--;

        for (int j = 0; j < n; j++)
        {
            printf("#");
        }

        printf("  ");

        for (int w = 0; w < n; w++)
        {
            printf("#");
        }

        n++;
        printf("\n");
    }
}
