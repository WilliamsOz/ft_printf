/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:06:25 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/25 15:37:54 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static t_data	treat_neg_d_i(t_data data, char *buffer, int i, int j)
{
	int		temp_precision;

	if (data.arg_imax < 0)
		buffer[i++] = data.arg_string[j++];
	if (data.plus > 0)
		i = bonus_plus(buffer, i, &data);
	else if (data.space > 0 && data.width--)
		i = bonus_space(buffer, i);
	if (data.precision >= data.arg_len && data.arg_imax < 0)
		data.precision++;
	temp_precision = data.precision;
	while (data.precision > data.arg_len)
	{
		buffer[i++] = '0';
		data.precision--;
	}
	while (data.arg_string[j] != '\0' && data.arg_len > 0)
		buffer[i++] = data.arg_string[j++];
	while (data.width > j && data.width > temp_precision)
	{
		buffer[i++] = data.fill_width;
		data.width--;
	}
	return (data);
}

static t_data	treat_pos_d_i(t_data data, char *buffer, int i, int j)
{
	if (data.space > 0 && data.width--)
		i = bonus_space(buffer, i);
	if ((data.arg_imax < 0 && ((data.precision > data.arg_len &&
		data.precision > data.width) || (data.zero > 0 &&
		data.width > data.arg_len && data.precision < data.arg_len &&
		data.fill_width == '0'))))
		buffer[i++] = data.arg_string[j++];
	while (data.width > data.arg_len && data.width-- > data.precision)
		buffer[i++] = data.fill_width;
	if (data.plus > 0)
		i = bonus_plus(buffer, i, &data);
	if (data.arg_imax < 0 && j == 0)
		buffer[i++] = data.arg_string[j++];
	while (data.precision-- > data.arg_len)
		buffer[i++] = '0';
	while (data.arg_string[j] != '\0' && data.arg_len > 0)
		buffer[i++] = data.arg_string[j++];
	return (data);
}

static t_data	init_buffer(t_data data, int buffer_size)
{
	char	buffer[buffer_size + 1];
	int		i;

	buffer_memset(buffer, buffer_size + 1);
	i = 0;
	if (((data.plus > 0 && data.zero > 0 && data.precision_coma == 0 &&
		data.width > data.arg_len) || (data.plus > 0 && data.width <= 0 &&
		data.precision_coma == 0)))
		i = bonus_plus(buffer, i, &data);
	if (data.sign_of_wdt == 1)
	{
		if (data.precision >= data.arg_len && data.arg_imax < 0)
			data.precision++;
		data = treat_pos_d_i(data, buffer, i, 0);
	}
	else if (data.sign_of_wdt == -1)
		data = treat_neg_d_i(data, buffer, i, 0);
	data.len += ft_strlen(buffer);
	write(1, buffer, ft_strlen(buffer));
	return (data);
}

static t_data	sort_for_d_i_convs(t_data data, int *buffer_size, int size)
{
	if (data.arg_imax == 0 && data.width >= data.arg_len &&
		data.precision == -1 && data.precision_star == 0 &&
		data.precision_coma > 0)
		data.arg_len = 0;
	if (data.space > 0 && data.plus > 0)
		data.space = 0;
	if (data.zero > 0 && data.minus > 0)
		data.zero = 0;
	if (data.space > 0 && data.arg_imax < 0)
		data.space = 0;
	if (data.plus > 0 && data.arg_imax < 0)
		data.plus = 0;
	if (data.minus > 0)
		data.sign_of_wdt = -1;
	if (data.width > data.arg_len)
		size = data.width;
	if (data.precision > data.width)
		size = data.precision;
	if (data.arg_len > size)
		size = data.arg_len;
	if (data.plus > 0 || data.space > 0 || data.arg_imax < 0)
		size++;
	*buffer_size = *buffer_size + size;
	return (data);
}

t_data			treat_d_i(t_data data)
{
	int		buffer_size;

	buffer_size = 0;
	if (data.arg_imax == 0 && data.plus == 0 && ((data.precision == 0 &&
		data.width < data.arg_len) || (data.precision < 0 &&
		data.sign_of_prc == 0 && data.width == -1 &&
		data.precision_coma > 0)))
		return (data);
	else if (data.precision <= 0 && data.arg_imax == 0 &&
		data.precision_coma > 0 && data.width == 0)
		data.arg_len = 0;
	data = sort_for_d_i_convs(data, &buffer_size, 0);
	if (data.zero > 0 && data.precision < 0 && data.sign_of_wdt > 0)
		data.fill_width = '0';
	data = init_buffer(data, buffer_size);
	return (data);
}
