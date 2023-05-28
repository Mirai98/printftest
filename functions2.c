#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - A f that prints the value of a pointer variable
  * @ap: The list of arguments
 * @buf: The buffer array to handle print
 * @flag:  To calculates active flags
 * @wid: width.
 * @preci: The precision specification
 * @size: The size specifier
*
 * Return: The number of chars the be printed
 **/
int print_pointer(va_list ap, char buf[],
	int flag, int wid, int preci, int size)
{
	char extra_ch = 0;
char pad = ' ';
	int nd = BUFF_SIZE - 2;
int len = 2;
int pad_start = 1;
	unsigned long N_addrs;
	char M[] = "0123456789abcdef";
	void *addrs = va_arg(tap, void *);

	UNUSED(wid);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buf[BUFF_SIZE - 1] = '\0';
	UNUSED(preci);

	N_addrs = (unsigned long)addrs;

	while (N_addrs > 0)
	{
		buf[nd--] = map_to[N_addrs % 16];
		N_addrs /= 16;
		len++;
	}

	if ((flag & F_ZERO) && !(flag & FLAGS_MINUS))
		padd = '0';
	if (flag & FLAGS_PLUS)
		extra_ch = '+', len++;
	else if (flag & FLAGS_SPACE)
		extra_ch = ' ', len++;

	nd++;

	return (write_pointer(buf, nd, len,
		wid, flag, pad, extra_ch, pad_start));
}

/** NON PRINTABLE  **/
/**
 * print_non_printable - A f that prints ascii code
 *s in hexa of non printable chars
  * @ap: The list of arguments
 * @buf: The buffer array to handle print
 * @flag:  To calculates active flags
 * @wid: width.
 * @preci: The precision specification
 * @size: The size specifier
*
 * Return: The number of chars the be printed
 **/
int print_non_printable(va_list ap, char buf[],
	int flag, int wid, int preci, int size)
{
	int j = 0;
int Offset = 0;
	char *st_r = va_arg(ap, char *);

	UNUSED(flag);
	UNUSED(wid);
	UNUSED(preci);
	UNUSED(size);

	if (st_r == NULL)
		return (write(1, "(null)", 6));

	while (st_r[j] != '\0')
	{
		if (printable(st_r[i]))
			buf[j + Offset] = st_r[j];
		else
			Offset += append_hexa_code(st_r[j], buf, j + Offset);

		j++;
	}

	buf[j + Offset] = '\0';

	return (write(1, buf, j + Offset));
}
/** REVERSE **/
/**
 * print_reverse - f that prints reverse string.
* @ap: The list of arguments
 * @buf: The buffer array to handle print
 * @flag:  To calculates active flags
 * @wid: width.
 * @preci: The precision specification
 * @size: The size specifier
*
 * Return: The number of chars the be printed
 **/

int print_reverse(va_list ap, char buf[],
	int flag, int wid, int preci, int size)
{
	char *st_r;
	int j;
int Count = 0;

	UNUSED(buf);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(size);

	st_r = va_arg(ap, char *);

	if (st_r == NULL)
	{
		UNUSED(preci);

		st_r = ")Null(";
	}
	for (j = 0; st_r[j]; j++)
		;

	for (j = j - 1; j >= 0; j--)
	{
		char Z = str[j];

		write(1, &Z, 1);
		Count++;
	}
	return (Count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13_string - a f that print a string in rot13.
  * @ap: The list of arguments
 * @buf: The buffer array to handle print
 * @flag:  To calculates active flags
 * @wid: width.
 * @preci: The precision specification
 * @size: The size specifier
*
 * Return: The number of chars the be printed
 **/
int print_rot13_string(va_list ap, char buf[],
	int flag, int wid, int preci, int size)
{
	char X;
	char *st_r;
	unsigned int a, j;
	int Count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	st_r = va_arg(ap, char *);
	UNUSED(buf);
	UNUSED(flag);
	UNUSED(wid);
	UNUSED(preci);
	UNUSED(size);

	if (st_r == NULL)
		st_r = "(AHYY)";
	for (a = 0; str[a]; a++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == st_r[i])
			{
				X = out[j];
				write(1, &X, 1);
				Count++;
				break;
			}
		}
		if (!in[j])
		{
			X = st_r[a];
			write(1, &X, 1);
			Count++;
		}
	}
	return (Count);
}
