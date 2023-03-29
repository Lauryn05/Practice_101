#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @l: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list l)
{
	int b = *i + 1;
	int precision = -1;

	if (format[b] != '.')
		return (precision);

	precision = 0;

	for (b += 1; format[b] != '\0'; b++)
	{
		if (is_digit(format[b]))
		{
			precision *= 10;
			precision += format[b] - '0';
		}
		else if (format[b] == '*')
		{
			b++;
			precision = va_arg(l, int);
			break;
		}
		else
			break;
	}

	*i = b - 1;

	return (precision);
}
