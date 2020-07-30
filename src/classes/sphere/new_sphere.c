/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 09:23:36 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/12 18:30:52 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sphere.h"
#include "exit.h"

static void	set_another(t_sphere *sphere, char *line)
{
	line = ft_next(line);
	sphere->color.r = (float)ft_atoi(line) / 255.f;
	line = ft_next(line);
	sphere->color.g = (float)ft_atoi(line) / 255.f;
	line = ft_next(line);
	sphere->color.b = (float)ft_atoi(line) / 255.f;
	sphere->del = &del_sphere;
	sphere->solve = &sp_solve;
	sphere->get_n = &sp_get_n;
	sphere->radius_square = sphere->diameter * sphere->diameter / 4;
}

t_sphere	*new_sphere(char *line)
{
	t_sphere	*sphere;

	if (!sphere_is_valid(line))
	{
		free(line);
		ft_exit(INVALID_INPUT);
	}
	if (!(sphere = (t_sphere *)malloc_gc(sizeof(t_sphere))))
		ft_exit(ENOMEM);
	sphere->identifier[0] = 's';
	sphere->identifier[1] = 'p';
	line = ft_next(line);
	sphere->center.x = ft_atof(line);
	line = ft_next(line);
	sphere->center.y = ft_atof(line);
	line = ft_next(line);
	sphere->center.z = ft_atof(line);
	line = ft_next(line);
	sphere->diameter = ft_atof(line);
	set_another(sphere, line);
	return (sphere);
}
