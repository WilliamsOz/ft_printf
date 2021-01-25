/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:53:14 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/25 15:39:47 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static t_data	treat_pos_percent(t_data data, char *buffer)
{
	int		i;

	i = 0;
	while (data.width > data.arg_len)
	{
		buffer[i++] = data.fill_width;
		data.width--;
	}
	buffer[i] = '%';
	return (data);
}

static t_data	treat_neg_percent(t_data data, char *buffer)
{
	int		i;

	i = 0;
	buffer[i++] = '%';
	while (data.width > data.arg_len)
	{
		buffer[i++] = data.fill_width;
		data.width--;
	}
	return (data);
}

static t_data	sort_for_percent(t_data data, int *buffer_size, int size)
{
	size = data.arg_len;
	if (data.width > data.arg_len)
		size = data.width;
	if (data.zero > 0 && data.minus > 0)
		data.zero = 0;
	if (data.minus > 0)
		data.sign_of_wdt = -1;
	if (data.zero > 0)
		data.fill_width = '0';
	*buffer_size = *buffer_size + size;
	return (data);
}

static t_data	init_buffer(t_data data, int buffer_size)
{
	char	buffer[buffer_size + 1];

	buffer_memset(buffer, buffer_size + 1);
	if (data.sign_of_wdt == 1)
		data = treat_pos_percent(data, buffer);
	else if (data.sign_of_wdt == -1)
		data = treat_neg_percent(data, buffer);
	data.len += ft_strlen(buffer);
	write(1, buffer, ft_strlen(buffer));
	return (data);
}

t_data			treat_percent(t_data data)
{
	int		buffer_size;

	buffer_size = 0;
	data = sort_for_percent(data, &buffer_size, 0);
	data = init_buffer(data, buffer_size);
	return (data);
}
