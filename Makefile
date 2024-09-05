# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: buozcan <buozcan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/05 18:23:09 by buozcan           #+#    #+#              #
#    Updated: 2024/09/05 20:39:30 by buozcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./src

SRC_MATH = $(SRC)/math

SRCS_MATH = \
	$(SRC_MATH)/Vec3.cpp

#SRCS = \
#	$(SRC)/ft_isalpha.c		$(SRC)/ft_isdigit.c		$(SRC)/ft_isalnum.c \
#	$(SRC)/ft_isascii.c		$(SRC)/ft_isprint.c		$(SRC)/ft_strlen.c \
#	$(SRC)/ft_memset.c		$(SRC)/ft_bzero.c		$(SRC)/ft_memcpy.c \
#	$(SRC)/ft_memmove.c		$(SRC)/ft_strlcpy.c		$(SRC)/ft_strlcat.c \
#	$(SRC)/ft_toupper.c		$(SRC)/ft_tolower.c		$(SRC)/ft_strchr.c \
#	$(SRC)/ft_strrchr.c		$(SRC)/ft_strncmp.c		$(SRC)/ft_memchr.c \
#	$(SRC)/ft_memcmp.c		$(SRC)/ft_strnstr.c		$(SRC)/ft_atoi.c \
#	$(SRC)/ft_calloc.c		$(SRC)/ft_malloc.c		$(SRC)/ft_new.c \
#	$(SRC)/ft_strdup.c		$(SRC)/ft_substr.c		$(SRC)/ft_strjoin.c \
#	$(SRC)/ft_split.c		$(SRC)/ft_strmapi.c		$(SRC)/ft_strcheck.c \
#	$(SRC)/ft_putnbr_fd.c	$(SRC)/ft_striteri.c	$(SRC)/ft_putchar_fd.c \
#	$(SRC)/ft_putstr_fd.c	$(SRC)/ft_putendl_fd.c	$(SRC)/ft_strtrim.c \
#	$(SRC)/ft_itoa.c		$(SRC)/ft_lstnew.c		$(SRC)/ft_lstadd_front.c \
#	$(SRC)/ft_lstsize.c		$(SRC)/ft_lstlast.c		$(SRC)/ft_lstadd_back.c \
#	$(SRC)/ft_lstdelone.c	$(SRC)/ft_lstclear.c	$(SRC)/ft_lstiter.c \
#	$(SRC)/ft_lstmap.c		$(SRC)/ft_lstswap.c		$(SRC)/ft_lstsort.c \
#	$(SRC)/ft_lstissorted.c	$(SRC)/ft_arrays.c		$(SRC)/ft_stackpop.c \
#	$(SRC)/ft_stackpush.c	$(SRC)/ft_stacknew.c	$(SRC)/ft_stackclear.c \
#	$(SRC)/ft_hash.c		$(SRC)/ft_strequ.c		$(SRC)/ft_swap.c

OBJ = ./obj

#ifeq ($(USE_MATH),TRUE)
#SRCS += \
#	$(SRC)/ft_vec_conv.c	$(SRC)/ft_vec2_float.c	$(SRC)/ft_vec2_op.c \
#	$(SRC)/ft_vec2_vec2.c	$(SRC)/ft_vec3_float.c	$(SRC)/ft_vec3_vec3.c \
#	$(SRC)/ft_vec3_op.c		$(SRC)/ft_vec4_float.c	$(SRC)/ft_vec4_op.c \
#	$(SRC)/ft_vec4_vec4.c	$(SRC)/ft_mtx3_basic.c	$(SRC)/ft_utils.c \
#	$(SRC)/ft_mtx4_basic.c	$(SRC)/ft_drawing.c		$(SRC)/ft_maps.c \
#	$(SRC)/ft_colors.c
#endif

CC = g++

FLAGS = -Wall -Werror -Wextra

NAME = mlx_cpp.a

OBJS = $(SRCS_MATH:$(SRC_MATH)/%.cpp=$(OBJ)/%.o)

$(OBJ)/%.o: $(SRC_MATH)/%.cpp $(OBJ)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(OBJ):
	mkdir $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	$(CC) $(FLAGS) -I./src/math mlx_cpp.a main.cpp -o test

.PHONY: all clean re fclean test