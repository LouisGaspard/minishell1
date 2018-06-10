/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

#include "my.h"
#include "minishell.h"

int	in_tab(char *str, char *env)
{
	int	a = 0;

	while (env[a] != '=')
		a++;
	if (my_strncmp(str, env, a) == 0)
		return (a);
	return (0);
}

int	already_in_tab(char *str, char **env)
{
	int	a = 0;
	int	len = 0;

	while (env[a]) {
		if ((len = in_tab(str, env[a])) != 0)
			return (len);
		a++;
	}
	return (0);
}

char	**change_line_in_tab(char **tab, char **new_env, int len)
{
	int	a = 0;
	char	*str;

	str = my_strcat(tab[1], "=");
	if (tab[2] == NULL)
		str = my_strcat(str, "");
	else
		str = my_strcat(str, tab[2]);
	while (my_strncmp(tab[1], new_env[a], len) != 0)
		a++;
	new_env[a] = my_strdup(str);
	return (new_env);
}

char	**setenv1(char **new_env, char **tab)
{
	int	len = 0;

	if (my_str_is_alphanum(tab[1]) == 1) {
		my_printf("%s%s%s", tab[0], ERR_SETENV_CHAR, ERR_SET2);
		return (new_env);
	}
	if (tab[2] != NULL && tab[3] != NULL) {
		my_printf("%s%s", tab[0], ERR_SETENV_ARG);
		return (new_env);
	}
	if ((len = already_in_tab(tab[1], new_env)) != 0) {
		return ((new_env = change_line_in_tab(tab, new_env, len)));
	}
	if (my_char_isnum(tab[1][0]) == 1) {
		if (tab[2] == NULL)
			return (new_env = my_add_env(tab[1], "", new_env));
		else
			return (my_add_env(tab[1], tab[2], new_env));
	}
	return (new_env);
}

char	**my_setenv(char **tab, char **env)
{
	char	**new_env;

	if ((new_env = my_realloc_env(env)) == NULL)
		return (NULL);
	if (tab[1] != NULL) {
		new_env = setenv1(new_env, tab);
		return (new_env);
	} else if (tab[1] == NULL && tab[2] == NULL) {
		my_show_word_array(new_env);
	} else
		my_printf("%s%s", tab[0], ERR_SETENV_NAME);
	return (env);
}
