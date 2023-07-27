#include "main.h"

/**
 * my_atoi - converts string to integer value
 * @str: string input to be onverted
 *
 * Return: the converted string value in int  on success
 */

int my_atoi(char *str)
{
	int sign = 1;
	int value = 0;

	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			value = value * 10 + (*str - '0');
		else
			return (0);
		str++;
	}
	return (sign * value);
}
