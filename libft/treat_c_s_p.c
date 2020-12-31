/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_c_s_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 15:51:09 by wiozsert          #+#    #+#             */
/*   Updated: 2020/12/31 15:09:24 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

char	*treat_percent(char *c_str)
{
	char *res;
	char *temp;

	if (!(temp = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	temp[0] = '%';
	temp [1] = '\0';
	res = ft_strsjoin(c_str, temp, 0, 0);
	free(temp);
	free(c_str);
	c_str = res;
	return (c_str);
}

static char	*treat_positive_cs(t_data data, char *c_str, char *buffer, int i)
{
	char	*temp;
	int		j;

	j = 0;
	if (data.width <= (int)data.arg_len)
	{
		while ((int)data.arg_len-- > 0 && data.precision-- > 0)
			buffer[i++] = data.arg_string[j++];
	}
	else if (data.width > (int)data.arg_len)
	{
		while (data.width > (int)data.arg_len && data.width-- > data.precision)
			buffer[i++] = ' ';
		while ((int)data.arg_len-- > 0 && data.precision-- > 0)
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
	if (data.width <= (int)data.arg_len)
	{
		while ((int)data.arg_len-- > 0 && data.precision-- > 0)
			buffer[i++] = data.arg_string[j++];
	}
	else if (data.width > (int)data.arg_len)
	{
		while ((int)data.arg_len-- > 0 && data.precision-- > 0)
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

char	    *treat_cs(t_data data, char *c_str, int n_sign, size_t B_SIZE)
{
	char	buffer[B_SIZE + 1];

	if (data.precision < (int)data.arg_len &&
		data.null_str_indicator == 1)
		return (c_str);
	buffer_memset(buffer, B_SIZE + 1);
	if (data.precision >= (int)data.arg_len && data.conv == 's')
		data.precision = data.arg_len;
	else if ((int)data.arg_len > data.precision && data.conv == 's')
		data.arg_len = data.precision;
	if (data.conv == 'c')
		data.precision = data.arg_len;
	if (n_sign == 0)
		c_str = treat_positive_cs(data, c_str, buffer, 0);
	else if (n_sign > 0)
		c_str = treat_negative_cs(data, c_str, buffer, 0);
	return (c_str);
}
