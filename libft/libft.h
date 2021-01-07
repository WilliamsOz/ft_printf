/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:46:23 by user42            #+#    #+#             */
/*   Updated: 2021/01/07 15:02:58 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

void				ft_putstr(const char *str);
char				*join_string(char *c_str, char *buffer);
char				*put_char_in_str(char *str, char c);
int					ft_strcmp(const char *s1, const char *s2);
void				buffer_memset(char *buffer, int b_size);
char				*ft_uitoa(uintmax_t n);
char				*ft_itoa(intmax_t n);
int					ft_atoi(const char *nptr);
char				*ft_strsjoin(char *str1, char *str2, int i, int len);
size_t				ft_strlen(const char *s);
int					strcmp_missing_conv(const char *src, char *conv, int i,
	int j);

# include <stdio.h>
# define DEBUG printf("ICI\n");
# define PRINTD(x) printf("%d\n", x);
# define PRINTC(x) printf("%c\n", x);
# define PRINTS(x) printf("%s\n", x);
# define PRINTP(x) printf("%p\n", x);
# define PRINTZ(x) printf("%zu\n", x);
# define PRINTJ(x) printf("%ju\n", x);

#endif
