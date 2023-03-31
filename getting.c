#include "main.h"
/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	int j, curr;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr = *i + 1; format[curr] != '\0'; curr++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		if (FLAGS_CH[j] == 0)
			break;
	}
	*i = curr - 1;
	return (flags);
}
#include "main.h"
/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr = *i + 1;
	int precision = -1;

	if (format[curr] != '.')
		return (precision);
	precision = 0;
	for (curr += 1; format[curr] != '\0'; curr++)
	{
		if (is_digit(format[curr]))
		{
			precision *= 10;
			precision += format[curr] - '0';
		}
		else if (format[curr] == '*')
		{
			curr++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = curr - 1;
	return (precision);
}
#include "main.h"
/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int curr = *i + 1;
	int size = 0;

	if (format[curr] == 'l')
		size = S_LONG;
	else if (format[curr] == 'h')
		size = S_SHORT;
	if (size == 0)
		*i = curr - 1;
	else
		*i = curr;
	return (size);
}
#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr;
	int width = 0;

	for (curr = *i + 1; format[curr] != '\0'; curr++)
	{
		if (is_digit(format[curr]))
		{
			width *= 10;
			width += format[curr] - '0';
		}
		else if (format[curr] == '*')
		{
			curr++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = curr - 1;
	return (width);
}
