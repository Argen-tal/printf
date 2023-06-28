#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
  * handle_integers - Handles integers in _printf
  * @format: the format specifier
  * @args: the va_list arguments.
  *
  * Return: the updated count.
  */
int handle_integers(char format, va_list args)
{
int count = 0;
char buffer[BUFFER_SIZE];
int bufferIndex = 0;
int i;
int j;

for (i = 0; format[i] != '\0'; ++i)
{
if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
{
int num = va_arg(args, int);

if (num < 0)
{
buffer[bufferIndex++] = '-';
num = -num;
}

if (num == 0)
{
buffer[bufferIndex++] = '0';
}

else
{
int reversedNumIndex = 0;
int reversedNum[BUFFER_SIZE];

while (num > 0)
{
reversedNum[reversedNumIndex++] = num % 10;
num /= 10;
}

while (reversedNumIndex > 0) 
{
buffer[bufferIndex++] = '0' + reversedNum[--reversedNumIndex];
}
}

++count;

++i;
}
else
{
buffer[bufferIndex++] = format[i];
}

if (bufferIndex >= BUFFER_SIZE - 1 || format[i + 1] == '\0') 
{
	buffer[bufferIndex] = '\0';
	for (j = 0; buffer[j] != '\0'; j++) 
	{
		_putchar(buffer[j]);
	}
	bufferIndex = 0;
}
}

return (count);
}
