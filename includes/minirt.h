/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 19:19:30 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/18 19:19:52 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "scene.h"

typedef struct	s_args
{
	t_bool		help;
	t_bool		save;
	const char	*path;
}				t_args;

void			show_help(void);

#endif
