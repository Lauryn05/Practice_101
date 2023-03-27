#include <unistd.h>
/**
 * _putchar - writes c to stdout
 * @c: the character to be printed out
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
