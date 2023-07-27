#include "main.h"
#include "printf.h"

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	int fd = 0;
	char line[100] = "";
	int a = 0;
	unsigned int count = 1;

	if (argc == 2)
	{
		if (argv[1] == NULL)
			return (0);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			_printf("hsh: %d: Can't open %s\n", 0, argv[1]);
			return (EXIT_SUCCESS);
		}

		while (readline(fd, line, sizeof(line)) > 0)
			a = non_interactive(line);
	}
	else
		a = interactive(count);
	return (a);
}
