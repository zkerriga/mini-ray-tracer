/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 15:10:42 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/24 15:12:13 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "basic_structures.h"

t_bool	check_vector(char **line)
{
	int	i;

	i = 0;
	while (i++ < 3)
	{
		if (!check_float(*line))
			return (FALSE);
		if (!(**line) ||
			!ft_float_between(ft_atof(*line), -1.0f, 1.0f))
			return (FALSE);
		*line = ft_next(*line);
	}
	return (TRUE);
}
