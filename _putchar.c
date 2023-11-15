#include <unistd.h>
#include "main.h"

/**
 * _putchar -writes a character to the standard output (stdout)
 * @c: the character to be written
 *
 * Return: On success, 1 is returned, -1  otherwise
 */

int _putchar(char c)
{
	return (write(1, &c ,1));
}
