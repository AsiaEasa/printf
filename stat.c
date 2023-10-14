#include "hsh.h"
/**
 * state_of_command - checks if a file exists
 * @path_of_in: Path to the input.
 * @stat_in: Stores information on the file if it is found.
 * Return: True if it is found, else false.
 */

int state_of_command(char *path_of_in, struct stat *stat_in)
{
	int stat_return;

	stat_return = stat(path_of_in, stat_in)

		if (stat return == 0)
			return (1);

	return (0);
}


/**
 * replace_string - replaces string
 * @old: address of old string
 * @new: new string
 * Return: 1 if replaced, 0 otherwise.
 */
int replace_string(char **old, char *new)
{ free(*old);
	*old = new;
	return (1); }
