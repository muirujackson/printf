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
	while (format && format[i])
	{

		if (!(format[i] == '%'))
		{
			_putchar(format[i]);
			i++;
			continue;
		}
		if (format[i + 1] == '\0')
			return (-1);
		if (format[i + 1] == '%')
		{
			_putchar(format[i + 1]);
			i += 2;
			continue;
		}
		while (j < 2 && (format[i + 1] != (funcs[j].fmt)))
				j++;
			if (j < 2)
			{
				k += funcs[j].fn(ap);
				i += 2;
				continue;
			} 
			
		_putchar(format[i]);
		_putchar(format[i + 1]);
		i += 2;
	}
	va_end(ap);
	return (i + k);
}
