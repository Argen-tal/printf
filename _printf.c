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
		{
			*count += _putchar('\\');
			*count += _putchar('0');
		}
		else
		{
			*count += _putchar(ch);
		}
	}
	else if (format == 's')
	{
		char *str = va_arg(args, char *);

		if (str == NULL)
			str = "(null)";

		*count += _puts(str);
	}
	else if (format == '%')
	{
		*count += _putchar('%');
	}
	else if (format == 'd' || format == 'i')
	{
		int num = va_arg(args, int);
		char buffer[BUFFER_SIZE];
		int length = snprintf(buffer, BUFFER_SIZE, "%d", num);

		if (length < 0)
			return (-1); /* Handle snprintf error */

		*count += length;
		if (*count > BUFFER_SIZE)
		{
			*count = -1; /* Buffer overflow */
			return (*count);
		}

		*count += _puts(buffer);
	}
	else
	{
		*count += (_putchar('%') + _putchar(format));
	}

	return (*count);
}

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
			if (count == -1) /* Handle errors from handle_format */
				return (-1);
		}
	}
	va_end(args);

	return (count);
}

