#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
char* search_command(char* command) {
	char* path = getenv("PATH");
	char* token = strtok(path, ":");
	struct stat buffer;
	char* command_path = malloc(strlen(command) + strlen(token) + 2); // +2 for '/' and null terminator

	while (token != NULL) {
		sprintf(command_path, "%s/%s", token, command);
		if (stat(command_path, &buffer) == 0 && S_ISREG(buffer.st_mode) && (buffer.st_mode & S_IXUSR)) {
			return command_path;
		}
		token = strtok(NULL, ":");
	}

	free(command_path);
	return NULL;
}
int main() {
	char command[100];
	printf("Enter a command: ");
	fgets(command, sizeof(command), stdin);
	command[strcspn(command, "\n")] = '\0'; // Remove trailing newline character

	char* command_path = search_command(command);
	if (command_path != NULL) {
		pid_t pid = fork();
		if (pid == 0) {
			// Child process
			char* arguments[] = {command_path, NULL}; // Create an array of arguments
			execve(command_path, arguments, NULL); // Pass the array as the second argument
			perror("execve"); // Execve failed
			exit(1);
		} else if (pid > 0) {
			// Parent process
			wait(NULL); // Wait for the child process to finish
		} else {
			perror("fork"); // Fork failed
			exit(1);
		}
	} else {
		printf("Command not found\n");
	}

	return 0;
}
