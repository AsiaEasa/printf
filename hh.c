#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	char in[] = "/bin/ls";
	char *arg[10]; // Assuming you have a fixe
	char *words = strtok(in, " ");
	int i = 0;

	while (words != NULL && i < 10) {
		arg[i] = words;
		words = strtok(NULL, " ");
		i++;
	}

	arg[i] = NULL; // Set the last element of arg[] to NULL as required by execve()

	execve(arg[0], arg, NULL);

	// If execve() returns, it means an error occurred
	perror("execve");
	return 1;
}
