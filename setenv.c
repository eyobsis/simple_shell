#include "main.h"

/**
 * set_env - sets an environment var
 * @tokens: the array of command tokens
 *
 * Return: 0 on success , -1 on failure
 */

int set_env(char **tokens)
{
	if (!tokens[1] || !tokens[2] || tokens[3])
		return (-1);
	if (setenv(tokens[1], tokens[2], 1) == -1)
		return (-1);
	return (0);
}

/**
 * unset_env - unsets an environment variable
 * @tokens: the array of command tokens
 *
 * Return: 0 on success, -1 on failure
 */
int unset_env(char **tokens)
{
	if (!tokens[1] || tokens[2])
		return (-1);
	if (unsetenv(tokens[1]) == -1)
		return (-1);
return (0);
}
