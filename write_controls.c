#include "main.h"
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
 * @is_negative: List of arguments
 * @indicat: number to beprinted
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int indicat, int size)
{
	char neg_ch = ' ';

	UNUSED(size);

	if (is_negative)
		neg_ch = '-';

	return (write(indicat, &neg_ch, 1));
}
