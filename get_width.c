#include "main.h"
/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @l: list of arguments.
 * Return: width.
 */
int get_width(const char *format, int *i, va_list l)
{
	int b;
	int width = 0;

	for (b = *i + 1; format[b] != '\0'; b++)
	{
		if (is_digit(format[b]))
		{
			width *= 10;
			width += format[b] - '0';
		}
		else if (format[b] == '*')
		{
			b++;
			width = va_arg(l, int);
			break;
		}
		else
			break;
	}

	*i = b - 1;

	return (width);
}
