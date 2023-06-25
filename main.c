#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    printf("Expected: %d, Actual: %d\n", len2, len);
    printf("\n");

    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    
    len = _printf("Length: %d\n", len);
    len2 = printf("Length: %d\n", len2);
    printf("Expected: %d, Actual: %d\n", len2, len);
    printf("\n");

    len = _printf("Negative numbers: %d, %d, %d\n", -762534, 0, -123456789);
    len2 = printf("Negative numbers: %d, %d, %d\n", -762534, 0, -123456789);
    printf("Expected: %d, Actual: %d\n", len2, len);
    printf("\n");

    len = _printf("Unsigned integers: %u, %u, %u\n", ui, 0, UINT_MAX);
    len2 = printf("Unsigned integers: %u, %u, %u\n", ui, 0, UINT_MAX);
    printf("Expected: %d, Actual: %d\n", len2, len);
    printf("\n");

    len = _printf("Unsigned octal: %o\n", ui);
    len2 = printf("Unsigned octal: %o\n", ui);
    printf("Expected: %d, Actual: %d\n", len2, len);
    printf("\n");

    len = _printf("Unsigned hexadecimal: %x, %X\n", ui, ui);
    len2 = printf("Unsigned hexadecimal: %x, %X\n", ui, ui);
    printf("Expected: %d, Actual: %d\n", len2, len);
    printf("\n");

    len = _printf("Characters: %c, %c, %c\n", 'H', 'e', 'y');
    len2 = printf("Characters: %c, %c, %c\n", 'H', 'e', 'y');
    printf("Expected: %d, Actual: %d\n", len2, len);
    printf("\n");

    len = _printf("Strings: %s, %s\n", "Hello", "World!");
    len2 = printf("Strings: %s, %s\n", "Hello", "World!");
    printf("Expected: %d, Actual: %d\n", len2, len);
    printf("\n");

    len = _printf("Addresses: %p, %p\n", addr, NULL);
    len2 = printf("Addresses: %p, %p\n", addr, NULL);
    printf("Expected: %d, Actual: %d\n", len2, len);
    printf("\n");

    len = _printf("Percent: %%\n");
    len2 = printf("Percent: %%\n");
    printf("Expected: %d, Actual: %d\n", len2, len);
    printf("\n");

    len = _printf("Unknown specifier: %r\n");
    len2 = _printf("Unknown specifier: %r\n");
    printf("Expected: %d, Actual: %d\n", len2, len);
    printf("\n");

    return (0);
}

