/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 07:04:47 by zkerriga          #+#    #+#             */
/*   Updated: 2020/07/25 07:04:49 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "minirt.h"
# include "render.h"

int		key_handler(int keycode, t_scene *scene);
int		close_handler(t_scene *scene);

#endif
