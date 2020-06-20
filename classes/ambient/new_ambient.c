/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 20:07:46 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 20:07:58 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"
#include "ambient.h"

t_ambient	*new_ambient(char *line)
{
	t_ambient	*ambient;

	if (!(ambient = (t_ambient *)malloc_gc(sizeof(t_ambient))))
		ft_exit(ENOMEM);
	ambient->identifier[0] = 'A';
	ambient->light_ratio = ft_atof((line = ft_next(line)));
	ambient->color.r = ft_atoi((line = ft_next(line)));
	ambient->color.g = ft_atoi((line = ft_next(line)));
	ambient->color.b = ft_atoi((line = ft_next(line)));
	return (ambient);
}

