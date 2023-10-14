#include "hsh.h"
/**
 * check_in_path - checks if a file exists in PATH
 * @filename: Name of the file to be checked.
 * @stat_in: Stores information on the file if it is found.
 * @array_of_path: value of PATH in column
 * @no_of_path: number of directions in PATH
 * This function search for a file in PATH. If it is found,
 * it concatenates the absolute path with the file name.
 * Return: The full path of the file or MULL if not found.
 */

char *check_in_path(char *filename, struct stat *stat_in,
		char **array_of_path, size_t no_of_path)
{
	size_t s;
	char *my_path;

	for (s = 0; s < no_of_path; s++)
	{
		my_path = str_concat(3, array_of_path[s], "/", filename);

		if (state_of_command(my_path, *stat_in))
		{
			free_all(array_of_path, no_of_path);
			return (my_path);
		}
	}
	free_all(array_of_path, no_of_path);

	free(my_path);
	return (NULL);
}

/**
 *_strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 *
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * str_concat - concatenates three strings
 * @word1: input value
 * @word2: input value
 * @word3: input value
 * Return: void
 */

char *str_concat(const char *word1, const char *word2, const char *word3)
{
	int total_length = strlen(word1) + strlen(word2) + strlen(word3) + 1;
	char *result = malloc(total_length * sizeof(char));

	_strcpy(result, word1);
	_strcat(result, word2);
	_strcat(result, word3);
	return (result); }


/**
 *_path - checks if a file exists in PATH
 * @words: Arguments passed to the shell program.
 * @stat_in: Stores information on the file if it is
 * Return: The full path of the file or MULL if not found.
 */

int *_path(char **words, struct stat *stat_in)
{ char *path, **array_of_path, *my_path;
	size_t no_of_path;

	path = in_env(“PATH”);
	array_of_path = str_tok(path, ':', &no_of_path);
	my_path = check_in_path(words[0], *_state_in, &array_of_path, &no_of_path);

	if (!my_path)
	{ perror("Error (file status)");
		return (1); }

	return (my_path); }
