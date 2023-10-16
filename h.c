#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

char* findCommandPath(const char* command) {
	char* path = getenv("PATH");
	char* pathCopy = strdup(path); // create a copy of PATH string

	char* token = strtok(pathCopy, ":"); // split PATH by ":" delimiter

	while (token != NULL) {
		char* fullPath = malloc(strlen(token) + strlen(command) + 2); // allocate memory for the full path

		sprintf(fullPath, "%s/%s", token, command); // construct the full path

		if (access(fullPath, X_OK) == 0) { // check if file exists and is executable
			free(pathCopy);
			return fullPath; // return the full path
		}

		free(fullPath);
		token = strtok(NULL, ":");
	}

	free(pathCopy);
	return NULL; // command not found in PATH
}

void executeCommand(const char* command) {
	char* commandPath = findCommandPath(command);

	if (commandPath) {
		pid_t pid = fork();

		if (pid == 0) {
			// Child process
			execl(commandPath, command, (char*)NULL);

			// This line should not be reached unless execl fails
			perror("execl");
			exit(1);
		} else if (pid > 0) {
			// Parent process
			wait(NULL);
		} else {
			perror("fork");
			exit(1);
		}

		free(commandPath);
	} else {
		printf("Command not found in PATH\n");
	}
}

int main() {
	executeCommand("ls -l");

	return 0;
}
