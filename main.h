#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * find_function - function that finds formats for _printf
 * calls the corresponding function.
 * @format: format (char, string, int, decimal)
 * Return: NULL or function associated ;
 */

int count_digits(int num);
int _printf(const char *format, ...);

#endif
