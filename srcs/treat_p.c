/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:44:24 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/25 15:38:52 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static t_data	treat_pos_p(t_data data, char *buffer, int i, int j)
{
	if (data.zero > 0)
	{
		i = addprefix_of_p_conv(buffer, i, &j);
		while (data.width-- > data.arg_len)
			buffer[i++] = data.fill_width;
	}
	while (data.width > data.arg_len && data.width > data.precision &&
		data.zero == 0)
	{
		buffer[i++] = ' ';
		data.width--;
	}
	if (data.zero == 0)
		i = addprefix_of_p_conv(buffer, i, &j);
	while (data.precision > data.arg_len)
	{
		buffer[i++] = '0';
		data.precision--;
	}
	while (data.arg_string[j] != '\0')
		buffer[i++] = data.arg_string[j++];
	return (data);
}

static t_data	treat_neg_p(t_data data, char *buffer)
{
	int		i;
	int		j;
	int		temp_precision;

	i = 0;
	j = 0;
	temp_precision = data.precision;
	i = addprefix_of_p_conv(buffer, i, &j);
	while (data.precision > data.arg_len)
	{
		buffer[i++] = '0';
		data.precision--;
	}
	while (data.arg_string[j] != '\0')
		buffer[i++] = data.arg_string[j++];
	while (data.width > data.arg_len && data.width > temp_precision)
	{
		buffer[i++] = ' ';
		data.width--;
	}
	return (data);
}

static t_data	init_buffer(t_data data, int buffer_size)
{
	char	buffer[buffer_size + 1];

	buffer_memset(buffer, buffer_size + 1);
	if (data.sign_of_wdt == 1)
		data = treat_pos_p(data, buffer, 0, 0);
	else if (data.sign_of_wdt == -1)
		data = treat_neg_p(data, buffer);
	data.len += ft_strlen(buffer);
	write(1, buffer, ft_strlen(buffer));
	return (data);
}

static t_data	sort_for_p_conv(t_data data, int *buffer_size, int size)
{
	if (data.zero > 0 && data.minus > 0)
		data.zero = 0;
	if (data.zero > 0)
		data.fill_width = '0';
	if (data.width > data.arg_len)
		size = data.width;
	else if (data.precision > data.arg_len && data.precision > data.width)
		size = data.precision;
	else if (data.arg_len >= data.width && data.arg_len > data.precision)
		size = data.arg_len;
	if (data.minus > 0)
		data.sign_of_wdt = -1;
	*buffer_size = *buffer_size + size;
	return (data);
}

t_data			treat_p(t_data data)
{
	int		buffer_size;

	buffer_size = 0;
	if (data.arg_umax == 0 && data.width <= data.arg_len &&
		data.precision <= data.arg_len)
	{
		data.len += ft_strlen(data.arg_string);
		write(1, data.arg_string, data.len);
		return (data);
	}
	if (data.precision > data.arg_len)
		data.precision += 2;
	data = sort_for_p_conv(data, &buffer_size, 0);
	data = init_buffer(data, buffer_size);
	if (data.arg_string != NULL)
		free(data.arg_string);
	return (data);
}
