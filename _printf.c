#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#include "main.h"

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

int _printf(const char *format, ...)
{
  va_list args;
  int count = 0;
  char buffer[BUFFER_SIZE];
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
      i++;

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
          /* Print an integer in decimal format */
          count += sprintf(buffer, "%d", va_arg(args, int));
          count += _puts(buffer);
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
