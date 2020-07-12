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

static t_3dvector	*create_ray(t_point *camera, int x, int y, float d)
{
	t_3dvector	*ray;
	float		divider;

	if (!(ray = (t_3dvector *)malloc(sizeof(t_3dvector))))
	{
		free_gc(NULL);
		ft_exit(ENOMEM);
	}
	ray->x = x - camera->x;
	ray->y = y - camera->y;
	ray->z = d - camera->z;
	divider = module(ray);
	ray->x /= divider;
	ray->y /= divider;
	ray->z /= divider;
	return (ray);
}

/*
** A call without a ray prepares the transformation matrix. A call from a ray applies the matrix to a ray.
** [x]   [xR(x) + yR(y) + zR(z) + R(x)P(x) + R(y)P(y) + R(z)P(z)]
** [y] = [xU(x) + yU(y) + zU(z) + U(x)P(x) + U(y)P(y) + U(z)P(z)]
** [z]   [xD(x) + yD(y) + zD(z) + D(x)P(x) + D(y)P(y) + D(z)P(z)]
** R - a right vector, U - an up vector, D - a camera's direction
** P - a camera's point
*/

static t_3dvector	*rotate_ray(t_3dvector *ray, t_3dvector *direction, t_point *camera)
{
	t_3dvector			tmp;
	static t_3dvector	right;
	static t_3dvector	up;
	static t_3dvector	add;

	if (ray)
	{
		set_point(&tmp, -ray->x, ray->y, ray->z);
		set_point(ray, vdot(&tmp, &right), vdot(&tmp, &up), vdot(&tmp, direction));
		normalize(ray);
	}
	else
	{
		set_point(&tmp, 0.f, 1.f, 0.f);
		vprod(&right, normalize(direction), &tmp);
		vprod(&up, &right, direction);
		set_point(&add, vdot(&right, camera), vdot(&up, camera), vdot(direction, camera));
	}
	return (ray);
}

void				render(t_scene *scene, t_camera *camera,
							int x_size, int y_size)
{
	int			x;
	int			y;
//	int			color;
	t_3dvector	*ray;
	float		d;
	int			*image;

	if (camera)
	{
		image = (int *)mlx_get_data_addr(scene->img, &x, &x, &x);
		d = scene->get_d(scene, camera->fov);
		rotate_ray(NULL, &camera->vector, &camera->point);
		y = 0;
		while (y < y_size)
		{
			x = 0;
			while (x < x_size)
			{
				ray = rotate_ray(create_ray(&camera->point, x - x_size / 2,
								y - y_size / 2, d), &camera->vector, NULL);
//				if ((color = trace_ray(scene, &camera->point, ray)))
//					mlx_pixel_put(scene->mlx, scene->window, x, y, color);
				image[y * x_size + x] = trace_ray(scene, &camera->point, ray);
				free(ray);
				++x;
			}
			++y;
		}
		mlx_put_image_to_window(scene->mlx, scene->window, scene->img, 0, 0);
	}
}
