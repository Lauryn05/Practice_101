#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int b = *i + 1; /*b = current i*/
	int size = 0;

	if (format[b] == 'l')
		size = S_LONG;
	else if (format[b] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = b - 1;
	else
		*i = b;

	return (size);
}
