/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:12:12 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/04 11:41:58 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

typedef struct s_graph
{
	int			type;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	double		xmax;
	double		xmin;
	double		ymax;
	double		ymin;
	char		color[27][7];
	t_complex	*c;
	int			img_height;
	int			img_width;
	int			moved;
}		t_graph;

//COLOR
t_graph	*new_graph(char *strFractal, char *strColor, double x, double y);
void	clear_graph(t_graph *graph);
int		img_to_screen(t_graph *graph);

#endif 