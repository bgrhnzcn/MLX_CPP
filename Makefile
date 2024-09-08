# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/05 18:23:09 by buozcan           #+#    #+#              #
#    Updated: 2024/09/07 16:39:51 by bgrhnzcn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = g++

FLAGS = -g -std=c++20 -Wall -Werror -Wextra #-pedantic

NAME = libmlxcpp.a

SRCEXT = cpp

SRCDIR = ./src

SRCS = $(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")

OBJEXT = o

OBJDIR = ./obj

OBJS = $(patsubst $(SRCDIR)/%.$(SRCEXT), $(OBJDIR)/%.$(OBJEXT), $(SRCS))

INCEXT = hpp

INC = $(shell find . -type f -name "*.h*" -exec dirname {} \; | sort -u  | sed 's/^/-I/')

all: $(NAME)

print:
	@echo $(SRCS)
	@echo $(OBJS)
	@echo $(INC)

$(OBJDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

test: $(NAME)
	@rm -f test
	$(CC) $(FLAGS) main.$(SRCEXT) -o test $(INC) -L./ -lmlxcpp -L./lib/mlx -lmlx -lXext -lX11
	@./test

.PHONY: all clean re fclean test