#include "main.h"
/**
 * print_char - prints a character
 * @ty: arguments
 * @buffer: Buffer array
 * @flags: Active flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: Number of characters printed
 */
int print_char(va_list ty, char buffer[], int flags,
		int width, int precision, int size)
{
	char s;

	s = va_arg(ty, int);
	return (handle_write_char(s, buffer, flags, width, precision, size));
}
