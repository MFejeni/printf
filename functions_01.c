#include "main.h"
#include <string.h>

/**
 * convert_size_number - Casts a number to S_LONG or S_SHORT
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * print_hex - prints hexadecimal handled by x
 * @types: arguments to be printed
 * @size: size of args may be ignored
 * Return: number of hex printed
 */

int print_hex(va_list types, int size)
{
	unsigned int n = va_arg(types, unsigned int);

	UNUSED(size);

	return (put_hex(n));
}


/**
 * print_octal - prints octal handled by o
 * @types: arguments to be printed
 * @size: size of args may be ignored
 * Return: number of octal printed
 */

int print_octal(va_list types, int size)
{       
        unsigned int n = va_arg(types, unsigned int);

        UNUSED(size);

        return (put_octal(n));
}

/**
 * print_unsigned - prints unsigned int handled by u
 * @types: arguments to be printed
 * @size: size of args may be ignored
 * Return: number of unsigned printed
 */

int print_unsigned(va_list types, int size)
{
        unsigned int n = va_arg(types, unsigned int);

        UNUSED(size);

        return (put_unsigned(n));
}

/**
 * print_Hexa - prints hexadecimal handled by X
 * @types: arguments to be printed
 * @size: size of args may be ignored
 * Return: number of hex printed
 */

int print_Hexa(va_list types, int size)
{
        unsigned int n = va_arg(types, unsigned int);

        UNUSED(size);

        return (put_Hexa(n));
}
