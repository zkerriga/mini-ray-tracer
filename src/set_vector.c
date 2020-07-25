/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 09:31:37 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/09 09:31:39 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** Write to `dest` vector obtained from two points.
** Example: vec.x = to.x - from.x;
*/

void	set_vector(t_vec3 *dest, t_point *to, t_point *from)
{
	dest->x = to->x - from->x;
	dest->y = to->y - from->y;
	dest->z = to->z - from->z;
}
