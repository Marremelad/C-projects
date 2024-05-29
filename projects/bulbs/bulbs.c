#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;
int binary[BITS_IN_BYTE];

void print_bulb(int bit);

int main(void)
{
// Ber användaren om en input.
    string message = get_string("Message: ");
    int word_lenght = strlen(message);
// Går igenom alla bokstäver i det valda ordet och konverterar dem till siffror.
    int value;
    for (int i = 0; i < word_lenght; i++)
    {
        value = message[i];
// Tar siffran och konverterar den till binär kod. Eftersom att denna uträkning kommer skapa den binära kodens "högraste" siffra först så måste vi stoppa i den på den högraste platsen i arrayen (binary[7]).
//Därför börjar vi med 'j' som 8 - 1 = 7.
    for (int j = BITS_IN_BYTE - 1; j > 0; j--)
        {
            binary[j] = value % 2;
            value /= 2;
        }
// Tar den binära koden och printar ut siffrorna en i taget från vänster till höger.Representeras av gula/svarta emojis. Alltså binary[0], binary[1], binary[2] etc etc...
        for (int k = 0; k < BITS_IN_BYTE; k++)
        {
            print_bulb(binary[k]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
