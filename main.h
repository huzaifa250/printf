#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef struct format
{
	char *id;
	int (*f)();
} match;

int _printf(const char *format, ...);
int _putchar(char c);
int print_string(va_list val);
int _strlen(char *str);
int _strlenc(const char *str);
int printf_char(va_list val);
int print_37(void);
int print_int(va_list args);
int print_dec(va_list args);
int print_bin(va_list val);

#endif
