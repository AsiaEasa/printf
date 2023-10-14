#include "main.h"

/**
 * print_error - prints an error message
 * @arg_v: the argument input
 * @in_count: number of execution
 * @words: the command input
 * @str: string error to print
 * Return: print the error message if not return 0
 */

void print_error(const char *arg_v, size_t in_count,
		const char *words, char *str) {
		char p[1024];
		char *s = my_itoa(in_count, p, 10);

		write(1, arg_v, _strlen(arg_v));
		write(1, ": ", 2);
		write(1, s, _strlen(s));
		write(1, ": ", 2);
		write(1, words, _strlen(words));
		write(1, ": ", 2);
		write(1, str, _strlen(str));
	}

/**
 * reverse - Reverses the characters in a character array.
 * @str: The character array to be reversed.
 * @length: The length of the character array.
 */

void reverse(char str[], int length)
{
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
		char temp = str[start];

		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}


/**
 * my_itoa - Convert an integer to a string
 * @num: The integer to be converted.
 * @str: Character array to store the resulting string.
 * @base: The base for the conversion .
 * Return: A pointer to the 'str' array,
 * which contains the string representation
 * of the input 'num' in the specified 'base'.
 */

char *my_itoa(int num, char str[], int base)
{
	int i = 0;

	while (num != 0)
	{
		int rem = num % base;

		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num /= base;
	}

	str[i] = '\0';
	reverse(str, i);

	return (str);
}


/**
 * handle_error - Handle errors in a program execution.
 * @pid: The process ID (PID) to check for an error.
 * Return: None.
 */
void handle_error(pid_t pid)
{
	if (pid == -1)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}}
