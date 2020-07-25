/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_is_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:52:35 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/24 15:04:57 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "basic_structures.h"

t_bool	cylinder_is_valid(char *line)
{
	line = ft_next(line);
	if (!check_coordinates(&line))
		return (FALSE);
	if (!check_vector(&line))
		return (FALSE);
	if (!check_float(line) || ft_atof(line) < 0)
		return (FALSE);
	line = ft_next(line);
	if (!check_float(line) || ft_atof(line) < 0)
		return (FALSE);
	line = ft_next(line);
	if (!check_color(&line))
		return (FALSE);
	if (*line == '\0')
		return (TRUE);
	else
		return (FALSE);
}
