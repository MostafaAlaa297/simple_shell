#include <string.h>
#include <stddef.h>
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
	char *token;

	while (environ[i] != NULL)
	{
		token = strtok(environ[i], "=");
		if (_strcmp(token, name) == 0)
			return (strtok(NULL, "="));
		i++;
	}
	return (NULL);
}
