#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);
int print_binary(unsigned int num);
int print_escaped_string(char *str);
int print_reversed_string(char *str);
int print_rot13_string(char *str);
int handle_format(char format, va_list args, int *count);

#endif /* MAIN_H */
