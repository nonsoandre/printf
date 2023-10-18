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
		(*counter)++;
	}
	else if (*format == '%')
	{
		_putchar('%');
		(*counter)++;
	}
	else if (*format == 's')
	{
		char *s = va_arg(args_list, char*);

		if (s == NULL)
			s = "(null)";
		while (*s)
		{
			_putchar(*s++);
			(*counter)++;
		}
	}
	else if (*format == 'd' || *format == 'i')
	{
		int num = va_arg(args_list, int);

		char *num_str = convert_num_to_str(num);

		if (!num_str)
			return (format); /* Memory error, you may want to handle this more gracefully */

		char *temp = num_str;

		while (*temp)
		{
			_putchar(*temp++);
			(*counter)++;
		}

		free(num_str);
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
		return (format);
	}
	return (format + 1);
}
