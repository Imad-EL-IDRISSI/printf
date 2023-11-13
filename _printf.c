#include "main.h"

/**
 * printf - custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */

int printf(const char *format, ...)
{
	int char_pr = 0;
	va_list args;

	if (format == NULL)
		return -1;

	
	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_pr++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				char_pr++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);
				write(1,&c, 1);
				char_pr++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char*);
				int len = 0;

				while (str[len] != '\0')
					len++;

				write(1, str, len);
				char_pr += len;
			}
		}

		format++;
	}

	va_end(args);

	return char_pr;
}
