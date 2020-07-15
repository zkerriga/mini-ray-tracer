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

t_3dvector	*rotate_x(t_3dvector *dest, float x)
{
	t_3dvector	tmp;

	set_point(&tmp, dest->x, dest->y, dest->z);
	dest->y = tmp.y * cos(x) - tmp.z * sin(x);
	dest->z = tmp.y * sin(x) + tmp.z * cos(x);
}

t_3dvector	*rotate_y(t_3dvector *dest, float y)
{
	t_3dvector	tmp;

	set_point(&tmp, dest->x, dest->y, dest->z);
	dest->x = tmp.x * cos(y) + tmp.z * sin(y);
	dest->z = tmp.x * -sin(y) + tmp.z * cos(y);
}

t_3dvector	*rotate_z(t_3dvector *dest, float z)
{
	t_3dvector	tmp;

	set_point(&tmp, dest->x, dest->y, dest->z);
	dest->x = tmp.x * cos(z) - tmp.y * sin(z);
	dest->y = tmp.x * sin(z) + tmp.y * cos(z);
}

t_3dvector	*rotate_ray(t_3dvector *ray, t_3dvector *dir)
{
	return (rotate_z(rotate_y(rotate_x(ray, dir->x), dir->y), dir->z));
}
