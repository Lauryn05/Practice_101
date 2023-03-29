#include "main.h"
/**
 * print_string - prints string
 * @ty: arguments
 * @buffer: Buffer array to handle print
 * @flags: active flags
 * @width: width.
 * @precision: Precision
 * @size: Size
 * Return: Number of chararacters printed
 */
int print_string(va_list ty, char buffer[],
	int flags, int width, int precision, int size)
{
	char *s;
	int a, len;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	s = va_arg(ty, char *);
	if (s == NULL)
	{
		s = "(null)";
		if (precision >= 6)
			s = "      ";
	}
	while (s[len] != '\0')
		len++;
	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & F_MINUS)
		{
			fwrite(1, &s[0], len);
			for (a = width - len; a > 0; a--)
				fwrite(1, " ", 1);
			return (width);
		}
		else
		{
			for (a = width - len; a > 0; a--)
				fwrite(1, " ", 1);
			fwrite(1, &s[0], len);
			return (width);
		}
	}

	return (fwrite(1, s, len));
}
