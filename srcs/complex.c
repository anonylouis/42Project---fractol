/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:16:46 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/02 18:14:24 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	*new_complex(double x, double y)
{
	t_complex	*z;

	z = malloc(sizeof(t_complex));
	if (z == NULL)
		return (NULL);
	z->x = x;
	z->y = y;
	return (z);
}

void	complex_assignation(t_complex *z, double x, double y)
{
	if (z)
	{
		z->x = x;
		z->y = y;
	}
}
