#ifndef SHELL_H
#define SHELL_H

/**
 * hsh - main shell loop
 * @info: pointer to parameter and return info struct
 * @av: argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int hsh(info_t *info, char **av);

/**
 * find_builtin - finds a builtin command
 * @info: pointer to parameter and return info struct
 *
 * Return: -1 if builtin not found,
 *         0 if builtin executed successfully,
 *         1 if builtin found but not successful,
 *         -2 if builtin signals exit()
 */
int find_builtin(info_t *info);

/**
 * find_cmd - finds a command in PATH
 * @info: pointer to parameter and return info struct
 *
 * Return: void
 */
void find_cmd(info_t *info);

/**
 * fork_cmd - forks a an exec thread to run cmd
 * @info: pointer to parameter and return info struct
 *
 * Return: void
 */
void fork_cmd(info_t *info);

#endif /* SHELL_H */

