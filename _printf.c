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
	char *str;
	int length = 0;
	unsigned int i;
	char *s;
	va_list ap;

	va_start(ap, format);
	for (str = format; *str != '\0'; str++)
	{
		if (*str != '%')
		{
			putchar(*str);
			length++;
		}
		else
		{
			str++;
			switch (*str)
			{
				case 'c':
					i = va_arg(ap, int);
					putchar(s);
					break;
				case 's':
					s = va_arg(ap, char *);
					while (*s != '\0')
					{
						putchar(*s);
						*s++;
					}
					break;
				default:
					putchar(*str);
			}
			length++;
		}
	}
	putchar('\n');
	return (length);
}
