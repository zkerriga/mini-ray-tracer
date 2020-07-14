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
#include "render.h"
#include "parser.h"

int	key_handler(int keycode, t_scene *scene)
{
	if (keycode == K_ESCAPE)
	{
		scene->del(scene);
		free_gc(NULL);
		exit(0);
	}
	else if (keycode == K_RIGHT)
	{
		render(scene, scene->get_cam(scene, RIGHT),
				scene->resolution->x_size, scene->resolution->y_size);
	}
	else if (keycode == K_LEFT)
	{
		render(scene, scene->get_cam(scene, LEFT),
				scene->resolution->x_size, scene->resolution->y_size);
	}
}

int	main(int ac, char **av)
{
	t_scene	*scene;

	if (ac > 1)
	{
		scene = parser(av[1], NULL);
		render(scene, scene->get_cam(scene, NONE),
				scene->resolution->x_size, scene->resolution->y_size);
		mlx_hook(scene->win, 2, 1L << 0, key_handler, scene);
		mlx_loop(scene->mlx);
	}
	else
	{
		//TODO: show help
	}
	return (0);
}
