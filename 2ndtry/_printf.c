#include "main.h"

/**
 * _printf - selects a function to print
 * @format: identifier
 * Return - Number of  characters printed
 */
int _printf(const char *format, ...)
{
	va_list argue;
	int a, b, len;
	int flags, width, precision, size, buff_ind;
	char buffer[BUFF_SIZE];

	va_start(argue, format);
	if (format == NULL)
		return (-1);
	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buffer[buff_ind++] = format[a];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			len++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &a);
			width = get_width(format, &a, argue);
			precision = get_precision(format, &a, argue);
			size = get_size(format, &a);
			++a;
			b = print_sign(format, &a, argue,
					buffer, flags, width, precision, size);

			if (len == -1)
				return (-1);
			len += b;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(argue);
	return (len);
}
