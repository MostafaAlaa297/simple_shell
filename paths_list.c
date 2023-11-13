#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * add_path - Adds a new node to the liked list
 * @head: A pointer to the first node of the list
 * @path: An array of the PATH env directories characters
 *
 * Return: The new added node
 */

struct path_node *add_path(struct path_node *head, const char *path)
{
	struct path_node *newnode = (struct path_node *)malloc(sizeof(struct path_node));
	
	if (newnode == NULL)
	{
		perror("newnode");
		exit(1);
	}
	newnode->path = _strdup(path);
	newnode->next = head;

	return (newnode);
}

/**
 * print_paths - Prints the linked list contains the PATH env
 * @head: A pointer to the first node of the list
 *
 * Return: Nothing
 */

void print_paths(struct path_node *head)
{
	struct path_node *current = head;

	while (current != NULL)
	{
		printf("%s\n", current->path);
		current = current->next;
	}
}

/**
 * free_paths - Frees the alloacated memory for the list
 * @head: A pointer that points to the first node of the list
 *
 * Return: Nothing
 */

void free_paths(struct path_node *head)
{
	struct path_node *current = head;

	while (current != NULL)
	{
		struct path_node *next = current->next;
		free(current->path);
		free(current);

		current = next;
	}
}

/**
 * build_path_list - Tokenizes the list that contains the PATH env
 *
 * Return: The tokenized path_list
 */

struct path_node *build_path_list()
{
	struct path_node *path_list = NULL;
	char *path_env = _getenv("PATH=");

	if (path_env != NULL)
	{
		char *token = strtok(path_env, ":");

		while (token != NULL)
		{
			path_list = add(path_list, token);
			token = strtok(NULL, ":");
		}
	}

	return (path_list);
}
