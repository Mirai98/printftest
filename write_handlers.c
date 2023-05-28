#include "main.h"

/** HANDLE **/
/**
 * Handle_write_char - A f that prints a string
 * @c: The char types
 * @buf: The buffer array to handle print
 * @flag:  To calculates active flags.
 * @wid: width.
 * @preci: the precision specifier
 * @size: THE Size specifier
 *
 * Return: The number of chars to be  printed
 */
int Handle_write_char(char c, char buf[],
	int flag, int wid, int preci, int size)

	int a = 0;
	char Padd = ' ';

	UNUSED(preci);
	UNUSED(size);

	if (flag & FLAGS_ZERO)
		Padd = '0';

	buf[a++] = c;
	buf[a] = '\0';

	if (wid > 1)
	{
		buf[BUFF_SIZE - 1] = '\0';
		for (a = 0; a < wid - 1; a++)
			buf[BUFF_SIZE - a - 2] = Padd;

		if (flag & FLAGS_MINUS)
			return (write(1, &buf[0], 1) +
					write(1, &buf[BUFF_SIZE - a - 1], wid - 1));
		else
			return (write(1, &buf[BUFF_SIZE - J - 1], wid - 1) +
					write(1, &buf[0], 1));
	}

	return (write(1, &buf[0], 1));
}

/**  NUMBER **/
/**
 * Handle_write_number - A f that prints a string
 * @nega_tive: The list of arguments
 * @ind: The char types.
 * @buf: The buffer array to handle print
 * @flag:  To calculates active flags
 * @wid: width.
 * @preci: The precision specifier
 * @size: the size specifier
 *
 * Return: The number of chars to be printed.
 */
int Handle_write_number(int nega_tive, int ind, char buf[],
	int flag, int wid, int preci, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char Padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flag & FLAGS_ZERO) && !(flag & FLAGS_MINUS))
		Padd = '0';
	if (nega_tive)
		extra_ch = '-';
	else if (flag & FLAGS_PLUS)
		extra_ch = '+';
	else if (flag & FLAGS_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buf, flag, wid, preci,
		len, Padd, extra_ch));
}

/**
 * Handle_write_num - A f that write a number using a bufffer
 * @ind: The index at which the number starts on the buffer
 * @buf: The buffer
 * @flag: flags
 * @wid: width
 * @preci: The precision specifier
 * @len: The number length
 * @Padd: The pading char
 * @extra_ch: The extra char
 *
 * Return: The number of printed chars.
 */
int Handle_write_num(int ind, char buf[], int flag, int wid, int preci,
	int len, char Padd, char extra_ch)
{
	int j;
int Padd_start = 1;

	if (preci == 0 && ind == BUFF_SIZE - 2 && buf[ind] == '0' && wid == 0)
		return (0);
	if (preci == 0 && ind == BUFF_SIZE - 2 && buf[ind] == '0')
		buf[ind] = Padd = ' ';
	if (preci > 0 && preci < len)
		Padd = ' ';
	while (preci > len)
		buf[--ind] = '0', len++;
	if (extra_ch != 0)
		len++;
	if (wid > len)
	{
		for (j = 1; j < wid - len + 1; j++)
			buf[j] = Padd;
		buf[j] = '\0';
		if (flag & FLAGS_MINUS && Padd == ' ')
		{
			if (extra_ch)
				buf[--ind] = extra_ch;
			return (write(1, &buf[ind], len) + write(1, &buf[1], j - 1));
		}
		else if (!(flag & Flags_MINUS) && Padd == ' ')
		{
			if (extra_ch)
				buf[--ind] = extra_ch;
			return (write(1, &buf[1], j - 1) + write(1, &buf[ind], len));
		}
		else if (!(flag & FLAGS_MINUS) && Padd == '0')
		{
			if (extra_ch)
				buf[--Padd_start] = extra_ch;
			return (write(1, &buf[Padd_start], j - Padd_start) +
				write(1, &buf[ind], len - (1 - Padd_start)));
		}
	}
	if (extra_ch)
		buf[--ind] = extra_ch;
	return (write(1, &buf[ind], len));
}

/**
 * Handle_write_unsgnd - a f that writes an unsigned number
 * @nega_tive: the number indicating if the num is negative
 * @ind:the index at which the number starts in the buffer
 * @buf: the array of chars
 * @flag: the flags specifiers
 * @wid: width
 * @preci: the precision specifier
 * @size: the size specifier
 *
 * Return: the number of written chars.
 */
int Handle_write_unsgnd(int nega_tive, int ind, char buf[],
	int flag, int wid, int preci, int size)
{
	/* The number is stored at the bufer's right and starts at position i */
	int len = BUFF_SIZE - ind - 1;
int j = 0;
	char Padd = ' ';

	UNUSED(nega_tive);
	UNUSED(size);

	if (preci == 0 && ind == BUFF_SIZE - 2 && buf[ind] == '0')
		return (0);

	if (preci > 0 && preci < len)
		Padd = ' ';

	while (preci > len)
	{
		buf[--ind] = '0';
		len++;
	}

	if ((flag & FLAGS_ZERO) && !(flag & FLAGS_MINUS))
		Padd = '0';

	if (wid > len)
	{
		for (j = 0; j < wid - len; j++)
			buf[j] = Padd;

		buf[j] = '\0';

		if (flag & FLAGS_MINUS)
		{
			return (write(1, &buf[ind], len) + write(1, &buf[0], J));
		}
		else
		{
			return (write(1, &buf[0], j) + write(1, &buf[ind], len));
		}
	}

	return (write(1, &buf[ind], len));
}

/**
 * write_pointer - a f that write a memory address
 * @buf: The arrays of chars
 * @ind: The index at which the number starts in the buffer
 * @len: the length of number
 * @wid: the width specifier
 * @flag: the flags specifier
 * @Padd: the char representing the padding
 * @extra_ch: the char representing extra char
 * @Padd_start: the index at which padding should start
 *
 * Return: the number of written chars.
 */
int Handle_write_pointer(char buf[], int ind, int len,
	int wid, int flag, char Padd, char extra_ch, int Padd_start)
{
	int j;

	if (wid > len)
	{
		for (j = 3; j < wid - len + 3; j++)
			buf[j] = Padd;
		buf[j] = '\0';
		if (flag & FLAGS_MINUS && Padd == ' ')
		{
			buf[--ind] = 'x';
			buf[--ind] = '0';
			if (extra_ch)
				buf[--ind] = extra_ch;
			return (write(1, &buf[ind], len) + write(1, &buf[3], j - 3));
		}
		else if (!(flag & FLAGS_MINUS) && Padd == ' ')
		{
			buf[--ind] = 'x';
			buf[--ind] = '0';
			if (extra_ch)
				buf[--ind] = extra_ch;
			return (write(1, &buf[3], j - 3) + write(1, &buf[ind], len));
		}
		else if (!(flag & FLAGS_MINUS) && Padd == '0')
		{
			if (extra_ch)
				buf[--Padd_start] = extra_ch;
			buf[1] = '0';
			buf[2] = 'x';
			return (write(1, &buf[Padd_start], j - Padd_start) +
				write(1, &buf[ind], len - (1 - Padd_start) - 2));
		}
	}
	buf[--ind] = 'x';
	buf[--ind] = '0';
	if (extra_ch)
		buf[--ind] = extra_ch;
	return (write(1, &buf[ind], BUFF_SIZE - ind - 1));
}
