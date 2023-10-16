#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
typedef struct format
{
	char *id;
	int (*f)();
} match;

int _printf(const char *format, ...);
int _putchar(char c);
int printf_char(va_list val);
int print_string(va_list val);
int print_37(void);
int _strlen(char *str);
int _strlenc(const char *str);

#endif
