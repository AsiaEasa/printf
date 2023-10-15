#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_WORD_COUNT 1024
#define BUFFER_SIZE 1024
int handle_exit(char *exit_args)
{

	exit(0); }

	int main() { 
		char *in = NULL;
		char str[BUFFER_SIZE], *words;
		size_t in_size = 0, no_of_words;
		ssize_t get;
		char *prompt = "$ ";
		while (1) {
			write(STDOUT_FILENO, prompt, 2);
			get = getline(&in, &in_size, stdin);
			if (get == -1) {
				perror("getline");
				exit(EXIT_FAILURE);
			}

			if (in[get - 1] == '\n') {

				in[get - 1] = '\0';
			}
			words = strtok(in, " ");
			while (words != NULL)
	words =strtok(NULL," ");
strcpy(str, in);
	if (strncmp(str, "exit",4) == 0)
			break;

		pid_t pid = fork();

		if (pid == -1) {
			printf("Error forking process.\n");
			exit(EXIT_FAILURE);
		}

		if (pid == 0) {
			if (execlp(in, in, NULL) == -1) {
				printf("Command not found: %s\n", in);
				exit(EXIT_FAILURE);
			}
		} else {
			wait(NULL);
		}
	}

free(in);
return 0;
}
