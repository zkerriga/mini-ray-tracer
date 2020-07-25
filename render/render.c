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

#include "minirt.h"
#include "render.h"
#include "func.h"

int		*render(t_scene *scene, int x_size, int y_size)
{
	int			x;
	int			y;
	t_vec3	ray;
	float		d;
	int			*image;

	image = scene->dmlx->addr;
	if (scene->act_cam)
	{
		d = scene->get_d(scene, scene->act_cam->fov);
		y = 0;
		while (y < y_size)
		{
			x = 0;
			while (x < x_size)
			{
				set_point(&ray, (float)x - (float)x_size / 2.f, (float)y - (float)y_size / 2.f, d);
				rotate_ray(&ray, &scene->act_cam->matrix);
				image[y * x_size + x] = trace_ray(scene, &scene->act_cam->point, scene->objects, &ray);
				++x;
			}
			++y;
		}
	}
	return (image);
}
