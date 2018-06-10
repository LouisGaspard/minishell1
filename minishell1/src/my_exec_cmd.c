/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** minishell1
*/

#include "my.h"
#include "minishell.h"

int	my_exec_cmd(char *path, char **tab, char **env)
{
	int	a = 0;
	int	pid;

	pid = fork();
	if (pid == 0)
		if ((execve(path, tab, env)) == -1)
			return (-1);
	waitpid(pid, &a, 0);
	if (a == 139)
		my_printf("%s", ERR_SEG);
	if (a == 136)
		my_printf("%s", ERR_FLOAT);
	return (0);
}
