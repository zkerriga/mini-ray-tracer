/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 15:11:43 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/24 15:12:07 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "basic_structures.h"

t_bool	check_float(char *line)
{
	if (*line == '-' || *line == '+')
		++line;
	while (ft_isdigit(*line))
		++line;
	if (*line == '.')
	{
		++line;
		while (ft_isdigit(*line))
			++line;
	}
	if (*line == ',' || ft_isspace(*line) || *line == '\0')
		return (TRUE);
	else
		return (FALSE);
}
