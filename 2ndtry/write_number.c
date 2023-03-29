#include "main.h"
/**
 * write_number - Prints a string
 * @is_neg: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags: active flags
 * @width: width.
 * @precision: precision
 * @size: Size
 * Return: Number of chars printed.
 */
int write_number(int is_neg, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_neg)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';
	return (write_num(ind, buffer, flags, width, precision,
		len, padd, extra_ch));
}
