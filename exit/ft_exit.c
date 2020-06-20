/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerriga <zkerriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 23:23:50 by zkerriga          #+#    #+#             */
/*   Updated: 2020/06/20 23:24:02 by zkerriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_exit(int error_code)
{
	if (error_code == ENOMEM)
		ft_exit_memerror(error_code);
	else if (error_code == INVALID_INPUT)
		ft_exit_invalid_input();
}

