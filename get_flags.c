#include "main.h"

/**
 * get_flags - to calculates active flags
 * @format: The formatted string in which to print the arguments
 * @j: To take a parameter
*
 * Return: flags
 */
int get_flags(const char *format, int *j)
{

	int i;
int Curr_j;
	int Flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {FLAGS_MINUS, FLAGS_PLUS,
		FLAGS_ZERO, FLAGS_HASH, FLAGS_SPACE, 0};

	for (Curr_j = *j + 1; format[Curr_j] != '\0'; Curr_j++)
	{
		for (i = 0; FLAGS_CH[i] != '\0'; i++)
			if (format[Curr_j] == FLAGS_CH[i])
			{
				Flags |= FLAGS_ARR[i];
				break;
			}

		if (FLAGS_CH[i] == 0)
			break;
	}

	*j = curr_j - 1;

	return (Flags);
}
