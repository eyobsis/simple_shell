#include "main.h"
#include "printf.h"

/**
 * interactive - executes the shell in interactive mode
 * @count: command number
 * Return: Always 0
 */

int interactive(unsigned int count)
{
	while (1) /* Infinite loop */
	{
		char *line = NULL, *token = NULL, *tokens[100] = { NULL };
		char *delim = " \n\t\r\a;";
		pid_t pid = 0;
		int i = 0, a = 0, status = 0;

		line = get_command();
		if (line == NULL)
		{
			perror("malloc failure");
			continue; }
		token = strtok(line, delim);
		while (token != NULL && i < 99)
		{
			tokens[i] = token;
			token = strtok(NULL, delim);
			i++; }
		if (*tokens == NULL)
		{
			free(line);
			continue; }
		if (_strcmp(*tokens, "exit") == 0)
		{
			free(line);
			return (EXIT_SUCCESS); }
		a = check_for_bin(tokens);
		pid = fork();
		if (pid == -1)
		{
			perror("fork: ");
			return (EXIT_SUCCESS); }
		if (pid == 0) /* run execve in a child process */
			execute(tokens, a, count);
		else
		{
			count++;
			wait(&status);
			free(line); }}
	return (EXIT_SUCCESS); }
