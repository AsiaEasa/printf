#include "main.h"



/**

 * get_precision - Calculates the precision for printing

 * @format: Formatted string in which to print the arguments

 * @i: List of arguments to be printed.

 * @list: list of arguments.

 *

 * Return: Precision.

 */

int get_precision(const char *format, int *i, va_list list)

{

	int curr = *i + 1;

	int pre = -1;



	if (format[curr] != '.')

		return (pre);



	pre = 0;



	for (curr += 1; format[curr] != '\0'; curr++)

	{

		if (is_digit(format[curr]))

		{

			pre *= 10;

			pre += format[curr] - '0';

		}

		else if (format[curr] == '*')

		{

			curr++;

			pre = va_arg(list, int);

			break;

		}

		else

			break;

	}



	*i = curr - 1;



	return (pre);

}
