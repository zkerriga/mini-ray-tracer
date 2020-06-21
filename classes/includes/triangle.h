/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 15:02:37 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 15:05:05 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "basic_structures.h"

typedef struct	s_triangle
{
	char		identifier[2];
	void		(*del)(struct s_triangle *);
	t_point		first;
	t_point		second;
	t_point		third;
	t_color		color;
}				t_triangle;

#endif
