<<<<<<< HEAD
#include "main.h"

/**
 * _printf - the function prints string literals to stdo.
 * @format: specific type of character to be printed.
 *
 * Return: 0
 */
=======
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

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

>>>>>>> 611ec37b66f5a6f006cbe6718f7a17fac1ecf8ad
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0; /* Number of characters printed */
    char buffer[BUFFER_SIZE]; /* Local buffer for efficient printing */
    int i;

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            /* Regular character, print it directly */
            count += _putchar(format[i]);
        }
        else
        {
            i++; /* Skip the '%' */

            /* Check the conversion specifier */
            switch (format[i])
            {
                case 'c':
                    /* Print a character */
                    count += _putchar(va_arg(args, int));
                    break;
                case 's':
                    /* Print a string */
                    count += _puts(va_arg(args, char *));
                    break;

                case '%':
                    /* Print a literal '%' */
                    count += _putchar('%');
break;

                case 'd':
                case 'i':
                    /* Print a decimal integer */
                    {
                        int num = va_arg(args, int);
                        int length = snprintf(buffer, BUFFER_SIZE, "%d", num);
                        count += _puts(buffer);
                        count += length;
                    }
                    break;

                default:
                    /* Invalid conversion specifier, ignore */
                    count += _putchar('%');
                    count += _putchar(format[i]);
                    break;
			}
		}
	}
	va_end(args);

