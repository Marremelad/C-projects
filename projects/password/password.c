// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
// Skapar boolean variabler nedanför och sätter dem till false.
    bool upper_req = false, lower_req = false, number_req = false, symbol_req = false;
    int length = strlen(password);
// Denna funktion fungerar på följade sätt. Ordet password som skickas ner i funktionen kommer att få sina bokstäver testade.
// Vi vill ju att password ska inehålla minst en liten och en stor bokstav minst en siffra och minst en symbol.
// Funktionen kommer att testa varje bokstav i password och se om den fyller något av kriterierna.
// En bokstav kan ju max uppfylla ett kriterium. När en bokstav uppfyller ett av "if-kriterirna" så stängs det kriteriet av genom att bli "true"

    for (int i = 0; i< length; i++)
    {
        if (upper_req == false)
        {
            upper_req = isupper(password[i]); //will become true, if isupper returns non 0
        }
        if (lower_req == false)
        {
            lower_req = islower(password[i]);
        }
        if (number_req == false)
        {
            number_req = isdigit(password[i]);
        }
        if (symbol_req == false)
        {
            symbol_req = !(isalnum(password[i]));
        }
    }
    // För att password ska godkännas av funktionen så måste alla boolean variabler bli true. Detta sker om alla "if-kriterier" stängs av.
    if (upper_req == true && lower_req == true && number_req == true && symbol_req == true)
    {
        return true;
    }
    return false;

}
