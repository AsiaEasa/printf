#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

char *my_getline(void) {
    char in[BUFFER_SIZE];
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
        char *temp = malloc((line_index + 1) * sizeof(char));
        if (temp == NULL) {
            // Handle memory allocation error
            free(line);
            return NULL;
        }
        memcpy(temp, line, line_index * sizeof(char));
        temp[line_index] = '\0';
        free(line); // Free the previous allocation
        line = temp;
    }

    return line;
}

int main(int argc, char *argv[]) {
    int ex, enough;
    char *in, *_path, *prompt, **arg;
    enough = 1;
    prompt = "$ ";
    write(STDOUT_FILENO, prompt, 2);
    in = my_getline();
    printf("%s", in);
    free(in); // Free the allocated memory
    return 0;
}
