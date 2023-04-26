#include "main.h"

/**
 * print_helper - check the format
 * @format: the format to be printed
 * @arg: argumnets
 * @i: int
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
		{'i', print_int},
		{'b', int_to_bin}
		};

	while (j < 5 && (format[i + 1] != (funcs[j].fmt)))
		j++;
	if (j < 5)
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
	if (format == NULL)
		return -1;

	va_list ap;
	va_start(ap, format);

	int pos = 0, num_printed = 0;
	while (format[pos] != '\0')
	{
		if (format[pos] != '%')
		{
			write(1, &format[pos], 1);
			num_printed++;
			pos++;
		} else
		{
		    if (format[pos + 1] == '\0')
                return (-1);
            else if (format[pos + 1] == '%')
            {
                write(1, "%", 1);
                num_printed++;
                pos += 2;
            } else if (format[pos + 1] == 'c')
            {
                char c = va_arg(ap, int);
                write(1, &c, 1);
                num_printed++;
                pos += 2;
            } else if (format[pos + 1] == 's')
            {
                char *str = va_arg(ap, char *);
                int i = 0;

                if (str == NULL)
                {
                    write(1, &"(null)", 6);
                    return (6);
                }
                while (str[i])
                {
                    write(1, &str[i], 1);
                    i++;
                }
                pos += 2;
                num_printed += (i - 1);
            } else
            {
                write(1, &format[pos], 1);
                write(1, &format[pos + 1], 1);
                pos += 2;
                num_printed += 2;
            }
		}
	}
	va_end(ap);
	return (num_printed);
}
