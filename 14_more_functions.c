#include "shell.h"

/**
 * is_interactive - checks if shell is running in interactive mode
 * @info: pointer to info_t struct
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int is_interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delimiter - checks if a character is a delimiter
 * @c: character to check
 * @delim: delimiter string
 *
 * Return: 1 if true, 0 if false
 */
int is_delimiter(char c, char *delim)
{
	while (*delim)
	{
		if (*delim == c)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * is_alpha - checks if a character is alphabetic
 * @c: character to check
 *
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int is_alpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, output = 0;

	while (s[i])
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			output *= 10;
			output += (s[i] - '0');
		}
		else if (output != 0)
			break;
		i++;
	}
	return (sign * output);
}

