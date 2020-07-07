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
** The function sums the values for all channels from two vectors
** (the maximum value is 1.0).
** The Function returns a pointer to dest without changes.
*/

t_rgbvec	*color_sum(t_rgbvec *dest, t_rgbvec one, t_rgbvec two)
{
	float	tmp;

	if ((tmp = one.r + two.r) > 1.0f)
		dest->r = 1.0f;
	else
		dest->r = tmp;
	if ((tmp = one.g + two.g) > 1.0f)
		dest->g = 1.0f;
	else
		dest->g = tmp;
	if ((tmp = one.b + two.b) > 1.0f)
		dest->b = 1.0f;
	else
		dest->b = tmp;
	return (dest);
}
