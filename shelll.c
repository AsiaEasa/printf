#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
char* searchAndReplaceCommand(char* command) {
	char* path = getenv("PATH");
	char* token = strtok(path, ":");

	while (token != NULL) {
		char* fullPath = malloc(strlen(token) + strlen(command) + 2);
		sprintf(fullPath, "%s/%s", token, command);

		if (access(fullPath, X_OK) == 0) {
			free(command);
			command = strdup(fullPath);
			free(fullPath);
			return command;
		}

		free(fullPath);
		token = strtok(NULL, ":");
	}

	return command;
}
int main() {
	char* command = strdup("ls -l");
	char* correctedCommand = searchAndReplaceCommand(command);

	printf("Corrected command: %s\n", correctedCommand);

	// Execute the corrected command here

	free(correctedCommand);
	return 0;
}
