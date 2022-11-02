/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:02:24 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/02 18:19:36 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_fractol_man(void)
{
	printf("Fract'ol can receive two optional arguments :\n\n");
	printf("The first is the type of fractal to display ");
	printf("and should be choosen betwwen :\n");
	printf("* Julia\n* Mandelbrot\n* Burningship\n");
	printf("\nThe second one is about the color ");
	printf("and should be choosen betwwen :\n");
	printf("* Blue\n* Red\n* Rainbow\n* Random\n");
	printf("\nPS : The program is not case sensitive\n");
}

int	check_argument(char *strFractalType, char *strColor)
{
	if (ft_strcmp(strColor, "blue") != 0
		&& ft_strcmp(strColor, "red") != 0
		&& ft_strcmp(strColor, "rainbow") != 0
		&& ft_strcmp(strColor, "random") != 0)
	{
		print_fractol_man();
		return (0);
	}
	if (ft_strcmp(strFractalType, "julia") != 0
		&& ft_strcmp(strFractalType, "Mandelbrot") != 0
		&& ft_strcmp(strFractalType, "Burningship") != 0)
	{
		print_fractol_man();
		return (0);
	}
	return (1);
}
