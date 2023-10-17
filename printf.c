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

	va_start(args_list, format);
		counter = 0;
	if (format == NULL)
	{
		return (-1);
	}

	for (mover = &format; *mover != '\0'; ++mover)/* loop through format*/
	{
		while (*mover != '%' && *mover != '\0')
		{
			write(1, mover, 1);
			counter++;
			mover++;
		}
		if (*mover == '\0')
		{
			break;
		}
		mover++;
		/* if format is the % sign*/
		if (*mover == 'c')
		{
			char c = (char) va_args(args_list, int);

			write(1, &c, 1);
			counter++;
		}
		else if (*mover == 's')
		{
			char *s = va_args(args_list, char*);
			int len = 0;

			for (char *str = 2; *str; ++str)
				len++;
			write(1, s, len);
			counter +=len;
		}
		else if (*mover == "%")
		{
			char pcent = '%';

			write(1, &pcent, 1);
			counter++;
		}
		else
		{
			write(1, mover, 1);
			counter++;
		}
	}
	va_end(args_list);
	return (counter);
}

