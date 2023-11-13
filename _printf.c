#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * printf - custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int printf(const char *format, ...)
{
	if (!format)
		return -1;

	va_list args;
	va_start(args, format);

	int count = 0;
	
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					{
						char *str = va_arg(args, char *);
						if (!str)
							str = "(null)";
						while (*str != '\0')
						{
							count += _putchar(*str);
							str++;
						}
						break;
					}
				case '%':
					count += _putchar('%');
					break;
				default:
					_putchar('%');
					count++;
					break;
			}
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}

	va_end(args);
	return (count);
}
