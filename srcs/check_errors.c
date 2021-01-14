/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:58:37 by user42            #+#    #+#             */
/*   Updated: 2021/01/14 13:07:01 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

int		check_all_errors(const char *src)
{
	char	*conv;

	conv = "cspdiuxX%no";
	if (check_missing_conv(src, conv, 0) == -1)
		return (-1);
	return (1);
}
