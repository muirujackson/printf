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
	int i = 0, k = 0;

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
		get_format(format, &i, &k, ap);
	}
	va_end(ap);
	return (i + k);
}
