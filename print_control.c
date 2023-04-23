#include "main.h"
/**
 * print_control - Prints type specified
 * @fmt: Formatted string to be printed
 * @list: List of arguments to be printed.
 * @indicat: indicat.
 * @size: Size specifier
 * Return: 1 or 2;
 */
int print_control(const char *fmt, int *indicat, va_list list, int size)
{
	int i, len = 0, printed_chars = -1;

	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*indicat] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*indicat] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (fmt[*indicat - 1] == ' ')
			len += write(1, " ", 1);
		len += write(1, &fmt[*indicat], 1);
		return (len);
	}
	return (printed_chars);
}
