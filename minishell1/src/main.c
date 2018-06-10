/*
** EPITECH PROJECT, 2017
** minishell1
** File description
** minishell1
*/

#include "my.h"
#include "minishell.h"
#include "gnl.h"

char	**my_find_cmd(char **tab, char **tab_path, char **env)
{
	int	y = 0;
	char	*path;

	if (tab[0][0] == '.' || tab[0][0] == '/')
		return (exec_prog(tab, env));
	if (check_cmd(tab, &env) == 1)
		return (env);
	while (tab_path[y]) {
		path = my_strcat(tab_path[y], "/");
		path = my_strcat(path, tab[0]);
		if (access(path, F_OK) != -1) {
			my_exec_cmd(path, tab, env);
			return (env);
		}
		y++;
	}
	if (exec_dir(tab, env) == 1)
		return (env);
	return (env);
}

void	my_shell(char **env)
{
	int	fd;
	char	*cmd;
	char	**tab;
	char	**tab_path;
	int	count_history = 1;

	fd = open(".mysh_history", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	my_printf("$> ");
	while ((cmd = get_next_line(0))) {
		if (cmd[0] == 0 || cmd == NULL) {
			my_printf("$> ");
			continue;
		}
		write_in_history(cmd, count_history ++, fd);
		tab = my_str_to_word_array2(cmd);
		tab_path = get_in_env(env, "PATH=");
		env = my_find_cmd(tab, tab_path, env);
		free(cmd);
		my_printf("$> ");
	}
}

char	**create_env(void)
{
	char	**env;
	char	*str = malloc(sizeof(char) * 1024);
	char	pwd[1024];

	getcwd(pwd, sizeof(pwd));
	str = my_strcat("PWD=", pwd);
	env = my_str_to_word_array2(str);
	return (env);
}

int	main(int ac, char **av, char **env)
{
	char	**my_env;

	(void)ac;
	(void)av;
	if (env[0] == NULL)
		my_env = create_env();
	else
		my_env = my_copy_env(env);
	my_shell(my_env);
	return (0);
}
