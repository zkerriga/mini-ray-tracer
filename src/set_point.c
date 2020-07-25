/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 18:11:33 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/11 18:11:35 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Write to `dest` x,y,z-coordinates.
*/

void	vset(t_vec3 *dest, float x, float y, float z)
{
	dest->x = x;
	dest->y = y;
	dest->z = z;
}
