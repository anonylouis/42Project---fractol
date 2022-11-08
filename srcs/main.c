/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:58:51 by lcalvie           #+#    #+#             */
/*   Updated: 2022/11/08 12:20:31 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_graph	*graph;

	if (argc == 1)
		graph = new_graph("julia", "blue", 0, 0);
	else if (argc == 2)
		graph = new_graph(argv[1], "blue", 0, 0);
	else if (argc == 3)
		graph = new_graph(argv[1], argv[2], 0, 0);
	else if (argc == 5)
		graph = new_graph(argv[1], argv[2],
				atod(argv[3]), atod(argv[4]));
	else
		graph = new_graph("wrong", "argument", 0, 0);
	if (graph && img_to_screen(graph))
	{
		mlx_hook(graph->win_ptr, 33, 1L << 17, close_loop, graph);
		mlx_key_hook(graph->win_ptr, keycatch, graph);
		mlx_mouse_hook(graph->win_ptr, mousecatch, graph);
		mlx_loop_hook(graph->mlx_ptr, mousemoved, graph);
		mlx_loop(graph->mlx_ptr);
	}
	clear_graph(graph);
	return (0);
}
