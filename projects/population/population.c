#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // Ask to input initial population of llamas. Input can not be lower than 9

    int llama_start;
    do
    {
        llama_start = get_int("How many llamas do you wan to start with? Minimum amount = 9\n");
    }
    while (llama_start < 9);

    // Create a variable named start_size to store the initial value of llama_start in order to print it at the end.

    //const int start_size = llama_start;

    // Ask user to input end population of llamas. Input can not be lower than llama_start.

    int llama_end;
    do
    {
        llama_end = get_int("Desired population of llamas? Desired population can not be less than starting amount.\n");
    }
    while (llama_end < llama_start);

    // Create variable llama_current in order to calculate the number of llamas. Once per loop llama_current wil be stored into
    // llama_start, allowing the number to grow.

    //int llama_current;
    int year = 0;
    while (llama_start < llama_end)

    {
        //llama_current = llama_start + (llama_start / 3) - (llama_start / 4);

        llama_start += llama_start / 12; //llama_current;

        year += 1;
    }

    //printf("\nStart size: %i\n", start_size);
    //printf("End size: %i\n", llama_current);
    printf("Years: %i\n", year);
}
