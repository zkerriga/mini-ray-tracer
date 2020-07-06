/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_sum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:00:20 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/06 18:01:22 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** The function writes the sum of two colors to dest,
** taking into account the brightness of the second color.
*/

void	color_sum(t_color *dest, t_color one, t_color two, float bright)
{
	short tmp;

	if ((tmp = one.r + two.r * bright) > 255)
		dest->r = 255;
	else
		dest->r = tmp;
	if ((tmp = one.g + two.g * bright) > 255)
		dest->g = 255;
	else
		dest->g = tmp;
	if ((tmp = one.b + two.b * bright) > 255)
		dest->b = 255;
	else
		dest->b = tmp;
}
