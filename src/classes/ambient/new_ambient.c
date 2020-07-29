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
#include "exit.h"
#include "ambient.h"

t_ambient	*new_ambient(char *line)
{
	t_ambient	*ambient;

	if (!ambient_is_valid(line))
		ft_exit(INVALID_INPUT);
	if (!(ambient = (t_ambient *)malloc_gc(sizeof(t_ambient))))
		ft_exit(ENOMEM);
	ambient->identifier[0] = 'A';
	line = ft_next(line);
	ambient->light_ratio = ft_atof(line);
	line = ft_next(line);
	ambient->color.r = (float)ft_atoi(line) / 255;
	line = ft_next(line);
	ambient->color.g = (float)ft_atoi(line) / 255;
	line = ft_next(line);
	ambient->color.b = (float)ft_atoi(line) / 255;
	ambient->del = &del_ambient;
	return (ambient);
}
