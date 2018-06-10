/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

#include "my.h"
#include "minishell.h"

int     pwd_in_env(char **env, int b)
{
	int     a = 0;

	while (env[a]) {
		if ((my_strncmp(env[a], "PWD=", 4)) == 0 && b == 1)
			return (a);
		if ((my_strncmp(env[a], "OLDPWD=", 4)) == 0 && b == 2)
			return (a);
		a++;
	}
	return (0);
}

char    **change_pwd_line(char *pwd, int line, char **env, int a)
{
	if (a == 1)
		env[line] = my_strcat("PWD=", my_strdup(pwd));
	else
		env[line] = my_strcat("OLDPWD=", my_strdup(pwd));
	return (env);
}

char    **change_new_pwd(char *pwd, char **env)
{
	int     line = 0;

	if ((line = pwd_in_env(env, 1)) != 0)
		env = change_pwd_line(pwd, line, env, 1);
	else
		env = create_pwd_line(pwd, env, 1);
	return (env);
}

char    **change_old_pwd(char *pwd, char **env)
{
	int     line = 0;

	if ((line = pwd_in_env(env, 2)) != 0)
		env = change_pwd_line(pwd, line, env, 2);
	else
		env = create_pwd_line(pwd, env, 2);
	return (env);
}

char    **change_pwd(char *old, char *new, char **env)
{
	env = change_new_pwd(new, env);
	env = change_old_pwd(old, env);
	return (env);
}
