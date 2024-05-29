
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string numb);
void rotation(char letter, int k);

int main(int argc, string argv[])
{
// Ser till att användaren måste ha minst och max två strings i command linen.
    if (argc != 2 || only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

// Ber användaren om en string.
    string plaintext = get_string("Message: ");

    int lenght = strlen(plaintext);
    int k = atoi(argv[1]);

    printf("ciphertext: ");
    for (int i = 0; i < lenght; i++)
    {
        rotation(plaintext[i], k);
    }
    printf("\n");
}

// Funktionen som ser till att användaren inte kan srkiva mer än två eller mindre än en string.
bool only_digits(string str)
{
    int lenght = strlen(str);
    for (int j = 0; j < lenght; j++)
    {
        if (isdigit(str[j]) == false)
        {
            return false;
        }
    }
    return true;
}

// Funktionen som roterar bokstäverna och krypterar meddelandet.
void rotation(char letter, int k)
{
    int c = 0;
// Uträkningen konverterar bokstavens ascii värde till sitt alfabetiska index värde. Därefter tillbaka till sitt ascii värde.
// Observera att k används som rotationsvärdet.
    if (isupper(letter))
    {
        c = (letter - 65 + k) % 26 + 65;
    }

    else if (islower(letter))
    {
        c = (letter - 97 + k) % 26 + 97;
    }
    else
    {
        c += (int) letter;
    }

    printf("%c", c);
}
