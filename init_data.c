/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 09:54:36 by user42            #+#    #+#             */
/*   Updated: 2020/12/03 11:33:25 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_libft.h"

t_data	init_data_zero(t_data data)
{
	data.conv = 0;
	data.minus = 0;
	data.plus = 0;
	data.zero = 0;
	data.space = 0;
	data.htag = 0;
	data.width_star = 0;
	data.width = 0;
	data.precision_coma = 0;
	data.precision_star = 0;
	data.l = 0;
	data.d_l = 0;
	data.h = 0;
	data.d_h = 0;
	data.indicator = 0;
	data.precision_num = 0;
	return (data);
}

t_data	init_data_minus_one(t_data data)
{
	data.conv = -1;
	data.minus = -1;
	data.plus = -1;
	data.zero = -1;
	data.space = -1;
	data.htag = -1;
	data.width_star = -1;
	data.width = -1;
	data.precision_coma = -1;
	data.precision_star = -1;
	data.l = -1;
	data.d_l = -1;
	data.h = -1;
	data.d_h = -1;
	data.indicator = -1;
	data.precision_num = -1;
	return (data);
}
