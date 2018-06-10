/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

#ifndef	__MINISHELL__
#define	__MINISHELL__

#define ERR_ACCESS	": No such file or directory.\n"
#define ERR_DIR		": Not a directory.\n"
#define ERR_FEW_ARG	": Too few arguments.\n"
#define ERR_NOT_FOUND	": Command not found.\n"
#define ERR_PERM	": Permission denied.\n"
#define ERR_EXIT	": Expression Syntax.\n"
#define ERR_SETENV_CHAR	": Variable name must contain alphanumeric"
#define ERR_SET2	" characters.\n"
#define ERR_SETENV_ARG	": Too many arguments.\n"
#define ERR_SETENV_NAME	": Variable name must begin with a letter.\n"
#define ERR_SEG		"Segmentation fault (core dumped)\n"
#define ERR_FLOAT	"Floating exception (core dumped)\n"

char	**my_cd(char **tab, char **env);
int	my_exec_cmd(char *path, char **tab, char **env);
int	check_cmd(char **tab, char ***env);
void	write_in_history(char *cmd, int nb, int fd);
char	**get_in_env(char **env, char *str);
char	**my_copy_env(char **env);
int	count_line(char **env);
int	my_str_is_alphanum(char *str);
char	**my_add_env(char *s1, char *s2, char **env);
char	**my_realloc_env(char **env);
char	*get_next_line(int fd);
char	**my_unsetenv(char **tab, char **env);
char	**my_setenv(char **tab, char **env);
int	check_exit(char *cmd, char *s_arg);
int     exec_dir(char **tab, char **env);
char	**exec_prog(char **tab, char **env);
char	**change_pwd(char *old, char *new, char **env);
int	is_directory(char *name);
char	**create_pwd_line(char *pwd, char **env, int b);

#endif
