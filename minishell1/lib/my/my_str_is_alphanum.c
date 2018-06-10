/*
** EPITECH PROJECT, 2018
** my
** File description:
** my
*/

#include "my.h"

int	my_str_is_alphanum(char *str)
{
	int	a = 0;

	while (str[a]) {
		if ((str[a] >= 'a' && str[a] <= 'z') ||
			(str[a] >= 'A' && str[a] <= 'Z') ||
			(str[a] >= '0' && str[a] <= '9'))
			a++;
		else
			return (1);
	}
	return (0);
}
