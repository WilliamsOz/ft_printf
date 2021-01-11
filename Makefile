# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 12:41:58 by wiozsert          #+#    #+#              #
#    Updated: 2021/01/11 14:41:22 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
PATHSRCS = ./srcs/
PATHLIBFT = ./libft/
ROOTFILEC = ft_printf.c
ROOTFILEO = ft_printf.o
FILESCLIBFT = $(PATHLIBFT)buffer_memset.c $(PATHLIBFT)ft_atoi.c $(PATHLIBFT)ft_itoa.c \
$(PATHLIBFT)ft_putstr.c $(PATHLIBFT)ft_strcmp.c $(PATHLIBFT)ft_strlen.c \
$(PATHLIBFT)ft_strsjoin.c $(PATHLIBFT)ft_uitoa.c $(PATHLIBFT)put_char_in_string.c \
$(PATHLIBFT)strcmp_missing_conv.c
FILESCSRCS = $(PATHSRCS)addr_or_hex_conversion.c $(PATHSRCS)check_bad_format.c \
$(PATHSRCS)check_errors.c $(PATHSRCS)check_format.c \
$(PATHSRCS)check_precision_incompatibility.c $(PATHSRCS)check_specifier_incompatibility.c \
$(PATHSRCS)get_arg_in_data.c $(PATHSRCS)get_data.c $(PATHSRCS)get_string.c \
$(PATHSRCS)init_data.c $(PATHSRCS)treat_d_i_u.c \
$(PATHSRCS)treat_hex.c $(PATHSRCS)treat_percent.c $(PATHSRCS)treat_c.c
PATHFILESCLIBFT = $(PATHLIBFT)buffer_memset.o $(PATHLIBFT)ft_atoi.o $(PATHLIBFT)ft_itoa.o \
$(PATHLIBFT)ft_putstr.o $(PATHLIBFT)ft_strcmp.o $(PATHLIBFT)ft_strlen.o \
$(PATHLIBFT)ft_strsjoin.o $(PATHLIBFT)ft_uitoa.o $(PATHLIBFT)put_char_in_string.o \
$(PATHLIBFT)strcmp_missing_conv.o
PATHFILESCSRCS = $(PATHSRCS)addr_or_hex_conversion.o $(PATHSRCS)check_bad_format.o \
$(PATHSRCS)check_errors.o $(PATHSRCS)check_format.o \
$(PATHSRCS)check_precision_incompatibility.o $(PATHSRCS)check_specifier_incompatibility.o \
$(PATHSRCS)get_arg_in_data.o $(PATHSRCS)get_data.o $(PATHSRCS)get_string.o \
$(PATHSRCS)init_data.o $(PATHSRCS)treat_d_i_u.o \
$(PATHSRCS)treat_hex.o $(PATHSRCS)treat_percent.o $(PATHSRCS)treat_c.o
# BONUSC = $(PATHSRCS)flags_bonus.c $(PATHSRCS)lenght_bonus.c
FILESOLIBFT = buffer_memset.o ft_atoi.o ft_itoa.o \
ft_putstr.o ft_strcmp.o ft_strlen.o \
ft_strsjoin.o ft_uitoa.o put_char_in_string.o \
strcmp_missing_conv.o
FILESOSRCS = addr_or_hex_conversion.o check_bad_format.o check_errors.o check_format.o \
check_precision_incompatibility.o check_specifier_incompatibility.o \
get_arg_in_data.o get_data.o get_string.o init_data.o treat_c.o \
treat_d_i_u.o treat_hex.o treat_percent.o
# BONUSC = $(PATHSRCS)flags_bonus.c $(PATHSRCS)lenght_bonus.c
# PATHFILESBONUSO = $(PATHSRCS)flags_bonus.o $(PATHSRCS)lenght_bonus.o
# BONUSO = flags_bonus.o lenght_bonus.o

all : $(NAME)

$(NAME) :
	gcc $(FLAGS) -c $(ROOTFILEC) $(FILESCLIBFT) $(FILESCSRCS)
	ar -rcs $(NAME) $(ROOTFILEO) $(FILESOLIBFT) $(FILESOSRCS)
	mv $(FILESOSRCS) ./srcs
	mv $(FILESOLIBFT) ./libft

clean : # $(PATHFILESBONUSO)
	rm -rf $(ROOTFILEO) $(PATHFILESCLIBFT) $(PATHFILESCSRCS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

# bonus : fclean # $(BONUSC) $(BONUSO)	mv $(BONUSO) ./srcs
# 	gcc $(FLAGS) -c $(ROOTFILEC) $(FILESCLIBFT) $(FILESCSRCS)
# 	ar -rcs $(NAME) $(ROOTFILEO) $(FILESOLIBFT) $(FILESOSRCS)
# 	mv $(FILESOSRCS) ./srcs
# 	mv $(FILESOLIBFT) ./libft
