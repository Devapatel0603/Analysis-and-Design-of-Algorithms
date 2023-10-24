#include <stdio.h>
#include <string.h>
#define q 101
unsigned long long customPow(int base, int exponent)
{
    unsigned long long result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result = (result * base) % q;
    }
    return result;
}
unsigned long long hash(char str[], int len)
{
    unsigned long long h = 0;
    for (int i = 0; i < len; i++)
    {
        h = (h * q + str[i]) % q;
    }
    return h;
}
int main()
{
    int tl, pl;
    printf("Enter length of text: ");
    scanf("%d", &tl);
    printf("Enter length of pattern: ");
    scanf("%d", &pl);
    char text[tl];
    char pattern[pl];
    printf("Text: ");
    for (int i = 0; i < tl; i++)
        scanf(" %c", &text[i]);
    printf("Pattern: ");
    for (int i = 0; i < pl; i++)
        scanf(" %c", &pattern[i]);
    unsigned long long patternHash = hash(pattern, pl);
    unsigned long long textHash = hash(text, pl);
    for (int i = 0; i <= tl - pl; i++)
    {
        if (textHash == patternHash)
        {
            int j;
            for (j = 0; j < pl; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == pl)
            {
                printf("Pattern found at index %d\n", i);
            }
        }
        if (i < tl - pl)
        {
            textHash = (q * (textHash - text[i] * customPow(q, pl - 1)) + text[i + pl]) % q;
        }
    }
    return 0;
}