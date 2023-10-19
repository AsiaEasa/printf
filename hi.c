#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** createArray() {
	char** str = (char**)malloc(2 * sizeof(char*)); // Allocate memory for 2 rows

	for (int i = 0; i < 2; i++) {
		str[i] = (char*)malloc(20 * sizeof(char)); // Allocate memory for each string
	}

	strcpy(str[0], "Hello");
	strcpy(str[1], "world!");

	return str;
}

void freeArray(char** str) {
	for (int i = 0; i < 2; i++) {
		free(str[i]);
	}
	free(str);
}

int main() {
	char** str = createArray();

	// Printing the strings
	for (int i = 0; i < 2; i++) {
		printf("String %d: %s\n", i+1, str[i]);
	}

	freeArray(str);

	return 0;
}
