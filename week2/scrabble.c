#include <ctype.h>
#include <stdio.h>
#include <string.h>

int readline(char str[], int n);
int WordPromptScore(char str[]);

int single_pointof_character[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main()
{
    char WordPrompt_1[50];
    char WordPrompt_2[50];

    int WordPrompt_1_Score, WordPrompt_2_Score = 0;

    printf("Player 1: ");
    readline(WordPrompt_1, sizeof(WordPrompt_1));

    printf("Player 2: ");
    readline(WordPrompt_2, sizeof(WordPrompt_2));

    WordPrompt_1_Score = WordPromptScore(WordPrompt_1);
    WordPrompt_2_Score = WordPromptScore(WordPrompt_2);

    if (WordPrompt_1_Score == WordPrompt_2_Score)
    {
        printf("Tie!\n");
    }
    else if (WordPrompt_1_Score > WordPrompt_2_Score)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
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
    return i;
}

int WordPromptScore(char str[])
{
    int score = 0;
    int sortindex = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]) && str[i] >= 'a' && str[i] <= 'z')
        {
            sortindex = str[i] - 'a';
            score += single_pointof_character[sortindex];
        }

        else if (isalpha(str[i]) && str[i] >= 'A' && str[i] <= 'Z')
        {
            sortindex = str[i] - 'A';
            score += single_pointof_character[sortindex];
        }
    }
    return score;
}
