/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 16:53:14 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/04 17:07:29 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

static char	*treat_pos_percent(t_data data, char *c_str, char *buffer, char c)
{
	char	*temp;
	int		i;

	i = 0;
	while (--data.width > data.arg_len)
		buffer[i++] = c;
	buffer[i] = '%';
	temp = ft_strsjoin(c_str, buffer, 0, 0);
	if (c_str != NULL)
		free(c_str);
	c_str = temp;
	return (c_str);
}

static char	*treat_neg_percent(t_data data, char *c_str, char *buffer, char c)
{
	char	*temp;
	int		i;

	i = 0;
	buffer[i++] = '%';
	while (--data.width > data.arg_len)
		buffer[i++] = c;
	temp = ft_strsjoin(c_str, buffer, 0, 0);
	if (c_str != NULL)
		free(c_str);
	c_str = temp;
	return (c_str);
}

char		*treat_percent(t_data data, char *c_str, size_t bsize, int sign_ow)
{
	char	buffer[bsize + 1];
	char	c;

	buffer_memset(buffer, bsize + 1);
	c = ' ';
	if (data.zero > 0)
		c = '0';
	if (sign_ow == 0)
		c_str = treat_pos_percent(data, c_str, buffer, c);
	else if (sign_ow > 0)
		c_str = treat_neg_percent(data, c_str, buffer, c);
	return (c_str);
}
