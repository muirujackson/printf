#include "main.h"
#include <stdarg.h>

/**
 * int _printf - function that produces output
 * @format: string that specify the format
 *
 * Return: int indicating total character printted
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i, j;
	func_fmt funcs[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		{"%", print_percent}
	};




	va_start(ap, format);
	i = 0;
	while (format && format[i])
	{
		j = 0;

		if (format[i] == '%')
		{
			i++;
			/**
			 * 4 equals to the number of funcs present
			 * so if j is less than four and our current
			 * format is not equal to format in funcs
			 * then j becomes j + 1
			 */
			while (j < 5 && (format[i] != *(funcs[j].fmt)))
				j++;
			if (j < 5)
			{
				funcs[j].fn(ap);
			}
			i++;
		}
		_putchar(format[i]);
		i++;
	}
	_putchar('\n');

	va_end(ap);
	return (i);
}
