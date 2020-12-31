/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision_incompatibility.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:12:03 by user42            #+#    #+#             */
/*   Updated: 2020/11/20 17:48:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_libft.h"

int		pr_coma(const char *src, int i)											//check incompatibility for coma
{
	if (src[i + 1] == ' ' || src[i + 1] == '.')
		return (-1);
	i++;
	while (src[i] >= '0' && src[i] <= '9')
		i++;
	if (src[i] == '-' || src[i] == '+' || src[i] == ' ' || src[i] == '#' ||
		src[i] == '.')
		return (-1);
	return (1);
}

int		pr_star(const char *src, int i, int is_width)							//check incompatibility for star
{
	if (src[i - 1] >= '1' && src[i - 1] <= '9')
		is_width++;
	if (is_width == 1)
		return (-1);
	if ((src[i + 1] >= '0' && src[i + 1] <= '9') || (src[i + 1] == '*' ||
		src[i + 1] == '-' || src[i + 1] == ' ' || src[i + 1] == '#'))
		return (-1);
	return (1);
}
