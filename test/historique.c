/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   historique.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:27:34 by user42            #+#    #+#             */
/*   Updated: 2020/11/20 11:44:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// t_list	g_tab_operating[6] =
// {
// 	{ 'c', &operating_char },
// 	{ 's', &operating_string },
// 	{ 'd', &operating_decimal },
// 	{ 'i', &operating_integer },
// 	{ '%', &operating_percentage },
// 	{ '\0', NULL},
// };

// int    ft_find_operating(va_list *my_list, char c)
// {
// 	int i;

// 	i = 0;
// 	// printf("\n\nccccc : |%c|\n\n", c);
// 	while (g_tab_operating[i].ptr_fct != NULL)
// 	{
// 		if (g_tab_operating[i].operating == c)
// 		{
// 			g_tab_operating[i].ptr_fct(my_list);
// 			return (1);
// 		}
// 		else
// 			i++;
// 	}
// 	return (-1);
// }

t_list	*init_new_data(t_list *new_data)
{
	if (!(new_data = (t_list*)malloc(sizeof(t_list) * 1)))
		return (NULL);
	new_data->arg1 = -1;
	new_data->arg2 = -1;
	new_data->conv = -1;
	new_data->flag1 = -1;
	new_data->flag2 = -1;
	new_data->value1 = -1;
	new_data->value2 = -1;
	new_data->minus = -1;
	new_data->zero = -1;
	new_data->coma = -1;
	new_data->star = -1;
	return(new_data);
}

int		create_data(const char *src, int i, t_list **data)
{
	t_list		*new_data;

	new_data = NULL;
	new_data = init_new_data(new_data);
	if (src[i] == '-' || src[i] == '0' || src[i] == '.' || src[i] == '*')
		new_data->flag1 = src[i];
	while (new_data->flag1 == src[i])
		i++;
	new_data->value1 = ft_atoi(src + i);
	if (new_data->value1 == 0)
		new_data->value1 = -1;
	while (src[i] >= '1' && src[i] <= '9')
		i++;
	if (src[i] == '-' || src[i] == '0' || src[i] == '.' || src[i] == '*')
		new_data->flag2 = src[i];
	while (new_data->flag2 == src[i])
		i++;
	new_data->value2 = ft_atoi(src + i);
	if (new_data->value2 == 0)
		new_data->value2 = -1;
	while (src[i] >= '1' && src[i] <= '9')
		i++;
	new_data->conv = src[i];
	ft_lstadd_back(data, new_data);
	return (i);
}

int		exploit_data(t_list *data, va_list list, int disp)
{
	init_flag();
}

int		first_read(const char *src, int displayed_char, t_list **data, va_list list)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		while (src[i] != '%' && src[i] != '\0')
		{
			ft_putchar(src[i]);
			i++;
			displayed_char++;
		}
		if (src[i] == '%')
		{
			i++;
			i = create_data(src, i, data);
			exploit_data(*data, list, displayed_char);
			i++;
		}
	}
	return (displayed_char);
}

// char	*putinstr(char c, char *str, int len, int i)
// {
// 	char	*temp;

// 	if (str == NULL)
// 	{
// 		if ((str = (char*)malloc(sizeof(char) * 2)) == NULL)
// 			return (NULL);
// 		str[0] = c;
// 		str[1] = '\0';
// 		return (str);
// 	}
// 	temp = str;
// 	len = strlen(str) + 2;
// 	if ((str = (char*)malloc(sizeof(char) * (len))) == NULL)
// 		return (NULL);
// 	str[len] = '\0';
// 	while (temp[++i] != '\0')
// 		str[i] = temp[i];
// 	str[i] = c;
// 	free(temp);
// 	return (str);
// }
