#include "main.h"
/**
 * print_bin - prints binary
 * @l: arguments
 * Return: 1
 */
int print_bin(va_list l)
{
	int flag, cont, a, b, i;
	unsigned int num, p;

	cont = 0;
	a = 1;
	num = va_arg(l, unsigned int);
	for (i = 0; i < 32; i++)
	{
		p = ((a << (31 + i)) & num);
		if (p >> (31 - i))
			flag = 1;
		if (flag)
		{
			b = p >> (31 - i);
			_putchar(b + 48);
			cont++;
		}
		if (cont == 0)
		{
			cont++;
			_putchar('0');
		}
	}
	return (cont);
}
