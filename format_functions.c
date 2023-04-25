#include "main.h"

/**
 * print_char - print a char
 *
 * @arg: a list of argument pointing
 *      to the character to be printed
 *
 * Return: nothing
*/
int print_char(va_list arg)
{
	char c = va_arg(arg, int);
	if(!c)
		return (1);
	else {
		_putchar(c);
		return (1);
	}
}

/**
 * print_int - print an integer
 *
 * @arg: a list of argument pointing
 *      to the character to be printed
 *
 * Return: nothing
*/
int print_int(va_list arg)
{
	int num = va_arg(arg, int);
	int digit, divisor = 1;
	int i = 0;

	if (num < 0)
	{
		num = -num;
		_putchar('-');
		i++;
	}

	if (num == 0)
	{
		_putchar('0');
		i++;
	}

	while (num / divisor > 9)
	{
		divisor *= 10;
	}

	while (divisor != 0)
	{
		digit = num / divisor;
		_putchar(digit + '0');
		i++;
		num = num % divisor;
		divisor /= 10;
	}
	return (i);
}


/**
 * print_string - print a string
 *
 * @arg: a list of argument pointing
 *      to the character to be printed
 *
 * Return: nothing
*/

int print_string(va_list arg)
{
	char *str = va_arg(arg, char *);
	int i = 0;

	if (str == NULL)
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		return (6);
	} else {
		while (str[i])
		{
			_putchar(str[i]);
			i++;
		}
		return (i);
	}
}
