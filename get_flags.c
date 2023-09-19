#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */

int get_flags(const char *format, int *i)

{

	/* - + 0 # ' ' */

	/* 1 2 4 8  16 */

	int j, cur;

	int fl = 0;

	const char CH[] = {'-', '+', '0', '#', ' ', '\0'};

	const int ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cur = *i + 1; format[cur] != '\0'; cur++)
	{
		for (j = 0; CH[j] != '\0'; j++)

			if (format[cur] == CH[j])
			{

				fl |= ARR[j];

				break;

			}

		if (CH[j] == 0)

			break;

	}

	*i = cur - 1;
	return (fl);

}
