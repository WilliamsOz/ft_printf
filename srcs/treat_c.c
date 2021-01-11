/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 15:51:09 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/11 14:19:56 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static t_data	treat_pos_c(t_data data, char *buffer)
{
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (data.width > data.arg_len)
	{
		buffer[i++] = data.fill_width;
		data.width--;
		size++;
	}
	buffer[i++] = data.arg_char;
	size++;
	join_c_conv(&data, buffer, size, 0);
	data.len_c_str += size;
	return (data);
}

static t_data	treat_neg_c(t_data data, char *buffer)
{
	int		size;
	int		i;

	i = 0;
	size = 0;
	buffer[i++] = data.arg_char;
	size++;
	while (data.width > data.arg_len)
	{
		buffer[i++] = data.fill_width;
		data.width--;
		size++;
	}
	join_c_conv(&data, buffer, size, 0);
	data.len_c_str += size;
	return (data);
}

static t_data	init_buffer(t_data data, int buffer_size)
{
	char	buffer[buffer_size + 1];

	buffer_memset(buffer, buffer_size + 1);
	if (data.sign_of_wdt == 1)
		data = treat_pos_c(data, buffer);
	else if (data.sign_of_wdt == -1)
		data = treat_neg_c(data, buffer);
	return (data);
}

static t_data	sort_for_c_conv(t_data data, int *buffer_size)
{
	int size;

	size = 0;
	if (data.width > data.arg_len)
		size = data.width;
	else
		size = data.arg_len;
	if ((data.zero > 0 && data.minus > 0) || (data.zero > 0 && data.width < 0))
		data.zero = 0;
	if (data.width < 0 || data.minus > 0)
	{
		data.sign_of_wdt = -1;
		if (data.width < 0)
			data.width *= -1;
	}
	if (data.zero > 0)
		data.fill_width = '0';
	*buffer_size = *buffer_size + size;
	return (data);
}

t_data			treat_c(t_data data)
{
	int		buffer_size;

	buffer_size = 0;
	if (data.conv == 'c')
	{
		data = sort_for_c_conv(data, &buffer_size);
		data = init_buffer(data, buffer_size);
	}
	return (data);
}
