#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 *
 */
typedef struct fmt
{
	char fmt;
	void (*fn)(va_list arg);
} func_fmt;

int print_helper(const char *format, va_list arg);
int _putchar(char c);
int _printf(const char *format, ...);
void print_string(va_list arg);
void print_int(va_list arg);
void print_char(va_list arg);
void int_helper(int n);
void print_percent();
#endif
