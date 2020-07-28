/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 09:44:23 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/21 09:44:54 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"
#include "cylinder.h"

static void	calculate(t_cylinder *self)
{
	float	half_height;

	half_height = self->height / 2;
	self->radius_square = self->diameter * self->diameter / 4;
	vset(&self->up_center, self->point.x + half_height * self->vector.x,
			self->point.y + half_height * self->vector.y,
			self->point.z + half_height * self->vector.z);
	vset(&self->down_center, self->point.x - half_height * self->vector.x,
			self->point.y - half_height * self->vector.y,
			self->point.z - half_height * self->vector.z);
}

static void	set_another(t_cylinder *cylinder, char *line)
{
	line = ft_next(line);
	cylinder->diameter = ft_atof(line);
	line = ft_next(line);
	cylinder->height = ft_atof(line);
	line = ft_next(line);
	cylinder->color.r = (float)ft_atoi(line) / 255.f;
	line = ft_next(line);
	cylinder->color.g = (float)ft_atoi(line) / 255.f;
	line = ft_next(line);
	cylinder->color.b = (float)ft_atoi(line) / 255.f;
	cylinder->del = &del_cylinder;
	cylinder->solve = &cy_solve;
	cylinder->get_n = &cy_get_n;
	cylinder->prepare = &cy_prepare;
	normalize(&cylinder->vector);
	calculate(cylinder);
}

t_cylinder	*new_cylinder(char *line)
{
	t_cylinder	*cylinder;

	if (!cylinder_is_valid(line))
		ft_exit(INVALID_INPUT);
	if (!(cylinder = (t_cylinder *)malloc_gc(sizeof(t_cylinder))))
		ft_exit(ENOMEM);
	cylinder->identifier[0] = 'c';
	cylinder->identifier[1] = 'y';
	line = ft_next(line);
	cylinder->point.x = ft_atof(line);
	line = ft_next(line);
	cylinder->point.y = ft_atof(line);
	line = ft_next(line);
	cylinder->point.z = ft_atof(line);
	line = ft_next(line);
	cylinder->vector.x = ft_atof(line);
	line = ft_next(line);
	cylinder->vector.y = ft_atof(line);
	line = ft_next(line);
	cylinder->vector.z = ft_atof(line);
	set_another(cylinder, line);
	return (cylinder);
}
