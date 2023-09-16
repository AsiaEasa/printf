#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/**
 * find_function - function that finds formats for _printf
 * calls the corresponding function.
 * @format: format (char, string, int, decimal)
 * Return: NULL or function associated ;
 */

int _putchar(char l);
int _printf(const char *format, ...);
int printf_char(va_list c);
int printf_string(va_list s);
int printf_percent(void);

typedef struct code_format
{
	char *sc;
	int (*f)(va_list);
} code_f;

#endif
