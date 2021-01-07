/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_c_s_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 15:51:09 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/06 12:16:21 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static char	*treat_positive_cs(t_data data, char *c_str, char *buffer, int i)
{
	char	*temp;
	int		j;

	j = 0;
	if (data.width <= data.arg_len)
	{
		while (data.arg_len-- > 0 && data.precision-- > 0)
			buffer[i++] = data.arg_string[j++];
	}
	else if (data.width > data.arg_len)
	{
		while (data.width > data.arg_len && data.width-- > data.precision)
			buffer[i++] = ' ';
		while (j < data.precision)
			buffer[i++] = data.arg_string[j++];
	}
	temp = ft_strsjoin(c_str, buffer, 0, 0);
	if (c_str != NULL)
		free(c_str);
	c_str = temp;
	return (c_str);
}

static char	*treat_negative_cs(t_data data, char *c_str, char *buffer, int i)
{
	char	*temp;
	int		j;

	j = 0;
	if (data.width <= data.arg_len)
	{
		while (data.arg_len-- > 0 && data.precision-- > 0)
			buffer[i++] = data.arg_string[j++];
	}
	else if (data.width > data.arg_len)
	{
		while (data.arg_len-- > 0 && data.precision-- > 0)
			buffer[i++] = data.arg_string[j++];
		while (i < data.width)
			buffer[i++] = ' ';
	}
	temp = ft_strsjoin(c_str, buffer, 0, 0);
	if (c_str != NULL)
		free(c_str);
	c_str = temp;
	return (c_str);
}

char		*treat_cs(t_data data, char *c_str, int n_sign, size_t b_size)
{
	char	buffer[b_size + 1];

	buffer_memset(buffer, b_size + 1);
	if (data.precision == -1 || data.precision > data.arg_len)
		data.precision = data.arg_len;
	if (data.precision >= data.arg_len && data.conv == 's' &&
		data.null_str_indicator == 0)
		data.precision = data.arg_len;
	else if (data.arg_len > data.precision && data.conv == 's'
		&& data.null_str_indicator == 0 && data.precision >= 0)
		data.arg_len = data.precision;
	if (data.conv == 'c')
		data.precision = data.arg_len;
	if (data.precision == -1 && data.null_str_indicator == 1)
		data.precision = data.arg_len;
	if (n_sign == 0)
		c_str = treat_positive_cs(data, c_str, buffer, 0);
	else if (n_sign > 0)
		c_str = treat_negative_cs(data, c_str, buffer, 0);
	return (c_str);
}
