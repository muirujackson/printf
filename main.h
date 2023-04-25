#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stddef.h>

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 *
 */
struct fmtt
{
	char fmt;
	int (*fn)(va_list arg);
}; 

typedef struct fmtt func_fmt;

int _putchar(char c);
int _printf(const char *format, ...);
int print_string(va_list arg);
int print_char(va_list arg);

#endif
