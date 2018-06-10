/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

#include "my.h"
#include "minishell.h"

char	**my_realloc_env(char **env)
{
	int	a = 0;
	char	**new_env;

	while (env[a])
		a++;
	if ((new_env = malloc(sizeof(char *) * (a + 2))) == NULL)
		return (NULL);
	a = 0;
	while (env[a]) {
		new_env[a] = my_strdup(env[a]);
		a++;
	}
	new_env[a] = NULL;
	new_env[a + 1] = NULL;
	return (new_env);
}
