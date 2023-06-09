#include "main.h"
/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, int size)
{
	char c = va_arg(types, int);

	UNUSED(size);
	return (write_char_control(c));
}
/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, int size)
{
	int length = 0;
	char *str = va_arg(types, char *);

	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
	}

	while (str[length] != '\0')
		length++;

	return (write(1, str, length));
}

/**
 * print_percent - Prints a percent sign
 * @types: List of arguments
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, int size)
{
	UNUSED(types);
	UNUSED(size);

	return (write(1, "%%", 1));
}

/**
 * print_int - Prints an int given as parameter
 * @types: List of arguments
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_int(va_list types, int size)
{

	long int n = va_arg(types, long int);

	n = convert_size_number(n, size);


	return (write_number(n, sizeof(long int)));
}

/**
 * print_binary - Prints an unsigned number
 * @types: List of arguments
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(size);
	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

