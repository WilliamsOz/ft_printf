/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_libft.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:36:36 by user42            #+#    #+#             */
/*   Updated: 2021/01/07 15:31:55 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_LIBFT_H
# define PRINTF_LIBFT_H

# include "libft/libft.h"

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
	int					l;
	int					d_l;
	int					h;
	int					d_h;
	char				*arg_string;
	int					null_str_indicator;
	char				arg_char;
	intmax_t			arg_imax;
	uintmax_t			arg_umax;
	intmax_t			*arg_pinteger;
	char				*arg_addr;
	char				*hex_temp;
	int					arg_len;
	char				*c_str;
	int					len_c_str;
}						t_data;

t_data					bonus_lenght_uinteger(t_data data, va_list list);
t_data					bonus_lenght_integer(t_data data, va_list list);
t_data					bonus_htag(t_data data, char *buffer, int *ptr_i);
int						bonus_plus(char *buffer, int i);
int						bonus_space(char *buffer, int i);
t_data					*get_string(const char *src, t_data *data, int start,
	int end);
int						get_end(const char *src, int i);
char					*putinstr(char c, char *str, int len, int i);
int						sp_minus(const char *src, int i, int is_width);
int						sp_plus(const char *src, int start, int is_width);
int						sp_space(const char *src, int i, int is_width);
int						sp_zero(const char *src, int i, int is_width);
int						pr_coma(const char *src, int i);
int						pr_star(const char *src, int i, int is_width);
int						check_format(const char *src, int start, int end);
int						check_missing_conv(const char *src, char *conv, int i);
int						check_all_errors(const char *src);
t_data					get_hex_arg(t_data data, va_list list);
int						get_lenforhex(unsigned long long ull,
	unsigned int ui);
t_data					convert_tiny_base(t_data data, char *base_t,
	char *res);
t_data					convert_caps_base(t_data data, char *base_c,
	char *res);
t_data					convert_hex(t_data data, char *base_t, char *base_c,
	int indicator);
t_data					get_address(t_data data, char *base, int i);
t_data					get_data(const char *src, t_data data, int i,
	va_list list);
t_data					get_arg(t_data data, va_list list);
t_data					init_arg_and_data(t_data data, int indicator);
t_data					sort_data(t_data data);
char					*treat_udi_di(t_data data, char *c_str,
	int sign_of_width, int b_size);
char					*treat_hex(t_data data, char *c_str, int sign_of_width,
	int b_size);
char					*treat_percent(t_data data, char *c_str, size_t bsize,
	int sign_ow);
t_data					treat_csp(t_data data);
t_data					treat_content(const char *src, va_list list,
	t_data data);
int						ft_printf(const char *format, ...);

#endif
