// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string input_string);

// Möjliggör användandet av commandlinens input i programmet. int argc visar hur många strings som används. string argv[] är en array av alla strings som används.
int main(int argc, string argv[])
{
// argc != 2 innebär att om det är färre elller fler än 2 strings så kommer programmet inte att fortsätta.
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }
//printar det andra föremålet i arrayen, alltså argv[1], då argv[0] är det första.
    printf("%s\n", replace(argv[1]));

}
// En funktion som byter ut vokalerna mot siffror.
string replace(string input_string)
{
//går igenom bokstäverna en efter en, med hjälp av switch byter ut vokaler mot siffror. Om en vokal uppfyller kriterierna för case så avslutas switch och loopen börjar med nästa bokstav.
    int length = strlen(input_string);
    for (int i = 0; i < length; i++)
    {
        switch (input_string[i])
        {
            case 'a':
                input_string[i] = 54; // ascii value of 6
                break;
            case 'e':
                input_string[i] = 51; // ascii value of 3
                break;
            case 'i':
                input_string[i] = 49; // ascii value of 1
                break;
            case 'o':
                input_string[i] = 48; // ascii value of 0
                break;
        }
    }
    return input_string;
}
