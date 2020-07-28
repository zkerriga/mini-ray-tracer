/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 06:57:11 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/25 07:18:59 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

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
		render(scene, scene->resolution->x_size, scene->resolution->y_size);
		scene->dmlx->put_win(scene->dmlx);
	}
	return (1);
}
