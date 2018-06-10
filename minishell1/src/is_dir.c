/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

#include "my.h"
#include "minishell.h"

int     is_directory(char *name)
{
	DIR     *repo;

	if ((repo = opendir(name)) == NULL)
		return (0);
	closedir(repo);
	return (1);
}
