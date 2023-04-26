#include "main.h"

/**
 * print_helper - check the format
 * @format: the format to be printed
 * @arg: argumnets
 * @i: int
 *
 * Return: number of int printed
 */
void print_helper(const char *format, va_list arg, int *pos, int *num_printed)
{
	int j = 0;
	func_fmt funcs[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'b', int_to_bin}
		};

	while (j < 5 && (format[(*pos) + 1] != (funcs[j].fmt)))
		j++;
	if (j < 5)
	{
		(*num_printed) += funcs[j].fn(arg);
	}
	write(1, &format[*pos], 1);
	(*num_printed)++;
	(*pos)++;
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
	int pos = 0, num_printed = 0;


	va_start(ap, format);
	if (format == NULL)
		return (-1);

	while (format && format[pos] != '\0')
	{
		if (format[pos] != '%')
		{
			write(1, &format[pos], 1);
			pos++;
			num_printed++;
			continue;
		}

		if (format[pos + 1] == '\0')
			return (-1);

		if (format[pos + 1] == '%')
		{
			write(1, "%", 1);
			pos += 2;
			num_printed++;
			continue;
		}
		print_helper(format, ap,&pos, &num_printed);
	}
	va_end(ap);
	return (num_printed);
}

