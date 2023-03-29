#include "main.h"
/**
 * write_point - Write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @len: Length of number
 * @width: width
 * @flags: Flags
 * @padd: padding
 * @extra_c: extra char
 * @begin_padd: Index at which padding should start
 * Return: Number of written chars.
 */
int write_point(char buffer[], int ind, int len,
	int width, int flags, char padd, char extra_c, int begin_padd)
{
	int a;

	if (width > len)
	{
		for (a = 3; a < width - len + 3; a++)
			buffer[a] = padd;
		buffer[a] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], len) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], a - 3) + write(1, &buffer[ind], len));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--begin_padd] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[begin_padd], a - begin_padd) +
				write(1, &buffer[ind], len - (1 - begin_padd) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
