#include "hsh.h"

/**
 * main - Entry point for the custom shell program.
 * @argc: Number of arguments provided.
 * @argv: Array of command-line arguments.
 * Return: Exit status.
 */
int main(int argc, char *argv[])
{int _stat, ex, enough;
	char *in, *_path, *fullpath, *prompt, **arg;
	size_t in_size = 0, no_of_words;
	ssize_t get;
	struct stat stat_in;

	enough = 1;
	prompt = "$ ";
	while (enough)
	{in = malloc(sizeof(char) * MAX_COMMAND_LENGTH);
		if (isatty(STDIN_FILENO) == 0)
			enough = 0;
		else

			write(STDOUT_FILENO, prompt, 2);

		in = my_getline();
		arg = malloc(BUFFER_SIZE * sizeof(char *));
		if (arg == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		arg = str_tok(in, ' ');

		if (_strcmp(arg[0], "setenv") == 0)
		{
			if (arg[1] != NULL && arg[2] != NULL)
			{
				set(arg[1], arg[2]);
				continue;	}
			else
				perror("Invalid setenv command syntax.");
		} else if (_strcmp(arg[0], "unsetenv") == 0)
		{
			if (arg[1] != NULL)
			{ unset(arg[2]);
				continue; }
			else
				perror("Invalid unsetenv command syntax");
		}

		if (_strncmp(arg[0], "cd", 2) == 0)
			chDir(arg[1]);
		if (_strncmp(arg[0], "exit", 4) == 0)
			handle_exit(arg);

		if (_strncmp(arg[0], "env", 3) == 0 || _strncmp(arg[0], "printenv", 4) == 0)
		{ envi(arg);
			continue; }

		ex = stat(arg[0], &stat_in);
		if (ex)

		{	_path = Path(arg[0]);
			if (!_path)
			{perror("path");
				continue; }}
		if (_path)
			my_fork(arg, _path); }
	free(in);
	return (0);
}
