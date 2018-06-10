/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** minishell
*/

#include "my.h"
#include "minishell.h"

void	my_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	my_putnbr_fd(int nb, int fd)
{
	int	neg = 0;

	if (nb < 0) {
		my_putchar_fd('-', fd);
		if (nb == -2147483648) {
			neg = 1;
			nb++;
		}
		nb = - nb;
	}
	if (nb >= 10)
		my_putnbr_fd(nb / 10, fd);
	if (neg == 1)
		my_putchar_fd((nb % 10) + 49, fd);
	else
		my_putchar_fd((nb % 10) + 48, fd);
}

void	write_in_history(char *cmd, int nb, int fd)
{
	my_putnbr_fd(nb, fd);
	write(fd, "\t", 1);
	write(fd, cmd, my_strlen(cmd));
	write(fd, "\n", 1);
}
