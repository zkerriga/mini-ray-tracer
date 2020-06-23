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

int	main(int ac, char **av)
{
	int		x;
	int		y;
	t_scene	*scene;

	if (ac > 1)
		scene = parser(av[1], NULL);
	//Установить точку отчёта камеры
	y = 0;
	while (y < scene->resolution->y_size)
	{
		x = 0;
		while (x < scene->resolution->x_size)
		{
			//преобразование координат для вывода в окно
			//color = Trace ray - определить цвет пикселя по x,y
			//раскрасить пиксель в массиве окна.
			++x;
		}
		++y;
	}
	return (0);
}
