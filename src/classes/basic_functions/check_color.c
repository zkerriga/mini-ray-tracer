/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 15:10:50 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/24 15:12:04 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "basic_structures.h"

t_bool	check_color(char **line)
{
	int	nbr;
	int	color;

	color = 0;
	while (color++ < 3)
	{
		if (!check_int(*line))
			return (FALSE);
		if (!(**line) || (nbr = ft_atoi(*line)) > 255 || nbr < 0)
			return (FALSE);
		*line = ft_next(*line);
	}
	return (TRUE);
}
