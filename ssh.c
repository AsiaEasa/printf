#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_WORD_COUNT 1024
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) { (void) argc;
	(void) argv;
	int status;
	char *in = NULL;
	char str[BUFFER_SIZE], *words, *arg[MAX_WORD_COUNT];
	size_t in_size = 0, no_of_words;
	int i;
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
		strcpy(str,in);
		words = strtok(str, " ");
	i = 0;
		while (words != NULL){
			arg[i]=words;
			words =strtok(NULL," ");
			i++;}
		arg[i] = NULL ;
		if (strncmp(str, "exit",4) == 0)
			break;
		 pid_t pid = fork();

		if (pid == -1) {
printf("Error forking process.\n");
	exit(EXIT_FAILURE); }
if (pid == 0) {
if (execve(arg[0], arg, NULL) == -1) {
printf("Command not found: %s\n", in);
	exit(EXIT_FAILURE);
		}
		 }

waitpid(pid, &status, 0);	 }
	return 0;
}
