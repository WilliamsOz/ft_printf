/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:58:37 by user42            #+#    #+#             */
/*   Updated: 2021/01/06 11:34:40 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

int		check_all_errors(const char *src)
{
	char	*conv;

	conv = "cspdiuxX%n";
	if (check_missing_conv(src, conv, 0) == -1)
		return (-1);
	return (1);
}
