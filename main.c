#include "main.h"
#include "printf.h"

/**
 * interactive - executes the shell in interactive mode
 *
 * Return: Always 0
 */

int interactive(void)
{
	while (1) /* Infinite loop */
	{
		char *line = NULL, *token = NULL, *tokens[100] = { NULL };
		char *delim = " \n\t\r\a";
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
			return (0); }
		a = check_for_bin(tokens);
		pid = fork();
		if (pid == -1)
		{
			perror("fork: ");
			return (EXIT_SUCCESS); }
		if (pid == 0) /* run execve in a child process */
			execute(tokens, a);
		else
		{
			wait(&status);
			free(line); }}
	return (0);
}
/**
 * non_interactive - executes the shell in non interactive mode
 * @line: gets the command straight from the command line
 *
 * Return: Always 0
 */

int non_interactive(char * line)
{
	char *token = NULL, *tokens[100] = { NULL };
	char *delim = " \n\t\r\a";
	pid_t pid = 0;
	int i = 0, a = 0, status = 0;

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
		i++;
		token = strtok(NULL, delim); }
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
		execute(tokens, a);
	else
		wait(&status);

	return (0);
}

/**
 * readline - custom readline, reads from the command line
 * @fd: file descriptor
 * @buffer: stores the input
 * @max_len: Max length
 */

int readline(int fd, char *buffer, int max_len)
{
	int read_bytes = 0;
	char ch;

	while (read_bytes < max_len && read(fd, &ch, 1) == 1) 
	{
		buffer[read_bytes++] = ch;
		if (ch == '\n')
			break; }
	return (read_bytes);
}

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: Always 0
 */

int main (int argc, char *argv[])
{
	int fd = 0;
	char line[100] = "";
	int a = 0;

	if (argc == 2)
	{
		if (argv[1] == NULL)
			return (0);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("file couldn't be opened");
			return (EXIT_SUCCESS);
		}

		while (readline(fd, line, sizeof(line)) > 0)
			a = non_interactive(line);
	}
	else
		a = interactive();
	return (a);
}
