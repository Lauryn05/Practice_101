#include "main.h"
/**
 * _printf - selects a function to print
 * @format: identifier
 * Return - Number of  characters printed
 */
int _printf(const char *format, ...)
{
	pt func_ar[] = {
		{"%c", print_char},
		{"%s", print_string},
		{"%d", print_int},
		{"%i", print_int},
		{"%%", print_per},
		{"%b", print_bin}
	};
	va_list argue;
	int a, b, len;

Here:
	va_start(argue, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	while (format[a] != '\0')
	{
		b = 4;
		while (b >= 0)
		{
			if (func_ar[b].c[0] == format[a] && func_ar[a].c[1] == format[a + 1])
			{
				len = len + func_ar[b].f(argue);
				a = a + 2;
				goto Here;
			}
			b--;
		}
		_putchar(format[a]);
		a++;
		len++;
	}
	va_end(argue);
	return (len);
}
