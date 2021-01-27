/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 09:54:36 by user42            #+#    #+#             */
/*   Updated: 2021/01/26 10:04:56 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static t_data	init_arg_data(t_data data)
{
	data.arg_string = NULL;
	data.is_str_null = 0;
	data.sign_of_prc = 1;
	data.sign_of_wdt = 1;
	data.fill_width = ' ';
	data.arg_char = 42;
	data.arg_imax = 0;
	data.arg_umax = 0;
	data.arg_len = 0;
	return (data);
}

static t_data	init_data_zero(t_data data)
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
	data.precision = 0;
	data.is_there_prc = 0;
	data.l = 0;
	data.d_l = 0;
	data.h = 0;
	data.d_h = 0;
	return (data);
}

t_data			init_arg_and_data(t_data data, int indicator)
{
	data = init_data_zero(data);
	if (indicator > 0)
		data = init_arg_data(data);
	return (data);
}
