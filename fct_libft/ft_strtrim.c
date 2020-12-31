/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:50:46 by user42            #+#    #+#             */
/*   Updated: 2020/11/26 11:08:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_charset(char c, const char *charset)
{
	int i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static char		*get_trimed_str(char const *s1, char const *set, size_t end)
{
	char	*new_str;
	size_t	start;
	size_t	copy;

	start = 0;
	while (s1[start] != '\0' && ft_is_charset(s1[start], set) == 1)
		start++;
	if (!(new_str = (char*)malloc(sizeof(char) * ((end - start) + 2))))
		return (NULL);
	copy = 0;
	while (start < end + 1)
	{
		new_str[copy] = s1[start];
		copy++;
		start++;
	}
	new_str[copy] = '\0';
	return (new_str);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	end;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && ft_is_charset(s1[i], set) == 1)
		i++;
	if (s1[0] == '\0' || s1[i] == '\0')
	{
		if (!(new_str = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		new_str[0] = '\0';
		return (new_str);
	}
	else
	{
		end = ft_strlen(s1) - 1;
		while (end > 0 && ft_is_charset(s1[end], set) == 1)
			end--;
		new_str = get_trimed_str(s1, set, end);
	}
	return (new_str);
}
