/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:49:39 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/27 15:45:14 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static t_data	treat_neg_hex(t_data data, char *buffer, int i, int j)
{
	int		temp_precision;

	if (data.htag > 0 && data.arg_umax > 0)
		data = bonus_htag(data, buffer, &i, 0);
	temp_precision = data.precision;
	while (data.precision-- > data.arg_len)
		buffer[i++] = '0';
	while (data.arg_string[j] != '\0' && data.arg_len > 0)
		buffer[i++] = data.arg_string[j++];
	while (data.width > temp_precision && data.width-- > data.arg_len)
		buffer[i++] = ' ';
	return (data);
}

static t_data	treat_pos_hex(t_data data, char *buffer, int i, int j)
{
	if (data.htag > 0 && data.arg_umax > 0 && data.zero > 0 &&
		data.precision_coma == 0)
		data = bonus_htag(data, buffer, &i, 1);
	while (data.width > data.precision && data.width-- > data.arg_len)
		buffer[i++] = data.fill_width;
	if (data.htag > 0 && data.arg_umax > 0)
		data = bonus_htag(data, buffer, &i, 0);
	while (data.precision-- > data.arg_len)
		buffer[i++] = '0';
	while (data.arg_string[j] != '\0' && data.arg_len > 0)
		buffer[i++] = data.arg_string[j++];
	return (data);
}

static t_data	sort_for_x_convs(t_data data)
{
	if (data.sign_of_prc == -1)
	{
		data.precision = 0;
		data.precision_coma = 0;
	}
	if (data.htag > 0 && data.arg_umax > 0)
		data.width -= 2;
	if (data.precision_coma > 0 && data.precision == 0 && data.arg_umax == 0)
		data.arg_len = 0;
	if (data.sign_of_prc == -1)
		data.precision = data.arg_len;
	if (data.zero > 0 && data.minus == 0 && data.sign_of_wdt == 1 &&
		data.precision_coma == 0)
		data.fill_width = '0';
	return (data);
}

static t_data	init_buffer(t_data data, int buffer_size)
{
	char	buffer[buffer_size + 1];
	int		len;

	buffer_memset(buffer, buffer_size + 1);
	if (data.sign_of_wdt == 1)
		data = treat_pos_hex(data, buffer, 0, 0);
	else if (data.sign_of_wdt == -1)
		data = treat_neg_hex(data, buffer, 0, 0);
	len = ft_strlen(buffer);
	write(1, buffer, len);
	data.len += len;
	return (data);
}

t_data			treat_hex(t_data data)
{
	int		buffer_size;

	buffer_size = 0;
	if (data.precision == 0 && data.width == 0 && data.arg_umax == 0 &&
		data.precision_coma > 0)
		return (data);
	buffer_size = data.arg_len;
	if (data.width > buffer_size)
		buffer_size = data.width;
	if (data.precision > buffer_size)
		buffer_size = data.precision;
	if (data.htag > 0)
		buffer_size += 3;
	data = sort_for_x_convs(data);
	data = init_buffer(data, buffer_size);
	return (data);
}
