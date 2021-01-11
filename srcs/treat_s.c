/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:59:11 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/08 12:00:05 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

t_data		treat_s(t_data data)
{
	
	return (data);
}


	// char	buffer[b_size + 1];
	// buffer_memset(buffer, b_size + 1);
	// if (data.precision == -1 || data.precision > data.arg_len)
	// 	data.precision = data.arg_len;
	// if (data.precision >= data.arg_len && data.conv == 's' &&
	// 	data.null_str_indicator == 0)
	// 	data.precision = data.arg_len;
	// else if (data.arg_len > data.precision && data.conv == 's'
	// 	&& data.null_str_indicator == 0 && data.precision >= 0)
	// 	data.arg_len = data.precision;
	// if (data.conv == 'c')
	// 	data.precision = data.arg_len;
	// if (data.precision == -1 && data.null_str_indicator == 1)
	// 	data.precision = data.arg_len;
	// if (n_sign == 0)
	// 	c_str = treat_positive_cs(data, c_str, buffer, 0);
	// else if (n_sign > 0)
	// 	c_str = treat_negative_cs(data, c_str, buffer, 0);
	// return (c_str);