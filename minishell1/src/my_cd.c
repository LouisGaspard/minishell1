/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

#include "my.h"
#include "minishell.h"

char    *my_home_path(char **env)
{
	int	a = 0;

	while (env[a]) {
		if ((my_strncmp(env[a], "HOME=", 5)) == 0)
			return (env[a] + 5);
		a++;
	}
	return (NULL);
}

int	chdir_back(char **env)
{
	int	a = 0;
	int	r_value;
	char	*pwd;

	while (env[a]) {
		if ((my_strncmp(env[a], "OLDPWD=", 7)) == 0) {
			pwd = my_strdup(env[a] + 7);
			break;
		}
		a++;
	}
	r_value = chdir(pwd);
	return (r_value);
}

char	**cd_dir(char **tab, char **env, char *pwd)
{
	int	a = 0;
	char	pwda[1024];

	if (tab[1][0] == '-' && tab[1][1] == '\0')
		a = chdir_back(env);
	else
		a = chdir(tab[1]);
	if (a == -1) {
		if (access(tab[1], F_OK) == -1) {
			my_printf("%s%s", tab[1], ERR_ACCESS);
			return (env);
		} else {
			my_printf("%s%s", tab[1], ERR_DIR);
			return (env);
		}
	} else {
		env = change_pwd(pwd, getcwd(pwda, sizeof(pwda)), env);
	}
	return (env);
}

char	**my_cd(char **tab, char **env)
{
	char	pwd[1024];
	char    *home_path;

	if ((home_path = my_home_path(env)) == NULL)
		return (env);
	getcwd(pwd, sizeof(pwd));
	if (tab[2] != NULL) {
		my_printf("%s%s", tab[0], ERR_SETENV_ARG);
		return (env);
	}
	if (tab[1] == NULL) {
		env = change_pwd(pwd, home_path, env);
		chdir(home_path);
		return (env);
	} else {
		env = cd_dir(tab, env, pwd);
		return (env);
	}
}
