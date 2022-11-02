/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:08:28 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/02 16:26:36 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

typedef struct s_complex
{
	double	x;
	double	y;
}		t_complex;

// COMPLEX
t_complex	*new_complex(double x, double y);
void		complex_assignation(t_complex *z, double x, double y);

#endif