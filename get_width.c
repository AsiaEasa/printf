#include "main.h"



/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */

int get_width(const char *format, int *i, va_list list)

{
	int cur;
	int wid = 0;

	for (cur = *i + 1; format[cur] != '\0'; cur++)

	{

		if (is_digit(format[cur]))

		{
			wid *= 10;
			wid += format[cur] - '0';
		}

		else if (format[cur] == '*')

		{

			cur++;

			wid = va_arg(list, int);

			break;
		}

		else

			break;

	}



	*i = cur - 1;
	return (wid);

}
