/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 09:12:42 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/21 09:12:47 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"
#include "light.h"

t_light	*new_light(char *line)
{
	t_light	*light;

	if (!light_is_valid(line))
		ft_exit(INVALID_INPUT);
	if (!(light = (t_light *)malloc_gc(sizeof(t_light))))
		ft_exit(ENOMEM);
	light->identifier[0] = 'l';
	light->identifier[1] = '\0';
	line = ft_next(line);
	light->point.x = ft_atof(line);
	line = ft_next(line);
	light->point.y = ft_atof(line);
	line = ft_next(line);
	light->point.z = ft_atof(line);
	line = ft_next(line);
	light->light_ratio = ft_atof(line);
	line = ft_next(line);
	light->color.r = light->light_ratio * ((float)ft_atoi(line) / 255.f);
	line = ft_next(line);
	light->color.g = light->light_ratio * ((float)ft_atoi(line) / 255.f);
	line = ft_next(line);
	light->color.b = light->light_ratio * ((float)ft_atoi(line) / 255.f);
	light->del = &del_light;
	return (light);
}
