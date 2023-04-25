#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>



/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 *
 */
typedef struct fmt
{
	char *fmt;
	int (*fn)(va_list arg);
} func_fmt;

int _putchar(char c);
int _printf(const char *format, ...);
int print_string(va_list arg);
int print_int(va_list arg);
int print_char(va_list arg);
#endif
