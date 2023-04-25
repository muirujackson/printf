#include "main.h"
#include <stdarg.h>

/**
 * print_helper - check the format
 * @format: the format to be printed
 * @arg: all arguments
 * @i: index
 *
 * Return: number of int printed
 */
int print_helper(const char *format, va_list arg, int i)
{
	int k = 0, j = 0;
	func_fmt funcs[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int}
	};
	while (j < 4 && (format[i + 1] != (funcs[j].fmt)))
		j++;
	if (j < 4)
	{
		k = funcs[j].fn(arg);
		return (k);
	}
	return (k);
}


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


	va_start(ap, format);
	if (format == NULL)
		return (-1);
	if (!format[i])
		return (0);
	while (format && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			i++;
			continue;
		}

		if (format[i + 1] == '\0')
			return (-1);

		if (format[i + 1] == '%')
		{
			j = j - 1;
			write(1, &format[i], 1);
			i += 2;
			continue;
		}
		k = print_helper(format, ap, i);

		if (k > 0)
		{
			i += 2;
			k -= 2;
			continue;
		}
		write(1, &format[i + i], 1);
		i +=2;
	}
	va_end(ap);
	return (i + k + j);
}

