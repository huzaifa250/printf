#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - output fucniton according to format
 * @format: character string
 *
 * Return: 0 success
 */
int _printf(const char *format, ...)
{
	int c;
	const char s;
	const char *str;
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			count++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				c  = va_arg(args, int);
				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, const char *);
				while (*str)
				{
					_putchar(*str);
					str++;
					count;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				count += 2;
			}
		}
		format++;
	}
	va_end(args);
	return (0);
}
