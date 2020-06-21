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

t_sphere	*new_sphere(char *line)
{
	t_sphere	*sphere;

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
	return (sphere);
}
