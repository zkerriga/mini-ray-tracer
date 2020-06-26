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

void	render(t_scene *scene, t_camera *camera, int x_size, int y_size)
{
	int		x;
	int		y;
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = scene->mlx;
	win_ptr = scene->window;
	y = 0;
	while (y < y_size)
	{
		x = 0;
		while (x < x_size)
		{
			//преобразование координат для вывода в окно
			//color = Trace ray - определить цвет пикселя по x,y
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00ff9a9e + (x + y) / 20);
			++x;
		}
		++y;
	}
}
