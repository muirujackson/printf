#include "main.h"

/**
 * _printf - function that produces output
 * @format: string that specify the format
 *
 * Return: int indicating total character printted
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, j = 0, k = 0;
	func_fmt funcs[] = {
		{'c', print_char},
		{'s', print_string}
	};

	va_start(ap, format);
	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			k--;
			if (format[i] == '\0')
				return (-1);
			if (format[i] == '%')
			{	_putchar(37);
				i++;
			}
			while (j < 2 && (format[i] != (funcs[j].fmt)))
				j++;
			if (j < 2)
			{
				k += funcs[j].fn(ap);
			}
		} else
		{
		_putchar(format[i]);
		i++;
		}
	}
	va_end(ap);
	return (i + k);
}
