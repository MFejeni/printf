#include "main.h"
#include <string.h>

/**
 * put_unsigned - prints unsigned
 * @num: num to print in unsigned
 * Return: 1 for success
 */

int put_unsigned(int num)
{
        char str[16];

        sprintf(str, "%u", num);
        return (write(1, str, strlen(str)));
}

/**
 * put_Hexa - prints Hexadecimal with capital lettes
 * @num: num to print in hexadecimal
 * Return: 1 for success
 */

int put_Hexa(int num)
{
        char str[16];

        sprintf(str, "%X", num);
        return (write(1, str, strlen(str)));
}
