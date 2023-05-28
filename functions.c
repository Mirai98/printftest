#include "main.h"
/** CHAR **/

/**
 * print_char - A f to prints a char
 * @ap: The List a of arguments
 * @buf: The Buffer array to handle print
 * @flag:  To calculates active flags
 * @wid: Width
 * @preci: The precision specification
 * @size: The size specifier
 * Return: number of chars to be printed
 */

int print_char(va_list ap, char buf[],
int flag, int wid, int preci, int size)
{
	char ch_ar = va_arg(ap, int);

	return (handle_write_char(ch_ar, buf, flag, wid, preci, size));
}

/**STRING**/

/**
 * print_string - A f that prints a string
 * @ap: The list a of arguments
 * @buf: The buffer array to handle print
 * @flag:  To calculates active flags
 * @wid: width.
 * @preci: Precision specification
 * @size: The size specifier
*
* Return: The number of chars to be printed
 */
int print_string(va_list ap, char buf[],
	int flag, int wid, int preci, int size)
{
	int len = 0;
int j;
	char *st_r = va_arg(ap, char *);

	UNUSED(buf);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(preci);
	UNUSED(size);
	if (st_r == NULL)
	{
		st_r = "(null)";
		if (preci >= 6)
			st_r = "      ";
	}

	while (st_r[len] != '\0')
		len++;

	if (preci >= 0 && preci < len)
		len = preci;

	if (wid > len)
	{
		if (flag & FLAGS_MINUS)
		{
			write(1, &st_r[0], len);
			for (j = wid - len; j > 0; j--)
				write(1, " ", 1);
			return (wid);
		}
		else
		{
			for (j = wid - len; j > 0; j--)
				write(1, " ", 1);
			write(1, &st_r[0], len);
			return (wid);
		}
	}
	return (write(1, st_r, len));
}

/**PERCENT SIGN **/

/**
 * print_percent - Af that prints a percent sign
 * @ap: The list of arguments
 * @buf: The buffer array to handle print
 * @flag:  To calculates active flags
 * @wid: width.
 * @preci: The precision specification
 * @size: the size specifier
*
 * Return: The number of chars to be printed
 */
int print_percent(va_list ap, char buf[],
	int flag, int wid, int preci, int size)
{
	UNUSED(ap);
	UNUSED(buf);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(preci);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/** INT **/

/**
 * print_int - A f that print int
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
	int nega_tive = 0;
	long int n = va_arg(ap, long int);
	unsigned long int nu;

	n = convert_size_number(n, size);

	if (n == 0)
		buf[j--] = '0';

	buf[BUFF_SIZE - 1] = '\0';
	nu = (unsigned long int)n;

	if (n < 0)
	{
		nu = (unsigned long int)((-1) * n);
		nega_tive = 1;
	}

	while (nu > 0)
	{
		buf[j--] = (nu % 10) + '0';
		nu /= 10;
	}

	j++;

	return (write_number(nega_tive, j, buf, flag, wid, preci, size));
}

/**BINARY**/

/**
 * print_binary - Af that prints an unsigned number
 * @ap: The list of arguments
 * @buf: The buffer array to handle print
 * @flag:  To calculates active flags
 * @wid: width.
 * @preci: The precision specification
 * @size: The size specifier
*
 * Return: The number of chars printed
 */
int print_binary(va_list ap, char buf[],
	int flag, int wid, int preci, int size)
{
	unsigned int n;
int m_m;
int j;
int sum;
	unsigned int b[32];
	int co;

	UNUSED(buf);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(preci);
	UNUSED(size);

	n = va_arg(ap, unsigned int);
	m_m = 2147483648; /* (2 ^ 31) */
	b[0] = n / m_m;
	for (j = 1; j < 32; j++)
	{
		m_m /= 2;
		b[j] = (n / m_m) % 2;
	}
	for (j = 0, sum = 0, co = 0; j < 32; j++)
	{
		sum += b[j];
		if (sum || j == 31)
		{
			char Z = '0' + b[j];

			write(1, &Z, 1);
			co++;
		}
	}
	return (co);
}
