#include "main.h"

/**
* _putchar - function to write out to the standard output the char c
* @c: char value character
* Return: always success 1 / -1 on error
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
