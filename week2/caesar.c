#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readline(char str[], int n);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]) % 26;
    char plaintext[500] = {};
    printf("plaintext: ");
    readline(plaintext, 500);
    // printf("%s\n", plaintext);

    char ciphertext[500] = {};
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            ciphertext[i] = (char) (base + ((plaintext[i] - base + key) % 26));
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    printf("ciphertext: %s\n", ciphertext);

    // printf("Program : %s\n", argv[0]);
    // printf("%s\n", argv[1]);
    // printf("inter: %d\n", key);
}

int readline(char str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
    {
        if (i < n)
        {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return n;
}
