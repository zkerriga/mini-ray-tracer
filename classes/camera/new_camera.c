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
#include "func.h"

static void	set_another(t_camera *camera, char *line)
{
	line = ft_next(line);
	camera->fov = ft_atoi(line);
	camera->del = &del_camera;
	normalize(&camera->vector);
	set_lookat(&camera->matrix, &camera->vector);
}

t_camera	*new_camera(char *line)
{
	t_camera	*camera;

	if (!camera_is_valid(line))
		ft_exit(INVALID_INPUT);
	if (!(camera = (t_camera *)malloc_gc(sizeof(t_camera))))
		ft_exit(ENOMEM);
	camera->identifier[0] = 'c';
	camera->identifier[1] = '\0';
	line = ft_next(line);
	camera->point.x = ft_atof(line);
	line = ft_next(line);
	camera->point.y = ft_atof(line);
	line = ft_next(line);
	camera->point.z = ft_atof(line);
	line = ft_next(line);
	camera->vector.x = ft_atof(line);
	line = ft_next(line);
	camera->vector.y = ft_atof(line);
	line = ft_next(line);
	camera->vector.z = ft_atof(line);
	set_another(camera, line);
	return (camera);
}
