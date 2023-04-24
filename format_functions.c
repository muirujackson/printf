#include "main.h"

/**
 * print_char - print a char
 *
 * @arg: a list of argument pointing
 *      to the character to be printed
 *
 * Return: nothing
*/

void print_char(va_list arg)
{
	char c = va_arg(arg, int);
	if(!c)
		_putchar('\0');
	else
		_putchar(c);
}

/**
 * print_int - print an integer
 *
 * @arg: a list of argument pointing
 *      to the character to be printed
 *
 * Return: nothing
*/
void print_int(va_list arg)
{
	int num = va_arg(arg, int);
	int digit, divisor = 1;
	
	if (num < 0)
	{
		num = -num;
		_putchar('-');
	}

	if (num == 0)
	{
		_putchar('0');
		
	}

	while (num / divisor > 9)
	{
		divisor *= 10;
	}

	while (divisor != 0)
	{
		digit = num / divisor;
		_putchar(digit + '0');
		num = num % divisor;
		divisor /= 10;
	}
}


/**
 * print_string - print a string
 *
 * @arg: a list of argument pointing
 *      to the character to be printed
 *
 * Return: nothing
*/

void print_string(va_list arg)
{
	char *str = va_arg(arg, char *);
	int i = 0;

	if (!str)
	{
		_putchar('\0');
	} else {
		while (str[i])
		{
			_putchar(str[i]);
			i++;
		}
	}
}

/**
 * print_percent - print percent sign
 * @arg: percent to be printed
 *
 * Return:nothing
 */
void print_percent()
{
	_putchar(37);
}
	
