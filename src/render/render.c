/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 11:05:24 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/26 11:05:40 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int		*render(t_scene *scene, int *image, int x_size, int y_size)
{
	register int	x;
	register int	y;
	t_vec3			ray;
	float			d;

	if (scene->act_cam)
	{
		d = scene->get_d(scene, scene->act_cam->fov);
		y = -1;
		while (++y < y_size)
		{
			x = -1;
			while (++x < x_size)
			{
				vset(&ray, (float)x - (float)x_size / 2.f,
						(float)y - (float)y_size / 2.f, d);
				rotate_ray(&ray, &scene->act_cam->matrix);
				image[y * x_size + x] = trace_ray(scene, &scene->act_cam->point,
													scene->objects, &ray);
			}
		}
	}
	return (image);
}
