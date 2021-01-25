/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:46:23 by user42            #+#    #+#             */
/*   Updated: 2021/01/25 15:19:08 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

# include <stdio.h>				//del

# define DEBUG printf("ICI\n");
# define PRINTD(x) printf("%d\n", x);
# define PRINTC(x) printf("%c\n", x);
# define PRINTS(x) printf("%s\n", x);
# define PRINTP(x) printf("%p\n", x);
# define PRINTZ(x) printf("%zu\n", x);
# define PRINTJ(x) printf("%ju\n", x);

//del

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
	int				sign_of_wdt;
	char			fill_width;
	int				precision_coma;
	int				precision_star;
	int				precision;
	int				sign_of_prc;
	int				l;
	int				d_l;
	int				h;
	int				d_h;
	char			*arg_string;
	int				is_str_null;
	char			arg_char;
	intmax_t		arg_imax;
	uintmax_t		arg_umax;
	intmax_t		*arg_pinteger;
	int				arg_len;
	int				len;
}					t_data;

void				ft_putstr(const char *str);
char				*put_char_in_str(char *str, char c);
int					ft_strcmp(const char *s1, const char *s2);
void				buffer_memset(char *buffer, int b_size);
char				*ft_uitoa(uintmax_t n);
char				*ft_itoa(intmax_t n);
int					ft_atoi(const char *nptr);
char				*ft_strsjoin(char *str1, char *str2, int i, int len);
char				*join_string(char *c_str, char *buffer);
size_t				ft_strlen(const char *s);
int					strcmp_missing_conv(const char *src, char *conv, int i,
	int j);
t_data				convert_octal(t_data data, char *base);
t_data				convert_hex(t_data data, char *base_t, char *base_c,
	int ind);
int					addprefix_of_p_conv(char *buffer, int i, int *ptr_j);
t_data				get_len_of_conv(t_data data);

#endif
