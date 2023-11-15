#ifndef MAIN_H
#define MAIN_H

struct path_node
{
	char *path;
	struct path_node *next;
};

int _putchar(char c);

int execute_command(char *input, struct path_node *path_list);

char *_getenv(const char *name);

int _strncmp(const char *s1, const char *s2, int n);

int _strcmp(const char *s1, const char *s2);

char *_strdup(char *str);

struct path_node *add_path(struct path_node *head, char *path);

void print_paths(struct path_node *head);

void free_paths(struct path_node *head);

struct path_nod *build_path_list();

int shell();

#endif /* MAIN_H */
