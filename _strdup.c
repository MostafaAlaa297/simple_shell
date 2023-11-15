#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated
 * space in memory,
 * which contains a copy of the string given as a parameter.
 *
 * @str: The string.
 *
 * Return: NULL if str = NULL
 * a pointer to the duplicated string,
 * NULL if insufficient memory was available
 *
 */
char *_strdup(char *str)
{
	unsigned int len = 0;
	unsigned int i;
	char *s;

	if (str == NULL)
		return (NULL);
	while (str[len])
		len++;
	s = malloc(len + 1);
	if (s == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		s[i] = str[i];
	s[len] = '\0';
	return (s);
}
