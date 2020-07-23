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

/*
** The function multiplies the beam vector by the camera transformation matrix.
*/

t_3dvector	*rotate_ray(t_3dvector *ray, t_matrix *lookat)
{
	t_3dvector	cp;

	cp = *normalize(ray);
	ray->x = cp.x * lookat->x_r.x + cp.y * lookat->y_u.x + cp.z * lookat->z_f.x;
	ray->y = cp.x * lookat->x_r.y + cp.y * lookat->y_u.y + cp.z * lookat->z_f.y;
	ray->z = cp.x * lookat->x_r.z + cp.y * lookat->y_u.z + cp.z * lookat->z_f.z;
	return (ray);
}
