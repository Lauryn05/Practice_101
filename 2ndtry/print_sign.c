#include "main.h"
/**
 * print_sign - Prints an argument based on its type
 * @f: Formatted string to print the arguments.
 * @l: arguments
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: active flags
 * @width: width.
 * @precision: Precision
 * @size: Size
 * Return: 1 or 2;
 */
int print_sign(const char *f, int *ind, va_list l, char buffer[],
	int flags, int width, int precision, int size)
{
	int a, b = 0, len = -1;
	pt signs[] = {
		{'c', print_char}, {'s', print_string},
		{'%', print_per}, {'i', print_int},
		{'d', print_int}, {'b', print_bin},
		{'u', print_unsigned}, {'o', print_octal},
		{'x', print_hexadec}, {'X', print_hexa_upper},
		{'p', print_pointer}, {'S', print_non_print},
		{'r', print_rev}, {'R', print_rot13},
		{'\0', NULL}
	};
	for (a = 0; signs[a].pt != '\0'; a++)
		if (pt[*ind] == signs[a].pt)
			return (signs[a].pt(l, buffer, flags, width, precision, size));
	if (signs[a].pt == '\0')
	{
		if (pt[*ind] == '\0')
			return (-1);
		b += write(1, "%%", 1);
		if (f[*ind - 1] == ' ')
			b += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (pt[*ind] != ' ' && pt[*ind] != '%')
				--(*ind);
			if (pt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		b += write(1, &pt[*ind], 1);
		return (b);
	}
	return (len);
}
