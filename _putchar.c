/**
 * _putchar - prints a character.
 * @c: character to be printed.
 *
 * Return: write, 1 address of c
 */
#include "main.h"

int _putchar(char c)
{
	return (write(1, &c, 1));
}
