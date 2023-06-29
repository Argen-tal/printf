#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * handle_integers - Handles the 'd' and 'i' format specifier in _printf.
 * @args: The va_list arguments.
 * @count: Pointer to the count of characters printed.
 *
 * Return: The updated count of characters printed.
 */
int handle_integers(va_list args, int *count)
{
        int len;
        char *buffer;

        va_list args_copy;
        va_copy(args_copy, args);
        len = vsnprintf(NULL, 0, "%d", args_copy);
        va_end(args_copy);

        buffer = malloc(len + 1);
        if (buffer == NULL)
                return -1;

        vsprintf(buffer, "%d", args);

        *count += _puts(buffer);
        free(buffer);

        return (*count);
}

