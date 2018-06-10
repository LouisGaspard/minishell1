/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** minishell1
*/

#include "my.h"

char	**get_in_env(char **env, char *str)
{
	int	a = 0;

	while (env[a]) {
		if ((my_strncmp(env[a], str, 5)) == 0)
			return (my_str_to_word_array(env[a] + 5));
		a++;
	}
	return (env);
}
