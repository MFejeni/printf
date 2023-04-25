#include "main.h"
/**
 * write_char_control - Prints a string as given in form of char
 * @c: char to be printed
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_char_control(char c)
{ 
	return (write(1,&c, 1));
}

/**
 * write_number - Prints a string
 * @is_negative: List of arguments
 * @indicat: char types.
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int indicat, int size)
{
	int length = BUFF_SIZE - indicat - 1;
	char extra_ch = 0;

	UNUSED(size);

	if (is_negative)
		extra_ch = '-';

	return (write(1, &extra_ch, indicat));
}
