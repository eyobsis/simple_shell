#include "main.h"
#include "printf.h"

/**
 * non_interactive - executes the shell in non interactive mode
 * @line: gets the command straight from the command line
 *
 * Return: Always 0
 */

int non_interactive(char *line)
{
	char *token = NULL, *tokens[100] = { NULL };
	char *delim = " \n\t\r\a";
	pid_t pid = 0;
	int i = 0, a = 0, status = 0, count = 0;

	if (line == NULL)
	{
	perror("malloc failure");
		return (0); }
	token = strtok(line, delim);
	if (token == NULL)
		return (0);
	while (token != NULL && i < 99)
	{
		tokens[i] = token;
		token = strtok(NULL, delim);
		i++;	}
	if (*tokens == NULL)
		return (0);
	if (_strcmp(*tokens, "exit") == 0)
		return  (0);
	a = check_for_bin(tokens);
	pid = fork();
	if (pid == -1)
	{
		perror("fork: ");
		return (EXIT_SUCCESS); }
	if (pid == 0) /* run execve in a child process */
		execute(tokens, a, count);
	else
		wait(&status);
	return (0);
}

