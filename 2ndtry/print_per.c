#include "main.h"
/**
 * print_per - prints % sign
 * @ty: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags: active flags
 * @width: width.
 * @precision: Precision
 * @size: Size
 * Return: Number of characters printed
 */
int print_per(va_list ty, char buffer[],
	int flags, int width, int precision, int size);
{
	UNUSED(ty);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
