#include "main.h"
/**
 * print_string - prints string
 * @l: arguments
 * Return: length
 */
int print_string(va_list l)
{
	char *s;
	int a, len;

	s = va_arg(l, char *);
	if (!s)
	{
		s = "(null)";
		len = _strlen(s);
		for (a = 0; a < len; a++)
			_putchar(s[a]);
	}
	else
	{
		len = _strlen(s);
		for (a = 0; a < len; a++)
			_putchar(s[a]);
	}
	return (len);
}
