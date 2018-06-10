/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

#include "my.h"
#include "minishell.h"

int	my_builtin(char **tab, char ****env)
{
	if (my_strcmp(tab[0], "env") == 0) {
		my_show_word_array(**env);
		return (1);
	}
	if (my_strcmp(tab[0], "setenv") == 0) {
		**env = my_setenv(tab, **env);
		return (1);
	}
	if (my_strcmp(tab[0], "cd") == 0) {
		**env = my_cd(tab, **env);
		return (1);
	}
	return (0);
}

void	read_history(void)
{
	int	fd;
	char	*str;

	fd = open(".mysh_history", O_RDONLY, 0644);
	while ((str = get_next_line(fd)))
		my_printf("%s\n", str);
}

int	check_cmd(char **tab, char ***env)
{
	if ((check_exit(tab[0], tab[1])) == 84)
		return (1);
	if ((my_builtin(tab, &env)) == 1)
		return (1);
	if (my_strcmp(tab[0], "unsetenv") == 0) {
		*env = my_unsetenv(tab, *env);
		return (1);
	}
	if (my_strcmp(tab[0], "history") == 0) {
		read_history();
		return (1);
	}
	return (0);
}
