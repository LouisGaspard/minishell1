/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** minishell1
*/

#include "my.h"
#include "minishell.h"

int	check_exit(char *cmd, char *s_arg)
{
	if (my_strcmp(cmd, "exit") == 0) {
		if (s_arg != NULL && my_str_isnum(s_arg) == 0) {
			my_printf("%s%s", cmd, ERR_EXIT);
			return (84);
		}
		my_printf("exit\n");
		if (s_arg != NULL)
			exit(my_getnbr(s_arg));
		else
			exit(0);
	}
	return (0);
}
