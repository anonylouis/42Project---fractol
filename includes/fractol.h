/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:58:48 by lcalvie           #+#    #+#             */
/*   Updated: 2022/11/08 12:19:56 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "../minilibx/mlx.h"
# include "complex.h"
# include "graph.h"

// SCREEN SIZE 
# define WIDTH 500
# define HEIGTH 500
// PRECISION
# define NB_ITERATION  60

# define ZOOM_IN 0.1
# define ZOOM_OUT 0.1
# define MOVESPEED 0.05

# define HEXA "0123456789ABCDEF"
# define COLORXPM "ABCDEFGHIJKLMNOPQRSTUVWXYZ."

//COLOR
void	fill_color_tab_blue(char color[27][8]);
void	fill_color_tab_rainbow(char color[27][8]);
void	fill_color_tab_red(char color[27][8]);
void	fill_color_tab_random(char color[27][8]);

//HOOK
int		keycatch(int keycode, t_graph *graph);
int		mousecatch(int mousecode, int x, int y, t_graph *graph);
int		mousemoved(t_graph *graph);
int		movegraph(t_graph *graph, int keycode);
int		close_loop(t_graph *graph);

//FRACTAL
int		generate_julia_img(t_graph *graph);
int		generate_mandelbrot_img(t_graph *graph);
int		generate_burningship_img(t_graph *graph);

//PRINT 
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//XPM
void	apprend_header_to_xpm(int fd);
void	append_color_to_xpm(char color[26][8], int fd);
void	apprend_line_to_xpm(int n, char line[WIDTH], int fd);

//ARGUMENTS
int		check_argument(char *strFractalType, char *strColor);

//UTILS
int		ft_strcmp(char *s1, char *s2);
double	atod(char *str);

#endif