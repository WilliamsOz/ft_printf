/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:46:23 by user42            #+#    #+#             */
/*   Updated: 2020/12/31 15:49:35 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>				//del

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
# define PRINTP(x) printf("%p\n", x);
# define PRINTZ(x) printf("%zu\n", x);
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

//DEL

// typedef struct		s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }					t_list;

int					ft_strcmp(const char *s1, const char *s2);
void				buffer_memset(char *buffer, size_t BUFFER_SIZE);
char				*ft_uitoa(uintmax_t n);
char				*ft_itoa(intmax_t n);
int					ft_atoi(const char *nptr);
char				*ft_strsjoin(char *str1, char *str2, int i, int len);
size_t				ft_strlen(const char *s);
int					strcmp_missing_conv(const char *src, char *conv, int i,
	int j);

#endif
