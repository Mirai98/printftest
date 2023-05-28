#include "main.h"

/**
 * is_printable -The evaluates if a char is printable
 * @c: The char to be evaluated
 *
 * Return: 1 if c is printable otherwise 0
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - A f that append ascci in hexadecimal code to buffer
 * @buf: The array of chars
 * @j: The Index at which to start appending.
 * @as_code: The ASSCI CODE.
 * Return: 3 Always
 */
int append_hexa_code(char as_code, char buf[], int j)
{
	char Map_to[] = "0123456789ABCDEF";

	if (as_code < 0)

		as_code *= -1;

	buf[j++] = '\\';
	buf[j++] = 'x';

	buf[j++] = Map_to[as_code / 16];
	buf[j] = Map_to[as_code % 16];

	return (3);
}

/**
 * is_digit -A f that  verifies if a char is a digit
 * @c: The char to be evaluated
 *
 * Return: 1 if c is a digit,otherwise 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number -A f that casts a number to the specified size
 * @num: The number to be casted.
 * @size: The number indicating the type to be casted.
 *
 * Return: The casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == SIZES_LONG)
		return (num);
	else if (size == SIZES_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - A f that casts a number to the specified size
 * @num: The number to be casted
 * @size: The number indicating the type to be casted
 *
 * Return: the casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == SIZES_LONG)
		return (num);
	else if (size == SIZES_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
