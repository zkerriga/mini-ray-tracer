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

void	render(t_scene *scene, t_camera *camera, int x_size, int y_size)
{
	int		x;
	int		y;
	void	*mlx_ptr;
	void	*win_ptr;
	int		background;

	mlx_ptr = scene->mlx;
	win_ptr = scene->window;
	background = color_to_int(bright(&scene->ambient->color, scene->ambient->light_ratio));
	if (camera)
	{
		y = 0;
		while (y < y_size)
		{
			x = 0;
			while (x < x_size)
			{
				//преобразование координат для вывода в окно
				//color = Trace ray - определить цвет пикселя по x,y
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, background);
				++x;
			}
			++y;
		}
	}
}
