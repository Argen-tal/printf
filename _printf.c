#include "main.h"

/**
 * _printf - the function prints string literals to stdo.
 * @format: specific type of character to be printed.
 *
 * Return: 0
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;  /* Number of characters printed */
    char buffer[BUFFER_SIZE];  /* Local buffer for efficient printing */
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
            i++;  /* Skip the '%' */

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
                    count += sprintf(buffer, "%d", va_arg(args, int));
                    count += _puts(buffer);
                    break;

                case 'u':
                    /* Print an unsigned decimal integer */
                    count += sprintf(buffer, "%u", va_arg(args, unsigned int));
                    count += _puts(buffer);
                    break;

                case 'o':
                    /* Print an octal integer */
                    count += sprintf(buffer, "%o", va_arg(args, unsigned int));
                    count += _puts(buffer);
                    break;

                case 'x':
                    /* Print a hexadecimal integer (lowercase) */
                    count += sprintf(buffer, "%x", va_arg(args, unsigned int));
                    count += _puts(buffer);
                    break;

                case 'X':
                    /* Print a hexadecimal integer (uppercase) */
                    count += sprintf(buffer, "%X", va_arg(args, unsigned int));
                    count += _puts(buffer);
                    break;

                case 'b':
                    /* Print an unsigned integer in binary format */
                    count += print_binary(va_arg(args, unsigned int));
                    break;

                case 'S':
                    /* Print a string with non-printable characters escaped */
                    count += print_escaped_string(va_arg(args, char *));
                    break;
                case 'p':
                    /* Print a pointer address */
                    count += sprintf(buffer, "%p", va_arg(args, void *));
                    count += _puts(buffer);
                    break;

                case 'r':
                    /* Print a reversed string */
                    count += print_reversed_string(va_arg(args, char *));
                    break;

                case 'R':
                    /* Print a ROT13 encoded string */
                    count += print_rot13_string(va_arg(args, char *));
                    break;

                default:
                    /* Invalid conversion specifier, ignore */
                    break;
			}
		}
	}
	va_end(args);

	return count;
}
