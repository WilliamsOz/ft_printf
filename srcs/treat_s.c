/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:59:11 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/26 15:44:34 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static t_data		treat_pos_s(t_data data, char *buffer)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data.width > data.arg_len)
	{
		buffer[i++] = data.fill_width;
		data.width--;
	}
	while (data.arg_len > 0)
	{
		buffer[i++] = data.arg_string[j++];
		data.arg_len--;
	}
	return (data);
}

static t_data		treat_neg_s(t_data data, char *buffer)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < data.arg_len)
		buffer[i++] = data.arg_string[j++];
	while (data.width > data.arg_len)
	{
		buffer[i++] = data.fill_width;
		data.width--;
	}
	return (data);
}

static t_data		init_buffer(t_data data, int buffer_size)
{
	char	buffer[buffer_size + 1];

	buffer_memset(buffer, buffer_size + 1);
	if (data.sign_of_wdt == 1)
		data = treat_pos_s(data, buffer);
	else if (data.sign_of_wdt == -1)
		data = treat_neg_s(data, buffer);
	data.len += ft_strlen(buffer);
	write(1, buffer, ft_strlen(buffer));
	return (data);
}

static t_data		sort_for_s_conv(t_data data, int *buffer_size, int size)
{
	if (data.sign_of_prc == -1 && data.precision < 0)
		data.precision = data.arg_len;
	if (data.minus > 0)
		data.sign_of_wdt = -1;
	if (data.precision < data.arg_len && data.sign_of_prc == 1 &&
		data.precision_coma > 0)
		data.arg_len = data.precision;
	else if (data.precision > data.arg_len)
		data.precision = data.arg_len;
	if (data.width > data.arg_len)
		size = data.width;
	else if (data.arg_len >= data.width)
		size = data.arg_len;
	if (data.zero > 0 && data.minus == 0)
		data.fill_width = '0';
	*buffer_size = *buffer_size + size;
	return (data);
}

t_data				*treat_s(t_data *data)
{
	int		buffer_size;

	buffer_size = 0;
	if (data->is_str_null == 1 && data->precision_coma == 1 &&
	data->precision == 0 && data->width == 0)
		return (data);
	if (data->precision_coma > 0 && data->precision_coma == 0 &&
		data->precision == 0)
	{
		if (!(data->arg_string = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		data->arg_string[0] = '\0';
		data->arg_len = 0;
		if (data->is_str_null > 0)
			data->is_str_null = 0;
	}
	*data = sort_for_s_conv(*data, &buffer_size, 0);
	*data = init_buffer(*data, buffer_size);
	return (data);
}
