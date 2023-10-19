#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

char *my_getline(void) {
    char in[BUFFER_SIZE];
    char str[BUFFER_SIZE];
    static char buffer[BUFFER_SIZE];
    static int buffer_index;
    static int buffer_size;
    char *line = NULL;
    int line_index = 0;
    char current_char;

    while (1) {
        if (buffer_index >= buffer_size) {
            buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            buffer_index = 0;
            if (buffer_size <= 0) {
                if (line_index == 0)
                    return NULL;
                break;
            }
        }

        current_char = buffer[buffer_index++];
        if (current_char == '\n')
            break;

        char *temp = malloc((line_index + 1) * sizeof(char));
        if (temp == NULL) {
            // Handle memory allocation error
            free(line);
            return NULL;
        }
        memcpy(temp, line, line_index * sizeof(char));
        temp[line_index++] = current_char;
        free(line); // Free the previous allocation
        line = temp;
    }

    if (line != NULL) {
        char *temp = realloc(line, (line_index + 1) * sizeof(char));
        if (temp == NULL) {
            // Handle memory allocation error
            free(line);
            return NULL;
        }
        line = temp;
        line[line_index] = '\0';
    }

    return line;
}
int main(int argc, char *argv[])
{int ex, enough;
	char *in, *_path, *prompt, **arg;
//	struct stat stat_in;
	(void) argc, (void) argv;
char *line;
char str[BUFFER_SIZE];
char *words;
	enough = 1;
	prompt = "$ ";
	//while (enough)

	//{
	//	if (isatty(STDIN_FILENO) == 0)
//
//			enough = 0;
//		else

			write(STDOUT_FILENO, prompt, 2);
		in = my_getline();
   strcpy(str,in);
  words = strtok(str, " ");
int i = 0;
  while (words != NULL){
   arg[i]=words;
   words =strtok(NULL," ");
   i++;}
  arg[i] = NULL ;
	printf("%s",arg[0]);	
		/*if (arg == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		arg = str_tok(in, ' ');
		if (check(arg) == 0)
			continue;
		else
			ex = stat(arg[0], &stat_in);
		if (ex)

		{	_path = Path(arg[0]);
			if (!_path)
			{perror("path");
				continue; }}
		if (_path)
			my_fork(arg, _path); }*/
free(in);
  return (0);
}
