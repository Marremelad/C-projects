// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));

    for (int j = 0; j < n; j++)
    {
        printf("%i\n", arr[j]);
    }
}

// TODO: return the max value
int max(int array[], int n)
{

    for (int i = 0; i < n; i++)
    {
        // int buffer = array[i];
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] < array[j])
            {
                array[i] = array[j];
                array[j] = array[i];

            }

            printf("%i\n", array[0]);
        }
    }
    int var = array[0];
    return var;


}


//Start out with a variable that keeps track of your max value. There are two ways to initialize this. You can start out using the lowest possible value (be careful you don’t start with zero, as the max value could be a negative number!)
// or you can start with the first element in the array.
