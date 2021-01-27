/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_u_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:30:04 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/27 15:45:23 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static t_data	treat_pos_u(t_data data, char *buffer, int i, int j)
{
	while (data.width > data.precision && data.width > data.arg_len)
	{
		buffer[i++] = data.fill_width;
		data.width--;
	}
	while (data.precision > data.arg_len)
	{
		buffer[i++] = '0';
		data.precision--;
	}
	while (data.arg_string[j] != '\0' && data.arg_len > 0)
		buffer[i++] = data.arg_string[j++];
	return (data);
}

static t_data	treat_neg_u(t_data data, char *buffer, int i, int j)
{
	int		temp_precision;

	temp_precision = data.precision;
	while (data.precision > data.arg_len)
	{
		buffer[i++] = '0';
		data.precision--;
	}
	while (data.arg_string[j] != '\0' && data.arg_len > 0)
		buffer[i++] = data.arg_string[j++];
	while (data.width > temp_precision && data.width > data.arg_len)
	{
		buffer[i++] = data.fill_width;
		data.width--;
	}
	return (data);
}

static t_data	sort_for_u(t_data data, int *buffer_size, int size)
{
	if (data.sign_of_prc == -1)
	{
		data.precision = 0;
		data.precision_coma = 0;
	}
	if (data.zero > 0 && data.minus > 0)
		data.zero = 0;
	if (data.minus > 0)
		data.sign_of_wdt = -1;
	if (data.width > data.arg_len)
		size = data.width;
	if (data.precision > data.width)
		size = data.precision;
	if (data.arg_len > size)
		size = data.arg_len;
	*buffer_size = *buffer_size + size;
	if (data.zero > 0 && data.minus == 0 && data.sign_of_wdt == 1 &&
		data.precision_coma == 0)
		data.fill_width = '0';
	return (data);
}

static t_data	init_buffer(t_data data, int buffer_size)
{
	char	buffer[buffer_size + 1];

	buffer_memset(buffer, buffer_size + 1);
	if (data.sign_of_wdt == 1)
		data = treat_pos_u(data, buffer, 0, 0);
	else if (data.sign_of_wdt == -1)
		data = treat_neg_u(data, buffer, 0, 0);
	data.len += ft_strlen(buffer);
	write(1, buffer, ft_strlen(buffer));
	return (data);
}

t_data			treat_u_integer(t_data data)
{
	int		buffer_size;

	if (data.precision <= 0 && data.width <= 0 && data.arg_umax == 0 &&
		data.precision_coma > 0)
		return (data);
	else if (data.precision <= 0 && data.arg_umax == 0 && data.width > 0 &&
		data.precision_coma > 0)
		data.arg_len = 0;
	buffer_size = 0;
	data = sort_for_u(data, &buffer_size, 0);
	data = init_buffer(data, buffer_size);
	return (data);
}
