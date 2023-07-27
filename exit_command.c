#include "main.h"
#include "printf.h"

/**
 * exit_command - exits the shell with the specifies exit status
 * @exit_status: the exit status of the shell
 *
 * Return: void
 */

void exit_command(int exit_status)
{
	if (exit_status != 0)
		(void) exit_status;
	exit(exit_status);
}
