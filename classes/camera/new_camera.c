/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 09:03:07 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/21 09:03:12 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "camera.h"
#include "minirt.h"

t_camera	*new_camera(char *line)
{
	t_camera	*camera;

	if (!(camera = (t_camera *)malloc_gc(sizeof(t_camera))))
		ft_exit(ENOMEM);
	camera->identifier[0] = 'c';
	camera->point.x = ft_atof((line = ft_next(line)));
	camera->point.y = ft_atof((line = ft_next(line)));
	camera->point.z = ft_atof((line = ft_next(line)));
	camera->vector.x = ft_atof((line = ft_next(line)));
	camera->vector.y = ft_atof((line = ft_next(line)));
	camera->vector.z = ft_atof((line = ft_next(line)));
	camera->fov = ft_atoi((line = ft_next(line)));
	return (camera);
}
