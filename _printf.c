#include "main.h"

void print_buffer(char b[], int *b_ind);

/**
 * _printf - New printf function
 * @format: format
*
 * Return: The total of characters printed
 */
int _printf(const char *format, ...)
{
	int j;
int P = 0;
int p_chars = 0;
	int flags,
int wid;
int preci;
int size;
int b_ind = 0;
va_list list;
char b[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			b[buff_ind++] = format[i];
			if (b_ind == BUFF_SIZE)
				print_buffer(b, &b_ind);
			/* write(1, &format[j], 1);*/
			p_chars++;
		}
		else
		{
			print_buffer(b, &b_ind);
			flag = get_flag(format, &j);
			wid = get_wid(format, &j, list);
			preci = get_preci(format, &j, list);
			size = get_size(format, &j);
			++j;
			p = handle_print(format, &j, list, b,
				flag, wid, preci, size);
			if (p == -1)
				return (-1);
			p_chars += p;
		}
	}

	print_buffer(b, &b_ind);

	va_end(list);

	return (p_chars);
}

/**
 * print_buffer - A function that prints the contents of the buffer if it exist
 * @b: array
 * @b_ind: Buffer Index at which to add next char to represents the length.
*
*return : void
*/
void print_buffer(char b[], int *b_ind)
{
	if (*b_ind > 0)
		write(1, &b[0], *b_ind);

	*b_ind = 0;
}
