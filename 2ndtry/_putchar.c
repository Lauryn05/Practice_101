#include <unistd.h>
/**
 * _putchar - writes c to stdout
 * @c: the character to be printed out
 * Return: 1 on success -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
