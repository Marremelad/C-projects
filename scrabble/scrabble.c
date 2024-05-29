#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    printf("%i\n", score1);
    printf("%i\n", score2);
    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{

// Denna funktion går igenom varje bokstav, tar redan på om den är stor eller liten, och ger sedan bokstaven ett poängvärde baserat på konstanten points.
    int length, total_points = 0;
    length = strlen(word);
    for (int i = 0; i < length; i++)
    {
        if (isupper(word[i]))
        {
            // Varje bokstav bör ha ett förbestämt värde. Det fixar bi med hjälp av uträkningen nedanför. POINTS är en array med 26 förbestämda värden. Värdena är i bokstavsordning.
            // Vi måste då se till att bokstavärna som bearbetas i funktioinen får rätt mängd poäng tilldelad till sig.
            //Exempel: Vi vill ge bokstaven 'a' värdet av POINTS[0] för att 'a' är den första bokstaven alfabetet.
            // Det löser vi genom POINTS[word[i]]. I POINTS så kommer word[i], i detta fall word[a], att representeras av en bokstavens ascii siffra, i detta fall 65.
            //Så egentligen så står det POINTS[word[65]] eller föränklat 'a' = POINTS[65]. 65 platser finns dock inte i arrayen POINTS och vi vill ju att 'a' ska vara samma som 'a' = POINTS[0].
            // Vi tar då 'a' - 65 (65 eftersom att det finns 65 små bokstäver i ascii) och det blir 0. 'a' är då 'a' = POINTS[0]. Gör man istället detta med 'b' så blir det 'b' - 65 som är lika med 'b' = POINTS[1]
            total_points += POINTS[word[i] - 65];
        }
        else if (islower(word[i]))
        {
            // Samma sak fast med stora bokstäver.
            total_points += POINTS[word[i] - 97];
        }
    }
    return total_points;
}
