#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)
#define S_SHORT 1
#define S_LONG 2

int _printf(const char *format, ...);
int print_control(const char *fmt, int *i, va_list list, int size);
int arg_size(const char *format, int *i);
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

void print_buffer(char buffer[], int *buff_num);
int write_char_control(char c);
int write_number(int is_positive, int indicat, int size);


long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

int main(void);

#endif
