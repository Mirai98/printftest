#include "main.h"

/**
 * get_size - To calculates the size to cast the argument
 * @format: A formatted string in which to print the arguments
 * @j: The list of arguments to be printed.
 *
 * Return: Precision
 */
int get_size(const char *format, int *j)
{
	int Curr_j = *j + 1;
	int Size = 0;

	if (format[Curr_j] == 'l')
		size = SIZES_LONG;
	else if (format[Curr_j] == 'h')
		Size = SIZES_SHORT;

	if (Size == 0)
		*j = Curr_j - 1;
	else
		*j = Curr_j;

	return (Size);
}
