#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* Flags */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/*Size*/
#define S_LONG 2
#define S_SHORT 1


/**
 * struct fmt - struct op
 * @c: format
 * @f: pointer to function
 */
typedef struct fmt
{
	char c;
	int (*f)(va_list, char[], int, int, int, int);
} pt;
/* _printf */
int _printf(const char *format, ...);
int print_sign(const char *f, int *ind, va_list l, char buffer[],
		int flags, int width, int precision, int size);

/*print specificationi*/
int print_char(va_list ty, char buffer[], int flags,
		int width, int precision, int size);
int print_int(va_list ty, char buffer[], int flags,
		int width, int precision, int size);
int print_per(va_list ty, char buffer[], int flags,
		int width, int precision, int size);
int print_string(va_list ty, char buffer[], int flags,
		int width, int precision, int size);
int _strlen(char *c);
int _putchar(char c);
int print_bin(va_list ty, char buffer[], int flags,
		int width, int precision, int size);
int print_unsigned(va_list ty, char buffer[], int flags,
		int width, int precision, int size);
int print_octal(va_list ty, char buffer[], int flags,
		int width, int precision, int size);
int print_hexadec(va_list ty, char buffer[], int flags,
		int width, int precision, int size);
int print_hexa_upper(va_list ty, char buffer[], int flags,
		int width, int precision, int size);
int print_hexa(va_list ty, char map_to[], char buffer[], int flags,
		int width, int precision, int size);

/*Non-printable*/
int print_non_print(va_list ty, char buffer[], int flags,
		int width, int precision, int size);

/*Menory address*/
int print_pointer(va_list ty, char buffer[], int flags,
		int width, int precision, int size);

/*Other specifiers*/
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list l);
int get_precision(const char *format, int *i, va_list l);
int get_size(const char *format, int *i);

/*Reverse printing*/
int print_rev(va_list ty, char buffer[], int flags,
		int width, int precision, int size);

/*print to rot 13*/
int print_rot13(va_list ty, char buffer[], int flags,
		int width, int precision, int size);

/*Print buffer*/
void print_buffer(char buffer[], int *buff_ind);

/*widh handling*/
int handle_write_char(char c, char buffer[], int flags,
		int width, int precision, int size);
int write_number(int is_pos, int ind, char buffer[],
		int flags, int width, int precision, int size);
int write_num(int ind, char buffer[], int flags,
		int width, int precision, int size,
		int len, char padd, char extra_c);
int write_point(char buffer[], int ind, int len,
		int width, int flags, char padd, int extra_c, int begin_padd);
int write_unsign(int is_neg, int ind, char buffer[],
		int flags, int width, int precision, int size);

/*Utils*/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsign(unsigned long int num, int size);

#endif
