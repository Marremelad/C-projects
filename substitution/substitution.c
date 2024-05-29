#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool check_key(string key);
void encrypt(string c, string key);
int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("usage\n");
        return 1;
    }

    if (!check_key(argv[1]))
    {
        return 1;
    }

    string message = get_string("message: ");
    string key = argv[1];

    printf("ciphertext: ");
    encrypt(message, key);

    printf("\n");
}

void encrypt(string message, string key)
{
    int length = strlen(message);

    for (int i = 0; i < length; i++)
    {

        if (isalpha(message[i]))
        {
            if (isupper(message[i]))
            {
                int letter = key[message[i] - 65];
                printf("%c", toupper(letter));
            }

            else if (islower(message[i]))
            {
                int letter = key[message[i] - 97];
                printf("%c", tolower(letter));
            }
        }
        else
        {
            printf("%c", message[i]);
        }
    }
}

bool check_key(string key)
{
    int length = strlen(key);

    if (length != 26)
    {
        printf("Key must be at least 26 characters\n");
        return false;
    }

    for (int i = 0; i < length; i++)
    {
        key[i] = toupper(key[i]);
    }

    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key can not contain a number\n");
            return false;
        }

        for (int j = i + 1; j < length; j++)
        {
            if (key[i] == key[j])
            {
                printf("The same letter can not be used twice in the key\n");
                return false;
            }
        }
    }
    return true;
}
