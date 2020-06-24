/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 16:16:57 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 16:17:14 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "resolution.h"
#include "libft.h"
#include "minirt.h"

void			del_resolution(t_resolution *self);
t_bool			resolution_is_valid(char *line);

t_resolution	*new_resolution(char *line)
{
	t_resolution	*resolution;

	if (!resolution_is_valid(line))
		ft_exit(INVALID_INPUT);
	if (!(resolution = (t_resolution *)malloc_gc(sizeof(t_resolution))))
		ft_exit(ENOMEM);
	resolution->identifier[0] = 'R';
	resolution->x_size = ft_atoi((line = ft_next(line)));
	resolution->y_size = ft_atoi((line = ft_next(line)));
	resolution->del = &del_resolution;
	return (resolution);
}
