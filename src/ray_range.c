/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 17:24:21 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/09 17:24:24 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** The function defines the minimum and maximum values of solutions for the ray.
** The first time the function is run to create a range,
** and the second time to delete it.
*/

t_range	*ray_range(float min, float max)
{
	static t_range	*range = NULL;

	if (!range)
	{
		if (!(range = (t_range *)malloc(sizeof(t_range))))
		{
			free_gc(NULL);
			ft_exit(ENOMEM);
		}
		range->min = min;
		range->max = max;
	}
	else
	{
		free(range);
		range = NULL;
	}
	return (range);
}
