#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite)
{
	if (name == NULL || value == NULL)
	{
		return (-1);
	}

	for (char **env = environ; *env != NULL; env++)
	{
		if (strncmp(*env, name, strlen(name)) == 0 && (*env)[strlen(name)] == '=')
		{
			if (overwrite)
		{
		char *new_entry = (char *)malloc(strlen(name) + strlen(value) + 2);

		if (new_entry == NULL)
		{
			perror("Memory allocation error");
			return (-1);
		}
		sprintf(new_entry, "%s=%s", name, value);
		free(*env);
		*env = new_entry;
		return (0);
		}
		else
			{
			return (0);
			}
		}
	}

	size_t new_entry_len = strlen(name) + strlen(value) + 2;
	char *new_entry = (char *)malloc(new_entry_len);

	if (new_entry == NULL)
	{
	perror("Memory allocation error");
	return (-1);
	}
	sprintf(new_entry, "%s=%s", name, value);

	int env_count = 0;

	for (char **env = environ; *env != NULL; env++)
	{
	env_count++;
	}

	char **new_environ = (char **)malloc((env_count + 2) * sizeof(char *));

	if (new_environ == NULL)
	{
		perror("Memory allocation error");
		free(new_entry);
		return (-1);
	}

	for (int i = 0; i < env_count; i++)
	{
	new_environ[i] = environ[i];
	}

	new_environ[env_count] = new_entry;
	new_environ[env_count + 1] = NULL;

	environ = new_environ;

	return (0);
}
int main(void)
{
	if (setenv("MY_VARIABLE", "12345", 1) == 0)
	{
	printf("Environment variable set or updated successfully.\n");
	}
	else
	{
		fprintf(stderr, "Failed to set or update environment variable.\n");
	}

	for (char **env = environ; *env != NULL; env++)
	{
	printf("%s\n", *env);
	}

	return (0);
}
