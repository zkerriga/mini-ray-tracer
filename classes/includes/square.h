/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 09:37:50 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/21 09:38:09 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H

# include "basic_structures.h"

typedef struct	s_square
{
	char		identifier[2];
	void		(*del)(struct s_square *);
	t_point		center;
	t_3dvector	vector;
	float		side_size;
	t_color		color;
}				t_square;

t_square		*new_square(char *line);

#endif
