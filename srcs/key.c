/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:04:06 by lcalvie           #+#    #+#             */
/*   Updated: 2022/11/08 11:58:10 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_loop(t_graph *graph)
{
	mlx_loop_end(graph->mlx_ptr);
	return (0);
}

int	keycatch(int keycode, t_graph *graph)
{
	if (keycode == 65307 || keycode == 113)
		mlx_loop_end(graph->mlx_ptr);
	else if (keycode == 108)
		graph->moved = 1 - graph->moved;
	else if (keycode == 65361 || keycode == 65362
		|| keycode == 65363 || keycode == 65364)
	{
		if (!movegraph(graph, keycode - 65360))
			mlx_loop_end(graph->mlx_ptr);
	}
	return (1);
}
