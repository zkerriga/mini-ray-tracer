/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 09:36:34 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/21 09:36:41 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minirt.h"
#include "square.h"

void		del_square(t_square *self);
t_bool		square_is_valid(char *line);

t_square	*new_square(char *line)
{
	t_square	*square;

	if (!square_is_valid(line))
		ft_exit(INVALID_INPUT);
	if (!(square = (t_square *)malloc_gc(sizeof(t_square))))
		ft_exit(ENOMEM);
	square->identifier[0] = 's';
	square->identifier[1] = 'q';
	square->center.x = ft_atof((line = ft_next(line)));
	square->center.y = ft_atof((line = ft_next(line)));
	square->center.z = ft_atof((line = ft_next(line)));
	square->vector.x = ft_atof((line = ft_next(line)));
	square->vector.y = ft_atof((line = ft_next(line)));
	square->vector.z = ft_atof((line = ft_next(line)));
	square->side_size = ft_atof((line = ft_next(line)));
	square->color.r = ft_atoi((line = ft_next(line)));
	square->color.g = ft_atoi((line = ft_next(line)));
	square->color.b = ft_atoi((line = ft_next(line)));
	square->del = &del_square;
	return (square);
}
