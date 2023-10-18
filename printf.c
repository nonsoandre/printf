#include "main.h"

/**
* _printf - c printf replication function
* function that produces output according to a format
* @format:  is a character string.
* The format string is composed of zero or more directives.
* Return: the number of characters printed
*/

int _printf(const char *format, ...)
{
	va_list args_list;
	int counter;

	const char *mover;

	counter = 0;
	if (format == NULL)
	{
		return (-1);
	}

	va_start(args_list, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
			while (*format == ' ')
				format++;
			format = format_func(format, args_list, &counter);
			format++;
		}
		else
		{
			_putchar(*format);
			format++;
			counter++;
		}
	}
	va_end(args_list);
	return (counter);
}

