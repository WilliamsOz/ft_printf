# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 12:41:58 by wiozsert          #+#    #+#              #
#    Updated: 2021/01/27 15:47:07 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
PATHSRCS = ./srcs/
PATHLIBFT = ./libft/
ROOTFILEC = ft_printf.c
ROOTFILEO = ft_printf.o
FILESCLIBFT = $(PATHLIBFT)buffer_memset.c $(PATHLIBFT)ft_atoi.c \
$(PATHLIBFT)ft_itoa.c $(PATHLIBFT)ft_strcmp.c $(PATHLIBFT)ft_strlen.c \
$(PATHLIBFT)ft_strsjoin.c $(PATHLIBFT)ft_uitoa.c \
$(PATHLIBFT)octal_conversion.c $(PATHLIBFT)addr_or_hex_conversion.c \
$(PATHLIBFT)get_len_of_conversion.c
FILESCSRCS = $(PATHSRCS)get_arg_in_data.c $(PATHSRCS)get_data.c \
$(PATHSRCS)init_data.c $(PATHSRCS)treat_hex.c $(PATHSRCS)treat_percent.c \
$(PATHSRCS)treat_c.c $(PATHSRCS)treat_s.c $(PATHSRCS)treat_p.c \
$(PATHSRCS)treat_d_i.c $(PATHSRCS)treat_u_integer.c
PATHFILESCLIBFT = $(PATHLIBFT)buffer_memset.o $(PATHLIBFT)ft_atoi.o \
$(PATHLIBFT)ft_itoa.o $(PATHLIBFT)ft_strcmp.o $(PATHLIBFT)ft_strlen.o \
$(PATHLIBFT)ft_strsjoin.o $(PATHLIBFT)ft_uitoa.o \
$(PATHLIBFT)octal_conversion.o $(PATHLIBFT)addr_or_hex_conversion.o \
$(PATHLIBFT)get_len_of_conversion.o
PATHFILESCSRCS = $(PATHSRCS)get_arg_in_data.o $(PATHSRCS)get_data.o \
$(PATHSRCS)init_data.o $(PATHSRCS)treat_hex.o $(PATHSRCS)treat_percent.o \
$(PATHSRCS)treat_c.o $(PATHSRCS)treat_s.o $(PATHSRCS)treat_p.o \
$(PATHSRCS)treat_d_i.o $(PATHSRCS)treat_u_integer.o
BONUSC = $(PATHSRCS)flags_bonus.c $(PATHSRCS)length_bonus.c
FILESOLIBFT = buffer_memset.o ft_atoi.o ft_itoa.o ft_strcmp.o \
ft_strlen.o ft_strsjoin.o ft_uitoa.o octal_conversion.o \
addr_or_hex_conversion.o get_len_of_conversion.o
FILESOSRCS = get_arg_in_data.o get_data.o init_data.o treat_hex.o \
treat_percent.o treat_c.o treat_s.o treat_p.o treat_d_i.o treat_u_integer.o
BONUSC = $(PATHSRCS)flags_bonus.c $(PATHSRCS)length_bonus.c
PATHFILESBONUSO = $(PATHSRCS)flags_bonus.o $(PATHSRCS)length_bonus.o
BONUSO = flags_bonus.o length_bonus.o

all : $(NAME)

$(NAME) :
	gcc $(FLAGS) -c $(ROOTFILEC) $(FILESCLIBFT) $(FILESCSRCS) $(BONUSC)
	ar -rcs $(NAME) $(ROOTFILEO) $(FILESOLIBFT) $(FILESOSRCS) $(BONUSO)
	mv $(FILESOSRCS) $(BONUSO) ./srcs
	mv $(FILESOLIBFT) ./libft

clean :
	rm -rf $(ROOTFILEO) $(PATHFILESCLIBFT) $(PATHFILESCSRCS) $(PATHFILESBONUSO)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : fclean all
