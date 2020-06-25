/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 16:36:27 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/17 16:38:17 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx.h"
#include "mlx_int.h"
#include "math.h"

#define BLACK 0x00000000
#define ANY 0x
#define ANY2 0x

int	main(int ac, char **av)
{
	int		x;
	int		y;
	t_scene	*scene;

	if (ac > 1)
	{
		scene = parser(av[1], NULL);
		//Установить точку отчёта камеры
		void	*mlx_ptr = mlx_init(); //TODO: check the return value
		void	*win_ptr = mlx_new_window(mlx_ptr, scene->resolution->x_size, scene->resolution->y_size, MAINTAINER);
		int x1 = 60;
		int y1 = 60;
		y = 0;
		while (y < scene->resolution->y_size)
		{
			x = 0;
			x1 = 60;
			while (x < scene->resolution->x_size)
			{
				//преобразование координат для вывода в окно
				//color = Trace ray - определить цвет пикселя по x,y
				//раскрасить пиксель в массиве окна.
				if (x != 0 && x % 120 == 0)
					x1 += 120;
				if (sqrt(pow(abs(x - x1), 2) + pow(abs(y - y1), 2)) < 50)
				{
					if ((x / 120 + y / 120) % 2 == 0)
						mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00ff9a9e + (x + y) / 20);
					else
						mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x008fd3f4 - (x + y) * 5);
				}
				++x;
			}
			if (y != 0 && y % 120 == 0)
				y1 += 120;
			++y;
		}
		mlx_loop(mlx_ptr);
		scene->del(scene);
		free_gc(NULL);
	}
	return (0);
}
