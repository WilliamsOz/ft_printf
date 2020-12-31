/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 19:17:26 by user42            #+#    #+#             */
/*   Updated: 2020/09/21 18:46:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;

	if (!(tab = malloc(sizeof(char) * (nmemb * size))))
		return (NULL);
	tab = ft_memset(tab, 0, (nmemb * size));
	return (tab);
}
