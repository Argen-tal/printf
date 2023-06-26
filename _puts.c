/**
 * _puts - prints a string
 * @str: string to be printed.
 *
 * Return: count
 */
#include "main.h"

int _puts(char *str)
{
	int count = 0;

	while (*str)
	{
		count += _putchar(*str);
		str++;
	}
	return (count);
}
