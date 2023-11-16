#include <stdio.h>

/**
 *fgets: Reads the input
 *return: Always 0
 */
int main() {
	while (1) {
		printf("$ ");
		char input[100]; // assuming commands are no longer than 100 characters
		fgets(input, sizeof(input), stdin);
		printf("%s", input);
	}
	return (0);
}
