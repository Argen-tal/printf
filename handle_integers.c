#include "main.h"
#include <stdio.h>
#include <stdbool.h>

/**
 * handle_integer_special_cases - Handles special cases for integers.
 * @num: The integer value.
 * @count: Pointer to the count of characters printed.
 *
 * Return: True if a special case was handled, false otherwise.
 */
int handle_integer_special_cases(int num, int *count)
{
    if (num == INT_MAX)
    {
        *count += _puts("INT_MAX");
        return 0;
    }
    else if (num == INT_MIN)
    {
        *count += _puts("INT_MIN");
        return 0;
    }
    else if (num == 0)
    {
        *count += _puts("0");
        return 0;
    }
    else if (num == 0)
    {
        *count += _puts("(null)");
        return 0;
    }

    return 1;
}

