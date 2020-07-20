/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rad_to_deg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 07:26:00 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/16 07:26:04 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

/*
** Converting radians to degrees.
*/

float	rad_to_deg(float radians)
{
	return (radians * 180 / M_PI);
}
