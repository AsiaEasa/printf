#include "hsh.h"

/**
 * envi -handles the env built-in command
 *@env_word: Arguments for the env command
 *@no_of_word :Mumber of arguments passed.
 *Return: Nothing
 */

int envi(char **env_word, size_t no_of_word)
{ char **ptr = environ;
	char *env;
	char *in_env;

	if (!env_word[1])
	{
		while (*ptr)
		{
			print_env(*ptr);
			print_env("\n");
			ptr++; }
		free_all(env_word, on_of_word);
		free_all(ptr, on_of_word);
		free(env)
			free(in_env);
		return (1);  }

	else if (env_word[1])
	{ env = env_word[1];
		++env;
		in_env = in_env(env)
			write(1, in_env, _strlen(in_env));
		free_all(env_word, on_of_word);
		free_all(ptr, on_of_word);
		free(env)
			free(in_env);
		return (1); }

	else if (env_word[2])
	{ perror("Error (number of argument is not correct)");
		free_all(env_word, on_of_word);
		free_all(ptr, on_of_word);
		free(env)
			free(in_env);
		exit(EXIT_SUCCESS); }

	else
		return (0); }

/**
 * print_env - print all environment
 * @str: point to environment
 * Return: Nothing.
 */
	void print_env(const char *str)
	{
		while (*str)
		{
			write(1, str, 1);
			str++;
		}
	}


/**
 * free_all - frees memory allocated
 * @array: array to be freed.
 * @len: Number of strings (pointers) in the all.
 * Return: Nothing.
 */

	void free_all(char **array, size_t len)
	{
		size_t x;

		for (x = 0; x < len; x++)
			free(array[x]);

		free(array);
	}
