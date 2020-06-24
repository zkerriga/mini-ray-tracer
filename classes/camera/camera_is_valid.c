/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_is_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:52:35 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/24 14:52:41 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "basic_structures.h"

t_bool	camera_is_valid(char *line)
{
	int		nbr;
	int		i;

	i = 0;
	while (i++ < 3)
	{
		line = ft_next(line);
		if (!(*line))
			return (FALSE);
	}
	i = 0;
	while (i++ < 3)
	{
		line = ft_next(line);
		if (!(*line) || !ft_float_between(ft_atof(line), -1.0f, 1.0f))
			return (FALSE);
	}
	line = ft_next(line);
	if (!(*line) || (nbr = ft_atoi(line)) < 0 || nbr > 180)
		return (FALSE);
	line = ft_next(line);
	if (*line)
		return (FALSE);
	return (TRUE);
}
