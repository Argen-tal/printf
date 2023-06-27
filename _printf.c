#include "main.h"
/**
 * _printf - Prints string literals to stdout.
 * @format: Specific type of character to be printed.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
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
			i++;
			if (format[i] == '\0')
				return (-1);

			count = handle_format(format[i], args, &count);
		}
	}
	va_end(args);
	return (count);
}
