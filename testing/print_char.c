#include "main.h"
/**
 * print_char - prints a character
 * @l: arguments
 * Return: 1
 */
int print_char(va_list l)
{
	char s;

	s = va_arg(l, int);
	_putchar(s);
	return (1);
}
