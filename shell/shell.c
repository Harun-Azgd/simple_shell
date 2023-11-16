#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	char input[1024];
	char* command;

	while (1) {
		printf("$ ");
		if (fgets(input, sizeof(input), stdin) == NULL) {
			break;
		}

		// Remove the newline character
		input[strcspn(input, "\n")] = '\0';

		// Fork a child process
		pid_t child_pid = fork();

		if (child_pid == -1) {
			perror("fork");
			exit(1);
		} else if (child_pid == 0) { // Child process
			command = strtok(input, " ");
			if (command != NULL) {
				// Execute the command with its full path
				execlp(command, command, (char*)NULL);
				perror("execlp");
				exit(1);
			}
		} else { // Parent process
			int status;
			waitpid(child_pid, &status, 0);
		}
	}

	return 0;
}
