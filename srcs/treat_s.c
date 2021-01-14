/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:59:11 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/12 11:03:07 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static t_data		treat_pos_s(t_data data, char *buffer)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data.width > data.arg_len)
	{
		buffer[i++] = ' ';
		data.width--;
		data.len_c_str++;
	}
	while (data.arg_len > 0)
	{
		buffer[i++] = data.arg_string[j++];
		data.arg_len--;
		data.len_c_str++;
	}
	temp = ft_strsjoin(data.c_str, buffer, 0, 0);
	if (data.c_str != NULL)
		free(data.c_str);
	data.c_str = temp;
	return (data);
}

static t_data		treat_neg_s(t_data data, char *buffer)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data.precision > 0)
	{
		buffer[i++] = data.arg_string[j++];
		data.precision--;
		data.len_c_str++;
	}
	while (data.width > data.arg_len)
	{
		buffer[i++] = ' ';
		data.width--;
		data.len_c_str++;
	}
	temp = ft_strsjoin(data.c_str, buffer, 0, 0);
	if (data.c_str != NULL)
		free(data.c_str);
	data.c_str = temp;
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
	return (data);
}

static t_data		sort_for_s_conv(t_data data, int *buffer_size, int size)
{
	if (data.width < 0 || data.minus > 0)
	{
		data.sign_of_wdt = -1;
		if (data.width < 0)
			data.width *= -1;
	}
	if (data.null_str_indicator == 1)
	{
		data.arg_string = "(null)";
		data.arg_len = 6;
	}
	if (data.precision < data.arg_len && data.precision >= 0)
		data.arg_len = data.precision;
	else
		data.precision = data.arg_len;
	if (data.width > data.arg_len)
		size = data.width;
	else if (data.arg_len >= data.width)
		size = data.arg_len;
	*buffer_size = *buffer_size + size;
	return (data);
}

t_data				*treat_s(t_data *data)
{
	int		buffer_size;

	if ((data->arg_string[0] == '\0' && data->width <= 0) ||
		(data->precision_coma > 0 && data->precision <= 0 &&
		data->width <= 0 && data->precision_star == 0))
		return (data);
	if ((data->null_str_indicator == 1 && data->precision == 0) ||
		(data->precision == -1 && data->precision_coma > 0 &&
		data->precision_star == 0))
	{
		if (!(data->arg_string = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		data->arg_string[0] = '\0';
		data->arg_len = 0;
		if (data->null_str_indicator > 0)
			data->null_str_indicator = 0;
	}
	*data = sort_for_s_conv(*data, &buffer_size, 0);
	*data = init_buffer(*data, buffer_size);
	return (data);
}
