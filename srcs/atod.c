/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:42:43 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/04 12:16:04 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	atod(char *str)
{
	long double	res;
	long double	afterpoint;
	int			negative;

	res = 0;
	afterpoint = 0;
	negative = 1;
	if (*str == '-' && *(str++))
		negative = -1;
	while ((*str >= '0' && *str <= '9')
		|| (*str == '.' && afterpoint == 0))
	{
		if (*str == '.')
			afterpoint = 0.1;
		else if (afterpoint == 0)
			res = 10 * res + (*str - '0');
		else
		{
			res = res + afterpoint * (*str - '0');
			afterpoint /= 10;
		}
		str++;
	}
	return (res * negative);
}
