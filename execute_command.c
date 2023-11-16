#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <linux/limits.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

#define MAX_ARG_COUNT 10

/**
 * execute_command - Executes the shell commands
 * @input: The input user enters in shell
 * @path_list: The linked list that contains PATH env dirs
 *
 * Return: 0 on success, and 1 otherwise
 */
int execute_command(char *input, struct path_node *path_list)
{
	char *args[MAX_ARG_COUNT];
	int arg_count = 0;
	char *token = strtok(input, " \t\n");
	pid_t child_pid;
	int status;
	char full_path[PATH_MAX];
	char *envp[2];
	extern char **environ;
	unsigned int i;
	envp[0] = _getenv("PATH");
	envp[1] = NULL;

	while (token != NULL && arg_count < MAX_ARG_COUNT - 1)
	{
		args[arg_count] = token;
		arg_count++;
		token = strtok(NULL, " \t\n");
	}
	args[arg_count] = NULL;

	if (arg_count > 0 && _strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}

	else if (arg_count > 0 && _strcmp(args[0], "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			printf("%s\n", environ[i]);
		}
		return (0);
	}

	while (path_list != NULL)
	{
		snprintf(full_path, PATH_MAX, "%s%s", path_list->path, args[0]);
		if (access(full_path, X_OK) == 0)
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error:");
				return (1);
			}

			if (child_pid == 0)
			{
				execve(full_path, args, envp);
					perror("execve");
					exit(1);
			}
			else
			{
				waitpid(child_pid, &status, 0);
				return (0);
			}
		}
		else if (access(args[0], X_OK) == 0)
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error forking:");
				return (1);
			}

			if (child_pid == 0)
			{
				execve(args[0], args, envp);
					perror("execve");
					exit(1);
			}
			else
			{		
				waitpid(child_pid, &status, 0);
				return (0);
			}
		}
		path_list = path_list->next;
	}
	fprintf(stderr, "Command not found: %s\n", args[0]);
	return (1);
}
