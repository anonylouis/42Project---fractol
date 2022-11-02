/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movegraph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 18:08:22 by lcalvie           #+#    #+#             */
/*   Updated: 2021/12/31 19:16:23 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	direction(int keycode)
{
	if (keycode == 2 || keycode == 3)
		return (1);
	return (-1);
}

int	movegraph(t_graph *graph, int keycode)
{
	double	d;
	int		i;

	i = direction(keycode);
	if (keycode == 1 || keycode == 3)
	{
		d = graph->xmax - graph->xmin;
		graph->xmin += (double) i * MOVESPEED * d;
		graph->xmax += (double) i * MOVESPEED * d;
	}
	else
	{
		d = graph->ymax - graph->ymin;
		graph->ymin += (double) i * MOVESPEED * d;
		graph->ymax += (double) i * MOVESPEED * d;
	}
	return (img_to_screen(graph));
}
