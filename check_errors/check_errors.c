/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:58:37 by user42            #+#    #+#             */
/*   Updated: 2020/11/18 17:54:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

int		check_all_errors(const char *src)										//check all errors
{
	char	*conv;

	conv = "cspdiuxX%n";
	if (check_missing_conv(src, conv, 0) == -1)
		return (-1);
	return (1);
}
