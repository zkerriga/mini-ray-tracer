/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 15:11:58 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/24 15:12:10 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "basic_structures.h"

t_bool	check_int(char *line)
{
	if (*line == '-' || *line == '+')
		++line;
	while (ft_isdigit(*line))
		++line;
	if (*line == ',' || ft_isspace(*line) || *line == '\0')
		return (TRUE);
	else
		return (FALSE);
}
