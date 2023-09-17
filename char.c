#include “main.h”

/**
 * printf_char - prints a char.
 * @val: arguments.
 * Return: 1.
 */
int printc(char *format, va_list pa)
{
	(void)format;
	_putchar(va_arg(pa, int));
	return (1);
}
