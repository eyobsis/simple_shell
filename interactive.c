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
		unsigned int exit_status = 0;

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
			if (i == 2 && tokens[1])
				exit_status = my_atoi(tokens[1]);
			exit_command(exit_status); }
		else if (_strcmp(*tokens, "setenv") == 0)
		{
			if (set_env(tokens) == -1)
			_printf("setenv:invalid arg\n", stderr);
				free(line);
				continue; }
		else if (_strcmp(*tokens, "unsetenv") == 0)
		{
			if (unset_env(tokens) == -1)
			_printf("unsetenv:invalid arg\n", stderr);
				free(line);
				continue; }
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
			free(line);
		}}
	return (0); }
