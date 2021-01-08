/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_d_i_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 15:52:53 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/08 11:59:48 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static t_data	init_buffer(t_data data, char *buffer, int *ptr_i)
{
	int		i;

	i = 0;
	if (data.arg_imax < 0 && data.width > data.arg_len &&
		data.precision >= data.arg_len)
		data.width--;
	// if (data.plus > 0 && (data.arg_imax >= 0 || data.arg_umax >= 0))
		// i = bonus_plus(buffer, i);
	else if (data.arg_imax < 0 && ((data.precision > data.width) ||
		(data.zero > 0 && data.precision >= data.width) ||
		(data.zero > 0 && data.width > data.arg_len && data.precision == -1)))
	{
		buffer[i++] = *data.arg_string;
		*ptr_i = i;
	}
	// else if (data.space > 0 && (data.arg_imax >= 0 || data.arg_umax >= 0))
		// i = bonus_space(buffer, i);
	return (data);
}

static char		*pos_udi_di(t_data data, char *c_str, char *buffer, int i)
{
	char	c;
	int		j;

	j = i;
	c = ' ';
	if (data.zero > 0 && data.width > 0 && data.precision == -1)
		c = '0';
	while (data.width > data.arg_len && data.width-- > data.precision)
		buffer[i++] = c;
	if (data.arg_imax < 0 && buffer[0] != '-')
		buffer[i++] = data.arg_string[j++];
	while (((data.precision >= data.arg_len && data.arg_imax < 0) ||
		(data.precision > data.arg_len)) && data.precision--)
		buffer[i++] = '0';
	while (data.arg_string[j] != '\0')
		buffer[i++] = data.arg_string[j++];
	c_str = join_string(c_str, buffer);
	return (c_str);
}

static char		*neg_udi_di(t_data data, char *c_str, char *buffer, int i)
{
	char	c;
	int		j;
	int		temp;

	j = i;
	c = ' ';
	if (data.zero > 0 && data.width > 0 && data.precision == -1)
		c = '0';
	temp = data.precision;
	while (((data.precision >= data.arg_len && data.arg_imax < 0) ||
		(data.precision > data.arg_len)) && data.precision--)
		buffer[i++] = '0';
	while (data.arg_string[j] != '\0')
		buffer[i++] = data.arg_string[j++];
	while (data.width > data.arg_len && data.width-- > temp)
		buffer[i++] = c;
	c_str = join_string(c_str, buffer);
	return (c_str);
}

static char		*treat_only_width(t_data data, char *c_str, char *buffer)
{
	char	*temp;
	int		i;

	i = 0;
	while (data.width-- > 0)
		buffer[i++] = ' ';
	temp = ft_strsjoin(c_str, buffer, 0, 0);
	if (c_str != NULL)
		free(c_str);
	c_str = temp;
	return (c_str);
}

char			*treat_udi_di(t_data data, char *c_str, int sign, int b_size)
{
	char	buffer[b_size + 1];
	int		i;

	i = 0;
	buffer_memset(buffer, b_size + 1);
	data = init_buffer(data, buffer, &i);
	if (data.arg_imax == 0 && data.arg_umax == 0 && data.precision == 0 &&
		data.width <= 0)
	{
		free(data.arg_string);
		if (!(data.arg_string = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		data.arg_string[0] = '\0';
	}
	if (data.arg_imax == 0 && data.arg_umax == 0 && data.precision == 0 &&
		data.width > 0)
		c_str = treat_only_width(data, c_str, buffer);
	else if (sign == 0)
		c_str = pos_udi_di(data, c_str, buffer, i);
	else if (sign > 0)
		c_str = neg_udi_di(data, c_str, buffer, i);
	free(data.arg_string);
	return (c_str);
}
