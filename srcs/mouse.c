/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:03:23 by lcalvie           #+#    #+#             */
/*   Updated: 2021/12/31 19:19:45 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mousecatch(int mousecode, int x, int y, t_graph *graph)
{
	if (mousecode != 4 && mousecode != 5)
		return (1);
	if (mousecode == 4)
	{
		graph->xmax -= ZOOM_IN * (graph->xmax - graph->xmin)
			* (1 - (double) x / (WIDTH -1));
		graph->xmin += ZOOM_IN * (graph->xmax - graph->xmin)
			* ((double) x / (WIDTH - 1));
		graph->ymax -= ZOOM_IN * (graph->ymax - graph->ymin)
			* ((double) y / (HEIGTH - 1));
		graph->ymin += ZOOM_IN * (graph->ymax - graph->ymin)
			* (1 - (double) y / (HEIGTH - 1));
	}
	if (mousecode == 5)
	{
		graph->xmax += ZOOM_OUT * (graph->xmax - graph->xmin) * 0.5;
		graph->xmin -= ZOOM_OUT * (graph->xmax - graph->xmin) * 0.5;
		graph->ymax += ZOOM_OUT * (graph->ymax - graph->ymin) * 0.5;
		graph->ymin -= ZOOM_OUT * (graph->ymax - graph->ymin) * 0.5;
	}
	if (!img_to_screen(graph))
		mlx_loop_end(graph->mlx_ptr);
	return (1);
}

int	mousemoved(t_graph *graph)
{
	int		x;
	int		y;
	double	c_x;
	double	c_y;

	if (graph->moved && graph->type == 0 && graph->xmin <= -1.5
		&& graph->xmax >= 1.5 && graph->ymin <= -1.5 && graph->ymax >= 1.5)
	{
		mlx_mouse_get_pos(graph->mlx_ptr, graph->win_ptr, &x, &y);
		c_x = graph->xmin + ((double )x / (WIDTH - 1))
			* (graph->xmax - graph->xmin);
		c_y = graph->ymin + ((double )y / (WIDTH - 1))
			* (graph->ymax - graph->ymin);
		if ((graph->c)->x != c_x || (graph->c)->y)
		{
			complex_assignation(graph->c, c_x, c_y);
			mlx_destroy_image(graph->mlx_ptr, graph->img_ptr);
			generate_julia_img(graph);
			mlx_put_image_to_window(graph->mlx_ptr, graph->win_ptr,
				graph->img_ptr, 0, 0);
		}
	}
	return (1);
}
