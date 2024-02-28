#include "shell.h"

/**
 * is_command - determines if a file is an executable command
 * @info: pointer to the info_t struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_command(info_t *info, char *path)
{
	struct stat st;

	if (!path || stat(path, &st) != 0)
		return (0);

	return (S_ISREG(st.st_mode));
}

/**
 * duplicate_chars - duplicates characters from path string
 * @pathstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *duplicate_chars(char *pathstr, int start, int stop)
{
	char *buf;
	int i, k;

	buf = malloc(sizeof(char) * (stop - start + 1));
	if (!buf)
		return (NULL);

	for (i = start, k = 0; i < stop; i++)
	{
		if (pathstr[i] != ':')
		{
			buf[k] = pathstr[i];
			k++;
		}
	}
	buf[k] = '\0';
	return (buf);
}

/**
 * find_path - finds the command in the PATH string
 * @info: pointer to the info_t struct
 * @pathstr: the PATH string
 * @cmd: the command to find
 *
 * Return: full path of cmd if found, otherwise NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);

	if (_strlen(cmd) > 2 && starts_with(cmd, "./"))
	{
		if (is_command(info, cmd))
			return (cmd);
	}

	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = duplicate_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_command(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}

