#include “main.h”

/**
 * printf_char - prints a char.
 * @val: arguments.
 * Return: 1.
 */

int printf_char(va_list num)
{
	char y;

	y = va_arg(num, int);
	_putchar(y);
	return (1);
}
