/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:45:55 by user42            #+#    #+#             */
/*   Updated: 2021/01/07 15:22:25 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static t_data	*str_notnull(const char *src, t_data *data, int start, int end)
{
	char	*temp;
	char	*temp2;
	int		i;
	int		len;

	temp = data->c_str;
	i = 0;
	len = end - start;
	if (!(temp2 = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	data->len_c_str += len;
	temp2[end - start] = '\0';
	while (start < end)
	{
		temp2[i] = src[start];
		i++;
		start++;
	}
	data->c_str = ft_strsjoin(temp, temp2, 0, 0);
	free(temp);
	free(temp2);
	return (data);
}

t_data		*get_string(const char *src, t_data *data, int start, int end)
{
	if (data->c_str == NULL)
	{
		if ((data->c_str = (char*)malloc(sizeof(char) * (end + 1)) == NULL))
			return (NULL);
		data->len_c_str += end;
		data->c_str[end] = '\0';
		while (start < end)
		{
			data->c_str[start] = src[start];
			start++;
		}
	}
	else
		data = str_notnull(src, data, start, end);
	return (data);
}

int			get_end(const char *src, int i)
{
	while (src[i] != 'c' && src[i] != 's' && src[i] != 'p' && src[i] != 'd' &&
		src[i] != 'i' && src[i] != 'u' && src[i] != 'x' && src[i] != 'X' &&
		src[i] != '%' && src[i] != 'n')
		i++;
	return (i + 1);
}
