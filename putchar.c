#include "main.h"

int _putchar(char c)
{
   return write(1, &c, 1);
}

int _puts(char *str)
{
    int count = 0;
    while (*str)
    {
        count += _putchar(*str);
        str++;
    }
    return count;
}
