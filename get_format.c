#include "main.h"

/**
 * get_format - check the format and print
 * @format: the format to check
 * @i: count
 * @k: count
 * @arg: argument
 *
 * Return: nothing
 */
void get_format(const char *format, int *i, int *k, va_list arg)
{
	int j = 0;
	func_fmt funcs[] = {
		{'c', print_char},
		{'s', print_string}
	};

	while (j < 2 && (format[*i + 1] != (funcs[j].fmt)))
		j++;
	if (j < 2)
	{
		*k += funcs[j].fn(arg);
		*i +=  2;
		return;
	}
	_putchar(format[*i]);
	_putchar(format[*i + 1]);
	*i += 2;
}

