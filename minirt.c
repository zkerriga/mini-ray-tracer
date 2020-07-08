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

int	main(int ac, char **av)
{
	t_scene	*scene;

	if (ac > 1)
	{
		scene = parser(av[1], NULL);
		render(scene, (scene->cameras ? scene->cameras->content : NULL),
			   scene->resolution->x_size, scene->resolution->y_size);
		system("sleep 5");
//		system("read -rs -n 1 key");
		scene->del(scene);
		free_gc(NULL);
	}
	return (0);
}
