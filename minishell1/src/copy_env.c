/*
** EPITECH PROJECT, 2018
** copy_env
** File description:
** copy_env
*/

#include "my.h"

int	count_line(char **env)
{
	int	a = 0;

	while (env[a])
		a++;
	return (a);
}

char	**my_copy_env(char **env)
{
	char	**my_env;
	int	line_nb;
	int	b = 0;

	line_nb = count_line(env);
	if ((my_env = malloc(sizeof(char *) * (line_nb + 1))) == NULL)
		return (NULL);
	while (b + 1 != line_nb) {
		my_env[b] = my_strdup(env[b]);
		b++;
	}
	my_env[b] = NULL;
	return (my_env);
}
