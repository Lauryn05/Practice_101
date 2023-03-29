#include "main.h"
/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @precision: Precision
 * @len: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 * Return: Number of printed chars.
 */
int write_num(int ind, char buffer[], int flags, int width,
		int precision, int len, char padd, char extra_c)
{
	int a, begin_padd = 1;

	if (precision == 0 && ind == BUFF_SIZE - 2
			&& buffer[ind] == '0' && width == 0)
		return (0);
	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (precision > 0 && precision < len)
		padd = ' ';
	while (precision > len)
		buffer[--ind] = '0', len++;
	if (extra_c != 0)
		len++;
	if (width > len)
	{
		for (a = 1; a < width - len + 1; a++)
			buffer[a] = padd;
		buffer[a] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (fwrite(1, &buffer[ind], len) + fwrite(1, &buffer[1], a - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (fwrite(1, &buffer[1], a - 1) + fwrite(1, &buffer[ind], len));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--begin_padd] = extra_c;
			return (fwrite(1, &buffer[begin_padd], a - begin_padd) +
					fwrite(1, &buffer[ind], len - (1 - begin_padd)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], len));
}
