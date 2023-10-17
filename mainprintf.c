#include "main.h"
/**
 * _printf - output fucniton according to format
 * @format: character string
 *
 * Return: 0 success
 */
int _printf(const char *format, ...)
{
	/* initialize an array match of format specifiers and their associated fucnitons*/
	match m[] = {{"%c", printf_char}, {"%s", print_string}, {"%%", print_37}};
	va_list args;
	int i = 0, len = 0;
	int j;

	/* returns error if format is NULL or contain %only*/
	 if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		/* initialize a label for 'goto' statement. to contniue processecing after handling a specifier*/
Here:
		j = 2;/* size of array *this size will increase as we handle more task since we will be adding format specifier and thier associated functions*/
		while (j >= 0)
		{
			/*check if the current and next characters match format specifiers in the array*/
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				/*update the position and length of he correspodning printing functions*/
				len += m[j].f(args);
				i += 2;
				goto Here;
			}
			j--;
		}
		/*if no mathc found, print the charter the update the position and lenght*/
		_putchar(format[i]);
		i++;
		len++;
	}
	/*clean up args list and return number of characters printed*/
	va_end(args);
	return (len);
}
