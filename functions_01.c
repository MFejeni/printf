#include "main.h"

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
