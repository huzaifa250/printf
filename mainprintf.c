#include "main.h"
/**
 * _printf - output fucniton according to format
 * @format: character string
 *
 * Return: 0 success
 */
int _printf(const char *format, ...)
{
	match m[] = {{"%s", print_string}, {"%c", printf_char}, {"%%", print_37}};
	va_list args;
	int i = 0, len = 0;
	int j;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);
Here:
	while (format[i] != '\0')
	{
		j = 2;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len += m[j].f(args);
				i += 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		i++;
		len++;
	}
	va_end(args);
	return (len);
}
