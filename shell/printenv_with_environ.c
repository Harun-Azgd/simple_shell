#include <stdio.h>
#include <stdlib.h>

extern char **environ; // Declare the environ variable

int main() {
	// Iterate through the environment variables using environ
	for (char **env = environ; *env != NULL; env++)
	{
	printf("%s\n", *env);
	}

	return 0;
}
