#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int read_line(char str[], int n);
int count_letters(char str[]);
int count_words(char str[]);
int count_sentences(char str[]);

int main(void)
{
    char book_content[1000];
    printf("Text: ");
    read_line(book_content, 1000);
    int letter_count = count_letters(book_content);
    int word_count = count_words(book_content);
    int sentence_count = count_sentences(book_content);
    int Coleman_Liau_index = round(0.0588f * ((float) letter_count / (float) word_count * 100.0f) -
                                   0.296f * ((float) sentence_count / (float) word_count * 100.0f) - 15.8);
    if (Coleman_Liau_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (Coleman_Liau_index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", Coleman_Liau_index);
    }

    // printf("%s\n", book_content);
    // printf("%d\n", count_letters(book_content));
    // printf("%d\n", count_words(book_content));
    // printf("%d\n", count_sentences(book_content));
}

int read_line(char str[], int n)
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

int count_letters(char *str)
{
    int i = 0, count = 0;
    for (i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(char *str)
{
    int i = 0, count = 0;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }
    return (count + 1);
}

int count_sentences(char *str)
{
    int i = 0, count = 0;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '!' || str[i] == '.' || str[i] == '?')
        {
            count++;
        }
    }
    return count;
}
