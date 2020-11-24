/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:38:13 by user42            #+#    #+#             */
/*   Updated: 2020/11/20 19:16:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_libft.h"

// t_data	sort_data(t_data data)
// {
	
// 	return (data);
// }

char	*get_content(const char *src, va_list list, char *c_str)
{
	t_data	data;
	(void)list;
	
	data.conv = 0;
	data = init_data_zero(data);
	data = get_data(src, data, 0);
	// data = sort_data(data);
	// exploit_data();

	/*----------- PRINT DATA -----------*/

	
	// printf("minus = %d\n", data.minus);
	// printf("plus = %d\n", data.plus);
	// printf("zero = %d\n", data.zero);
	// printf("space = %d\n", data.space);
	// printf("htag = %d\n", data.htag);
	// printf("width_star = %d\n", data.width_star);
	// printf("width = %d\n", data.width);
	// printf("precision_coma = %d\n", data.precision_coma);
	// printf("precision_star = %d\n", data.precision_star);
	// printf("precision_num = %d\n", data.precision_num);
	// printf("l = %d\n", data.l);
	// printf("d_l = %d\n", data.d_l);
	// printf("h = %d\n", data.h);
	// printf("d_h = %d\n", data.d_h);
	// printf("conversion = %c\n", data.conv);

	
	return (c_str);
}

char	*read_input(const char *src, va_list list, int i, char *c_str)
{
	int keep;

	keep = 0;
	(void)list;
	while (src[i] != '\0')
	{
		if (src[i] != '%')
		{
			while (src[i] != '%' && src[i] != '\0')
				i++;
			if (src[i] == '%' || src[i] == '\0')
				c_str = get_string(src, c_str, keep, i);
			keep = i;
		}
		else if (src[i] == '%')
		{
			c_str = get_content(src + (i + 1), list, c_str);
			i = get_end(src, i + 1);
			keep = i;
		}
	}
	return (c_str);
}

int     ft_printf(const char *format, ...)
{
	va_list		list;
	int			displayed_char;
	char		*content_string;

	if (format[0] == '\0')
		return (0);
	if (check_all_errors(format) == -1)
		return (-1);
	va_start(list, format);
	content_string = NULL;
	content_string = read_input(format, list, 0, content_string);
	va_end(list);
	displayed_char = ft_strlen(content_string);
	// PRINTS(content_string)
	free(content_string);
	return (displayed_char);
}

int     main(void)
{
	// printf("%d\n", ft_printf(""));
	printf("%d\n", ft_printf("Cou%cou : d Cou%cou", 42)); // pb pas d'erreur
	// printf("%d\n", ft_printf("percentage = %% \nchar = %c \nstring = %s \ndecimal = %d \ninteger = %i \n", 'c', "Willy", 42, 42));
	// printf("%d\n", ft_printf("percentage = %% \nchar = %c \nstring = %s \ndecimal = %d \ninteger = %i \n", 'c', "Willy", 42, 42));
	// printf("%d\n", ft_printf(""));
	// printf("%d\n", ft_printf("Coucou : %05.5 05.5d\n", 42));
	// printf("%d\n", ft_printf("Coucou : [%-050.5ld].*\n", 42));
	// printf("Coucou : %50.*d5\n", 42);
	// printf("%d\n", ft_printf("Coucou : %+0+0+0+050.50d", 42));
	// printf("Coucou : [%0*d.5]\n", 5, 42);
	return (0);
}

// add condition errors :

// when there is 2 . ? need to check
// modifier la precision si precision_num existe
// modifier la longueur si width existe
// incrementer le data.zero seulement si il n'y a pas de . avant