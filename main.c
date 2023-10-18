#include <stdio.h>
#include <limits.h>
#include "main.h"

/**
* main - Entry point test function
* Return: Success
*/
int main(void)
{

	int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;

	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Hello %s!\n", "World");
	_printf("I am %c years old.\n", '5');
	_printf("Printing a percentage sign: %%\n");

	return (0);
}
