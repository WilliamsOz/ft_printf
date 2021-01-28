/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:46:23 by user42            #+#    #+#             */
/*   Updated: 2021/01/28 11:33:41 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

typedef struct			s_b_type
{
	long				i_long;
	long long			i_llong;
	signed char			i_schar;
	unsigned	long	u_long;
	unsigned long long	u_llong;
	long				*ptr_long;
	long long			*ptr_llong;
	short				*ptr_short;
	char				*ptr_char;
}						t_b_type;

typedef struct			s_data
{
	int					conv;
	int					minus;
	int					plus;
	int					zero;
	int					space;
	int					htag;
	int					width_star;
	int					width;
	int					sign_of_wdt;
	char				fill_width;
	int					precision_coma;
	int					precision_star;
	int					precision;
	int					sign_of_prc;
	int					is_there_prc;
	int					l;
	int					d_l;
	int					h;
	int					d_h;
	char				*arg_string;
	int					is_str_null;
	char				arg_char;
	intmax_t			arg_imax;
	uintmax_t			arg_umax;
	intmax_t			*arg_pinteger;
	int					arg_len;
	int					len;
}						t_data;

t_data					get_address(t_data data, char *base, int i);
t_data					convert_hex(t_data data, char *base_t, char *base_c,
	int ind);
int						get_end(const char *src, int i);
void					buffer_memset(char *buffer, int b_size);
char					*ft_uitoa(uintmax_t n);
char					*ft_itoa(intmax_t n);
int						ft_atoi(const char *nptr);
char					*ft_strsjoin(char *str1, char *str2, int i, int len);
char					*join_string(char *c_str, char *buffer);
size_t					ft_strlen(const char *s);
t_data					convert_octal(t_data data, char *base);
t_data					convert_hex(t_data data, char *base_t, char *base_c,
	int ind);
int						addprefix_of_p_conv(char *buffer, int i, int *ptr_j);
t_data					get_len_of_conv(t_data data);

#endif
