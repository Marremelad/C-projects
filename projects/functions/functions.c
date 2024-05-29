#include <cs50.h>
#include <stdio.h>


int get_size(void);
void print_grid(int h);

int main(void)
{
    int n = get_size();
    print_grid(n);
}



//function for input
int get_size(void)
{
    int n;
    do
    {
        n = get_int("Size ");
    }
    while ( n < 1 || n > 8);
    return n;
}
//function for size of ramp
void print_grid(int h)
{
    int n = 1;
    int k = h - 1;

    for (int i = 0; i < h; i++)
    {

        for (int d = 0; d < k; d++)
        {
            printf(" ");
        }
        k = k - 1;

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
