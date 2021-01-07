/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:19:59 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/06 14:50:02 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static char	*treat_pos_hex(t_data data, char *buffer)
{
	char	c;
	int		i;
	int		j;

	c = ' ';
	j = 0;
	i = 0;
	if (data.zero > 0)
		c = '0';
	if (data.htag > 0 && data.arg_umax > 0)
		data = bonus_htag(data, buffer, &i);
	while (data.width > data.arg_len && data.width-- > data.precision)
		buffer[i++] = c;
	while (data.precision-- > data.arg_len)
		buffer[i++] = '0';
	while (data.arg_len-- >= 0)
		buffer[i++] = data.hex_temp[j++];
	return (buffer);
}

static char	*treat_neg_hex(t_data data, char *buffer)
{
	char	c;
	int		i;
	int		j;

	c = ' ';
	j = 0;
	i = 0;
	if (data.zero > 0)
		c = '0';
	if (data.htag > 0 && data.arg_umax > 0)
		data = bonus_htag(data, buffer, &i);
	while (data.precision-- > data.arg_len)
		buffer[i++] = '0';
	while (j < data.arg_len)
		buffer[i++] = data.hex_temp[j++];
	while (data.width > data.arg_len && data.width-- > data.precision)
		buffer[i++] = c;
	return (buffer);
}

char		*treat_hex(t_data data, char *c_str, int sign_of_width, int b_size)
{
	char	buffer[b_size + 1];
	char	*temp;

	buffer_memset(buffer, b_size + 1);
	if (data.htag > 0)
		data.width -= 2;
	if (sign_of_width == 0)
		treat_pos_hex(data, buffer);
	else if (sign_of_width > 0)
		treat_neg_hex(data, buffer);
	temp = ft_strsjoin(c_str, buffer, 0, 0);
	if (c_str != NULL)
		free(c_str);
	c_str = temp;
	free(data.hex_temp);
	return (c_str);
}
