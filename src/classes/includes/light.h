/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 15:33:25 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 15:33:35 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "basic_structures.h"

typedef struct	s_light
{
	char		identifier[2];
	t_point		point;
	float		light_ratio;
	t_rgbvec	color;
	void		(*del)(struct s_light *);
}				t_light;

t_light			*new_light(char *line);
void			del_light(t_light *self);
t_bool			light_is_valid(char *line);

#endif
