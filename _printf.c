#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

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
            switch (format[i])                                                                       {
                case 'c':
                    /* Print a character */
                    count += _putchar(va_arg(args, int));
                    break;
                case 's':
<<<<<<< HEAD
                    /* Print a string */
                    {
                        char *str = va_arg(args, char *);
                        if (str == NULL)
                            str = "(null)"; /* Handle NULL strings */
                        count += _puts(str);
                    }
=======
                    /* Print a string */                                                                     count += _puts(va_arg(args, char *));
>>>>>>> ca231abf8a3eaefd93e9fc024e43c47f84b73cf1
                    break;
                case '%':
                    /* Print a literal '%' */
                    count += _putchar('%');
                    break;
                case 'd':
                case 'i':
                    /* Print a decimal integer */
                    {
                        int num = va_arg(args, int);                                                             int length = snprintf(buffer, BUFFER_SIZE, "%d", num);
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
    return count;
}
