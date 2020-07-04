/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 09:23:36 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/21 09:23:42 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sphere.h"
#include "minirt.h"

void		del_sphere(t_sphere *self);
t_bool		sphere_is_valid(char *line);
float		solve(t_sphere *self, t_point *camera, t_3dvector *ray);
t_3dvector	*get_n(t_sphere *self, t_point *point);

t_sphere	*new_sphere(char *line)
{
	t_sphere	*sphere;

	if (!sphere_is_valid(line))
		ft_exit(INVALID_INPUT);
	if (!(sphere = (t_sphere *)malloc_gc(sizeof(t_sphere))))
		ft_exit(ENOMEM);
	sphere->identifier[0] = 's';
	sphere->identifier[1] = 'p';
	sphere->center.x = ft_atof((line = ft_next(line)));
	sphere->center.y = ft_atof((line = ft_next(line)));
	sphere->center.z = ft_atof((line = ft_next(line)));
	sphere->diameter = ft_atof((line = ft_next(line)));
	sphere->color.r = ft_atoi((line = ft_next(line)));
	sphere->color.g = ft_atoi((line = ft_next(line)));
	sphere->color.b = ft_atoi((line = ft_next(line)));
	sphere->del = &del_sphere;
	sphere->solve = &solve;
	sphere->get_n = &get_n;
	return (sphere);
}
