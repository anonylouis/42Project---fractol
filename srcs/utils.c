/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:06:00 by lcalvie           #+#    #+#             */
/*   Updated: 2021/12/31 19:16:09 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	ft_toupcase(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (ft_toupcase(*s1) != ft_toupcase(*s2))
			return (ft_toupcase(*s1) - ft_toupcase(*s2));
		s1++;
		s2++;
	}
	return (ft_toupcase(*s1) - ft_toupcase(*s2));
}
