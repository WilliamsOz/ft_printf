/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:38:13 by user42            #+#    #+#             */
/*   Updated: 2021/01/28 11:59:19 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_libft.h"

t_data	exploit_data(t_data data)
{
	if (data.conv == 'c')
		data = treat_c(data);
	else if (data.conv == 's')
		treat_s(&data);
	else if (data.conv == 'p')
		data = treat_p(data);
	else if (data.conv == 'd' || data.conv == 'i')
		data = treat_d_i(data);
	else if (data.conv == 'x' || data.conv == 'X')
		data = treat_hex(data);
	else if (data.conv == 'u')
		data = treat_u_integer(data);
	if (data.arg_string != NULL && (data.conv == 'p' || data.conv == 'u' ||
		data.conv == 'x' || data.conv == 'X' || data.conv == 'd' ||
		data.conv == 'i'))
		free(data.arg_string);
	return (data);
}

t_data	treat_content(const char *src, va_list list, t_data data)
{
	data = init_arg_and_data(data, 1);
	data = get_data(src, data, list);
	data = get_arg(data, list);
	data = get_len_of_conv(data);
	if (data.conv == '%')
		data = treat_percent(data);
	else if (data.conv != 'n')
		data = exploit_data(data);
	return (data);
}

t_data	read_input(const char *src, va_list list, t_data data)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		while (src[i] != '\0' && src[i] != '%')
		{
			write(1, &src[i], 1);
			i++;
			data.len++;
		}
		if (src[i] == '%')
		{
			data = treat_content(src + (i + 1), list, data);
			i = get_end(src, i + 1);
		}
	}
	return (data);
}

int		ft_printf(const char *format, ...)
{
	t_data		data;
	va_list		list;

	if (format[0] == '\0')
		return (0);
	data.len = 0;
	va_start(list, format);
	data = read_input(format, list, data);
	va_end(list);
	return (data.len);
}
