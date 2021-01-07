/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:41:56 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/06 14:50:13 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

t_data		bonus_lenght_integer(t_data data, va_list list)
{
	if ((data.conv == 'd' || data.conv == 'i') && data.l > 0)
		data.arg_imax = (long)va_arg(list, long);
	else if ((data.conv == 'd' || data.conv == 'i') && data.d_l > 0)
		data.arg_imax = (long long)va_arg(list, long long);
	else if ((data.conv == 'd' || data.conv == 'i') && data.h > 0)
		data.arg_imax = (short)va_arg(list, int);
	else if ((data.conv == 'd' || data.conv == 'i') && data.d_h > 0)
		data.arg_imax = (char)va_arg(list, int);
	return (data);
}

t_data		bonus_lenght_uinteger(t_data data, va_list list)
{
	if ((data.conv == 'u' || data.conv == 'x' || data.conv == 'X')
		&& data.l > 0)
		data.arg_umax = (unsigned long)va_arg(list, unsigned long);
	else if ((data.conv == 'u' || data.conv == 'x' || data.conv == 'X')
		&& data.d_l > 0)
		data.arg_umax = (unsigned long long)va_arg(list, unsigned long long);
	else if ((data.conv == 'u' || data.conv == 'x' || data.conv == 'X')
		&& data.h > 0)
		data.arg_umax = (unsigned short)va_arg(list, int);
	else if ((data.conv == 'u' || data.conv == 'x' || data.conv == 'X')
		&& data.d_h > 0)
		data.arg_umax = (unsigned char)va_arg(list, int);
	return (data);
}
