/*#include <string.h>
#include <stddef.h>*/
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * _getenv - gets an environment variable
 * and returns its value.
 * @name: the name of the variable.
 *
 * Return: a pointer to its string value.
 */

char *_getenv(const char *name)
{
	extern char **environ;
	unsigned int i = 0;
	/*char *token;*/
	char *path_env = NULL;

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], name, 5) == 0)
		{
			path_env = environ[i] + 5;
			break;
		}
	}

	if (path_env == NULL)
	{
		printf("PATH env not found\n");
		return (NULL);
	}

	printf("%s\n", path_env);
	return (path_env);


	/*while (environ[i] != NULL)
	{
		token = strtok(environ[i], "=");
		if (_strcmp(token, name) == 0)
			return (strtok(NULL, "="));
		i++;
	}
	return (NULL);*/
}
