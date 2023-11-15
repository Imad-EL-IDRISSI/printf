#ifndef MY_PRINTF
#define MY_PRINTD

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

/**
 * struct convert - converter for printf
 * @sym: type char pointer of the specifier
 * @f: function for the conversion specifier
 */
struct convert
{
	char *sym;
	int (*f)(va_list);
}
typedef struct convert conver_t;

int _purtchar(char c);
int _printf(const char *format, ...);
void _vprintf(const char *format, va_list args);
int parser(const char *format, conver_t funct_list[], va_list args);
int p_char(va_list);
int p_string(va_list args);
int p_percent(va_list);
int print_unsgined_number(unsigned int n);
int print_number(va_list);
int p_integer(va_list);

#endif

