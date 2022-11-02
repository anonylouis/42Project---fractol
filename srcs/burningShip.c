/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningShip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:30:25 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/02 18:14:01 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_in_graph_burningship(t_complex *z, t_complex c)
{
	int		i;
	double	x_abs;
	double	y_abs;

	i = 0;
	z->x = 0;
	z->y = 0;
	while (i < NB_ITERATION)
	{
		if (z->x * z->x + z->y * z->y >= 4)
			return ((double) i / NB_ITERATION * 26);
		x_abs = z->x;
		if (z->x < 0.0)
			x_abs = z->x * -1.0;
		y_abs = z->y;
		if (z->y < 0.0)
			y_abs = z->y * -1.0;
		z->x = x_abs * x_abs - y_abs * y_abs - c.x;
		z->y = 2.0 * x_abs * y_abs - c.y;
		i++;
	}
	return (26);
}

void	write_burningship_xpm(t_graph *graph, int fd, t_complex *z)
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
			line[x] = COLORXPM[is_in_graph_burningship(z, *(graph->c))];
		}
		apprend_line_to_xpm(y, line, fd);
	}
	write(fd, "};", 2);
}

int	generate_burningship_img(t_graph *graph)
{
	t_complex	*z;
	int			fd;

	fd = open("./burningship.xpm", O_CREAT | O_WRONLY | O_TRUNC, 0755);
	if (fd == -1)
		return (0);
	z = new_complex(0, 0);
	if (z == NULL)
		return (0);
	write_burningship_xpm(graph, fd, z);
	close(fd);
	free(z);
	graph->img_ptr = mlx_xpm_file_to_image(graph->mlx_ptr, "./burningship.xpm",
			&(graph->img_width), &(graph->img_height));
	return (1);
}
