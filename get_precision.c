#include "main.h"

/**
 * get_precision - to calculates the precision for printing
 * @format: a formatted string in which to print the arguments
 * @j: The list of arguments to be printed.
 * @list: The list of arguments.
 *
 * Return: precision
 */
int get_precision(const char *format, int *j, va_list list)
{
	int Curr_j = *j + 1;
	int Precision = -1;

	if (format[Curr_j] != '.')
		return (Precision);

	Precision = 0;

	for (Curr_j += 1; format[Curr_j] != '\0'; Curr_j++)
	{
		if (is_digit(format[Curr_j]))
		{
			Precision *= 10;
			Precision += format[Curr_j] - '0';
		}
		else if (format[Curr_j] == '*')
		{
			Curr_j++;
			Precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*j = Curr_j - 1;

	return (Precision);
}
