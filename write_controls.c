#include "main.h"
#include <string.h>

/**
 * write_char_control - Prints a string as given in form of char
 * @c: char to be printed
 *
 * Return: Number of chars printed.
 */
int write_char_control(char c)
{
	return (write(1, &c, 1));
}

/**
 * write_number - Prints a string
 * @number: number to beprinted
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int number, int size)
{
	UNUSED(size);
	return (put_num(number));
}

/**
 * put_num - tries to print numbers
 * @num: num to print
 * Return: 1 for success
 */

int put_num(int num)
{
	char str[16];

	sprintf(str, "%d", num);
	return (write(1, str, strlen(str)));
}
