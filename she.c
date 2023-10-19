#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main() {
	char *input = NULL;
	size_t bufsize = 0;
	ssize_t characters;

	while (1) {
		printf(">> ");

		characters = getline(&input, &bufsize, stdin);

		if (characters == -1) {
			printf("Error reading input.\n");
			exit(EXIT_FAILURE);
		}

		if (input[characters - 1] == '\n') {
			// Remove trailing newline character
			input[characters - 1] = '\0';
		}

		if (strcmp(input, "exit") == 0) {
			break;
		}

		pid_t pid = fork();

		if (pid == -1) {
			printf("Error forking process.\n");
			exit(EXIT_FAILURE);
		}

		if (pid == 0) {
			// Child process
			if (execlp(input, input, NULL) == -1) {
				printf("Command not found: %s\n", input);
				exit(EXIT_FAILURE);
			}
		} else {
			// Parent process
			wait(NULL);
		}
	}

	free(input);
	return 0;
}
