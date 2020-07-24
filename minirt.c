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

void	print_camera(t_camera *camera) //TODO: delete this function
{
	puts("CAMERA:");
	printf("point={%.1f,%.1f,%.1f} dir={%.2f,%.2f,%.2f}, fov=%d\n",
			camera->point.x, camera->point.y, camera->point.z, camera->vector.x,
			camera->vector.y, camera->vector.z, camera->fov);
}

int		key_handler(int keycode, t_scene *scene)
{
	if (keycode == K_ESCAPE)
	{
		scene->del(scene);
		free_gc(NULL);
		exit(0);
	}
	else if (keycode == K_RIGHT || keycode == K_LEFT)
	{
		scene->act_cam = scene->get_cam(scene,
										keycode == K_RIGHT ? RIGHT : LEFT);
		print_camera(scene->act_cam);
		render(scene, scene->resolution->x_size, scene->resolution->y_size);
		scene->dmlx->put_win(scene->dmlx);
	}
}

void	argparse(t_args *args, int ac, char **av)
{
	args->path = NULL;
	args->save = FALSE;
	args->help = FALSE;

	if (ac == 1)
		args->help = TRUE;
	else
	{
		while (--ac > 0)
		{
			if (ft_memcmp(av[ac], "--help", 7) == 0
				|| ft_memcmp(av[ac], "-h", 3) == 0)
				args->help = TRUE;
			else if (ft_memcmp(av[ac], "--save", 7) == 0
					|| ft_memcmp(av[ac], "-s", 3) == 0)
				args->save = TRUE;
			else if (args->path == NULL)
				args->path = av[ac];
			else
				args->help = TRUE;
		}
	}
	if (args->path == NULL)
		args->help = TRUE;
}

int		main(int ac, char **av)
{
	t_scene	*scene;
	t_args	args;

	argparse(&args, ac, av);
	if (args.help)
		show_help();
	else
	{
		scene = parser(av[1], NULL);
		scene->act_cam = scene->get_cam(scene, NONE);
		if (args.save)
		{
			render(scene, scene->resolution->x_size, scene->resolution->y_size);
			scene->dmlx->put_bmp(scene->dmlx, scene->resolution->x_size, scene->resolution->y_size);
		}
		else
		{
			scene->dmlx->set_win(scene->dmlx, scene->resolution->x_size, scene->resolution->y_size);
			render(scene, scene->resolution->x_size, scene->resolution->y_size);
			scene->dmlx->put_win(scene->dmlx);
			mlx_hook(scene->dmlx->win, 2, 1L << 0, key_handler, scene);
			mlx_loop(scene->dmlx->mlx);
		}
	}
	return (0);
}
