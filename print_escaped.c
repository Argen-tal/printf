#include "main.h"
/**
 * print_escaped_strings: checks for none printable characters
 * @str: strinf to be checked.
 */
int print_escaped_string(char *str)
{
    int count = 0;
    while (*str)
    {
        if (*str < ' ' || *str >= 127)
        {
            /* Non-printable character, escape it */
            count += _putchar('\\');
            count += _putchar('x');
            count += _putchar((*str >> 4) + '0');
            count += _putchar((*str & 0x0F) + '0');
        }
        else
        {
            /* Printable character, print it directly */
            count += _putchar(*str);
        }
        str++;
    }
    return count;
}
