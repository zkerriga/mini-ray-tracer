/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:12:05 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/12 18:33:23 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "render.h"

float	pl_solve(t_plane *self, t_point *origin, t_vec3 *ray, t_limits *l)
{
	float	t;
	t_vec3	op;

	if (fbetween((t = vdot(&self->norm, ray)), -INACCURACY, +INACCURACY))
		return (-1.f);
	vget(&op, origin, &self->point);
	t = -vdot(&self->norm, &op) / t;
	if (fbetween(t, l->min, l->max))
		return (t);
	else
		return (-1.f);
}
