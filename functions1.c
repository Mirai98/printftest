#include "main.h"

/** UNSIGNED NUMBER **/
/**
 * print_unsigned - A f that prints an unsigned number
 * @ap: The list of arguments
 * @buf: The buffer array to handle print
 * @flag:  To calculates active flags
 * @wid: width.
 * @preci: The precision specification
 * @size: The size specifier
*
 * Return: The number of chars printed
 */
int print_int(va_list ap, char buf[],
		int flag, int wid, int preci, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int n = va_arg(ap, unsigned long int);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buf[j--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buf[j--] = (n % 10) + '0';
		n /= 10;
	}

	j++;

	return (write_unsgnd(0, j, buf, flag, wid, preci, size));
}

/** UNSIGNED NUMBER IN OCTAL **/
/**
 * print_octal - A f that prints an unsigned number in octal notation
 * @ap: The list of arguments
 * @buf: The buffer array to handle print
 * @flag:  To calculates active flags
 * @wid: width.
 * @preci: The precision specification
 * @size: The size specifier
*
 * Return: The number of chars printed
 */
int print_octal(va_list ap, char buf[],
	int flag, int wid, int preci, int size)
{

	int j = BUFF_SIZE - 2;
	unsigned long int n = va_arg(ap, unsigned long int);
	unsigned long int init_n = n;

	UNUSED(wid);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buf[j--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buf[j--] = (n % 8) + '0';
		n /= 8;
	}

	if (flag & F_HASH && init_n != 0)
		buf[j--] = '0';

	j++;

	return (write_unsgnd(0, j, buf, flag, wid, preci, size));
}

/** UNSIGNED NUMBER IN HEXADECIMAL **/
/**
 * print_hexadecimal - A f that prints an unsigned number
 *in hexadecimal notation
  * @ap: The list of arguments
 * @buf: The buffer array to handle print
 * @flag:  To calculates active flags
 * @wid: width.
 * @preci: The precision specification
 * @size: The size specifier
*
 * Return: The number of chars printed
 **/
int print_hexadecimal(va_list ap, char buf[],
	int flag, int wid, int preci, int size)
{
	return (print_hexa(types, "0123456789abcdef", buf,
		flag, 'x', wid, preci, size));
}
/** UNSIGNED NUMBER IN UPPER HEXADECIMAL **/
/**
* print_hexadecimal - A f that prints an unsigned number
*in upper hexadecimal notation
  * @ap: The list of arguments
 * @buf: The buffer array to handle print
 * @flag:  To calculates active flags
 * @wid: width.
 * @preci: The precision specification
 * @size: The size specifier
*
 * Return: The number of chars printed
 **/
int print_hexa_upper(va_list ap, char buf[],
	int flag, int wid, int preci, int size)
{
	return (print_hexa(ap, "0123456789ABCDEF", buf,
		flag, 'X', wid, preci, size));
}
/**  HEXX NUM IN LOWER OR UPPER  **/
/**
 * print_hexa - A f that prints a hexadecimal number in lower or upper
 * @ap: The list of arguments
 * @map_t: The array of values to map the number to
 * @buf: the buffer array to handle print
 * @flag:  To calculates active flags
 * @flag_2: To calculates active flags
 * @wid: width
 * @preci: The precision specification
 * @size: The Size specifier
*
 * Return: The number of chars printed
 **/
int print_hexa(va_list ap, char map_t[],
	char buf[], int flag, char flag_2, int wid, int preci, int size);
{
	int j = BUFF_SIZE - 2;
	unsigned long int n = va_arg(ap, unsigned long int);
	unsigned long int init_n = n;

	UNUSED(wid);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buf[j--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buf[j--] = map_to[n % 16];
		n /= 16;
	}

	if (flag & FLAGS_HASH && init_n != 0)
	{
		buf[j--] = flag_2;
		buf[j--] = '0';
	}

	j++;

	return (write_unsgnd(0, j, buf, flag, wid, preci, size));
}
