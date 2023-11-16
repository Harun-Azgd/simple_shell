#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
	printf("Usage: %s <filename>\n", argv[0]);
	return (1);
	}

	const char *filename = argv[1];
	char *path = getenv("PATH");

	if (path == NULL)
	{
	fprintf(stderr, "PATH environment variable is not set.\n");
	return (1);
	}

	char *path_copy = strdup(path);

	if (path_copy == NULL)
	{
	perror("Memory allocation error");
	return (1);
	}

	char *dir = strtok(path_copy, ":");

	while (dir != NULL)
	{

	char full_path[PATH_MAX];

	snprintf(full_path, sizeof(full_path), "%s/%s", dir, filename);
	if (access(full_path, F_OK) == 0)
	{
		printf("%s\n", full_path);
		free(path_copy);
		return (0);
	}
	dir = strtok(NULL, ":");
	}

	printf("%s not found in the PATH.\n", filename);

	free(path_copy);
	return (0);
}
