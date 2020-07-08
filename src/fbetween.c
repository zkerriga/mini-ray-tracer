/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fbetween.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:38:29 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/08 14:38:31 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	fbetween(float nbr, float down, float up)
{
	return (nbr > down && nbr < up);
}
