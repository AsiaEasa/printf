#include "hsh.h"
/**
 *_exit - handles the 'exit' buil-in command
 * @exit_args: Arrguments for the exit command.
 * @no_of_args: Number of arguments passed.
 * Return: Nothing
 */


void _exit(char **exit_args, size_t no_of_args)
{
	int status =  EXIT_SUCCESS;

	if (exit_args[1])
		status = _atoi(exit_args[1]);
	free_all(exit_args, no_of_args);
	exit(status);
}


/**
 * _atoi - convert a string into an integer.
 * @s: the string to use.
 * Return: integer.
 */

int _atoi(char *s)
{
	int sign = 1, i = 0;
	unsigned int res = 0;

	while (!(s[i] <= '9' && s[i] >= '0') && s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] <= '9' && (s[i] >= '0' && s[i] != '\0'))
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	res *= sign;
	return (res);
}
