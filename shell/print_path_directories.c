#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_path_directories()
{
	char *path = getenv("PATH");

	if (path == NULL) {
		fprintf(stderr, "PATH environment variable is not set.\n");
		return;
	}

	char *path_copy = strdup(path);
	if (path_copy == NULL) {
		perror("Memory allocation error");
		return;
	}

	char *dir = strtok(path_copy, ":");
	while (dir != NULL) {
		printf("%s\n", dir);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
}

int main() {
		printf("Directories in the PATH environment variable:\n");
		print_path_directories();

	return 0;
}
