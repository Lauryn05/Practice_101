#include "main.h"
/**
 * print_dec - prints decimal
 * @l: argument
 * Return: number of characters printed
 */
int print_dec(va_list l)
{
	int n = va_arg(l, int);
	int num, digit, last, exp, a;

	last = n % 10;
	exp = 1;
	a = 1;

	n = n / 10;
	num = n;
	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		a++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			a++;
		}
	}
	_putchar(last + '0');
	return (a);
}
