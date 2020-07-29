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

void	sp_min_solution_of_equation(float t[2], const float k[3], t_limits *l)
{
	float	discriminant;
	float	t1;
	float	t2;
	t_bool	t1_is_biggest;

	if ((discriminant = k[1] * k[1] - 4 * k[0] * k[2]) < 0)
	{
		t[0] = -1.f;
		t[1] = -1.f;
	}
	else
	{
		t1 = (-k[1] + sqrt(discriminant)) / (2 * k[0]);
		t2 = (-k[1] - sqrt(discriminant)) / (2 * k[0]);
		t1 = fbetween(t1, l->min, l->max) ? t1 : -1.f;
		t2 = fbetween(t2, l->min, l->max) ? t2 : -1.f;
		t1_is_biggest = t2 > 0.f && (t1 < 0.f || t2 < t1);
		t[0] = t1_is_biggest ? t2 : t1;
		t[1] = t1_is_biggest ? t1 : t2;
	}
}

float	sp_solve(t_sphere *self, t_point *origin, t_vec3 *ray, t_limits *l)
{
	float	t[2];
	float	k[3];
	t_vec3	oc;

	vget(&oc, origin, &self->center);
	k[0] = vdot(ray, ray);
	k[1] = 2 * vdot(&oc, ray);
	k[2] = vdot(&oc, &oc) - self->radius_square;
	sp_min_solution_of_equation(t, k, l);
	return (t[0]);
}
