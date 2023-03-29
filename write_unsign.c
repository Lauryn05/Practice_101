#include "main.h"
/**
 * write_unsign - Writes an unsigned number
 * @is_neg: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags
 * @width: Width
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of printed characters
 */
int write_unsign(int is_neg, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1, a = 0;
	char padd = ' ';

	UNUSED(is_neg);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);
	if (precision > 0 && precision < len)
		padd = ' ';
	while (precision > len)
	{
		buffer[--ind] = '0';
		len++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (width > len)
	{
		for (a = 0; a < width - len; a++)
			buffer[a] = padd;

		buffer[a] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], len) + write(1, &buffer[0], a));
		}
		else
		{
			return (write(1, &buffer[0], a) + write(1, &buffer[ind], len));
		}
	}

	return (write(1, &buffer[ind], len));
}
