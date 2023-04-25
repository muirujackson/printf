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
	if (!c)
		return (-1);
	_putchar(c);
	return (1);
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
	int count = 0;

	while(num != 0)
	{
		num /= 10;
		count++;
	}


	int digit, divisor = 1;
	
	if (num < 0)
	{
		num = -num;
		_putchar('-');
		count++;
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
	return (count);
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
	int i = 0; j = 0;

	while(str[j])
		j++;

	if (str == NULL)
	{
		write(1, &"(null)", 6);
		return (6);
	}
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i - 1);

