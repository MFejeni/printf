#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define BUFF_SIZE 1024
#define UNUSED(x) void (x)


int _printf(const char *format, ...);
int print_control(const char *fmt, int *i, va_list list, int size);

/**
 * struct fmt - Struct op
 *
 * @fmt: Format.
 * @fn: Function associated.
 */
typedef struct fmt
{
	char fmt;
	int (*fn)(va_list, int);
} fmt_t;



int print_char(va_list types, int size);
int print_string(va_list types, int size);
int print_percent(va_list types, int size);


int print_int(va_list types, int size);
int print_binary(va_list types, int size);


int write_char_control(char c, int size);
int write_number(int is_positive, int indicat, int size);


long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
