#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - create custom printf
 * @format: format of input
 * Return: length of string to output
*/

int _printf(const char *format, ...)
{
	const char *str;
	int length = 0;
	const char *s;
	va_list ap;

	va_start(ap, format);
	for (str = format; *str != '\0'; str++)
	{
		if (*str != '%')
		{
			_putchar(*str);
			length++;
		}
		else
		{
			str++;
			switch (*str)
			{
				case 'c':
					_putchar(va_arg(ap, int));
					break;
				case 's':
					s = va_arg(ap, const char *);
					for (; *s != '\0'; s++)
						_putchar(*s);
					break;
				default:
					_putchar(*str);
			}
			length++;
		}
	}
	return (length);
}
