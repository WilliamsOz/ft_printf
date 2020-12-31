/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_d_i_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 15:52:53 by wiozsert          #+#    #+#             */
/*   Updated: 2020/12/31 16:01:25 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static char	*pos_udi_di(t_data data, char *c_str, char *buffer, int i)
{
	char 	*temp;
	int		j;

	j = 0;
	if (data.space > 0 && (data.arg_imax >= 0 || data.arg_umax >= 0))
	{
		buffer[i++] = ' ';
		data.width--;
	}
	while ((int)data.arg_len < data.width && data.width-- > data.precision)
		buffer[i++] = ' ';
	if (data.plus > 0 && (data.arg_imax >= 0 || data.arg_umax >= 0))
		buffer[i++] = '+';
	while (data.precision-- > (int)data.arg_len)
		buffer[i++] = '0';
	while ((int)data.arg_len-- >= 0)
		buffer[i++] = data.arg_string[j++];
	temp = ft_strsjoin(c_str, buffer, 0, 0);
	if (c_str != NULL)
		free(c_str);
	c_str = temp;
	return (c_str);
}

static char	*neg_udi_di(t_data data, char *c_str, char *buffer, int i)
{
	char	*temp;
	int		j;

	j = 0;
	if (data.space > 0 && (data.arg_imax >= 0 || data.arg_umax >= 0))
	{
		buffer[i++] = ' ';
		data.width--;
	}
	if (data.plus > 0 && (data.arg_imax >= 0 || data.arg_umax >= 0))
		buffer[i++] = '+';
	while (i < data.precision - (int)data.arg_len)
		buffer[i++] = '0';
	while (j < (int)data.arg_len)
		buffer[i++] = data.arg_string[j++];
	while (data.width > (int)data.arg_len && data.width-- > data.precision)
		buffer[i++] = ' ';
	temp = ft_strsjoin(c_str, buffer, 0, 0);
	if (c_str != NULL)
		free(c_str);
	c_str = temp;
	return (c_str);
}

char	*treat_udi_di(t_data data, char *c_str, int sign_of_width, int B_SIZE)
{
	char	buffer[B_SIZE + 1];

	buffer_memset(buffer, B_SIZE + 1);
	if (data.arg_imax == 0 && data.arg_umax == 0 && data.precision == 0)
	{
		free(data.arg_string);
		if (!(data.arg_string = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		data.arg_string[0] = '\0';
	}
	else if (sign_of_width == 0)
		c_str = pos_udi_di(data, c_str, buffer, 0);
	else if (sign_of_width > 0)
		c_str = neg_udi_di(data, c_str, buffer, 0);
	free(data.arg_string);
	return (c_str);
}
