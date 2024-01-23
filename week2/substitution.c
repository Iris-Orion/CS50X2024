#include <ctype.h>
#include <stdio.h>
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
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    char plaintext[500], ciphertext[500];
    int encrypt_num[26] = {0}, alphabet_count[26] = {0};

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]))
        {
            char encrypt_base = isupper(argv[1][i]) ? ('A' + i) : ('a' + i);
            encrypt_num[i] = argv[1][i] - encrypt_base;
            int count_base = isupper(argv[1][i]) ? 'A' : 'a';
            alphabet_count[argv[1][i] - count_base] += 1;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (alphabet_count[i] != 1)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    readline(plaintext, 500);

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            ciphertext[i] = (char) (plaintext[i] + encrypt_num[plaintext[i] - base]);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';

    printf("ciphertext: %s\n", ciphertext);
}

int readline(char str[], int n)
{
    printf("plaintext: ");
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
