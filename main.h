#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);
int print_binary(unsigned int num);
int print_escaped_string(char *str);
int print_reversed_string(char *str);
int print_rot13_string(char *str);

#endif /* MAIN_H */
