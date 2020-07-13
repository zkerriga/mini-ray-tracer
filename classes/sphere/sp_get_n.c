/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_get_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:34:41 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/12 18:30:54 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "sphere.h"
#include "func.h"

t_3dvector	*sp_get_n(t_sphere *self, t_point *point, t_point *camera)
{
	t_3dvector	*norm;

	if (!(norm = (t_3dvector *)malloc(sizeof(t_3dvector))))
	{
		free_gc(NULL);
		ft_exit(ENOMEM);
	}
	norm->x = point->x - self->center.x;
	norm->y = point->y - self->center.y;
	norm->z = point->z - self->center.z;
	if (2 * modulep(camera, &self->center) < self->diameter)
		reverse_vec(norm);
	return (normalize(norm));
}
