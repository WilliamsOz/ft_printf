/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 09:54:36 by user42            #+#    #+#             */
/*   Updated: 2020/12/31 15:09:09 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

t_data	sort_data(t_data data)
{
	if (data.zero > 0 && data.minus > 0)
		data.zero = 0;
	if (data.space > 0 && data.plus > 0)
		data.space = 0;
	if (data.zero > 0 && data.precision_coma > 0)
		data.zero = 0;
	if (data.precision < 0 && (data.conv == 'd' || data.conv == 'i'))
		data.precision = 0;
	if (data.arg_imax < 0 && data.space > 0)
		data.space = 0;
	if (data.width_star > 0)
		data.width = data.width_star;
	if (data.conv == 'c')
		data.arg_string = &data.arg_char;
	if (data.conv == '%' && data.precision > 0)
		data.precision = data.arg_len;
	if (data.conv == 'p')
		data.arg_string = data.arg_addr;
	return (data);
}

static t_data	init_arg_data(t_data data)
{
	data.arg_string = NULL;
	data.null_str_indicator = 0;
	data.arg_char = '\0';
	data.arg_imax = -1;
	data.arg_umax = 0;
	data.arg_addr = NULL;
	data.hex_temp = NULL;
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
	data.width = -1;
	data.precision_coma = 0;
	data.precision_star = -1;
	data.precision = -1;
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
