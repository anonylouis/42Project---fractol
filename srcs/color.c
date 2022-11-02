/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:29:20 by lcalvie           #+#    #+#             */
/*   Updated: 2021/12/31 19:29:27 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	rgb_to_hexa(char color[7], int r, int g, int b)
{
	color[0] = '#';
	color[1] = HEXA[r / 16];
	color[2] = HEXA[r % 16];
	color[3] = HEXA[g / 16];
	color[4] = HEXA[g % 16];
	color[5] = HEXA[b / 16];
	color[6] = HEXA[b % 16];
}

void	fill_color_tab_rainbow(char color[27][7])
{
	int	r;
	int	g;
	int	b;
	int	i;

	r = 255;
	g = 51;
	b = 0;
	i = 1;
	while (i < 26)
	{
		rgb_to_hexa((color)[i++], r, g, b);
		if (g < 255 && b < 255)
			g += 51;
		else if (r > 0 && b < 255)
			r -= 51;
		else if (b < 255)
			b += 51;
		else if (g > 0)
			g -= 51;
		else
			r += 51;
	}
	rgb_to_hexa((color)[0], 255, 43, 206);
	rgb_to_hexa((color)[26], 255, 255, 255);
}

void	fill_color_tab_blue(char color[27][7])
{
	int	r;
	int	g;
	int	b;
	int	i;

	r = 0;
	g = 35;
	b = 95;
	i = 0;
	while (b < 255)
	{
		rgb_to_hexa((color)[i++], r, g, b);
		b += 16;
		g += 6;
	}
	while (r < 255)
	{
		rgb_to_hexa((color)[i++], r, g, b);
		r += 17;
		g += 10;
	}
	rgb_to_hexa((color)[i++], r, g, b);
	rgb_to_hexa((color)[0], 0, 21, 57);
	rgb_to_hexa((color)[26], 255, 255, 255);
}

void	fill_color_tab_red(char color[27][7])
{
	int	r;
	int	g;
	int	b;
	int	i;

	r = 255;
	g = 250;
	b = 0;
	i = 0;
	while (g > 0)
	{
		rgb_to_hexa((color)[i++], r, g, b);
		g -= 10;
	}
	rgb_to_hexa((color)[i++], r, g, b);
	rgb_to_hexa((color)[0], 255, 215, 80);
	rgb_to_hexa((color)[26], 255, 0, 0);
}

void	fill_color_tab_random(char color[27][7])
{
	int		fd;
	int		i;
	char	buffer[3];
	char	ret;

	fd = open("/dev/urandom", O_RDONLY);
	i = -1;
	while (++i <= 26)
	{
		ret = read(fd, buffer, 3);
		if (ret == 3)
		{
			rgb_to_hexa((color)[i], (unsigned char) buffer[0],
				(unsigned char) buffer[1], (unsigned char) buffer[2]);
		}
		else
			rgb_to_hexa((color)[i], 255, 255, 255);
	}
}

/*
int main()
{
	//t_graph	*graph;

	//graph = new_graph();

	//int fd = open("julia.xpm", O_CREAT | O_WRONLY | O_TRUNC);
	//append_color_to_xpm(graph->color, fd);

	char	color[27][7];
	fill_color_tab_random(color);
	return(0);
}*/
