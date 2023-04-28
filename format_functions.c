#include "main.h"
/**
 * int_to_bin - print a char
 *
 * @arg: a list of argument pointing
 *      to the character to be printed
 *
 * Return: nothing
*/
int int_to_bin(va_list arg)
{
	int num = va_arg(arg, int);
	int binary[32];
	int index = 0;
	int i;

	if (num < 0)
		return (-1);
	while (num > 0)
	{
		binary[index++] = num % 2;
		num /= 2;
	}

	for (i = index - 1; i >= 0; i--)
	{
		char b = binary[i] + '0';

		write(1, &b, 1);
	}
	return (index - 1);
}
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

	write(1, &c, 1);
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
	int n = num;
	int count = 0;
	int digit, divisor = 1;
	char p;

	while (n != 0)
	{
		n /= 10;
		count++;
	}

	if (num < 0)
	{
		num = -num;

		write(1, "-", 1);
		count++;
	}

	if (num == 0)
	{
		write(1, "0", 1);

	}

	while (num / divisor > 9)
	{
		divisor *= 10;
	}

	while (divisor != 0)
	{
		digit = num / divisor;
		p = digit + '0';
		write(1, &p, 1);
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

int print_string(va_list arg)
{
	char *str = va_arg(arg, char *);
	int i = 0;

	if (str == NULL)
	{
		write(1, &"(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

