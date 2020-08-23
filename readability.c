#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int letters = 0;
int words = 1;
int other = 0;
int total = 0;
int sentences = 0;

int main(void)
{
    // gets text from user
    string t = get_string("Text: ");
    // Counts the amount of letters, sentences, and  words in text
    for (total = 0; total < strlen(t); total++)
    {
        if (isalnum(t[total]))
        {
            letters = (letters + 1);
        }
        else if (isblank(t[total]))
        {
            words = (words + 1);
        }
        else if ((t[total]) == '.' || t[total] == '!' || t[total] == '?')
        {
            sentences = sentences + 1;
        }
        else if (ispunct(t[total]))
        {
            other = (other + 1);
        }
    }
    // finds the average of letters per 100 words "L"
    float L = ((float)letters / words) * 100;
    // finds the average number of sentences per 100 words "S"
    float S = ((float)sentences / words) * 100;
    //Calculates Grade
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    // If statement for printing above grade 16, before grade 1, or grade
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 1 && index < 16)
    {
        printf("Grade %.0f\n", index);
    }
    else if (index >= 16.5)
    {
        printf("Grade 16+\n");
    }
}
