#include "main.h"
/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags: active flags.
 * @width: width.
 * @precision: precision
 * @size: Size
 * Return: Number of characters printed.
 */
int handle_write_char(char c, char buffer[], int flags,
		int width, int precision, int size)
{
	int a = 0;
	char ind = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		ind = '0';

	buffer[a++] = c;
	buffer[a] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (a = 0; a < width - 1; a++)
			buffer[BUFF_SIZE - a - 2] = ind;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - a - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - a - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}
