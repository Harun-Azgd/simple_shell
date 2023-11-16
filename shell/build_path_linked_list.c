#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
*struct PathNode - Defines a structure for a node in linked list
*struct PathNode *addPathNode - Adds new directory node  to linked list
*void printPathList - prints the linked list
*void freePathList - function to free memory allocated in linked list
*freePathList - clean up and free memory
*/
struct PathNode
{
	char *directory;
	struct PathNode *next;
};

 struct PathNode *addPathNode(struct PathNode *head, const char *directory)
{
	struct PathNode *newNode = (struct PathNode *)malloc(sizeof(struct PathNode));

	if (newNode == NULL)
	{
	perror("Memory allocation error");
	exit(1);
	}
	newNode->directory = strdup(directory);
	newNode->next = head;
	return (newNode);
}

void printPathList(struct PathNode *head)
{
	struct PathNode *current = head;

	while (current != NULL)
	{
	printf("%s\n", current->directory);
	current = current->next;
	}
}

void freePathList(struct PathNode *head)
{

	while (head != NULL)
	{
		struct PathNode *temp = head;

		head = head->next;
		free(temp->directory);
		free(temp);
	}
}

int main(void)
{
	char *path = getenv("PATH");

	if (path == NULL)
	{
	fprintf(stderr, "PATH environment variable is not set.\n");
	return (1);
	}

	struct PathNode *pathList = NULL;

	char *token = strtok(path, ":");

	while (token != NULL)
	{
	pathList = addPathNode(pathList, token);
	token = strtok(NULL, ":");
	}

	printf("Directories in the PATH environment variable:\n");
	printPathList(pathList);

	freePathList(pathList);

	return (0);
}
