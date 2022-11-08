/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:14:47 by lcalvie           #+#    #+#             */
/*   Updated: 2022/11/08 12:19:56 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_graph_color_tab(char color[27][8], char *strColor)
{
	if (ft_strcmp(strColor, "BLUE") == 0)
		fill_color_tab_blue(color);
	else if (ft_strcmp(strColor, "RED") == 0)
		fill_color_tab_red(color);
	else if (ft_strcmp(strColor, "RAINBOW") == 0)
		fill_color_tab_rainbow(color);
	else if (ft_strcmp(strColor, "RANDOM") == 0)
		fill_color_tab_random(color);
	else
		fill_color_tab_blue(color);
}

void	display_graph_fractal_type(t_graph *graph, char *strFractalType,
	double x, double y)
{
	if (ft_strcmp(strFractalType, "JULIA") == 0)
	{
		graph->type = 0;
		graph->c = new_complex(x, y);
	}
	else if (ft_strcmp(strFractalType, "MANDELBROT") == 0)
	{
		graph->type = 1;
		graph->c = new_complex(0, 0);
		graph->xmax = 1.3;
		graph->xmin = -2.2;
		graph->ymax = 1.6;
		graph->ymin = -1.6;
	}
	else if (ft_strcmp(strFractalType, "BURNINGSHIP") == 0)
	{
		graph->type = 2;
		graph->c = new_complex(0, 0);
	}
	else
	{
		graph->type = 0;
		graph->c = new_complex(0, 0);
	}
}

t_graph	*new_graph(char *strFractalType, char *strColor, double x, double y)
{
	t_graph	*graph;

	if (!check_argument(strFractalType, strColor))
		return (NULL);
	graph = malloc(sizeof(t_graph));
	if (graph == NULL)
		return (NULL);
	graph->mlx_ptr = mlx_init();
	if (!graph->mlx_ptr)
	{
		free(graph);
		return (NULL);
	}
	graph->win_ptr = mlx_new_window(graph->mlx_ptr, WIDTH, HEIGTH, "FRACT'OL");
	graph->img_ptr = NULL;
	graph->xmax = 2;
	graph->xmin = -2;
	graph->ymax = 2;
	graph->ymin = -2;
	graph->moved = 0;
	display_graph_color_tab(graph->color, strColor);
	display_graph_fractal_type(graph, strFractalType, x, y);
	return (graph);
}

int	img_to_screen(t_graph *graph)
{
	if (graph->img_ptr != NULL)
		mlx_destroy_image(graph->mlx_ptr, graph->img_ptr);
	if (graph->type == 0)
	{
		if (!generate_julia_img(graph))
			return (0);
	}
	else if (graph->type == 1)
	{
		if (!generate_mandelbrot_img(graph))
			return (0);
	}
	else if (graph->type == 2)
	{
		if (!generate_burningship_img(graph))
			return (0);
	}
	mlx_put_image_to_window(graph->mlx_ptr, graph->win_ptr,
		graph->img_ptr, 0, 0);
	return (1);
}

void	clear_graph(t_graph *graph)
{
	if (graph)
	{
		mlx_destroy_image(graph->mlx_ptr, graph->img_ptr);
		mlx_clear_window(graph->mlx_ptr, graph->win_ptr);
		mlx_destroy_window(graph->mlx_ptr, graph->win_ptr);
		mlx_destroy_display(graph->mlx_ptr);
		free(graph->mlx_ptr);
		free(graph->c);
		free(graph);
	}
}
