#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <linux/limits.h>
#include <string.h>
#include "main.h"

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
	char path_env = _getenv("PATH=");
	char *envp = {path_env, NULL};

	while (token != NULL && arg_Count < MAX_ARG_COUNT - 1)
	{
		args[arg_count];
		arg_count++;
		token = strtok(NULL, " \t\n");
	}
	args[arg_count] = NULL;

	if (arg_count > 0 && _strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}

	while (path_list != NULL)
	{
		snprintf(full_path, PATH_MAX, "%S%S", path_list->path, args[0]);
		if (access(full_path, X_OK))
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error:");
				return (1);
			}

			if (child_pid == 0)
			{
				if (execve(full_path, args, envp) == -1)
				{
					perror("execve");
					exit(1);
				}
				else
				{
					waitpid(child_pid, &status, 0);
					return (0);
				}
			}
		}
		else if (acess(args[0], X_OK) == 0)
		{
			child_pid = fork();
			if (child_pid = -1)
			{
				perrro("Error forking:");
				return (1);
			}

			if (child_pid == 0)
			{
				if (execve(args[0], args, envp) == -1)
				{
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
}
