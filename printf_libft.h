/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_libft.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:36:36 by user42            #+#    #+#             */
/*   Updated: 2020/12/31 15:49:20 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_LIBFT_H
# define PRINTF_LIBFT_H

#define _GNU_SOURCE 1
# include "./libft/libft.h"
# include <stdarg.h>

typedef	struct			s_operator
{
	char				operating;
	void				(*ptr_fct)(va_list*);
}						t_operator;

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
	size_t				arg_len;
}						t_data;

char					*c_str_isnt_null(const char *src, char *c_str, int start, int end);
char					*get_string(const char *src, char *c_str, int start, int end);
int						get_end(const char *src, int i);
char					*putinstr(char c, char *str, int len, int i);
int						sp_minus(const char *src, int i, int is_width);				//check incompatibility for minus
int						sp_plus(const char *src, int start, int is_width);			//check incompatibility for plus
int						sp_space(const char *src, int i, int is_width);				//check incompatibility for space
int						sp_zero(const char *src, int i, int is_width);				//check incompatibility for zero
int						pr_coma(const char *src, int i);							//check incompatibility for coma
int						pr_star(const char *src, int i, int is_width);				//check incompatibility for star
int						check_format(const char *src, int start, int end);			//check the good format of the string between % and conversion
int						check_missing_conv(const char *src, char *conv, int i);					//check if conversion exist after %
int						check_all_errors(const char *src);							//check all errors
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
t_data 					get_arg(t_data data, va_list list, char *c_str);
t_data					init_arg_and_data(t_data data, int indicator);
t_data					sort_data(t_data data);
char					*treat_cs(t_data data, char *c_str, int n_sign,
	size_t B_SIZE);
char					*treat_udi_di(t_data data, char *c_str,
	int sign_of_width, int B_SIZE);
char					*treat_hex(t_data data, char *c_str, int sign_of_width,
	int B_SIZE);
char					*treat_percent(char *c_str);
char					*treat_content(const char *src, va_list list,
	char *c_str);
int						ft_printf(const char *src, ...);
int						ft_asprintf(char **content_string, const char *format, ...);

#endif
