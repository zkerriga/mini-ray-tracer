/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 15:12:29 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 15:12:34 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLUTION_H
# define RESOLUTION_H

# include "basic_structures.h"

typedef struct	s_resolution
{
	char		identifier[2];
	void		(*del)(struct s_resolution *);
	int			x_size;
	int			y_size;
}				t_resolution;

t_resolution	*new_resolution(char *line);
void			del_resolution(t_resolution *self);
t_bool			resolution_is_valid(char *line);

#endif
