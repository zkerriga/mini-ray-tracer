/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 14:30:06 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 14:30:19 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "basic_structures.h"

typedef struct	s_sphere
{
	char		identifier[2];
	t_point		center;
	float		diameter;
	t_color		color;
}				t_sphere;

#endif
