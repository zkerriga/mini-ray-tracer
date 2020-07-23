/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:39:27 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/13 18:39:34 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "func.h"
#include "math.h"

t_3dvector	*rotate_ray(t_3dvector *ray, t_matrix *lookat)
{
	t_3dvector	cp;

	cp = *normalize(ray);
	ray->x = cp.x * lookat->x_r.x + cp.y * lookat->y_u.x + cp.z * lookat->z_f.x;
	ray->y = cp.x * lookat->x_r.y + cp.y * lookat->y_u.y + cp.z * lookat->z_f.y;
	ray->z = cp.x * lookat->x_r.z + cp.y * lookat->y_u.z + cp.z * lookat->z_f.z;
	return (ray);
}

/*
t_3dvector	*rotate_x(t_3dvector *dest, t_3dvector tmp, float angle)
{
	dest->y = tmp.y * cos(angle) - tmp.z * sin(angle);
	dest->z = tmp.y * sin(angle) + tmp.z * cos(angle);
}

t_3dvector	*rotate_y(t_3dvector *dest, t_3dvector tmp, float angle)
{
	dest->x = tmp.x * cos(angle) + tmp.z * sin(angle);
	dest->z = -(tmp.x * sin(angle)) + tmp.z * cos(angle);
}

t_3dvector	*rotate_z(t_3dvector *dest, t_3dvector tmp, float angle)
{
	dest->x = tmp.x * cos(angle) - tmp.y * sin(angle);
	dest->y = tmp.x * sin(angle) + tmp.y * cos(angle);
}
*/
/*
float	get_first_angle(t_3dvector *dir)
{
	if (dir->x < 0)
		return (-acos(dir->z));
	else
		return (acos(dir->z));
}*/
/*

t_3dvector	*rotate_ray(t_3dvector *ray, t_3dvector *dir)
{
	static double		si;
	static double		co;
	static float		first_angle;
	static t_3dvector	r;
	t_3dvector			cp;

	if (!ray)
	{
		set_point(&cp, 0.f, 0.f, 1.f);
		first_angle = (dir->x < 0) ? -acos(dir->z) : acos(dir->z);
		rotate_y(&cp, cp, first_angle);
		set_point(&r, cp.z, 0.f, cp.x);
		si = dir->y;
		co = cos(asin(dir->y));
	}
	else
	{
		rotate_y(ray, *ray, first_angle);
		set_point(&cp, ray->x, ray->y, ray->z);
		set_point(ray, cp.x * r.x * r.x * (1 - co) + cp.x * co - cp.y * r.z * si + cp.z * r.x * r.z * (1 - co),
				  cp.x * r.z * si + cp.y * co - cp.z * r.x * si,
				  cp.x * r.x * r.z * (1 - co) + cp.y * r.x * si + cp.z * r.z * r.z * (1 - co) + cp.z * co);
	}
//	rotate_z(ray, *ray, asin(dir->y));
	return (ray);
}
*/
