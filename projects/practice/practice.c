#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name? ");

    printf("Hello %s\n", name);

    for (int i = 0; i < 5; i++)
    {
        printf("%c\n", name[i]);
    }
}
