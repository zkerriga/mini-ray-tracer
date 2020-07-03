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
	divider = sqrt(pow(ray->x, 2) + pow(ray->y, 2) + pow(ray->z, 2));
	ray->x /= divider;
	ray->y /= divider;
	ray->z /= divider;
	return (ray);
}

void	render(t_scene *scene, t_camera *camera, int x_size, int y_size)
{
	int			x;
	int			y;
	void		*mlx_ptr;
	void		*win_ptr;
	int			background;
	int			color;
	t_3dvector	*ray;
	float		d;

	mlx_ptr = scene->mlx;
	win_ptr = scene->window;
	if (camera)
	{
		background = color_to_int(bright(&scene->ambient->color, scene->ambient->light_ratio));
		d = scene->get_d(scene, camera->fov);
		y = 0;
		while (y < y_size)
		{
			x = 0;
			while (x < x_size)
			{
				ray = create_ray(&camera->point, x - x_size / 2, y - y_size / 2, d);
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, trace_ray(scene, &camera->point, ray));
				free(ray);
				++x;
			}
			++y;
		}
	}
}
