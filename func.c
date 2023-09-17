#include "main.h"



/************************* PRINT CHAR *************************/



/**

 * print_char - Prints a char

 * @types: List a of arguments

 * @buffer: Buffer array to handle print

 * @flags:  Calculates active flags

 * @width: Width

 * @precision: Precision specification

 * @size: Size specifier

 * Return: Number of chars printed

 */

int print_char(va_list types, char buffer[],

		int flags, int width, int precision, int size)

{

	char c = va_arg(types, int);



	return (handle_write_char(c, buffer, flags, width, precision, size));

}

/************************* PRINT A STRING *************************/

/**

 * print_string - Prints a string

 * @types: List a of arguments

 * @buffer: Buffer array to handle print

 * @flags:  Calculates active flags

 * @width: get width.

 * @precision: Precision specification

 * @size: Size specifier

 * Return: Number of chars printed

 */

int print_string(va_list types, char buffer[],

		int flags, int width, int precision, int size)

{

	int len = 0, i;

	char *ptr = va_arg(types, char *);



	UNUSED(buffer);

	UNUSED(flags);

	UNUSED(width);

	UNUSED(precision);

	UNUSED(size);

	if (ptr == NULL)

	{

		ptr = "(null)";

		if (precision >= 6)

			ptr = "      ";

	}



	while (ptr[len] != '\0')

		len++;



	if (precision >= 0 && precision < len)

		len = precision;



	if (width > len)

	{

		if (flags & F_MINUS)

		{

			write(1, &ptr[0], len);

			for (i = width - len; i > 0; i--)

				write(1, " ", 1);

			return (width);

		}

		else

		{

			for (i = width - len; i > 0; i--)

				write(1, " ", 1);

			write(1, &ptr[0], len);

			return (width);

		}

	}



	return (write(1, ptr, len));

}

/************************* PRINT PERCENT SIGN *************************/

/**

 * print_percent - Prints a percent sign

 * @types: Lista of arguments

 * @buffer: Buffer array to handle print

 * @flags:  Calculates active flags

 * @width: get width.

 * @precision: Precision specification

 * @size: Size specifier

 * Return: Number of chars printed

 */

int print_percent(va_list types, char buffer[],

		int flags, int width, int precision, int size)

{

	UNUSED(types);

	UNUSED(buffer);

	UNUSED(flags);

	UNUSED(width);

	UNUSED(precision);

	UNUSED(size);

	return (write(1, "%%", 1));

}



/************************* PRINT INT *************************/

/**

 * print_int - Print int

 * @types: Lista of arguments

 * @buffer: Buffer array to handle print

 * @flags:  Calculates active flags

 * @width: get width.

 * @precision: Precision specification

 * @size: Size specifier

 * Return: Number of chars printed

 */

int print_int(va_list types, char buffer[],

		int flags, int width, int precision, int size)

{

	int i = BUFF_SIZE - 2;

	int neg = 0;

	long int n = va_arg(types, long int);

	unsigned long int num;



	n = convert_size_number(n, size);



	if (n == 0)

		buffer[i--] = '0';



	buffer[BUFF_SIZE - 1] = '\0';

	num = (unsigned long int)n;



	if (n < 0)

	{

		num = (unsigned long int)((-1) * n);

		neg = 1;

	}



	while (num > 0)

	{

		buffer[i--] = (num % 10) + '0';

		num /= 10;

	}



	i++;



	return (write_number(neg, i, buffer, flags, width, precision, size));

}



/************************* PRINT BINARY *************************/

/**

 * print_binary - Prints an unsigned number

 * @types: Lista of arguments

 * @buffer: Buffer array to handle print

 * @flags:  Calculates active flags

 * @width: get width.

 * @precision: Precision specification

 * @size: Size specifier

 * Return: Numbers of char printed.

 */

int print_binary(va_list types, char buffer[],

		int flags, int width, int precision, int size)

{

	unsigned int n, l, x, sum;

	unsigned int a[32];

	int count;



	UNUSED(buffer);

	UNUSED(flags);

	UNUSED(width);

	UNUSED(precision);

	UNUSED(size);



	n = va_arg(types, unsigned int);

	l = 2147483648; 

	a[0] = n / l;

	for (x = 1; x < 32; x++)

	{

		l /= 2;

		a[x] = (n / l) % 2;

	}

	for (x = 0, sum = 0, count = 0; x < 32; x++)

	{

		sum += a[x];

		if (sum || x == 31)

		{

			char z = '0' + a[x];



			write(1, &z, 1);

			count++;

		}

	}

	return (count);

}
