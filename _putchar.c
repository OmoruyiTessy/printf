#include "main.h"
/**
 * _putchar - print characters
 * @c: character
 * Return: can be 1
 * on error return -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
