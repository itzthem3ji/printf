#include "main.h"

/**
 * _printf - a function that produces output
 * according to a format
 * Description: this function calls theget_print() function 
 * which will use the conversion specifiers to determine
 * the exact printing function to call
 * @format: pointer to a character string
 * Return: length of the formated output string
 */

int _printf(const char *format, ...)
{
	int (*ptr)(va_list, flags_t *);
	const char *p;
	va_list argp;
	flags_t flags = {0, 0, 0};

	register int count = 0;

	va_start(argp, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')\
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			ptr = geet_print(*p);
			count += (ptr)
				? ptr(argp, &flags)
				: _printf("%%%c", *p);
		} else
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(argp);
	return (count);
}
