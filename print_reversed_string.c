#include "main.h"
/**
 * print_reversed_string - prints a string in reverse.
 * @str: string to be printed
 */
int print_reversed_string(char *str)
{
    int count = 0;
    int length = 0;
    char *end = str;
    int i;

    /* Find the length of the string */
    while (*end)
    {
        length++;
        end++;
    }

    /* Print the string in reverse order */                                                 for (i = length - 1; i >= 0; i--)
    {
        count += _putchar(str[i]);
    }

    return count;
}
