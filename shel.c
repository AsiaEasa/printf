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
			printf("%s",fullPath);
			return fullPath; // return the full path
		}

		free(fullPath);
		token = strtok(NULL, ":");
	}

	free(pathCopy);
	return NULL; // command not found in PATH
}

void executeCommand(const char* command) {
	// Tokenize the command to separate arguments
	char* token;
	char* arguments[MAX_COMMAND_LENGTH / 2 + 1];
	int argCount = 0;

	char* commandCopy = strdup(command); // create a copy of command string

	token = strtok(commandCopy, " ");
	while (token != NULL) {
		arguments[argCount] = token;
		argCount++;
		token = strtok(NULL, " ");
	}
	arguments[argCount] = NULL;
int m = 0;
    while (arguments[m] != NULL) {
	            printf("%s\n",arguments[m]);
		            m++;
			        }
	char* commandPath = findCommandPath(arguments[0]);

printf("%s\n",commandPath);
	if (commandPath) {
		pid_t pid = fork();

		if (pid == 0) {
			// Child process
			execv(commandPath, arguments);

			// This line should not be reached unless execv fails
			perror("execv");
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

	free(commandCopy);
}

int main() {
	char command[MAX_COMMAND_LENGTH];

	while (1) {
		printf("Enter a command: ");
		fgets(command, sizeof(command), stdin);

		// Remove trailing newline character
		command[strcspn(command, "\n")] = 0;

		executeCommand(command);
	}

	return 0;
}
