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

	for (const char *mover = format; *mover != '\0'; mover++)
	{
		/* If the current character isn't a */
		/* specifier introducer, print it as a normal character. */
		if (*mover != '%')
		{
			_putchar(*mover);
			counter++;
		}
		else
		{
			/* If the current character is a specifier */
			/* introducer, we process according to the specifier */
			mover++;  /* Move past the '%' character */
			if (*mover == '\0')
			{
				break;  /* End of format string, break from loop */
			}

			while (*mover == ' ')
			{
				mover++;  /* Skip spaces after '%' */
			}

			/* Call function to handle formatting. */
			/* This function can adjust the mover pointer if necessary. */
			mover = format_func(mover, args_list, &counter);

			if (mover == NULL || *mover == '\0')
			{
				break;  /*In case of an error or end of the format string, we exit the loop*/
			}
		}
	}
	va_end(args_list);  /*Clean up the argument list*/
	return (counter);  /*Return the count of characters printed*/
}
