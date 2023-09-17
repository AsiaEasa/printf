#include "main.h"



/****************** PRINT POINTER ******************/

/**

 * print_pointer - Prints the value of a pointer variable

 * @types: List a of arguments

 * @buffer: Buffer array to handle print

 * @flags:  Calculates active flags

 * @width: get width

 * @precision: Precision specification

 * @size: Size specifier

 * Return: Number of chars printed.

 */

int print_pointer(va_list types, char buffer[],

		int flags, int width, int precision, int size)

{

	char c = 0, add = ' ';

	int in = BUFF_SIZE - 2, len = 2, start = 1; 

	unsigned long addrs;

	char map_to[] = "0123456789abcdef";

	void *addrs = va_arg(types, void *);



	UNUSED(width);

	UNUSED(size);



	if (addrs == NULL)

		return (write(1, "(nil)", 5));



	buffer[BUFF_SIZE - 1] = '\0';

	UNUSED(precision);



	addrs = (unsigned long)addrs;



	while (addrs > 0)

	{

		buffer[in--] = map_to[addrs % 16];

		addrs /= 16;

		len++;

	}



	if ((flags & F_ZERO) && !(flags & F_MINUS))

		add = '0';

	if (flags & F_PLUS)

		c = '+', len++;

	else if (flags & F_SPACE)

		c = ' ', len++;



	in++;



	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/

	return (write_pointer(buffer, in, len,

				width, flags, add, c, start));

}



/************************* PRINT NON PRINTABLE *************************/

/**

 * print_non_printable - Prints ascii codes in hexa of non printable chars

 * @types: Lista of arguments

 * @buffer: Buffer array to handle print

 * @flags:  Calculates active flags

 * @width: get width

 * @precision: Precision specification

 * @size: Size specifier

 * Return: Number of chars printed

 */

int print_non_printable(va_list types, char buffer[],

		int flags, int width, int precision, int size)

{

	int i = 0, offs = 0;

	char *ptr = va_arg(types, char *);



	UNUSED(flags);

	UNUSED(width);

	UNUSED(precision);

	UNUSED(size);



	if (ptr == NULL)

		return (write(1, "(null)", 6));



	while (ptr[i] != '\0')

	{

		if (is_printable(ptr[i]))

			buffer[i + offs] = ptr[i];

		else

			offs += append_hexa_code(ptr[i], buffer, i + offs);



		i++;

	}



	buffer[i + offs] = '\0';



	return (write(1, buffer, i + offs));

}



/************************* PRINT REVERSE *************************/

/**

 * print_reverse - Prints reverse string.

 * @types: Lista of arguments

 * @buffer: Buffer array to handle print

 * @flags:  Calculates active flags

 * @width: get width

 * @precision: Precision specification

 * @size: Size specifier

 * Return: Numbers of chars printed

 */



int print_reverse(va_list types, char buffer[],

		int flags, int width, int precision, int size)

{

	char *ptr;

	int i, count = 0;



	UNUSED(buffer);

	UNUSED(flags);

	UNUSED(width);

	UNUSED(size);



	ptr = va_arg(types, char *);



	if (ptr == NULL)

	{

		UNUSED(precision);



		ptr = ")Null(";

	}

	for (i = 0; ptr[i]; i++)

		;



	for (i = i - 1; i >= 0; i--)

	{

		char z = ptr[i];



		write(1, &z, 1);

		count++;

	}

	return (count);

}

/************************* PRINT A STRING IN ROT13 *************************/

/**

 * print_rot13string - Print a string in rot13.

 * @types: Lista of arguments

 * @buffer: Buffer array to handle print

 * @flags:  Calculates active flags

 * @width: get width

 * @precision: Precision specification

 * @size: Size specifier

 * Return: Numbers of chars printed

 */

int print_rot13string(va_list types, char buffer[],

		int flags, int width, int precision, int size)

{

	char x;

	char *ptr;

	unsigned int i, j;

	int count = 0;

	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";



	ptr = va_arg(types, char *);

	UNUSED(buffer);

	UNUSED(flags);

	UNUSED(width);

	UNUSED(precision);

	UNUSED(size);



	if (ptr == NULL)

		ptr = "(AHYY)";

	for (i = 0; ptr[i]; i++)

	{

		for (j = 0; in[j]; j++)

		{

			if (in[j] == ptr[i])

			{

				x = out[j];

				write(1, &x, 1);

				count++;

				break;

			}

		}

		if (!in[j])

		{

			x = str[i];

			write(1, &x, 1);

			count++;

		}

	}

	return (count);

}
