/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 15:15:20 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 15:15:26 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_H
# define AMBIENT_H

# include "basic_structures.h"

typedef struct	s_ambient
{
	char		identifier[2];
	float		light_ratio;
	t_color		color;
}				t_ambient;

#endif
