/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 17:38:33 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/12 18:30:56 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "render.h"

static void	solution_of_equation(float t[2], float k1, float k2, float k3)
{
	float	discriminant;

	if ((discriminant = k2 * k2 - 4 * k1 * k3) < 0)
	{
		t[0] = -1.f;
		t[1] = -1.f;
	}
	else
	{
		t[0] = (-k2 + sqrt(discriminant)) / (2 * k1);
		t[1] = (-k2 - sqrt(discriminant)) / (2 * k1);
	}
}

float		sp_solve(t_sphere *self, t_point *origin, t_vec3 *ray, t_limits *l)
{
	float	t[2];
	t_vec3	oc;

	vget(&oc, origin, &self->center);
	solution_of_equation(t, vdot(ray, ray), 2 * vdot(&oc, ray),
				vdot(&oc, &oc) - self->radius_square);
	if (fbetween(t[0], l->min, l->max) &&
		!(fbetween(t[1], l->min, l->max) && t[0] > t[1]))
		return (t[0]);
	else if (fbetween(t[1], l->min, l->max))
		return (t[1]);
	else
		return (-1.f);
}
