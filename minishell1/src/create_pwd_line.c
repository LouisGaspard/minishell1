/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

#include "my.h"
#include "minishell.h"

char    **create_pwd_line(char *pwd, char **env, int b)
{
	char    **new_env;
	int     a = 0;

	new_env = my_realloc_env(env);
	while (new_env[a])
		a++;
	if (b == 1)
		new_env[a] = my_strdup(my_strcat("PWD=", pwd));
	else
		new_env[a] = my_strdup(my_strcat("OLDPWD=", pwd));
	return (new_env);
}
