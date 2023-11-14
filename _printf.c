#include "main.h"
#define BUFFER_SIZE 1024

/**
 * _putchar - writes a character to the standard output
 * @c: the character to be written.
 *
 * Return: 1 on success, -1 otherwize.
 */

int _putchar(char c)
{
	return write(1, &c, 1);
}

/*
 * print_buffer - prints the buffer to stdout.
 * @buffer: the buffer to be printed.
 * @index_buffer: the index in the buffer.
 *
 * Return: number of the characters printed.
 */
int print_buffer(char *buffer, unsigned int index_buffer)
{
	int count = 0;

	count += write(1, buffer, index_buffer);
	return (count);
}

/**
 * printf - custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */

int printf(const char *format, ...)
{
	if (!format)
		return (-1);

	unsigned int i = 0, len = 0, index_buffer = 0;
	va_list args;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(args,format);
	buffer = malloc(sizeof(char) * BUFFER_SIZE);

	if (!buffer)
		return (-1);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				print_buffer(buffer, index_buffer);
				free(buffer);
				va_end(args);
				return (-1);
			}
			else
			{
				function = get_print_func(format, i + 1);
				if (function == NULL)
				{
					if(format[i + 1] == ' ' && !format[i  2])
						return (-1);
					handl_buf(buffer, format[i], index_buffer), len++, i--;
				}
				else
				{
					len += function(args, buffer, index_buffer);
					i += ev_print_func(format, i + 1);
				}
			}
			i ++;
		}
		else
		{
			handl_buf(buffer, format[i], index_buffer), len++;
		}

		for (index_buffer = len; index_buffer > BUFFER_SIZE ;index_buffer -= BUFFER_SIZE)
			;
	}

	print_buffer(buffer, index_buffer);
	free(buffer);
	va_end(args);
	return len;
}
