/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:54:31 by lcalvie           #+#    #+#             */
/*   Updated: 2021/12/31 19:30:01 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_in_graph_mandelbrot(t_complex *z, t_complex c)
{
	int		i;
	double	x_save;

	i = 0;
	z->x = 0;
	z->y = 0;
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

void	write_mandelbrot_xpm(t_graph *graph, int fd, t_complex *z)
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
			graph->c->x = graph->xmax - (graph->xmax - graph->xmin)
				* (1 - ((double) x / (WIDTH - 1)));
			graph->c->y = graph->ymin + (graph->ymax - graph->ymin)
				* (1 - ((double) y / (HEIGTH - 1)));
			line[x] = COLORXPM[is_in_graph_mandelbrot(z, *(graph->c))];
		}
		apprend_line_to_xpm(y, line, fd);
	}
	write(fd, "};", 2);
}

int	generate_mandelbrot_img(t_graph *graph)
{
	t_complex	*z;
	int			fd;

	fd = open("./mandelbrot.xpm", O_CREAT | O_WRONLY | O_TRUNC, 0755);
	if (fd == -1)
		return (0);
	z = new_complex(0, 0);
	if (z == NULL)
		return (0);
	write_mandelbrot_xpm(graph, fd, z);
	close(fd);
	free(z);
	graph->img_ptr = mlx_xpm_file_to_image(graph->mlx_ptr, "./mandelbrot.xpm",
			&(graph->img_width), &(graph->img_height));
	return (1);
}
