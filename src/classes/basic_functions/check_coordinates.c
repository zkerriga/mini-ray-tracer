/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:01:57 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/24 16:02:19 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "basic_structures.h"

t_bool	check_coordinates(char **line)
{
	int	i;

	i = 0;
	while (i++ < 3)
	{
		if (**line == '\0')
			return (FALSE);
		if (!check_float(*line))
			return (FALSE);
		*line = ft_next(*line);
	}
	return (TRUE);
}
