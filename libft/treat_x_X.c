/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_x_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:19:59 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/04 18:25:53 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static char	*treat_pos_hex(t_data data, char *buffer, int i)
{
	char	c;
	int		j;

	j = 0;
	c = ' ';
	if (data.zero > 0)
		c = '0';
	while (data.width > data.arg_len && data.width-- > data.precision)
		buffer[i++] = c;
	if (data.htag > 0)
	{
		buffer[i++] = '0';
		if (data.conv == 'x')
			buffer[i++] = 'x';
		else if (data.conv == 'X')
			buffer[i++] = 'X';
	}
	while (data.precision-- > data.arg_len)
		buffer[i++] = '0';
	while (data.arg_len-- >= 0)
		buffer[i++] = data.hex_temp[j++];
	return (buffer);
}

static char	*treat_neg_hex(t_data data, char *buffer, int i)
{
	char	c;
	int		j;

	j = 0;
	c = ' ';
	if (data.zero > 0)
		c = '0';
	if (data.htag > 0)
	{
		buffer[i++] = '0';
		if (data.conv == 'x')
			buffer[i++] = 'x';
		else if (data.conv == 'X')
			buffer[i++] = 'X';
	}
	while (data.precision-- > data.arg_len)
		buffer[i++] = '0';
	while (j < data.arg_len)
		buffer[i++] = data.hex_temp[j++];
	while (data.width > data.arg_len && data.width-- > data.precision)
		buffer[i++] = c;
	return (buffer);
}

char	*treat_hex(t_data data, char *c_str, int sign_of_width, int B_SIZE)
{
	char	buffer[B_SIZE + 1];
	char	*temp;

	buffer_memset(buffer, B_SIZE + 1);
	if (data.hex_temp[0] == '0' && data.precision == 0)
	{
		free(data.hex_temp);
		if (!(data.hex_temp = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		data.hex_temp[0] = '\0';
	}
	if (data.htag > 0)
		data.width -= 2;
	if (sign_of_width == 0)
		treat_pos_hex(data, buffer, 0);
	else if(sign_of_width > 0)
		treat_neg_hex(data, buffer, 0);
	temp = ft_strsjoin(c_str, buffer, 0, 0);
	if (c_str != NULL)
		free(c_str);
	c_str = temp;
	free(data.hex_temp);
	return (c_str);
}
