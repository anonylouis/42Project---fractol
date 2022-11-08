/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:01:58 by lcalvie           #+#    #+#             */
/*   Updated: 2022/11/08 12:15:16 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_in_graph_julia(t_complex *z, t_complex c)
{
	int		i;
	double	x_save;

	i = 0;
	while (i < NB_ITERATION)
	{
		if (z->x * z->x + z->y * z->y >= 4)
			return ((double) i / NB_ITERATION * 26);
		x_save = z->x;
		z->x = z->x * z->x - z->y * z->y + c.x;
		z->y = 2 * x_save * z->y + c.y;
		i++;
	}
	return (26);
}

void	write_julia_xpm(t_graph *graph, int fd, t_complex *z)
{
	int		x;
	int		y;
	char	line[WIDTH];

	apprend_header_to_xpm(fd);
	append_color_to_xpm(graph->color, fd);
	y = -1;
	while (++y < HEIGTH)
	{
		x = -1;
		while (++x < WIDTH)
		{
			z->x = graph->xmax - (graph->xmax - graph->xmin)
				* (1 - ((double) x / (WIDTH - 1)));
			z->y = graph->ymin + (graph->ymax - graph->ymin)
				* (1 - ((double) y / (HEIGTH - 1)));
			line[x] = COLORXPM[is_in_graph_julia(z, *(graph->c))];
		}
		apprend_line_to_xpm(y, line, fd);
	}
	write(fd, "};", 2);
}

int	generate_julia_img(t_graph *graph)
{
	t_complex	*z;
	int			fd;

	fd = open("./julia.xpm", O_CREAT | O_WRONLY | O_TRUNC, 0755);
	if (fd == -1)
		return (0);
	z = new_complex(0, 0);
	if (z == NULL)
	{
		close(fd);
		return (0);
	}
	write_julia_xpm(graph, fd, z);
	close(fd);
	free(z);
	graph->img_ptr = mlx_xpm_file_to_image(graph->mlx_ptr, "./julia.xpm",
			&(graph->img_width), &(graph->img_height));
	return (1);
}
/*
int main()

{
	t_graph	*graph;

	graph = new_graph();

	int fd = open("julia.xpm", O_CREAT | O_WRONLY | O_TRUNC);
	complex_assignation(graph->c, -0.4, 0.6);
	generate_julia_img(graph);
	return(0);
}*/
