#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
 // Ber användaren om input. Antalet veckor som hitintills har studerats.
    int weeks = get_int("Number of weeks taking CS50: ");
// Tar antalet veckor och gör en array (hour[weks]), som kommer att vara lika stor som antalet veckor. Detta för att kunna sätta in timmarna i respektive vecka.
// Alltså, har jag pluggat i x antal veckor så kommer varje "timmvärde" få en vecka var.
    int hours[weeks];

// Det jah precis förklarade i komentaren innan. Denna loop genomförs lika många gånger som antalet veckor pluggade. Värdet get_int kommet därefter att stoppas in i var sin plats i arrayen.
// Altså, om du pluggat 2 veckor, 2h första veckan och 3h andra veckan, så kommer hours[0] = 2h, samt hours[1] = 3h. Två platser i arrayen har då använts, 0 och 1.
   for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }
// Ber användaren om ytterligare en input. Bokstäverna T eller A. Med hjälp av funktionen toupper så kommer bokstaven bli stor oavsätt om man skriver den som liten.
    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// En funktion som tar värdena weeks, hours samt T eller A för att räkna ut den totala mängden timmar som pluggats eller den genomsnittliga mängden timmar som pluggats.
float calc_hours(int hours[], int weeks, char output)
{
// Loopar igenom arrayen så många gånger som weeks är angivet. Tar då respektive värde från arraye, detta fall antalet timmar, och lägger till det på total.
// Alltså, om arrayen ska loopas igenom två gånger så kommer värdena hours[0] och hours[1] att plockas ut. Först plockas värde 1 ut och läggs på total.
// Funktionen loopar til nästa del av arrayen (värde 1) och det värdet läggs på total. Lägg märke till att värdet plussas på det gamla värdet.
    float total = 0;
    if ( output == 'T')
    {
        for (int i = 0; i < weeks; i++)
        {
            total += hours[i];
        }
    }
// Samma sak fast här delas även total med weeks för att få ett snittvärde.
    else if ( output == 'A')
    {
        for (int i = 0; i < weeks; i++)
        {
            total += hours[i];
        }
        total = total / weeks;
    }
// Värdena som skciaks tillbaka kommer att vara decimaltal då total är en float.
    return total;

}
