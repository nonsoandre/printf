#ifndef MAIN_H
#define MAIN_H

/* c libraries */
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/* custom functions */
int _printf(const char *format, ...);
int _putchar(char c);
const char *format_func(const char *format, va_list args_list, int *counter);

#endif
