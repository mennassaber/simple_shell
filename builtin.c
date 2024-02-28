#include "shell.h"

/**
 * my_exit - Exits the shell
 * @info: Structure containing potential arguments.
 * Return: Exits with a given exit status
 *         (0) if info->argv[0] != "exit"
 */
int my_exit(info_t *info)
{
    int exit_code;

    if (info->argv[1])  /* If there is an exit argument */
    {
        exit_code = err_atoi(info->argv[1]);
        if (exit_code == -1)
        {
            info->status = 2;
            print_error(info, "Illegal number: ");
            e_puts(info->argv[1]);
            e_putchar('\n');
            return (1);
        }
        info->err_num = exit_code;
        return (-2);
    }
    info->err_num = -1;
    return (-2);
}

/**
 * my_cd - Changes the current directory of the process
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int my_cd(info_t *info)
{
    char *current_dir, *target_dir, buffer[1024];
    int chdir_ret;

    current_dir = getcwd(buffer, 1024);
    if (!current_dir)
        p_error("TODO: >>getcwd failure emsg here<<\n");
    if (!info->argv[1])
    {
        target_dir = get_env(info, "HOME=");
        if (!target_dir)
            chdir_ret = chdir((target_dir = get_env(info, "PWD=")) ? target_dir : "/");
        else
            chdir_ret = chdir(target_dir);
    }
    else if (strcmp(info->argv[1], "-") == 0)
    {
        if (!get_env(info, "OLDPWD="))
        {
            puts(current_dir);
            putchar('\n');
            return (1);
        }
        puts(get_env(info, "OLDPWD="));
        putchar('\n');
        chdir_ret = chdir((target_dir = get_env(info, "OLDPWD=")) ? target_dir : "/");
    }
    else
        chdir_ret = chdir(info->argv[1]);
    if (chdir_ret == -1)
    {
        print_error(info, "can't cd to ");
        e_puts(info->argv[1]);
        e_putchar('\n');
    }
    else
    {
        set_env(info, "OLDPWD", get_env(info, "PWD="));
        set_env(info, "PWD", getcwd(buffer, 1024));
    }
    return (0);
}

/**
 * my_help - Displays help information
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int my_help(info_t *info)
{
    char **arg_array;

    arg_array = info->argv;
    puts("help call works. Function not yet implemented \n");
    if (0)
        puts(*arg_array); /* temp att_unused workaround */
    return (0);
}

