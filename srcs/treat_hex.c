/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:49:39 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/14 13:58:52 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static t_data	treat_neg_hex(t_data data, char *buffer, int i, int j)
{
	if (data.htag > 0 && data.arg_umax > 0)
		data = bonus_htag(data, buffer, &i, 0);
	while (data.precision-- > 0)
		buffer[i++] = '0';
	while (data.arg_string[j] != '\0' && data.arg_len > 0)
		buffer[i++] = data.arg_string[j++];
	while (data.width-- > 0)
		buffer[i++] = ' ';
	return (data);
}

static t_data	treat_pos_hex(t_data data, char *buffer, int i, int j)
{
	if (data.htag > 0 && data.arg_umax > 0 && data.zero > 0 &&
		data.precision_coma == 0)
		data = bonus_htag(data, buffer, &i, 1);
	while (data.width-- > 0)
		buffer[i++] = data.fill_width;
	if (data.htag > 0 && data.arg_umax > 0)
		data = bonus_htag(data, buffer, &i, 0);
	while (data.precision-- > 0)
		buffer[i++] = '0';
	while (data.arg_string[j] != '\0' && data.arg_len > 0)
		buffer[i++] = data.arg_string[j++];
	return (data);
}

static t_data	sort_for_x_convs(t_data data)
{
	int temp_precision;
	int	temp_arglen;

	temp_precision = data.precision;
	if (data.precision_coma == 0 || data.precision < 0)
		data.precision = 0;
	if (data.precision_coma > 0)
		data.precision -= data.arg_len;
	temp_arglen = data.arg_len;
	if (data.arg_umax > 0 && data.htag > 0)
		data.arg_len += 2;
	if (data.precision > 0 && data.htag > 0)
		data.width = data.width - (temp_arglen + temp_precision);
	else if (data.precision > 0 && data.htag == 0)
		data.width -= temp_precision;
	else
		data.width -= data.arg_len;
	if (data.minus > 0)
		data.sign_of_wdt = -1;
	return (data);
}

static t_data	init_buffer(t_data data, int buffer_size)
{
	char	*temp;
	char	buffer[buffer_size + 1];

	buffer_memset(buffer, buffer_size + 1);
	if (data.zero > 0 && data.precision_coma == 0)
		data.fill_width = '0';
	if (data.sign_of_wdt == 1)
		data = treat_pos_hex(data, buffer, 0, 0);
	else if (data.sign_of_wdt == -1)
		data = treat_neg_hex(data, buffer, 0, 0);
	temp = ft_strsjoin(data.c_str, buffer, 0, 0);
	if (data.c_str != NULL)
		free(data.c_str);
	data.c_str = temp;
	data.len_c_str += ft_strlen(buffer);
	return (data);
}

t_data			treat_hex(t_data data)
{
	int		buffer_size;

	buffer_size = 0;
	if (data.precision <= 0 && data.width <= 0 && data.arg_umax == 0 &&
		data.precision_coma > 0)
		return (data);
	else if (data.precision_coma > 0 && data.arg_umax == 0)
		data.arg_len = 0;
	if (data.zero > 0 && data.minus > 0)
		data.zero = 0;
	if (data.width > data.arg_len)
		buffer_size = data.width;
	if (data.precision > data.width)
		buffer_size = data.precision;
	if (data.arg_len > buffer_size)
		buffer_size = data.arg_len;
	if (data.htag > 0)
		buffer_size += 2;
	data = sort_for_x_convs(data);
	data = init_buffer(data, buffer_size);
	if (data.arg_string != NULL)
		free(data.arg_string);
	return (data);
}
