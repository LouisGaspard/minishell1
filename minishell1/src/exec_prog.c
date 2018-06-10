/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

#include "my.h"
#include "minishell.h"

char    *parse_exec(char *str)
{
	char    *dest;
	int     a = my_strlen(str);
	int     b = 0;

	while (str[a] != '/') {
		b++;
		a--;
	}
	a++;
	dest = malloc(sizeof(char) * b + 1);
	b = 0;
	while (str[a]) {
		dest[b] = str[a];
		b++;
		a++;
	}
	return (dest);
}

int     my_exec_dir(char *str, char **tab, char **env)
{
	char    **tab_path = get_in_env(env, "PATH=");
	char    *path;
	int     y = 0;

	while (tab_path[y]) {
		path = my_strcat(tab_path[y], "/");
		path = my_strcat(path, str);
		if (access(path, F_OK) != -1) {
			my_exec_cmd(path, tab, env);
			return (1);
		}
		y++;
	}
	if ((my_exec_cmd(str, tab, env)) == 0)
		return (1);
	return (0);
}

int     exec_dir(char **tab, char **env)
{
	DIR	*repo;
	char    *str;

	if (access(tab[0], F_OK) == -1) {
		my_printf("%s%s", tab[0], ERR_NOT_FOUND);
		return (1);
	}
	if ((repo = opendir(tab[0])) != NULL) {
		my_printf("%s%s", tab[0], ERR_NOT_FOUND);
		return (1);
	}
	str = parse_exec(tab[0]);
	if ((my_exec_dir(str, tab, env)) == 1)
		return (1);
	return (0);
}

void	exec_rac(char **tab, char **env)
{
	if ((is_directory(tab[0])) == 1) {
		my_printf("%s%s", tab[0], ERR_PERM);
		return;
	} else {
		my_exec_cmd(tab[0], tab, env);
		return;
	}
}

char    **exec_prog(char **tab, char **env)
{
	char    cwd[1024];
	DIR     *repo;

	if (tab[0][0] == '.' && tab[0][1] == '/') {
		if ((repo = opendir(tab[0] + 2)) == NULL &&
			access(my_strcat(getcwd(cwd, sizeof(cwd)), tab[0]
				+ 1), X_OK) != -1)
			my_exec_cmd(tab[0], tab, env);
		else if (access(my_strcat(getcwd(cwd, sizeof(cwd)), tab[0]
					+ 1), X_OK) != -1)
			my_printf("%s%s", tab[0], ERR_PERM);
		else
			my_printf("%s%s", tab[0], ERR_NOT_FOUND);
		return (env);
	}
	else if (tab[0][0] == '/')
		exec_rac(tab, env);
	return (env);
}
