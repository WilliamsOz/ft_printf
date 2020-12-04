/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_libft.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 16:36:36 by user42            #+#    #+#             */
/*   Updated: 2020/12/03 12:27:30 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_LIBFT_H
# define PRINTF_LIBFT_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>				//del

typedef	struct		s_operator
{
	char			operating;
	void			(*ptr_fct)(va_list*);
}					t_operator;

typedef struct		s_data
{
	int				conv;
	int				minus;
	int				plus;
	int				zero;
	int				space;
	int				htag;
	int				width_star;
	int				width;
	int				precision_coma;
	int				precision_star;
	int				precision_num;
	int				l;
	int				d_l;
	int				h;
	int				d_h;
	int				indicator;
	char			*arg_string;
	char			arg_char;
	long			arg_integer;
}					t_data;

t_list				init_lk_l_data(t_list *lk_list);
t_data				init_data_zero(t_data data);								//init data to 0
t_data				init_data_minus_one(t_data data);							//init data to -1
int					get_indicator(const char *src, t_data *data, int i);
void				get_lenght(const char *src, t_data *data, int i);
void				get_width(const char *src, t_data *data, int i);
void				get_precision(const char *src, t_data *data, int i);
t_data				get_data(const char *src, t_data data, int i);
char				*c_str_isnt_null(const char *src, char *c_str, int start, int end);
char				*get_string(const char *src, char *c_str, int start, int end);
int					get_end(const char *src, int i);
char				*putinstr(char c, char *str, int len, int i);
int					sp_minus(const char *src, int i, int is_width);				//check incompatibility for minus
int					sp_plus(const char *src, int start, int is_width);			//check incompatibility for plus
int					sp_space(const char *src, int i, int is_width);				//check incompatibility for space
int					sp_zero(const char *src, int i, int is_width);				//check incompatibility for zero
int					pr_coma(const char *src, int i);							//check incompatibility for coma
int					pr_star(const char *src, int i, int is_width);				//check incompatibility for star
int					check_bad_place(const char *src, int start, int end,
	t_data data);																//check the good format of indicator place (not after precision) and precision place (not after size)
int					check_too_many(const char *src, int start, int end,
	t_data data); 																//check if there are too many star or coma
int					check_format(const char *src, int start, int end);			//check the good format of the string between % and conversion
int					check_compatibility(const char *src, int start, int end,
	int is_width);																//check incompatibility
int					strcmp_missingconv(const char *src, char *conv, int i,
	int j);																		//Compare 2 string and return index + 1 if conversion is found, othewise return -1
int					check_for_unknow(const char *src, int i, int keep);			// check that flag and conversion after % is know
int					check_format_after_lenght(const char *src, int start);		//check good format after lenght
int					check_lenght(const char *src, int start, int end);
int					check_missing_conv(const char *src, char *conv, int i);		//check if conversion exist after %
int					check_all_errors(const char *src);							//check all errors
int					ft_printf(const char *src, ...);

//DEL

/* PRINT DATA
	printf("minus = %d\n", data.minus);
	printf("plus = %d\n", data.plus);
	printf("zero = %d\n", data.zero);
	printf("space = %d\n", data.space);
	printf("htag = %d\n", data.htag);
	printf("width_star = %d\n", data.width_star);
	printf("width = %d\n", data.width);
	printf("precision_coma = %d\n", data.precision_coma);
	printf("precision_star = %d\n", data.precision_star);
	printf("l = %d\n", data.l);
	printf("d_l = %d\n", data.d_l);
	printf("h = %d\n", data.h);
	printf("d_h = %d\n", data.d_h);
	printf("conversion = %c\n", data.conv);
*/

# define DEBUG printf("ICI\n");
# define PRINTD(x) printf("%d\n", x);
# define PRINTC(x) printf("%c\n", x);
# define PRINTS(x) printf("%s\n", x);

//DEL

#endif
