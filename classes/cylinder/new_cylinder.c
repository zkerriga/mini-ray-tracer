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

void		del_cylinder(t_cylinder *self);
t_bool		cylinder_is_valid(char *line);

t_cylinder	*new_cylinder(char *line)
{
	t_cylinder	*cylinder;

	if (!cylinder_is_valid(line))
		ft_exit(INVALID_INPUT);
	if (!(cylinder = (t_cylinder *)malloc_gc(sizeof(t_cylinder))))
		ft_exit(ENOMEM);
	cylinder->identifier[0] = 'c';
	cylinder->identifier[1] = 'y';
	cylinder->point.x = ft_atof((line = ft_next(line)));
	cylinder->point.y = ft_atof((line = ft_next(line)));
	cylinder->point.z = ft_atof((line = ft_next(line)));
	cylinder->vector.x = ft_atof((line = ft_next(line)));
	cylinder->vector.y = ft_atof((line = ft_next(line)));
	cylinder->vector.z = ft_atof((line = ft_next(line)));
	cylinder->diameter = ft_atof((line = ft_next(line)));
	cylinder->height = ft_atof((line = ft_next(line)));
	cylinder->color.r = (float)ft_atoi((line = ft_next(line))) / 255;
	cylinder->color.g = (float)ft_atoi((line = ft_next(line))) / 255;
	cylinder->color.b = (float)ft_atoi((line = ft_next(line))) / 255;
	cylinder->del = &del_cylinder;
	return (cylinder);
}
