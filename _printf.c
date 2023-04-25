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
