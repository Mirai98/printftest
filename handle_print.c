#include "main.h"
/**
 * Handle_printf - a f that  Prints an argument based on its type
 * @Fmt: the formatted string in which to print the arguments.
 * @list: The list of arguments to be printed.
 * @I: ind
 * @buf: The Buffer array to handle print.
 * @flag: To Calculates active flags
 * @wid: width.
 * @preci: The precision specification
 * @size: The Size specifier
 * Return: 1 or 2
 */

int Handle_printf(const char *Fmt, int *I,
va_list list, char buf[], int flag, int wid, int preci, int size);
{
	int j;
int Unknow_len = 0;
int Printed_chars = -1;
	Fmt_t Fmt_ap[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13_string}, {'\0', NULL}
	};
	for (j = 0; Fmt_ap[j].Fmt != '\0'; j++)
		if (Fmt[*I] == Fmt_ap[j].Fmt)
			return (Fmt_ap[j].Fn(list, buf, flag, wid, preci, size));

	if (Fmt_ap[j].Fmt == '\0')
	{
		if (Fmt[*I] == '\0')
			return (-1);
		Unknow_len += write(1, "%%", 1);
		if (Fmt[*I - 1] == ' ')
			Unknow_len += write(1, " ", 1);
		else if (wid)
		{
			--(*I);
			while (Fmt[*I] != ' ' && Fmt[*I] != '%')
				--(*I);
			if (Fmt[*I] == ' ')
				--(*I);
			return (1);
		}
		Unknow_len += write(1, &Fmt[*I], 1);
		return (Unknow_len);
	}
	return (printed_chars);
}
