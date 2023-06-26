#include "main.h"
/**
 * print_rot13_string - rotates characters from N to z and prints non alphabetic
 * chaeacters directly.
 * @str: srring to be rotatwd.
 */
int print_rot13_string(char *str)
{
    int count = 0;
    while (*str)
    {
        if ((*str >= 'A' && *str <= 'M') || (*str >= 'a' && *str <= 'm'))
        {
            /* Rotate characters from A to M */
            count += _putchar(*str + 13);
        }
        else if ((*str >= 'N' && *str <= 'Z') || (*str >= 'n' && *str <= 'z'))
        {
            /* Rotate characters from N to Z */
            count += _putchar(*str - 13);
        }
        else
        {
            /* Non-alphabetic character, print it directly */
            count += _putchar(*str);
        }
        str++;
    }                                                                                       return count;
}
