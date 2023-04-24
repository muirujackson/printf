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
	int n = va_arg(arg, int);

	if (n == 0)
		putchar('0');
	else
		int_helper(n);
}

/**
 * int_helper - check test cases
 * @num: number to be printed
 *
 * Return: nothing
 */
void int_helper(int num)
{
	if (num < 0)
	{
		putchar('-');
		num = -num;
	}
	if (num == 0)
	{
		return;
	}
	int_helper(num / 10);
	putchar((num % 10) + '0');
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

	if (str == NULL)
	{
		return;
	}
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
