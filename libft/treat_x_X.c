/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_x_X.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:19:59 by wiozsert          #+#    #+#             */
/*   Updated: 2020/12/17 00:43:46 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static char	*treat_pos_hex(t_data data, char *c_str, char *buffer, int i)
{
	char	*temp;
	int		j;

	j = 0;
	while (data.width > (int)data.arg_len && data.width-- > data.precision)
		buffer[i++] = ' ';
	if (data.htag > 0)
	{
		buffer[i++] = '0';
		if (data.conv == 'x')
			buffer[i++] = 'x';
		else if (data.conv == 'X')
			buffer[i++] = 'X';
	}
	while (data.precision-- > (int)data.arg_len)
		buffer[i++] = '0';
	while ((int)data.arg_len-- >= 0)
		buffer[i++] = data.hex_temp[j++];
	temp = ft_strsjoin(c_str, buffer, 0, 0);
	if (c_str != NULL)
		free(c_str);
	c_str = temp;
	return (c_str);
}

static char	*treat_neg_hex(t_data data, char *c_str, char *buffer, int i)
{
	char	*temp;
	int		j;

	j = 0;
	if (data.htag > 0)
	{
		buffer[i++] = '0';
		if (data.conv == 'x')
			buffer[i++] = 'x';
		else if (data.conv == 'X')
			buffer[i++] = 'X';
	}
	while (data.precision-- > (int)data.arg_len)
		buffer[i++] = '0';
	while (j < (int)data.arg_len)
		buffer[i++] = data.hex_temp[j++];
	while (data.width > (int)data.arg_len && data.width-- > data.precision)
		buffer[i++] = ' ';
	temp = ft_strsjoin(c_str, buffer, 0, 0);
	if (c_str != NULL)
		free(c_str);
	c_str = temp;
	return (c_str);
}

char	*treat_hex(t_data data, char *c_str, int sign_of_width, int B_SIZE)
{
	char	buffer[B_SIZE + 1];

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
		c_str = treat_pos_hex(data, c_str, buffer, 0);
	else if(sign_of_width > 0)
		c_str = treat_neg_hex(data, c_str, buffer, 0);
	free(data.hex_temp);
	return (c_str);
}
