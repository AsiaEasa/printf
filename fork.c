#include "hsh.h"

/**
 * my_fork - handles the fork
 * @words: Arguments passed to the shell program.
 * @no_of_words: Number of arguments passed
 * Return: Nothing If successful or error if it fails.
 */

int my_fork(char **words, size_t no_of_words)
{ pid_t child_ID, wait_ID = -1;
	int ID_status;

	child_ID = fork();

	if (child_ID == -1)
	{ free_all(words, no_of_words);
		handle_error(child_ID); }

	if (child_ID == 0)
		exe(words, no_of_words, environ);

	if (pid_t waitpid(child_ID, &ID_status, 0) == -1)
	{ free_all(words, no_of_words);
		handle_error(wait_ID); }
	return (0); }
