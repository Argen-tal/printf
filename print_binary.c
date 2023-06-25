#include "main.h"
/**
 * print binary - prints binary form of integers
 * @num: number to ve converted.
 *
 * Return: count
 */
int print_binary(unsigned int num)
{
    int count = 0;
    int i = 0;
    int j;
    char buffer[BUFFER_SIZE];

    if (num == 0)
    {
        count += _putchar('0');
    }
    else
    {
        while (num > 0)
        {
            buffer[i++] = num % 2 + '0';
            num /= 2;
        }

        for (j = i - 1; j >= 0; j--)
        {
            count += _putchar(buffer[j]);
        }
    }

    return count;
}
