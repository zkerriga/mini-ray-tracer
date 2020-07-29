/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_get_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:30:46 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/13 16:30:48 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"
#include "render.h"
#include "plane.h"

static t_bool	is_plane(t_cylinder *self, t_point *point)
{
	t_vec3	tmp;

	vget(&tmp, &self->up_center, point);
	normalize(&tmp);
	if (fbetween(vdot(&tmp, &self->vector), -INACCURACY, +INACCURACY))
		return (TRUE);
	vget(&tmp, &self->down_center, point);
	normalize(&tmp);
	if (fbetween(vdot(&tmp, &self->vector), -INACCURACY, +INACCURACY))
		return (TRUE);
	return (FALSE);
}

t_vec3			*cy_get_n(t_cylinder *self, t_point *point, t_point *camera)
{
	t_vec3 *norm;
	t_vec3 camera_to_point;
	t_vec3 point_to_center;
	t_vec3 orthogonal;

	if (!(norm = (t_vec3 *)malloc(sizeof(t_vec3))))
	{
		free_gc(NULL);
		ft_exit(ENOMEM);
	}
	if (is_plane(self, point))
		*norm = self->vector;
	else
	{
		vget(&point_to_center, point, &self->point);
		vprod(&orthogonal, &point_to_center, &self->vector);
		vprod(norm, &orthogonal, &self->vector);
	}
	vget(&camera_to_point, point, camera);
	if (vdot(norm, &camera_to_point) > 0.f)
		reverse_vec(norm);
	return (normalize(norm));
}
