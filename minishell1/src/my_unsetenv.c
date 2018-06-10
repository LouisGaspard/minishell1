/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

#include "my.h"
#include "minishell.h"

char	**env_remove_line(char **env, int line)
{
	int	t_line = 0;
	int	a = line;
	char	**new_env = env;

	if (line == -1)
		return (new_env);
	while (env[t_line])
		t_line++;
	free(env[line]);
	while (a != t_line - 1) {
		new_env[a] = my_strdup(env[a + 1]);
		a++;
	}
	new_env[a] = NULL;
	return (new_env);
}

int	find_same(char **tab, int i, char **new_env, int a)
{
	while (my_strncmp(tab[i], new_env[a], my_strlen(tab[i])) != 0) {
		if (a + 1 < count_line(new_env))
			a++;
		else
			return (-1);
	}
	return (a);
}

char	**my_unsetenv(char **tab, char **env)
{
	int	i = 1;
	int	a = 0;
	char	**new_env = env;

	if (tab[1] == NULL) {
		my_printf("%s%s", tab[0], ERR_FEW_ARG);
		return (new_env);
	}
	while (tab[i]) {
		a = 0;
		if (tab[i] != NULL)
			a = find_same(tab, i, new_env, a);
		env = env_remove_line(env, a);
		i++;
	}
	return (new_env);
}
