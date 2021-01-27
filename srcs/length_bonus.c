/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:41:56 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/27 15:44:20 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

void		init_bonus_data(t_b_type b_type)
{
	b_type.i_long = 0;
	b_type.i_llong = 0;
	b_type.i_schar = 0;
	b_type.u_long = 0;
	b_type.u_llong = 0;
	b_type.ptr_long = NULL;
	b_type.ptr_llong = NULL;
	b_type.ptr_short = NULL;
	b_type.ptr_char = NULL;
}

t_data		bl_integer(t_data data, va_list list, t_b_type b_type)
{
	if (data.l > 0)
	{
		b_type.i_long = va_arg(list, long);
		data.arg_imax = b_type.i_long;
	}
	else if (data.d_l > 0)
	{
		b_type.i_llong = va_arg(list, long long);
		data.arg_imax = b_type.i_llong;
	}
	else if (data.h > 0)
		data.arg_imax = (short)va_arg(list, int);
	else if (data.d_h > 0)
	{
		b_type.i_schar = (signed char)va_arg(list, int);
		data.arg_imax = b_type.i_schar;
	}
	return (data);
}

t_data		bl_uinteger(t_data data, va_list list, t_b_type b_type)
{
	if (data.l > 0)
	{
		b_type.u_long = va_arg(list, unsigned long);
		data.arg_umax = b_type.u_long;
	}
	else if (data.d_l > 0)
	{
		b_type.u_llong = va_arg(list, unsigned long long);
		data.arg_umax = b_type.u_llong;
	}
	else if (data.h > 0)
		data.arg_umax = (unsigned short)va_arg(list, int);
	else if (data.d_h > 0)
		data.arg_umax = (unsigned char)va_arg(list, int);
	return (data);
}

t_data		bl_for_n(t_data data, va_list list, t_b_type b_type)
{
	if (data.l > 0)
	{
		b_type.ptr_long = va_arg(list, long*);
		*b_type.ptr_long = data.len;
	}
	else if (data.d_l > 0)
	{
		b_type.ptr_llong = va_arg(list, long long*);
		*b_type.ptr_llong = data.len;
	}
	else if (data.h > 0)
	{
		b_type.ptr_short = va_arg(list, short*);
		*b_type.ptr_short = data.len;
	}
	else if (data.d_h > 0)
	{
		b_type.ptr_char = va_arg(list, char*);
		*b_type.ptr_char = data.len;
	}
	return (data);
}
