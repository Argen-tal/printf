#include "main.h"

/**
 * _printf - the function prints string literals to stdo.
 * @format: specific type of character to be printed.
 * % - Regular character, print it directly, and Print a literal '%'
 * case c - Print a character.
 * case s - Print a string.
 * case d and i - print a decimal integer.
 * default - Unknown conversion specifier, print it.
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0; /* Number of characters printed */
    int i;

    if (format == NULL)
        return (-1);

    va_start(args, format);
    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            count += _putchar(format[i]);
        }
        else
        {
            i++; /* Skip the '%' */

            /* Check the conversion specifier */
            switch (format[i])
            {
                case 'c':
                    count += _putchar(va_arg(args, int));
                    break;
                case 's':
                    {
                        char *str = va_arg(args, char *);
                        if (str == NULL)
                            str = "(null)"; /* Handle NULL strings */
                        count += _puts(str);
                    }
                    break;
                case '%':
                    count += _putchar('%');
                    break;
                case 'd':
		case 'i':
		    {
        		int num = va_arg(args, int);
        		char buffer[BUFFER_SIZE];
        		int length = snprintf(buffer, BUFFER_SIZE, "%d", num);
        		count += _puts(buffer);
        		count += length;
		    }
		    break;
                default:
                    count += _putchar('%');
                    count += _putchar(format[i]);
                    break;
            }
        }
    }
    va_end(args);
    return count;
}

