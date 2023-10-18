#include "main.h"
/**
* convert_num_to_str - a replica of itoa function in c
* @num: number to convert
* Return: Buffer
*/

char *convert_num_to_str(int num)
{
	char *buffer = malloc(50); /*Ensure this is large enough for any int*/

	if (!buffer)
		return (NULL);

	int n = num;

	int i = 0, isNegative = 0;

	if (n < 0)
	{
		isNegative = 1;
		n = -n;
	}

	do {
		buffer[i++] = n % 10 + '0'; /* Convert integer to character */
	} while ((n /= 10) > 0);

	if (isNegative)
		buffer[i++] = '-';

	buffer[i] = '\0';

	/* Reverse the string */
	for (int start = 0, end = i - 1; start < end; start++, end--)

	{
		char c = buffer[start];

		buffer[start] = buffer[end];
		buffer[end] = c;
	}

	return (buffer);
}
