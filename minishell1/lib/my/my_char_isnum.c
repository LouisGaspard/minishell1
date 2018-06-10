/*
** EPITECH PROJECT, 2018
** char_isnum
** File description:
** char_isnum
*/

#include "my.h"

int	my_char_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}
