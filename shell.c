#define _GNU_SOURCE
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
 * shell - A shell interface to execute
 * different commands
 *
 * Return: 0 on success, and 1 otherwise
 */

int shell(void)
{
	struct path_node *path_list = build_path_list();
	char *input = NULL;
	size_t len = 0;
	ssize_t n;
	int i;

	while (1)
	{
		_putchar('$');
		_putchar(' ');
		fflush(stdout);
		n = getline(&input, &len, stdin);
		if (n == -1)
		{
			if (feof(stdin))
			{
				_putchar('\n');
				_putchar('^');
				_putchar('D');
				_putchar('\n');
				break;
			}
			else
			{
				perror("getline");
				break;
			}
		}
		i = 0;
		while (input[i])
		{
			_putchar(input[i]);
			i++;
		}
		execute_command(input, path_list);
		free(input);
		input = NULL;
		len = 0;
	}
	free(input);
	free_paths(path_list);

	return (0);
}
