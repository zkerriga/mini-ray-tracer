/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_multi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 16:51:09 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/07 16:52:42 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** The function multiply the values for all channels from two vectors.
** The Function returns a pointer to dest without changes.
*/

t_rgbvec	*color_multi(t_rgbvec *dest, t_rgbvec one, t_rgbvec two)
{
	dest->r = one.r * two.r;
	dest->g = one.g * two.g;
	dest->b = one.b * two.b;
	return (dest);
}
