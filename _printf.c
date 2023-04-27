#include "main.h"

/**
 * _printf - printf function prints with some limitations
 * @format: format of string to be printed
 * Return: printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int size, buff_num = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_num++] = format[i];
			if (buff_num == BUFF_SIZE)
				print_buffer(buffer, &buff_num);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_num);

			++i;
			size = arg_size(format, &i);
			printed = print_control(format, &i, list, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_num);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints something if there is one
 * @buffer: Array of  charactors
 * @buff_num:  represents the length
 */
void print_buffer(char buffer[], int *buff_num)
{
	if (*buff_num > 0)
		write(1, &buffer[0], *buff_num);

	*buff_num = 0;
}

#include "main.h"

/**
 * arg_size -  calculates the size of the argument
 * @format: Formatted string int which to print the argument
 * @i: list  to be printed
 * Return: size required to proceed
 */
int arg_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
