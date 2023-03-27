#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
/**
 * struct printing - matches conversion specifiers for printf
 * @c: char pointer of specifier eg: d, i, s, c, %
 * @f: pointer to function
 */
typedef struct printing
{
	char *c;
	int (*f)();
} pt;
/* _printf */
int _printf(const char *format, ...);

/*print specification*/
int print_char(va_list l);
int print_int(va_list l);
int print_per(void);
int print_string(va_list l);
int _strlen(char *c);
int _putchar(char c);

#endif
