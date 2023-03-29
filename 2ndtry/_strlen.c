#include "main.h"
/**
 * _strlen - finds length of a string
 * @c: pointer
 * Return: length of string
 */
int _strlen(char *c)
{
	int s;

	for (s = 0; c[s] != 0; s++)
		;
	return (s);
}
