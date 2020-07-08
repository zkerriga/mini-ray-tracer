/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:34:41 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/04 16:34:44 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "sphere.h"
#include "func.h"

t_3dvector	*get_n(t_sphere *self, t_point *point)
{
	t_3dvector	*vec;
	float		divider;

	if (!(vec = (t_3dvector *)malloc(sizeof(t_3dvector))))
	{
		free_gc(NULL);
		ft_exit(ENOMEM);
	}
	vec->x = point->x - self->center.x;
	vec->y = point->y - self->center.y;
	vec->z = point->z - self->center.z;
	divider = module(*vec);
	vec->x /= divider;
	vec->y /= divider;
	vec->z /= divider;
	return (vec);
}
