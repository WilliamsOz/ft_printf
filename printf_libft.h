/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_libft.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:36:36 by user42            #+#    #+#             */
/*   Updated: 2021/01/28 11:34:12 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_LIBFT_H
# define PRINTF_LIBFT_H

# include "libft/libft.h"

void					init_bonus_data(t_b_type b_type);
t_data					bl_for_n(t_data data, va_list list, t_b_type b_type);
t_data					bl_uinteger(t_data data, va_list list, t_b_type b_type);
t_data					bl_integer(t_data data, va_list list, t_b_type b_type);
t_data					bonus_htag(t_data data, char *buffer, int *ptr_i,
	int ind);
int						bonus_plus(char *buffer, int i, t_data *data);
int						bonus_space(char *buffer, int i, t_data *data);
int						get_end(const char *src, int i);
char					*putinstr(char c, char *str, int len, int i);
int						sp_minus(const char *src, int i, int is_width);
int						sp_plus(const char *src, int start, int is_width);
int						sp_space(const char *src, int i, int is_width);
int						sp_zero(const char *src, int i, int is_width);
int						pr_coma(const char *src, int i);
int						pr_star(const char *src, int i, int is_width);
t_data					get_hex_arg(t_data data, va_list list);
t_data					get_data(const char *src, t_data data, va_list list);
t_data					get_arg(t_data data, va_list list);
t_data					init_arg_and_data(t_data data, int indicator);
char					*treat_udi_di(t_data data, char *c_str,
	int sign_of_width, int b_size);
t_data					treat_percent(t_data data);
t_data					treat_hex(t_data data);
t_data					treat_u_integer(t_data data);
t_data					treat_d_i(t_data data);
t_data					treat_p(t_data data);
t_data					*treat_s(t_data *data);
t_data					treat_c(t_data data);
int						ft_printf(const char *format, ...);

#endif
