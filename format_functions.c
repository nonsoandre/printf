#include "main.h"
/**
 * format_func - While loop through the arg format va list
 * @format: The format
 * @args_list: Argument va_list passed
 * @counter: Counter, number of char
 * Return: char counter ptr
 */

const char *format_func(const char *format, va_list args_list, int *counter)
{
	if (*format == 'c')
	{
		char c = (char) va_arg(args_list, int);

		_putchar(c);
		*counter++;
	}
	else if (*format == '%')
	{
		_putchar('%');
		*counter++;
	}
	else if (*format == 's')
	{
		char *s = va_arg(args_list, char*);

		while (*s)
		{
			_putchar(*s++);
			*counter++;
		}
	}
	else
	{
		_putchar('%');
		(*counter)++;
		if (*format)
		{
			_putchar(*format);
			(*counter)++;
		}
	}
	return (format);
}
