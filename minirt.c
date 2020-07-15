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

void	print_camera(t_camera *camera)
{
	puts("CAMERA:");
	printf("point={%.1f,%.1f,%.1f} dir={%.1f,%.1f,%.1f}, fov=%d\n",
			camera->point.x, camera->point.y, camera->point.z, camera->vector.x,
			camera->vector.y, camera->vector.z, camera->fov);
}

int	key_handler(int keycode, t_scene *scene)
{
	t_camera	*camera;

	if (keycode == K_ESCAPE)
	{
		scene->del(scene);
		free_gc(NULL);
		exit(0);
	}
	else if (keycode == K_RIGHT)
	{
		camera = scene->get_cam(scene, RIGHT);
		print_camera(camera);
		render(scene, camera,
				scene->resolution->x_size, scene->resolution->y_size);
	}
	else if (keycode == K_LEFT)
	{
		camera = scene->get_cam(scene, LEFT);
		print_camera(camera);
		render(scene, camera,
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
