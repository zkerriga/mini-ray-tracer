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

static t_3dvector	*create_ray(float x, float y, float z)
{
	t_3dvector	*ray;

	if (!(ray = (t_3dvector *)malloc(sizeof(t_3dvector))))
	{
		free_gc(NULL);
		ft_exit(ENOMEM);
	}
	ray->x = x;
	ray->y = y;
	ray->z = z;
	return (normalize(ray));
}
/*
static t_3dvector	*create_ray(t_3dvector *to)
{
	t_3dvector	*ray;

	if (!(ray = (t_3dvector *)malloc(sizeof(t_3dvector))))
	{
		free_gc(NULL);
		ft_exit(ENOMEM);
	}
	ray->x = to->x;
	ray->y = to->y;
	ray->z = to->z;
	return (normalize(ray));
}*/

void				render(t_scene *scene, t_camera *camera,
							int x_size, int y_size)
{
	int			x;
	int			y;
	t_3dvector	*ray;
	float		d;
	int			*image;

	if (camera)
	{
		image = (int *)mlx_get_data_addr(scene->img, &x, &x, &x); //TODO: создать структуру для этих дел
		d = scene->get_d(scene, camera->fov);
		rotate_ray(NULL, &camera->vector);
		y = 0;
		while (y < y_size)
		{
			x = 0;
			while (x < x_size)
			{
				ray = rotate_ray(create_ray((float)x - (float)x_size / 2, (float)y - (float)y_size / 2, d), &camera->vector);
				image[y * x_size + x] = trace_ray(scene, &camera->point, ray);
				free(ray);
				++x;
			}
			++y;
		}
		mlx_put_image_to_window(scene->mlx, scene->win, scene->img, 0, 0);
	}
}
