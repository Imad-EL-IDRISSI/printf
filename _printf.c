#include "main.h"
#include <stdint.h>

/**
 * _printf - is a function that select the correct function to print.
 * @format: identifer to look for.
 * Return: the length of the string.
 */
int _printf(const char *format, ...)
{
	int printed_chars;

	conver_t funct_list[] =	{
		{"c", p_char},
		{"s", p_string},
		{"%", p_percent},
		{"d", p_integer},
		{"i", p_integer},
		{NULL, NULL}
	};

	va_list args;


	if (format == NULL)
		return (-1);

	va_start(args, format);

	/** call a parser function*/

	printed_chars = parser(format, funct_list, args);
	va_end(args);

	return (printed_chars);
}
