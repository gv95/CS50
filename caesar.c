#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main ( int argc, string argv[])
{
    if (argc == 2)
    {
        int k = atoi(argv[1]);
        if ( k != 0)
        {
            printf("plaintext: ");
        string plaintext = get_string();
        printf("ciphertext: ");
        for ( int i = 0, n = strlen(plaintext); i < n; i++)
        {
            char c = plaintext[i];
            if (isalpha(c))
            {
                if (isupper(c))
                {
                    printf("%c", (((c - 65) + k) % 26) + 65);
                }
                else
                {
                    printf("%c", (((c - 97) + k) % 26) + 97);
                }
            }
            else
            {
                printf("%c", c);
            }
        }
        printf("\n");
        return 0;
        }
    }
    else
    {
        return 1;
    }
}