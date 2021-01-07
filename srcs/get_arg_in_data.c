/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_in_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:44:43 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/07 15:29:19 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static t_data	get_for_n_arg(t_data data, va_list list)
{
	if (data.d_l > 0)
		data.arg_pinteger = (intmax_t*)va_arg(list, int*);
	else
		data.arg_pinteger = (long*)va_arg(list, int*);
	*data.arg_pinteger = data.len_c_str;
	return (data);
}

static t_data	get_simple_arg(t_data data, va_list list)
{
	if (data.conv == 'c')
		data.arg_char = va_arg(list, int);
	else if (data.conv == 's')
	{
		data.arg_string = va_arg(list, char*);
		if (data.arg_string == NULL)
		{
			data.arg_string = "(null)";
			data.null_str_indicator = 1;
		}
	}
	else if (data.conv == 'p')
	{
		data.arg_umax = va_arg(list, unsigned long long);
		if (data.arg_umax == 0)
			data.arg_addr = "0x0";
		else
			data = get_address(data, "0123456789abcdef", -1);
	}
	return (data);
}

static t_data	get_uinteger(t_data data, va_list list)
{
	if (data.l == 0 && data.d_l == 0 && data.h == 0 && data.d_h == 0)
		data.arg_umax = (unsigned int)va_arg(list, unsigned int);
	else
		data = bonus_lenght_uinteger(data, list);
	data.arg_string = ft_uitoa(data.arg_umax);
	return (data);
}

static t_data	get_integer_arg(t_data data, va_list list)
{
	if (data.l == 0 && data.d_l == 0 && data.h == 0 && data.d_h == 0)
		data.arg_imax = (int)va_arg(list, int);
	else
		data = bonus_lenght_integer(data, list);
	data.arg_string = ft_itoa(data.arg_imax);
	return (data);
}

t_data			get_arg(t_data data, va_list list)
{
	if (data.conv == 'c' || data.conv == 's' || data.conv == 'p')
		data = get_simple_arg(data, list);
	else if (data.conv == 'n')
		data = get_for_n_arg(data, list);
	else if (data.conv == 'd' || data.conv == 'i')
		data = get_integer_arg(data, list);
	else if (data.conv == 'u' || data.conv == 'x' || data.conv == 'X')
	{
		data = get_uinteger(data, list);
		if (data.conv == 'x')
			data = convert_hex(data, "0123456789abcdef", "0123456789ABCDEF", 0);
		if (data.conv == 'X')
			data = convert_hex(data, "0123456789abcdef", "0123456789ABCDEF", 1);
	}
	return (data);
}
