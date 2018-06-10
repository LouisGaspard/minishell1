/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

#include "my.h"
#include "minishell.h"

char	**my_add_env(char *s1, char *s2, char **env)
{
	int	a = 0;
	char	*str;

	str = my_strcat(s1, "=");
	str = my_strcat(str, s2);
	while (env[a])
		a++;
	env[a] = my_strdup(str);
	return (env);
}
