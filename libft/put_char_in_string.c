/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char_in_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:11:08 by wiozsert          #+#    #+#             */
/*   Updated: 2021/01/06 11:11:27 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*put_char_in_str(char *str, char c)
{
	if (!(str = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}
