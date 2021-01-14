/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:45:55 by user42            #+#    #+#             */
/*   Updated: 2021/01/14 13:15:54 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static t_data	*notnull(const char *src, t_data *data, int start, int end)
{
	char	*new_str;
	char	*temp;
	int		i;
	int		len;

	i = 0;
	len = end - start;
	if (!(temp = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	data->len_c_str += len;
	temp[len] = '\0';
	while (start < end)
	{
		temp[i] = src[start];
		i++;
		start++;
	}
	new_str = ft_strsjoin(data->c_str, temp, 0, 0);
	free(data->c_str);
	free(temp);
	data->c_str = new_str;
	return (data);
}

static t_data	*strsjoin_c(const char *src, t_data *data, int start, int end)
{
	char	*temp;
	int		len;

	len = data->len_c_str + (end - start);
	if (!(temp = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	temp[len] = '\0';
	len = 0;
	while (len < data->len_c_str)
	{
		temp[len] = data->c_str[len];
		len++;
	}
	data->len_c_str += (end - start);
	while (start < end)
	{
		temp[len] = src[start];
		len++;
		start++;
	}
	free(data->c_str);
	data->c_str = temp;
	return (data);
}

t_data			*get_string(const char *src, t_data *data, int start, int end)
{
	if (data->c_str == NULL)
	{
		if (!(data->c_str = (char*)malloc(sizeof(char) * (end + 1))))
			return (NULL);
		data->len_c_str += end;
		data->c_str[end] = '\0';
		while (start < end)
		{
			data->c_str[start] = src[start];
			start++;
		}
	}
	else if (data->conv == 'c')
		data = strsjoin_c(src, data, start, end);
	else
		data = notnull(src, data, start, end);
	return (data);
}

int				get_end(const char *src, int i)
{
	while (src[i] != 'c' && src[i] != 's' && src[i] != 'p' && src[i] != 'd' &&
		src[i] != 'i' && src[i] != 'u' && src[i] != 'x' && src[i] != 'X' &&
		src[i] != '%' && src[i] != 'n' && src[i] != 'o')
		i++;
	return (i + 1);
}
