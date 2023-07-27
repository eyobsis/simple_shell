#include "main.h"
#include "printf.h"
/**
 * execute_bin - executes commands with a /bin/
 * @av: the command
 *
 * Return: None
 */

void execute_bin(char **av,int count)
{
	if ((execve(av[0], av, environ)) == 0)
	{
		_printf("hsh: %u: %s: not found", count, av[0]);
		exit(EXIT_SUCCESS);
	}
}

/**
 * execute - executes the given commands
 * @av: takes in the command
 * @a: 5 if the command starts with "/bin/"
 * @count: the command number
 * return: None
 */

void execute(char **av, int a, int count)
{
	char *full_path = NULL, *path = NULL, *token = NULL, *delim = ":";
	size_t dir_len = 0, cmd_len = 0, slash_len = 1;

	if(_strcmp("env", av[0]) == 0)
	{
		env();
		exit(EXIT_SUCCESS); }
	if (a == 5)
		execute_bin(av, count);
	path = _getenv("PATH");
	if (path == NULL || *path == '\0')
	{
		perror("PATH variable not set");
		exit(EXIT_SUCCESS); }
	token = strtok(path, delim);
	if (token == NULL)
	{	perror("empty");
		exit(EXIT_SUCCESS); }
	while (token)
	{
		dir_len = _strlen(token);
		cmd_len = _strlen(av[0]);
		full_path = malloc(dir_len + cmd_len + slash_len + 1);
		if (!full_path)
		{
			perror("malloc failure");
			exit(EXIT_SUCCESS); }
		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, av[0]);
		if ((access(full_path, X_OK)) == 0)
		{
			if ((execve(full_path, av, environ)) == -1)
			{
				perror("execve");
				exit(EXIT_SUCCESS); }}
		else
		{
			free(full_path);
			token = strtok(NULL, delim); }}
	if (token == NULL)
	{
		_printf("hsh: %u: %s: not found\n", count, av[0]);
		exit(EXIT_SUCCESS); }}
