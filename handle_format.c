#include "main.h"

/**
 * handle_format - Handles the format specifier in _printf.
 * @format: The format specifier character.
 * @args: The va_list arguments.
 * @count: Pointer to the count of characters printed.
 *
 * Return: The updated count of characters printed.
 */
int handle_format(char format, va_list args, int *count)
{

	if (format == 'c')
	{
		char ch = (char)va_arg(args, int);

		if (ch == '\0')
			*count += _putchar('\0');
		else
			*count += _putchar(ch);
	}
	else if (format == 's')
	{
		char *str = va_arg(args, char *);

		if (str == NULL)
			str = "(null)";
		*count += _puts(str);
	}
	else if (format == '%')
		*count += _putchar('%');
	else if (format == 'd' || format == 'i')
	{	
		*count += handle_integers(args, count);
	}
	else
		*count += (_putchar('%') + _putchar(format));

	return (*count);
}
