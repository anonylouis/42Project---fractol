/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:24:40 by lcalvie           #+#    #+#             */
/*   Updated: 2021/12/31 19:15:17 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	apprend_header_to_xpm(int fd)
{
	ft_putstr_fd("/* XPM */\nstatic char *FRACTOL_XPM[] = {\n\"", fd);
	ft_putnbr_fd(WIDTH, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(HEIGTH, fd);
	ft_putstr_fd(" 27 1 \",\n", fd);
}

void	append_color_to_xpm(char color[26][7], int fd)
{
	int		i;

	i = 0;
	while (i < 26)
	{
		ft_putchar_fd('"', fd);
		ft_putchar_fd('A' + i, fd);
		ft_putstr_fd(" c ", fd);
		write(fd, color[i], 7);
		ft_putstr_fd("\",\n", fd);
		i++;
	}
	ft_putstr_fd("\". c ", fd);
	ft_putstr_fd(color[i], fd);
	ft_putstr_fd("\",\n", fd);
}

void	apprend_line_to_xpm(int n, char line[WIDTH], int fd)
{
	ft_putchar_fd('"', fd);
	write(fd, line, WIDTH);
	if (n != (HEIGTH - 1))
		ft_putstr_fd("\",\n", fd);
	else
		ft_putstr_fd("\"\n", fd);
}
